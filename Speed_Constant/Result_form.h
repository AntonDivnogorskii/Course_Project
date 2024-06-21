#pragma once

#include "MyForm.h"

namespace SpeedConstant {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Result_form
	/// </summary>
	public ref class Result_form : public System::Windows::Forms::Form
	{
	public:
		Result_form(const double k, const double n, const double d, const double r)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			textBox_reaction_order->Text = Convert::ToString(n);
			textBox_speed_constant->Text = Convert::ToString(k);
			textBox_variance->Text = Convert::ToString(d);
			textBox_correlation->Text = Convert::ToString(r);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Result_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBox_reaction_order;
	private: System::Windows::Forms::TextBox^ textBox_correlation;
	private: System::Windows::Forms::TextBox^ textBox_speed_constant;
	private: System::Windows::Forms::TextBox^ textBox_variance;
	private: System::Windows::Forms::Button^ button_OK;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_correlation = (gcnew System::Windows::Forms::TextBox());
			this->textBox_speed_constant = (gcnew System::Windows::Forms::TextBox());
			this->textBox_variance = (gcnew System::Windows::Forms::TextBox());
			this->textBox_reaction_order = (gcnew System::Windows::Forms::TextBox());
			this->button_OK = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(15, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(222, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Порядок реакции (N) =";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(15, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(254, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Константа скорости (K) = ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(15, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(132, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Дисперсия = ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(15, 175);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(143, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Корреляция = ";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox_correlation);
			this->groupBox1->Controls->Add(this->textBox_speed_constant);
			this->groupBox1->Controls->Add(this->textBox_variance);
			this->groupBox1->Controls->Add(this->textBox_reaction_order);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(442, 219);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Результаты";
			// 
			// textBox_correlation
			// 
			this->textBox_correlation->Location = System::Drawing::Point(323, 175);
			this->textBox_correlation->Name = L"textBox_correlation";
			this->textBox_correlation->ReadOnly = true;
			this->textBox_correlation->Size = System::Drawing::Size(100, 22);
			this->textBox_correlation->TabIndex = 7;
			// 
			// textBox_speed_constant
			// 
			this->textBox_speed_constant->Location = System::Drawing::Point(323, 90);
			this->textBox_speed_constant->Name = L"textBox_speed_constant";
			this->textBox_speed_constant->ReadOnly = true;
			this->textBox_speed_constant->Size = System::Drawing::Size(100, 22);
			this->textBox_speed_constant->TabIndex = 6;
			// 
			// textBox_variance
			// 
			this->textBox_variance->Location = System::Drawing::Point(323, 133);
			this->textBox_variance->Name = L"textBox_variance";
			this->textBox_variance->ReadOnly = true;
			this->textBox_variance->Size = System::Drawing::Size(100, 22);
			this->textBox_variance->TabIndex = 5;
			// 
			// textBox_reaction_order
			// 
			this->textBox_reaction_order->Location = System::Drawing::Point(323, 44);
			this->textBox_reaction_order->Name = L"textBox_reaction_order";
			this->textBox_reaction_order->ReadOnly = true;
			this->textBox_reaction_order->Size = System::Drawing::Size(100, 22);
			this->textBox_reaction_order->TabIndex = 4;
			// 
			// button_OK
			// 
			this->button_OK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_OK->Location = System::Drawing::Point(136, 244);
			this->button_OK->Name = L"button_OK";
			this->button_OK->Size = System::Drawing::Size(188, 60);
			this->button_OK->TabIndex = 5;
			this->button_OK->Text = L"Ok";
			this->button_OK->UseVisualStyleBackColor = true;
			this->button_OK->Click += gcnew System::EventHandler(this, &Result_form::button_OK_Click);
			// 
			// Result_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(469, 318);
			this->Controls->Add(this->button_OK);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Result_form";
			this->Text = L"Результаты расчётов";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button_OK_Click(System::Object^ sender, System::EventArgs^ e);
};
}
