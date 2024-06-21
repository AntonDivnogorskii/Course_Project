#pragma once
#include <cmath>
#include "Result_form.h"

namespace SpeedConstant {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label3;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::NumericUpDown^ numeric_of_points;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox_CB;
	private: System::Windows::Forms::TextBox^ textBox_CC;



	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_C;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_T;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox_CD;

	private: System::Windows::Forms::Button^ button_file_data;
	private: System::Windows::Forms::Button^ button_make_calculations;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ menu_information;
	private: System::Windows::Forms::ToolStripMenuItem^ menu_tests;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button_clear;
	private: System::Windows::Forms::Button^ button_save_data;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;















	private: System::ComponentModel::IContainer^ components;











	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column_C = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_T = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numeric_of_points = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox_CD = (gcnew System::Windows::Forms::TextBox());
			this->textBox_CB = (gcnew System::Windows::Forms::TextBox());
			this->textBox_CC = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button_make_calculations = (gcnew System::Windows::Forms::Button());
			this->button_file_data = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_information = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_tests = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button_clear = (gcnew System::Windows::Forms::Button());
			this->button_save_data = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_of_points))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(44, 67);
			this->label3->MaximumSize = System::Drawing::Size(1000, 1000);
			this->label3->MinimumSize = System::Drawing::Size(1, 1);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(337, 37);
			this->label3->TabIndex = 5;
			this->label3->Text = L"3A = 2B + C + 5D";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(71, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(236, 29);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Скорость реакции";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->numeric_of_points);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox_CD);
			this->groupBox1->Controls->Add(this->textBox_CB);
			this->groupBox1->Controls->Add(this->textBox_CC);
			this->groupBox1->Location = System::Drawing::Point(21, 128);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(399, 379);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ввод исходных данных";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(34, 156);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(206, 25);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Количество точек:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column_C,
					this->Column_T
			});
			this->dataGridView1->Location = System::Drawing::Point(11, 196);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(382, 173);
			this->dataGridView1->TabIndex = 9;
			// 
			// Column_C
			// 
			this->Column_C->HeaderText = L"C";
			this->Column_C->MinimumWidth = 6;
			this->Column_C->Name = L"Column_C";
			this->Column_C->Width = 125;
			// 
			// Column_T
			// 
			this->Column_T->HeaderText = L"t";
			this->Column_T->MinimumWidth = 6;
			this->Column_T->Name = L"Column_T";
			this->Column_T->Width = 125;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(206)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->label2->Location = System::Drawing::Point(34, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(207, 25);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Концентрация Cd -";
			// 
			// numeric_of_points
			// 
			this->numeric_of_points->Location = System::Drawing::Point(263, 159);
			this->numeric_of_points->Name = L"numeric_of_points";
			this->numeric_of_points->Size = System::Drawing::Size(106, 22);
			this->numeric_of_points->TabIndex = 5;
			this->numeric_of_points->ValueChanged += gcnew System::EventHandler(this, &MyForm::numeric_of_points_ValueChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::MediumAquamarine;
			this->label5->Location = System::Drawing::Point(34, 66);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(206, 25);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Концентрация Cc -";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::DarkViolet;
			this->label4->Location = System::Drawing::Point(34, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(207, 25);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Концентрация Cb -";
			// 
			// textBox_CD
			// 
			this->textBox_CD->Location = System::Drawing::Point(263, 113);
			this->textBox_CD->Name = L"textBox_CD";
			this->textBox_CD->Size = System::Drawing::Size(106, 22);
			this->textBox_CD->TabIndex = 12;
			// 
			// textBox_CB
			// 
			this->textBox_CB->Location = System::Drawing::Point(263, 25);
			this->textBox_CB->Name = L"textBox_CB";
			this->textBox_CB->Size = System::Drawing::Size(106, 22);
			this->textBox_CB->TabIndex = 3;
			// 
			// textBox_CC
			// 
			this->textBox_CC->Location = System::Drawing::Point(263, 69);
			this->textBox_CC->Name = L"textBox_CC";
			this->textBox_CC->Size = System::Drawing::Size(106, 22);
			this->textBox_CC->TabIndex = 4;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->chart);
			this->groupBox2->Location = System::Drawing::Point(448, 128);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(995, 534);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Графики";
			// 
			// chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(6, 21);
			this->chart->Name = L"chart";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Color = System::Drawing::Color::Red;
			series1->Legend = L"Legend1";
			series1->Name = L"Ca расч";
			series1->YValuesPerPoint = 2;
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::Blue;
			series2->Legend = L"Legend1";
			series2->Name = L"Ca эксп";
			series3->BorderWidth = 2;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::Lime;
			series3->Legend = L"Legend1";
			series3->Name = L"Cc";
			series4->BorderWidth = 2;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			series4->Legend = L"Legend1";
			series4->Name = L"Cb";
			series5->BorderWidth = 2;
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series5->Color = System::Drawing::Color::Yellow;
			series5->Legend = L"Legend1";
			series5->Name = L"Cd";
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Series->Add(series3);
			this->chart->Series->Add(series4);
			this->chart->Series->Add(series5);
			this->chart->Size = System::Drawing::Size(983, 507);
			this->chart->TabIndex = 0;
			this->chart->Text = L"3A+ 2B";
			// 
			// button_make_calculations
			// 
			this->button_make_calculations->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_make_calculations->Location = System::Drawing::Point(466, 55);
			this->button_make_calculations->Name = L"button_make_calculations";
			this->button_make_calculations->Size = System::Drawing::Size(458, 67);
			this->button_make_calculations->TabIndex = 13;
			this->button_make_calculations->Text = L"Произвести расчёты";
			this->button_make_calculations->UseVisualStyleBackColor = true;
			this->button_make_calculations->Click += gcnew System::EventHandler(this, &MyForm::button_make_calculations_Click);
			// 
			// button_file_data
			// 
			this->button_file_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_file_data->Location = System::Drawing::Point(36, 525);
			this->button_file_data->Name = L"button_file_data";
			this->button_file_data->Size = System::Drawing::Size(369, 59);
			this->button_file_data->TabIndex = 12;
			this->button_file_data->Text = L"Загрузить данные из файла";
			this->button_file_data->UseVisualStyleBackColor = true;
			this->button_file_data->Click += gcnew System::EventHandler(this, &MyForm::button_file_data_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1455, 28);
			this->menuStrip1->TabIndex = 14;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menu_information,
					this->menu_tests
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(60, 24);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// menu_information
			// 
			this->menu_information->Name = L"menu_information";
			this->menu_information->Size = System::Drawing::Size(260, 26);
			this->menu_information->Text = L"Основная информация ";
			this->menu_information->Click += gcnew System::EventHandler(this, &MyForm::menu_information_Click);
			// 
			// menu_tests
			// 
			this->menu_tests->Name = L"menu_tests";
			this->menu_tests->Size = System::Drawing::Size(260, 26);
			this->menu_tests->Text = L"Провести тестирование";
			this->menu_tests->Click += gcnew System::EventHandler(this, &MyForm::menu_tests_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button_clear
			// 
			this->button_clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_clear->Location = System::Drawing::Point(36, 603);
			this->button_clear->Name = L"button_clear";
			this->button_clear->Size = System::Drawing::Size(369, 59);
			this->button_clear->TabIndex = 15;
			this->button_clear->Text = L"Очистить все поля";
			this->button_clear->UseVisualStyleBackColor = true;
			this->button_clear->Click += gcnew System::EventHandler(this, &MyForm::button_clear_Click);
			// 
			// button_save_data
			// 
			this->button_save_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_save_data->Location = System::Drawing::Point(967, 55);
			this->button_save_data->Name = L"button_save_data";
			this->button_save_data->Size = System::Drawing::Size(458, 67);
			this->button_save_data->TabIndex = 16;
			this->button_save_data->Text = L"Сохранить результаты";
			this->button_save_data->UseVisualStyleBackColor = true;
			this->button_save_data->Click += gcnew System::EventHandler(this, &MyForm::button_save_data_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1455, 689);
			this->Controls->Add(this->button_save_data);
			this->Controls->Add(this->button_clear);
			this->Controls->Add(this->button_make_calculations);
			this->Controls->Add(this->button_file_data);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Оценка кинетических констант методом рег. анализа";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_of_points))->EndInit();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//рассчётные переменные
	public: double k = 0, n = 0, d = 0, r = 0;
	private: double Cc = 0, Cb = 0, Cd = 0, Ca = 0;
	private: int reg_up = 0, reg_down = 0;

	//переменные для проверок
	private: const int lenght_strings = 2, not_a_table = 4;
	public: int count_of_points = 0;
	private: bool is_calculations = false;
	array<String^>^ mySplitString;

	private: System::Void button_clear_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_make_calculations_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void numeric_of_points_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void menu_information_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void menu_tests_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_file_data_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_save_data_Click(System::Object^ sender, System::EventArgs^ e);


	private: 
		bool check_user_input();
		void clear_fields();
};
}
