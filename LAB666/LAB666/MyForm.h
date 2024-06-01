//MyForm.h
//графическая оболочка, заголовки функций
//Ельнова Екатерина, группа 3091, 1 курс
//29.05.24-31.05.24
#pragma once
#include "Stack.h"
namespace LAB666 {

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
	private: System::Windows::Forms::ListBox^ lstStack;
	private: System::Windows::Forms::Button^ btnPush;
	private: System::Windows::Forms::TextBox^ txtInput;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Button^ btnSort;



	protected:

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
			this->lstStack = (gcnew System::Windows::Forms::ListBox());
			this->btnPush = (gcnew System::Windows::Forms::Button());
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->btnSort = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lstStack
			// 
			this->lstStack->FormattingEnabled = true;
			this->lstStack->Location = System::Drawing::Point(12, 107);
			this->lstStack->Name = L"lstStack";
			this->lstStack->Size = System::Drawing::Size(447, 121);
			this->lstStack->TabIndex = 0;
			// 
			// btnPush
			// 
			this->btnPush->Location = System::Drawing::Point(303, 11);
			this->btnPush->Name = L"btnPush";
			this->btnPush->Size = System::Drawing::Size(75, 22);
			this->btnPush->TabIndex = 1;
			this->btnPush->Text = L"Добавить";
			this->btnPush->UseVisualStyleBackColor = true;
			this->btnPush->Click += gcnew System::EventHandler(this, &MyForm::btnPush_Click);
			// 
			// txtInput
			// 
			this->txtInput->Location = System::Drawing::Point(12, 12);
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(216, 20);
			this->txtInput->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(384, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 22);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Удалить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::btnPop_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 46);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 20);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Сумма";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(174, 47);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(156, 20);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Разность";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::btnSubtract_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 72);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(156, 20);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Умножение";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::btnMultiply_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(174, 72);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(156, 20);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Деление";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::btnDivide_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"int", L"double", L"char" });
			this->comboBox1->Location = System::Drawing::Point(235, 12);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(62, 21);
			this->comboBox1->TabIndex = 9;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->comboBox2->Location = System::Drawing::Point(336, 46);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(123, 21);
			this->comboBox2->TabIndex = 10;
			// 
			// btnSort
			// 
			this->btnSort->Location = System::Drawing::Point(336, 72);
			this->btnSort->Name = L"btnSort";
			this->btnSort->Size = System::Drawing::Size(123, 20);
			this->btnSort->TabIndex = 11;
			this->btnSort->Text = L"Сортировка";
			this->btnSort->UseVisualStyleBackColor = true;
			this->btnSort->Click += gcnew System::EventHandler(this, &MyForm::btnSort_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(471, 261);
			this->Controls->Add(this->btnSort);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txtInput);
			this->Controls->Add(this->btnPush);
			this->Controls->Add(this->lstStack);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(487, 300);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(487, 300);
			this->Name = L"MyForm";
			this->Text = L"Лабараторная работа 6";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//объявление функций нажатия на кнопку
	private: void LAB666::MyForm::btnPush_Click(System::Object^ sender, System::EventArgs^ e);
	private: void LAB666::MyForm::btnPop_Click(System::Object^ sender, System::EventArgs^ e);
	private: void LAB666::MyForm::btnAdd_Click(System::Object^ sender, System::EventArgs^ e);
	private: void LAB666::MyForm::btnSubtract_Click(System::Object^ sender, System::EventArgs^ e);
	private: void LAB666::MyForm::btnMultiply_Click(System::Object^ sender, System::EventArgs^ e);
	private: void LAB666::MyForm::btnDivide_Click(System::Object^ sender, System::EventArgs^ e);
	private: void LAB666::MyForm::btnSort_Click(System::Object^ sender, System::EventArgs^ e);
};
}
