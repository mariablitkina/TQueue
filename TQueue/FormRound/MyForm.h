#pragma once
#include "../TQueue/TQueue.h"
namespace FormRound {

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
		int MaxSize;
		int Size;
		double p;
		double q;
		int PopCount;
		int PushCount;
		int count;

		TQueue<int>* pQueue;
		int CenterX, CenterY, Width, Height;
		Graphics^ gr;
		Pen^ BlackPen;
		Pen^ WhitePen;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;

		   Random^ rnd1;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			gr = CreateGraphics();
			rnd1 = gcnew Random();

			BlackPen = gcnew Pen(Color::Pink);
			BlackPen->Width = 10.0F;
			WhitePen = gcnew Pen(SystemColors::Control);
			WhitePen->Width = 10.0F;

			CenterX = 150;
			CenterY = 200;
			Width = Height = 200;

			PopCount = PushCount = 0;
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

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
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(367, 114);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 41);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Нарисовать очередь";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(228, 23);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(89, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"100";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(228, 59);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(88, 22);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"20";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(230, 98);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(87, 22);
			this->textBox3->TabIndex = 3;
			this->textBox3->Text = L"0,6";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(228, 133);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(89, 22);
			this->textBox4->TabIndex = 4;
			this->textBox4->Text = L"0,4";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Максимальная длина очереди";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(175, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Исходная длина очереди";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 98);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(176, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Вероятность добавления";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 138);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(175, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Вероятность извлечения";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(93, 243);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(48, 22);
			this->textBox5->TabIndex = 9;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(93, 293);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(48, 22);
			this->textBox6->TabIndex = 10;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 243);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 17);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Добавили";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 293);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 17);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Взяли";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(708, 621);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		//Read parametrs
		MaxSize = Convert::ToInt32(textBox1->Text);
		Size = Convert::ToInt32(textBox2->Text);
		p = Convert::ToDouble(textBox3->Text);
		q = Convert::ToDouble(textBox4->Text);
		//Create Queue
		pQueue = new TQueue<int>(MaxSize);
		for (int i = 0; i < Size; i++)
		{
			pQueue->Push(i);
		};
		DrawQueue();
		timer1->Enabled = true;

	}
		   void DrawQueue()
		   {
			   int start = 360 * pQueue->GetHead() / pQueue->GetMaxSize();
			   int finish = 360 * (pQueue->GetSize()) / pQueue->GetMaxSize();
			   gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);

		   };
		   void Clean()
		   {
			   int start = 360 * pQueue->GetHead() / pQueue->GetMaxSize();
			   int finish = 360 * (pQueue->GetSize()) / pQueue->GetMaxSize();
			   gr->DrawArc(WhitePen, CenterX, CenterY, Width, Height, start, finish);
		   };
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Clean();
		if (rnd1->NextDouble() < p) {
			if (!pQueue->IsFull()) {
				pQueue->Push(1);
				PushCount++;
			}
		}
		if (rnd1->NextDouble() < q) {
			if (!pQueue->IsEmpty()) {
				pQueue->Pop();
				PopCount++;
			}
		}
		DrawQueue();
		textBox5->Text = Convert::ToString(PushCount);
		textBox6->Text = Convert::ToString(PopCount);
	};
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
