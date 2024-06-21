#include "MyForm.h"

using namespace System::IO;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
using namespace System::Drawing;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	SpeedConstant::MyForm form;
	Application::Run(% form);
}

System::Void SpeedConstant::MyForm::button_make_calculations_Click(System::Object^ sender, System::EventArgs^ e) {

    if (!check_user_input()) {
        return;
    }

    //обновление переменых для проверок
    is_calculations = true;

    //объявление переменных для рассчётов
    d = 0.0;
    int i, size_for_arrays = Convert::ToInt32(SpeedConstant::MyForm::numeric_of_points->Value);
    array<double>^ y = gcnew array<double>(size_for_arrays);
    array<double>^ x = gcnew array<double>(size_for_arrays);
    double s1 = (Convert::ToInt32(numeric_of_points->Value) - 1),
        s2 = 0.0, s3 = 0.0, s4 = 0.0, s5 = 0.0, s6 = 0.0, t;

    //Очистка графиков после предыдущего расчета
    this->chart->Series[0]->Points->Clear();
    this->chart->Series[1]->Points->Clear();
    this->chart->Series[2]->Points->Clear();
    this->chart->Series[3]->Points->Clear();
    this->chart->Series[4]->Points->Clear();

    Ca = Convert::ToDouble(dataGridView1[0, 0]->Value) * 3;
    Cb = Convert::ToDouble(textBox_CB->Text);
    Cc = Convert::ToDouble(textBox_CC->Text);
    Cd = Convert::ToDouble(textBox_CD->Text);
    
    //Расчет значений локальных переменных, необходимых для решения задачи
    for (i = 0; i < Convert::ToInt32(numeric_of_points->Value) - 1; i++) {

        y[i] = log(fabs(Convert::ToDouble(dataGridView1[0, i + 1]->Value) - Convert::ToDouble(dataGridView1[0, i]->Value)) /
            (Convert::ToDouble(dataGridView1[1, i + 1]->Value) - Convert::ToDouble(dataGridView1[1, i]->Value)));
        x[i] = log(Convert::ToDouble(dataGridView1[0, i]->Value));

        s2 += x[i];
        s3 += y[i];
        s4 += x[i] * x[i];
        s5 += x[i] * y[i];
        s6 += y[i] * y[i];
    }

    //Расчет константы скорости реакции, порядка реакции, коэффициента корреляции
    k = exp((s3 * s4 - s2 * s5) / (s1 * s4 - s2 * s2));
    n = (s1 * s5 - s2 * s3) / (s1 * s4 - s2 * s2);
    r = (s1 * s5 - s2 * s3) / sqrt((s1 * s4 - s2 * s2) * (s1 * s6 - s3 * s3));

    //Построение графиков и расчет концентраций компонентов реакции
    for (i = 0; i < Convert::ToInt32(numeric_of_points->Value); i++) {
        this->chart->Series[0]->Points->AddXY(Convert::ToDouble(dataGridView1[1, i]->Value),
            Convert::ToDouble(dataGridView1[0, i]->Value) * 3);

        if (i == 0) {
            this->chart->Series[1]->Points->AddXY(Convert::ToDouble(dataGridView1[1, i]->Value), Ca);
            this->chart->Series[2]->Points->AddXY(Convert::ToDouble(dataGridView1[1, i]->Value), Cc);
            this->chart->Series[3]->Points->AddXY(Convert::ToDouble(dataGridView1[1, i]->Value), Cb);
            this->chart->Series[4]->Points->AddXY(Convert::ToDouble(dataGridView1[1, i]->Value), Cd);
        }
        else {
            t = Convert::ToDouble(dataGridView1[1, i]->Value) - Convert::ToDouble(dataGridView1[1, i - 1]->Value);
            this->chart->Series[2]->Points->AddXY(Convert::ToDouble(dataGridView1[1, i]->Value), Cc = Cc + k * pow(Ca, n) * t);
            this->chart->Series[3]->Points->AddXY(Convert::ToDouble(dataGridView1[1, i]->Value), Cb = Cb + k * 2 * pow(Ca, n) * t);
            this->chart->Series[4]->Points->AddXY(Convert::ToDouble(dataGridView1[1, i]->Value), Cd = Cd + k * 5 * pow(Ca, n) * t);
            if (reg_down > reg_up)
                this->chart->Series[1]->Points->AddXY(Convert::ToDouble(dataGridView1[1, i]->Value), Ca = Ca - k * pow(Ca, n) * t);
            else
                this->chart->Series[1]->Points->AddXY(Convert::ToDouble(dataGridView1[1, i]->Value), Ca = Ca + k * pow(Ca, n) * t);
        }
        //расчет дисперсии
        d += pow(Convert::ToDouble(dataGridView1[0, i]->Value) - Ca / 3, 2);
    }

    //вывод данных
    Result_form^ results_form;
    results_form = gcnew Result_form(k, n, d, r);
    results_form->Show();

	return System::Void();
}

System::Void SpeedConstant::MyForm::numeric_of_points_ValueChanged(System::Object^ sender, System::EventArgs^ e) {

    is_calculations = false;

    int new_count_of_rows = Convert::ToInt32(numeric_of_points->Value);
    int old_row_count = dataGridView1->Rows->Count;

    //изменение количества строк в таблице
    if (new_count_of_rows > old_row_count) {
        for (int i = old_row_count; i < new_count_of_rows; i++) {
            DataGridViewRow^ row = gcnew DataGridViewRow();
            row->HeaderCell->Value = "" + (dataGridView1->RowCount + 1);
            row->CreateCells(dataGridView1);
            dataGridView1->Rows->Add(row);
            dataGridView1->RowHeadersWidth = 100;
        }
        return System::Void();
    }

    if (new_count_of_rows < old_row_count) {
        for (int i = 0; i + new_count_of_rows < old_row_count; i++) {
            dataGridView1->Rows->RemoveAt((old_row_count - i - 1));
            dataGridView1->Refresh();
        }
        return System::Void();
    }
}

System::Void SpeedConstant::MyForm::menu_information_Click(System::Object^ sender, System::EventArgs^ e) {

    MessageBox::Show("      Данная программа расчитывает порядок и консанту скорости химической реакции.\n"
        "       Для начала работы введите данные об исходных веществах: начальные концетрации Cb, Cc и Cd, заполните таблицу с изменением концетрации Ca в течении времени.\n"
        "\tАвтор программы: Дивногорский Антон Андреевич\n"
        "\tГруппа: 4303\n"
        "\tУчебное заведение: СПбГТИ(ТУ)", "Основная информация");

    return System::Void();
}

System::Void SpeedConstant::MyForm::menu_tests_Click(System::Object^ sender, System::EventArgs^ e) {

    is_calculations = false;

    const int lenght_strings = 2, lenght_rows = 6;
    double testing_data[6][2] = { {2.2, 0},
                                  {1.7, 1.7},
                                  {1.5, 2.5},
                                  {1.4, 3.1},
                                  {1.2, 3.8},
                                  {1.1, 4.5} };

    textBox_CB->Text = "0,1";
    Cb = 0.1;
    textBox_CC->Text = "0,7";
    Cc = 0.7;
    textBox_CD->Text = "0,5";
    Cd = 0.5;

    numeric_of_points->Value = lenght_rows;

    for (int i = 0; i < lenght_rows; i++) {
        for (int j = 0; j < lenght_strings; j++) {
            dataGridView1[j, i]->Value = testing_data[i][j];
        }
    }

    return System::Void();
}

System::Void SpeedConstant::MyForm::button_save_data_Click(System::Object^ sender, System::EventArgs^ e) {

    bool savetxtsucces = false;
    bool saveimgsucces = false;

    //проверка рассчётов
    if (!is_calculations) {
        MessageBox::Show("Вы ещё не провели рассчёты!", "Внимание!");
        return;
    }

    //сохранение данных в файле
    saveFileDialog1->FileName = "data.txt";
    saveFileDialog1->Filter = "txt files (*.txt)|*.txt";
    if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        StreamWriter^ write_data = gcnew StreamWriter(saveFileDialog1->FileName);
        write_data->Write("Порядок реакции: ");
        write_data->WriteLine(Convert::ToString(n));
        write_data->Write("Константа скорости: ");
        write_data->WriteLine(Convert::ToString(k));
        write_data->Write("Дисперсия: ");
        write_data->WriteLine(Convert::ToString(d));
        write_data->Write("Кореляция: ");
        write_data->WriteLine(Convert::ToString(r));

        write_data->Close();
        savetxtsucces = true;
    }

    saveFileDialog1->Title = "Сохранить изображение как ...";
    saveFileDialog1->Filter = "*.bmp|*.bmp;|*.png|*.png;|*.jpg|*.jpg";
    saveFileDialog1->AddExtension = true;
    saveFileDialog1->FileName = "graphicImage";

    if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        switch (saveFileDialog1->FilterIndex)
        {
        case 1: chart->SaveImage(saveFileDialog1->FileName, System::Windows::Forms::DataVisualization::Charting::ChartImageFormat::Bmp); break;
        case 2: chart->SaveImage(saveFileDialog1->FileName, System::Windows::Forms::DataVisualization::Charting::ChartImageFormat::Png); break;
        case 3: chart->SaveImage(saveFileDialog1->FileName, System::Windows::Forms::DataVisualization::Charting::ChartImageFormat::Jpeg); break;
        }
        saveimgsucces = true;
    }

    if (savetxtsucces && !saveimgsucces) MessageBox::Show("Сохранены только результаты порядка, константы скорости, кореляции и дисперсии!", "Внимание!");
    if (saveimgsucces && !savetxtsucces) MessageBox::Show("Сохранен только график!", "Внимание!");
    if (saveimgsucces * savetxtsucces) MessageBox::Show("Результаты последнего расчета сохранены!", "Успех!");

    return System::Void();
}

System::Void SpeedConstant::MyForm::button_file_data_Click(System::Object^ sender, System::EventArgs^ e) {

    Stream^ myStream;
    String^ Readfile;

    clear_fields();

    if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        if ((myStream = openFileDialog1->OpenFile()) != nullptr) {

            String^ strfilename = openFileDialog1->InitialDirectory + openFileDialog1->FileName;

            Readfile = File::ReadAllText(strfilename);

            mySplitString = Readfile->Split('\n', ' ');

            if (mySplitString->Length < 6) {
                MessageBox::Show("В файле недостаточно данных!", "Внимание!");
                return;
            }

            for (int i = 0; i < (mySplitString->Length); i++) {
                try {
                    if (i == 0) {
                        Cb = Convert::ToDouble(mySplitString[i]);
                        textBox_CB->Text = mySplitString[i];
                    }
                    else if (i == 1) {
                        Cc = Convert::ToDouble(mySplitString[i]);
                        textBox_CC->Text = mySplitString[i];
                    }
                    else if (i == 2) {
                        Cd = Convert::ToDouble(mySplitString[i]);
                        textBox_CD->Text = mySplitString[i];
                    }
                }
                catch (...) {
                    MessageBox::Show("Некоректные данные в файле в полях концентрации Cb, Cc, Cd !", "Внимание!");
                    clear_fields();
                    return;
                }
                try {
                    if (i == 3) {
                        numeric_of_points->Value = Convert::ToInt32(mySplitString[i]);
                    }
                }
                catch (...) {
                    MessageBox::Show("Некоректные данные в файле в поле \"в количестве точек\"!", "Внимание!");
                    clear_fields();
                    return;
                }

                if ((mySplitString->Length - not_a_table) / 2 != Convert::ToDouble(mySplitString[3])) {
                    MessageBox::Show("Недостаточное количество концетрации С и времени t!", "Внимание!");
                    return;
                }
            }

            for (int i = 0; i < (mySplitString->Length - not_a_table) / 2; i++) {
                for (int j = 0; j < lenght_strings; j++) {
                    try {
                        dataGridView1[j, i]->Value = Convert::ToDouble(mySplitString[i * 2 + not_a_table + j]);
                    }
                    catch (...) {
                        MessageBox::Show("Некоректные данные в файле в полях конценраций C и времени t!", "Внимание!");
                        clear_fields();
                        return;
                    }
                }
            }

            myStream->Close();
            is_calculations = false;
        }
    }

    return System::Void();
}

bool SpeedConstant::MyForm::check_user_input() {

    //проверка на корректные данные ca, cb, cc, cd и количества точек
    try {
        Cb = Convert::ToDouble(textBox_CB->Text);
        Cc = Convert::ToDouble(textBox_CC->Text);
        Cd = Convert::ToDouble(textBox_CD->Text);

        if (Convert::ToDouble(textBox_CB->Text) <= 0 || Convert::ToDouble(textBox_CC->Text) <= 0 || Convert::ToDouble(textBox_CD->Text) <= 0) {
            MessageBox::Show("Начальные концентрации должны быть больлше 0!", "Внимание!");
            return 0;
        }
    }
    catch (...) {
        MessageBox::Show("Некоректные данные в полях концентрации Cb, Cc, Cd!", "Внимание!");
        return 0;
    }

    if (Convert::ToInt32(numeric_of_points->Value) == 0) {
        MessageBox::Show("Количество точек должно быть больше 0!", "Внимание!");
        return 0;
    }

    //проверка таблицы на корректные данные
    for (int j = 0; j < dataGridView1->ColumnCount; j++) {
        for (int i = 0; i < dataGridView1->Rows->Count; i++) {
            if (dataGridView1[j, i]->Value == nullptr) {
                MessageBox::Show("Заполните таблицу!", "Внимание!");
                return 0;
            }
        }
    }

    for (int i = 0; i < dataGridView1->Rows->Count; i++) {
        for (int j = 0; j < dataGridView1->ColumnCount; j++) {
            try {
                Convert::ToDouble(dataGridView1[j, i]->Value);
            }
            catch (...) {
                MessageBox::Show("Пожалуйста, заполните таблицу числами!", "Внимание!");
                return 0;
            }
        }
    }

    for (int i = 0; i < dataGridView1->Rows->Count - 1; i++) {
        if (Convert::ToDouble(dataGridView1[0, i]->Value) > Convert::ToDouble(dataGridView1[0, i + 1]->Value))
            reg_down++;
        else
            reg_up++;
        if (Convert::ToDouble(dataGridView1[0, i]->Value) == Convert::ToDouble(dataGridView1[0, i + 1]->Value)) {
            MessageBox::Show("Концентрация в соседних точках должна быть различна", "Внимание!");
            return 0;
        }
        if (Convert::ToDouble(dataGridView1[1, i]->Value) >= Convert::ToDouble(dataGridView1[1, i + 1]->Value)) {
            MessageBox::Show("Время должно увеличиваться!", "Внимание!");
            return 0;
        }
        if (Convert::ToDouble(dataGridView1[1, i]->Value) < 0 || Convert::ToDouble(dataGridView1[0, i]->Value) < 0) {
            MessageBox::Show("Время и концентрация не могут быть отрицательными", "Внимание!");
            return 0;
        }
    }

    return 1;
}

System::Void SpeedConstant::MyForm::button_clear_Click(System::Object^ sender, System::EventArgs^ e) {

    is_calculations = false;

    this->chart->Series[0]->Points->Clear();
    this->chart->Series[1]->Points->Clear();
    this->chart->Series[2]->Points->Clear();
    this->chart->Series[3]->Points->Clear();
    this->chart->Series[4]->Points->Clear();

    clear_fields();

    return System::Void();
}

void SpeedConstant::MyForm::clear_fields() {

    textBox_CB->Text = "";
    Cb = 0;
    textBox_CC->Text = "";
    Cc = 0;
    textBox_CD->Text = "";
    Cd = 0;
    numeric_of_points->Value = 0;
}
