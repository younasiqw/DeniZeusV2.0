#pragma once
#include <Windows.h>
#include <fstream>
#include "json.h"

#pragma comment(lib, "User32.lib")

using json = nlohmann::json;
int aim_key = 0;

namespace DeniZeusLauncher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TabControl^ tabControl1;

	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::CheckBox^ checkBox1;






	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TrackBar^ trackBar4;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox6;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TrackBar^ trackBar3;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::CheckBox^ checkBox7;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::ColorDialog^ color_box;
	private: System::Windows::Forms::ColorDialog^ color_health;
	private: System::Windows::Forms::ColorDialog^ color_armor;
	private: System::Windows::Forms::CheckBox^ checkBox10;
	private: System::Windows::Forms::CheckBox^ checkBox9;
	private: System::Windows::Forms::CheckBox^ checkBox8;
	private: System::Windows::Forms::CheckBox^ checkBox12;
	private: System::Windows::Forms::CheckBox^ checkBox11;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::CheckBox^ checkBox13;
	private: System::Windows::Forms::CheckBox^ checkBox15;
	private: System::Windows::Forms::CheckBox^ checkBox14;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TrackBar^ trackBar5;
	private: System::Windows::Forms::ColorDialog^ color_ally_chams;
	private: System::Windows::Forms::ColorDialog^ color_enemy_chams;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::CheckBox^ checkBox18;
	private: System::Windows::Forms::CheckBox^ checkBox17;
	private: System::Windows::Forms::CheckBox^ checkBox16;
	private: System::Windows::Forms::CheckBox^ checkBox19;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TrackBar^ trackBar6;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::TextBox^ textBox7;
private: System::Windows::Forms::Label^ label19;









	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->checkBox12 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox11 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->checkBox15 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox14 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox13 = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->checkBox18 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox19 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->checkBox17 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->checkBox16 = (gcnew System::Windows::Forms::CheckBox());
			this->trackBar6 = (gcnew System::Windows::Forms::TrackBar());
			this->color_box = (gcnew System::Windows::Forms::ColorDialog());
			this->color_health = (gcnew System::Windows::Forms::ColorDialog());
			this->color_armor = (gcnew System::Windows::Forms::ColorDialog());
			this->color_ally_chams = (gcnew System::Windows::Forms::ColorDialog());
			this->color_enemy_chams = (gcnew System::Windows::Forms::ColorDialog());
			this->panel1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->BeginInit();
			this->tabPage5->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 251);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(249, 29);
			this->panel1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(249, 29);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::Button1_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(249, 251);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->trackBar4);
			this->tabPage1->Controls->Add(this->checkBox3);
			this->tabPage1->Controls->Add(this->checkBox2);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->radioButton2);
			this->tabPage1->Controls->Add(this->radioButton1);
			this->tabPage1->Controls->Add(this->checkBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(241, 225);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Glow";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(138, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 78);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Static mode using\r\nin-game function for\r\nglowing. This using\r\nvery low CPU but\r\nc"
				L"olors can not\r\nchangable.\r\n";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 132);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Alpha : 0";
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(9, 103);
			this->trackBar4->Maximum = 100;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(89, 42);
			this->trackBar4->TabIndex = 13;
			this->trackBar4->TickFrequency = 10;
			this->trackBar4->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar4->ValueChanged += gcnew System::EventHandler(this, &MainForm::TrackBar4_ValueChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(146, 80);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(84, 17);
			this->checkBox3->TabIndex = 12;
			this->checkBox3->Text = L"Glow enemy";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(11, 80);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(68, 17);
			this->checkBox2->TabIndex = 11;
			this->checkBox2->Text = L"Glow ally";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(143, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Static color based";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Health based";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(146, 39);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(81, 17);
			this->radioButton2->TabIndex = 2;
			this->radioButton2->Text = L"Static mode";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(9, 39);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(95, 17);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Dynamic mode";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(9, 6);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(65, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Enabled";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckBox1_CheckedChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->comboBox2);
			this->tabPage2->Controls->Add(this->textBox4);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->trackBar3);
			this->tabPage2->Controls->Add(this->textBox3);
			this->tabPage2->Controls->Add(this->label7);
			this->tabPage2->Controls->Add(this->trackBar2);
			this->tabPage2->Controls->Add(this->textBox2);
			this->tabPage2->Controls->Add(this->label5);
			this->tabPage2->Controls->Add(this->trackBar1);
			this->tabPage2->Controls->Add(this->checkBox6);
			this->tabPage2->Controls->Add(this->checkBox5);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->comboBox1);
			this->tabPage2->Controls->Add(this->textBox1);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->checkBox4);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(241, 225);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Aimbot";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(73, 8);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(56, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Aim mode:";
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Always", L"When key pressed", L"When fire", L"Key pressed or fire" });
			this->comboBox2->Location = System::Drawing::Point(135, 5);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(97, 21);
			this->comboBox2->TabIndex = 15;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ComboBox2_SelectedIndexChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(190, 197);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(43, 20);
			this->textBox4->TabIndex = 14;
			this->textBox4->Text = L"1,0";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MainForm::TextBox4_TextChanged);
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::TextBox4_KeyPress);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(111, 200);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(79, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Recoil percent:";
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(114, 171);
			this->trackBar3->Maximum = 1000;
			this->trackBar3->Minimum = 10;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(118, 42);
			this->trackBar3->TabIndex = 12;
			this->trackBar3->TickFrequency = 5;
			this->trackBar3->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar3->Value = 10;
			this->trackBar3->ValueChanged += gcnew System::EventHandler(this, &MainForm::TrackBar3_ValueChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(45, 197);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(62, 20);
			this->textBox3->TabIndex = 11;
			this->textBox3->Text = L"1";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MainForm::TextBox3_TextChanged);
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::TextBox3_KeyPress);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(8, 200);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(31, 13);
			this->label7->TabIndex = 10;
			this->label7->Text = L"FOV:";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(8, 171);
			this->trackBar2->Maximum = 360;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(100, 42);
			this->trackBar2->TabIndex = 9;
			this->trackBar2->TickFrequency = 5;
			this->trackBar2->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar2->ValueChanged += gcnew System::EventHandler(this, &MainForm::TrackBar2_ValueChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(117, 145);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(76, 20);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"1,0";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MainForm::TextBox2_TextChanged);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::TextBox2_KeyPress);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(8, 148);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(71, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Smoothness :";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(8, 119);
			this->trackBar1->Maximum = 2000;
			this->trackBar1->Minimum = 10;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(225, 42);
			this->trackBar1->TabIndex = 1;
			this->trackBar1->TickFrequency = 5;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar1->Value = 10;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &MainForm::TrackBar1_ValueChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(114, 96);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(97, 17);
			this->checkBox6->TabIndex = 6;
			this->checkBox6->Text = L"Aim when jump";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(8, 96);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(79, 17);
			this->checkBox5->TabIndex = 5;
			this->checkBox5->Text = L"Friendly fire";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 61);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(80, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Aiming bone  :  ";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Pelvis", L"Stomatch", L"Chest", L"Spine", L"Neck",
					L"Head"
			});
			this->comboBox1->Location = System::Drawing::Point(114, 58);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(119, 21);
			this->comboBox1->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(8, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"None";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::Control;
			this->button2->Location = System::Drawing::Point(114, 29);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(119, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Set aim key";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::Button2_Click);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(8, 6);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(65, 17);
			this->checkBox4->TabIndex = 0;
			this->checkBox4->Text = L"Enabled";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->checkBox12);
			this->tabPage3->Controls->Add(this->checkBox11);
			this->tabPage3->Controls->Add(this->checkBox10);
			this->tabPage3->Controls->Add(this->checkBox9);
			this->tabPage3->Controls->Add(this->checkBox8);
			this->tabPage3->Controls->Add(this->label12);
			this->tabPage3->Controls->Add(this->panel4);
			this->tabPage3->Controls->Add(this->label11);
			this->tabPage3->Controls->Add(this->panel3);
			this->tabPage3->Controls->Add(this->label10);
			this->tabPage3->Controls->Add(this->panel2);
			this->tabPage3->Controls->Add(this->checkBox7);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(241, 225);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"ESP";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// checkBox12
			// 
			this->checkBox12->AutoSize = true;
			this->checkBox12->Location = System::Drawing::Point(114, 111);
			this->checkBox12->Name = L"checkBox12";
			this->checkBox12->Size = System::Drawing::Size(81, 17);
			this->checkBox12->TabIndex = 12;
			this->checkBox12->Text = L"ESP enemy";
			this->checkBox12->UseVisualStyleBackColor = true;
			// 
			// checkBox11
			// 
			this->checkBox11->AutoSize = true;
			this->checkBox11->Location = System::Drawing::Point(8, 111);
			this->checkBox11->Name = L"checkBox11";
			this->checkBox11->Size = System::Drawing::Size(65, 17);
			this->checkBox11->TabIndex = 11;
			this->checkBox11->Text = L"ESP ally";
			this->checkBox11->UseVisualStyleBackColor = true;
			// 
			// checkBox10
			// 
			this->checkBox10->AutoSize = true;
			this->checkBox10->Location = System::Drawing::Point(114, 81);
			this->checkBox10->Name = L"checkBox10";
			this->checkBox10->Size = System::Drawing::Size(77, 17);
			this->checkBox10->TabIndex = 10;
			this->checkBox10->Text = L"Armor ESP";
			this->checkBox10->UseVisualStyleBackColor = true;
			// 
			// checkBox9
			// 
			this->checkBox9->AutoSize = true;
			this->checkBox9->Location = System::Drawing::Point(114, 57);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(81, 17);
			this->checkBox9->TabIndex = 9;
			this->checkBox9->Text = L"Health ESP";
			this->checkBox9->UseVisualStyleBackColor = true;
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Location = System::Drawing::Point(114, 32);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(118, 17);
			this->checkBox8->TabIndex = 8;
			this->checkBox8->Text = L"Esp name and rank";
			this->checkBox8->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(32, 81);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(60, 13);
			this->label12->TabIndex = 7;
			this->label12->Text = L"Armor color";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Black;
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Location = System::Drawing::Point(8, 78);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(17, 17);
			this->panel4->TabIndex = 6;
			this->panel4->Click += gcnew System::EventHandler(this, &MainForm::Panel4_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(32, 57);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(64, 13);
			this->label11->TabIndex = 5;
			this->label11->Text = L"Health color";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Black;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Location = System::Drawing::Point(8, 54);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(17, 17);
			this->panel3->TabIndex = 4;
			this->panel3->Click += gcnew System::EventHandler(this, &MainForm::Panel3_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(32, 32);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(51, 13);
			this->label10->TabIndex = 3;
			this->label10->Text = L"Box color";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Black;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->panel2->Location = System::Drawing::Point(8, 29);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(17, 17);
			this->panel2->TabIndex = 2;
			this->panel2->Click += gcnew System::EventHandler(this, &MainForm::Panel2_Click);
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(8, 6);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(65, 17);
			this->checkBox7->TabIndex = 0;
			this->checkBox7->Text = L"Enabled";
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->textBox5);
			this->tabPage4->Controls->Add(this->label15);
			this->tabPage4->Controls->Add(this->trackBar5);
			this->tabPage4->Controls->Add(this->label14);
			this->tabPage4->Controls->Add(this->label13);
			this->tabPage4->Controls->Add(this->panel6);
			this->tabPage4->Controls->Add(this->panel5);
			this->tabPage4->Controls->Add(this->checkBox15);
			this->tabPage4->Controls->Add(this->checkBox14);
			this->tabPage4->Controls->Add(this->checkBox13);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(241, 225);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Chams";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(112, 100);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(121, 20);
			this->textBox5->TabIndex = 17;
			this->textBox5->Text = L"1,0";
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MainForm::TextBox5_TextChanged);
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::TextBox5_KeyPress);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(12, 103);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(93, 13);
			this->label15->TabIndex = 16;
			this->label15->Text = L"Chams brightness:";
			// 
			// trackBar5
			// 
			this->trackBar5->Location = System::Drawing::Point(8, 75);
			this->trackBar5->Maximum = 1000;
			this->trackBar5->Minimum = 10;
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->Size = System::Drawing::Size(225, 42);
			this->trackBar5->TabIndex = 15;
			this->trackBar5->TickFrequency = 5;
			this->trackBar5->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar5->Value = 10;
			this->trackBar5->ValueChanged += gcnew System::EventHandler(this, &MainForm::TrackBar5_ValueChanged);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(135, 55);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(65, 13);
			this->label14->TabIndex = 5;
			this->label14->Text = L"Enemy color";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(32, 55);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(49, 13);
			this->label13->TabIndex = 4;
			this->label13->Text = L"Ally color";
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::Black;
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->ForeColor = System::Drawing::SystemColors::ControlText;
			this->panel6->Location = System::Drawing::Point(112, 52);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(17, 17);
			this->panel6->TabIndex = 3;
			this->panel6->Click += gcnew System::EventHandler(this, &MainForm::Panel6_Click);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Black;
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->panel5->Location = System::Drawing::Point(8, 52);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(17, 17);
			this->panel5->TabIndex = 3;
			this->panel5->Click += gcnew System::EventHandler(this, &MainForm::Panel5_Click);
			// 
			// checkBox15
			// 
			this->checkBox15->AutoSize = true;
			this->checkBox15->Location = System::Drawing::Point(112, 29);
			this->checkBox15->Name = L"checkBox15";
			this->checkBox15->Size = System::Drawing::Size(92, 17);
			this->checkBox15->TabIndex = 2;
			this->checkBox15->Text = L"Chams enemy";
			this->checkBox15->UseVisualStyleBackColor = true;
			// 
			// checkBox14
			// 
			this->checkBox14->AutoSize = true;
			this->checkBox14->Location = System::Drawing::Point(8, 29);
			this->checkBox14->Name = L"checkBox14";
			this->checkBox14->Size = System::Drawing::Size(76, 17);
			this->checkBox14->TabIndex = 1;
			this->checkBox14->Text = L"Chams ally";
			this->checkBox14->UseVisualStyleBackColor = true;
			// 
			// checkBox13
			// 
			this->checkBox13->AutoSize = true;
			this->checkBox13->Location = System::Drawing::Point(8, 6);
			this->checkBox13->Name = L"checkBox13";
			this->checkBox13->Size = System::Drawing::Size(65, 17);
			this->checkBox13->TabIndex = 0;
			this->checkBox13->Text = L"Enabled";
			this->checkBox13->UseVisualStyleBackColor = true;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->groupBox3);
			this->tabPage5->Controls->Add(this->groupBox2);
			this->tabPage5->Controls->Add(this->groupBox1);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(241, 225);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Misc";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox7);
			this->groupBox3->Controls->Add(this->label19);
			this->groupBox3->Controls->Add(this->checkBox18);
			this->groupBox3->Location = System::Drawing::Point(6, 157);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(227, 63);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Flash Alpha";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(112, 37);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(88, 20);
			this->textBox7->TabIndex = 7;
			this->textBox7->Text = L"1";
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &MainForm::TextBox7_TextChanged);
			this->textBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::TextBox7_KeyPress);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(6, 40);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(90, 13);
			this->label19->TabIndex = 6;
			this->label19->Text = L"Reduce percent: ";
			// 
			// checkBox18
			// 
			this->checkBox18->AutoSize = true;
			this->checkBox18->Location = System::Drawing::Point(6, 19);
			this->checkBox18->Name = L"checkBox18";
			this->checkBox18->Size = System::Drawing::Size(65, 17);
			this->checkBox18->TabIndex = 2;
			this->checkBox18->Text = L"Enabled";
			this->checkBox18->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBox19);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->label16);
			this->groupBox2->Controls->Add(this->checkBox17);
			this->groupBox2->Location = System::Drawing::Point(6, 85);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(227, 66);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"BHop";
			// 
			// checkBox19
			// 
			this->checkBox19->AutoSize = true;
			this->checkBox19->Location = System::Drawing::Point(112, 17);
			this->checkBox19->Name = L"checkBox19";
			this->checkBox19->Size = System::Drawing::Size(88, 17);
			this->checkBox19->TabIndex = 6;
			this->checkBox19->Text = L"Humanizated";
			this->checkBox19->UseVisualStyleBackColor = true;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(112, 40);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(88, 20);
			this->textBox6->TabIndex = 5;
			this->textBox6->Text = L"1";
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MainForm::TextBox6_TextChanged);
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::TextBox6_KeyPress);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(6, 43);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(101, 13);
			this->label16->TabIndex = 4;
			this->label16->Text = L"Hit chance percent:";
			// 
			// checkBox17
			// 
			this->checkBox17->AutoSize = true;
			this->checkBox17->Location = System::Drawing::Point(6, 19);
			this->checkBox17->Name = L"checkBox17";
			this->checkBox17->Size = System::Drawing::Size(65, 17);
			this->checkBox17->TabIndex = 1;
			this->checkBox17->Text = L"Enabled";
			this->checkBox17->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label18);
			this->groupBox1->Controls->Add(this->label17);
			this->groupBox1->Controls->Add(this->checkBox16);
			this->groupBox1->Controls->Add(this->trackBar6);
			this->groupBox1->Location = System::Drawing::Point(6, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(227, 73);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Night mode";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(77, 50);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(88, 13);
			this->label18->TabIndex = 18;
			this->label18->Text = L"Best value is 0.3!";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(7, 27);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(64, 13);
			this->label17->TabIndex = 17;
			this->label17->Text = L"Factor: 0.01";
			// 
			// checkBox16
			// 
			this->checkBox16->AutoSize = true;
			this->checkBox16->Location = System::Drawing::Point(6, 50);
			this->checkBox16->Name = L"checkBox16";
			this->checkBox16->Size = System::Drawing::Size(65, 17);
			this->checkBox16->TabIndex = 0;
			this->checkBox16->Text = L"Enabled";
			this->checkBox16->UseVisualStyleBackColor = true;
			// 
			// trackBar6
			// 
			this->trackBar6->Location = System::Drawing::Point(80, 19);
			this->trackBar6->Maximum = 100;
			this->trackBar6->Minimum = 1;
			this->trackBar6->Name = L"trackBar6";
			this->trackBar6->Size = System::Drawing::Size(141, 42);
			this->trackBar6->TabIndex = 16;
			this->trackBar6->TickFrequency = 5;
			this->trackBar6->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar6->Value = 1;
			this->trackBar6->ValueChanged += gcnew System::EventHandler(this, &MainForm::TrackBar6_ValueChanged);
			// 
			// color_box
			// 
			this->color_box->AnyColor = true;
			this->color_box->FullOpen = true;
			this->color_box->SolidColorOnly = true;
			// 
			// color_health
			// 
			this->color_health->AnyColor = true;
			this->color_health->FullOpen = true;
			this->color_health->SolidColorOnly = true;
			// 
			// color_armor
			// 
			this->color_armor->AnyColor = true;
			this->color_armor->FullOpen = true;
			this->color_armor->SolidColorOnly = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(249, 280);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MainForm";
			this->Text = L"DeniZeus Launcher";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->EndInit();
			this->tabPage5->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

public: void update_values() {
	label6->Text = "Alpha : " + trackBar4->Value / 100.f;
	label17->Text = "Factor:" + (trackBar6->Value / 100.f);
	textBox2->Text = Convert::ToString(trackBar1->Value / 10.f);
	textBox3->Text = Convert::ToString(trackBar2->Value);
	textBox4->Text = Convert::ToString(trackBar3->Value / 10.f);
	textBox5->Text = Convert::ToString(trackBar5->Value / 10.f);
	panel2->BackColor = color_box->Color;
	panel3->BackColor = color_health->Color;
	panel4->BackColor = color_armor->Color;
	panel5->BackColor = color_ally_chams->Color;
	panel6->BackColor = color_enemy_chams->Color;
}

public: int bonecombo_to_bone(int i) {
	switch (i)
	{
	case 0:
		return 0;
	case 1:
		return 3;
	case 2:
		return 5;
	case 3:
		return 6;
	case 4:
		return 7;
	case 5:
		return 8;
	}
}

public: int bone_to_bonecombo(int i) {
		switch (i)
		{
		case 0:
			return 0;
		case 3:
			return 1;
		case 5:
			return 2;
		case 6:
			return 3;
		case 7:
			return 4;
		case 8:
			return 5;

		default:
			return 5;
		}
	}


private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	json saveconfig;

	saveconfig["glow"]["glow_enabled"] = (bool)checkBox1->Checked;
	saveconfig["glow"]["glow_static"] = (bool)radioButton2->Checked;
	saveconfig["glow"]["glow_ally"] = (bool)checkBox2->Checked;
	saveconfig["glow"]["glow_enemy"] = (bool)checkBox3->Checked;
	saveconfig["glow"]["glow_dynamic_alpha"] = (float)(trackBar4->Value / 100.f);

	saveconfig["aimbot"]["aimbot_bone"] = (int)bonecombo_to_bone(comboBox1->SelectedIndex);
	saveconfig["aimbot"]["aimbot_key"] = aim_key;
	saveconfig["aimbot"]["aimbot_type"] = (int)comboBox2->SelectedIndex;
	saveconfig["aimbot"]["aimbot_enabled"] = (bool)checkBox4->Checked;
	saveconfig["aimbot"]["aimbot_friendly_fire"] = (bool)checkBox5->Checked;
	saveconfig["aimbot"]["aimbot_when_jump"] = (bool)checkBox6->Checked;
	saveconfig["aimbot"]["aimbot_smoothness"] = (float)(trackBar1->Value / 10.f);
	saveconfig["aimbot"]["aimbot_fov"] = (float)(trackBar2->Value);
	saveconfig["aimbot"]["recoil_percent"] = (float)(trackBar3->Value / 10.f);

	saveconfig["esp"]["esp_enabled"] = (bool)checkBox7->Checked;
	saveconfig["esp"]["esp_name_and_rank"] = (bool)checkBox8->Checked;
	saveconfig["esp"]["esp_health"] = (bool)checkBox9->Checked;
	saveconfig["esp"]["esp_armor"] = (bool)checkBox10->Checked;
	saveconfig["esp"]["esp_ally"] = (bool)checkBox11->Checked;
	saveconfig["esp"]["esp_enemy"] = (bool)checkBox12->Checked;
	saveconfig["esp"]["esp_box_color"]["r"] = color_box->Color.R;
	saveconfig["esp"]["esp_box_color"]["g"] = color_box->Color.G;
	saveconfig["esp"]["esp_box_color"]["b"] = color_box->Color.B;
	saveconfig["esp"]["esp_health_color"]["r"] = color_health->Color.R;
	saveconfig["esp"]["esp_health_color"]["g"] = color_health->Color.G;
	saveconfig["esp"]["esp_health_color"]["b"] = color_health->Color.B;
	saveconfig["esp"]["esp_armor_color"]["r"] = color_armor->Color.R;
	saveconfig["esp"]["esp_armor_color"]["g"] = color_armor->Color.G;
	saveconfig["esp"]["esp_armor_color"]["b"] = color_armor->Color.B;

	saveconfig["chams"]["chams_enabled"] = (bool)checkBox13->Checked;
	saveconfig["chams"]["chams_ally"] = (bool)checkBox14->Checked;
	saveconfig["chams"]["chams_enemy"] = (bool)checkBox15->Checked;
	saveconfig["chams"]["chams_ally_color"]["r"] = color_ally_chams->Color.R;
	saveconfig["chams"]["chams_ally_color"]["g"] = color_ally_chams->Color.G;
	saveconfig["chams"]["chams_ally_color"]["b"] = color_ally_chams->Color.B;
	saveconfig["chams"]["chams_enemy_color"]["r"] = color_enemy_chams->Color.R;
	saveconfig["chams"]["chams_enemy_color"]["g"] = color_enemy_chams->Color.G;
	saveconfig["chams"]["chams_enemy_color"]["b"] = color_enemy_chams->Color.B;
	saveconfig["chams"]["chams_brightness"] = (float)(trackBar5->Value / 10.f);

	saveconfig["bhop"]["bhop_enabled"] = (bool)checkBox17->Checked;
	saveconfig["bhop"]["bhop_humanization"] = (bool)checkBox19->Checked;
	saveconfig["bhop"]["bhop_hit_chance"] = (float)Convert::ToInt32(textBox6->Text);

	saveconfig["night_mode"]["night_mode_enabled"] = (bool)checkBox16->Checked;
	saveconfig["night_mode"]["night_mode_tone"] = (float)trackBar6->Value / 100.f;

	saveconfig["flash_reducer"]["flash_reducer_enabled"] = (bool)checkBox18->Checked;
	saveconfig["flash_reducer"]["flash_reducer_percent"] = (float)Convert::ToUInt32(textBox7->Text);




	std::ofstream file("config.dcf");

	file << saveconfig;

	System::Diagnostics::Process::Start("DeniZeus2.0.exe");

	Application::Exit();
}

private: System::Void CheckBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

}

private: System::Void TrackBar4_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	label6->Text = "Alpha : " + trackBar4->Value / 100.f;
}
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	comboBox2->SelectedIndex = 0;
	comboBox1->SelectedIndex = 0;
	std::ifstream cfile("config.dcf");
	
	try
	{
		json loadconfig = json::parse(cfile);
		//Glow ended
		checkBox1->Checked = loadconfig["glow"]["glow_enabled"].get<bool>();
		radioButton2->Checked = loadconfig["glow"]["glow_static"].get<bool>();
		checkBox2->Checked = loadconfig["glow"]["glow_ally"].get<bool>();
		checkBox3->Checked = loadconfig["glow"]["glow_enemy"].get<bool>();
		trackBar4->Value = loadconfig["glow"]["glow_dynamic_alpha"].get<float>() * 100.f;

		comboBox1->SelectedIndex = bone_to_bonecombo(loadconfig["aimbot"]["aimbot_bone"].get<int>());

		int loadkey = loadconfig["aimbot"]["aimbot_key"].get<int>();
		char name[1024];
		UINT scanCode = MapVirtualKeyA(loadkey, MAPVK_VK_TO_VSC);
		LONG lParamValue = (scanCode << 16);
		switch (loadkey)
		{
		case 1:
			memcpy_s(name, sizeof(name), "Left mouse button", sizeof("Left mouse button"));
			break;
		case 2:
			memcpy_s(name, sizeof(name), "Right mouse button", sizeof("Right mouse button"));
			break;
		case 4:
			memcpy_s(name, sizeof(name), "Middle mouse button", sizeof("Middle mouse button"));
			break;
		case 5:
			memcpy_s(name, sizeof(name), "X1 mouse button", sizeof("X1 mouse button"));
			break;
		case 6:
			memcpy_s(name, sizeof(name), "X2 mouse button", sizeof("X2 mouse button"));
			break;

		default:
			GetKeyNameTextA(lParamValue, name, 1024);
		}
		aim_key = loadkey;
		textBox1->Text = gcnew String(name);

		comboBox2->SelectedIndex = loadconfig["aimbot"]["aimbot_type"].get<int>();
		checkBox4->Checked = loadconfig["aimbot"]["aimbot_enabled"].get<bool>();
		checkBox5->Checked = loadconfig["aimbot"]["aimbot_friendly_fire"].get<bool>();
		checkBox6->Checked = loadconfig["aimbot"]["aimbot_when_jump"].get<bool>();
		if (Convert::ToInt32(loadconfig["aimbot"]["aimbot_smoothness"].get<float>() * 10.f) > trackBar1->Maximum && Convert::ToInt32(loadconfig["aimbot"]["aimbot_smoothness"].get<float>() * 10.f) < 10000 && Convert::ToInt32(loadconfig["aimbot"]["aimbot_smoothness"].get<float>() * 10.f) >= 0) {
			trackBar1->Maximum = Convert::ToInt32(loadconfig["aimbot"]["aimbot_smoothness"].get<float>() * 10.f);
		}
		if (Convert::ToInt32(loadconfig["aimbot"]["aimbot_smoothness"].get<float>() * 10.f) < 10000 && Convert::ToInt32(loadconfig["aimbot"]["aimbot_smoothness"].get<float>() * 10.f) >= 0) {
			trackBar1->Value = Convert::ToInt32(loadconfig["aimbot"]["aimbot_smoothness"].get<float>() * 10.f);
		}
		trackBar2->Value = Convert::ToInt32(loadconfig["aimbot"]["aimbot_fov"].get<float>());
		trackBar3->Value = Convert::ToInt32(loadconfig["aimbot"]["recoil_percent"].get<float>() * 10.f);

		checkBox7->Checked = loadconfig["esp"]["esp_enabled"].get<bool>();
		checkBox8->Checked = loadconfig["esp"]["esp_name_and_rank"].get<bool>();
		checkBox9->Checked = loadconfig["esp"]["esp_health"].get<bool>();
		checkBox10->Checked = loadconfig["esp"]["esp_armor"].get<bool>();
		checkBox11->Checked = loadconfig["esp"]["esp_ally"].get<bool>();
		checkBox12->Checked = loadconfig["esp"]["esp_enemy"].get<bool>();
		color_box->Color = Color::FromArgb(loadconfig["esp"]["esp_box_color"]["r"].get<int>(), loadconfig["esp"]["esp_box_color"]["g"].get<int>(), loadconfig["esp"]["esp_box_color"]["b"].get<int>());
		color_health->Color = Color::FromArgb(loadconfig["esp"]["esp_health_color"]["r"].get<int>(), loadconfig["esp"]["esp_health_color"]["g"].get<int>(), loadconfig["esp"]["esp_health_color"]["b"].get<int>());
		color_armor->Color = Color::FromArgb(loadconfig["esp"]["esp_armor_color"]["r"].get<int>(), loadconfig["esp"]["esp_armor_color"]["g"].get<int>(), loadconfig["esp"]["esp_armor_color"]["b"].get<int>());
		
		checkBox13->Checked = loadconfig["chams"]["chams_enabled"].get<bool>();
		checkBox14->Checked = loadconfig["chams"]["chams_ally"].get<bool>();
		checkBox15->Checked = loadconfig["chams"]["chams_enemy"].get<bool>();
		color_ally_chams->Color = Color::FromArgb(loadconfig["chams"]["chams_ally_color"]["r"].get<int>(), loadconfig["chams"]["chams_ally_color"]["g"].get<int>(), loadconfig["chams"]["chams_ally_color"]["b"].get<int>());
		color_enemy_chams->Color = Color::FromArgb(loadconfig["chams"]["chams_enemy_color"]["r"].get<int>(), loadconfig["chams"]["chams_enemy_color"]["g"].get<int>(), loadconfig["chams"]["chams_enemy_color"]["b"].get<int>());
		trackBar5->Value = Convert::ToInt32(loadconfig["chams"]["chams_brightness"].get<float>() * 10.f);

		checkBox17->Checked = loadconfig["bhop"]["bhop_enabled"].get<bool>();
		checkBox19->Checked = loadconfig["bhop"]["bhop_humanization"].get<bool>();
		textBox6->Text = Convert::ToInt32(loadconfig["bhop"]["bhop_hit_chance"].get<float>()).ToString();

		checkBox16->Checked = loadconfig["night_mode"]["night_mode_enabled"].get<bool>();
		trackBar6->Value = Convert::ToInt32(loadconfig["night_mode"]["night_mode_tone"].get<float>() * 100.f);
		
		checkBox18->Checked = loadconfig["flash_reducer"]["flash_reducer_enabled"].get<bool>();
		textBox7->Text = Convert::ToInt32(loadconfig["flash_reducer"]["flash_reducer_percent"].get<float>()).ToString();

	} catch (const std::exception&){}

	update_values();
}
private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
	button2->Text = "WAITING KEY";
	button2->BackColor = Color::Red;
	button2->Refresh();
	int key = -1;
	while (key == -1)
	{
		for (size_t i = 0; i <= 254; i++)
		{
			if (GetAsyncKeyState(i) & 0x8000) {
				key = i;
			}
		}
	}

	char name[1024];
	UINT scanCode = MapVirtualKeyA(key, MAPVK_VK_TO_VSC);
	LONG lParamValue = (scanCode << 16);




	switch (key)
	{
	case 1:
		memcpy_s(name, sizeof(name), "Left mouse button", sizeof("Left mouse button"));
		break;
	case 2:
		memcpy_s(name, sizeof(name), "Right mouse button", sizeof("Right mouse button"));
		break;
	case 4:
		memcpy_s(name, sizeof(name), "Middle mouse button", sizeof("Middle mouse button"));
		break;
	case 5:
		memcpy_s(name, sizeof(name), "X1 mouse button", sizeof("X1 mouse button"));
		break;
	case 6:
		memcpy_s(name, sizeof(name), "X2 mouse button", sizeof("X2 mouse button"));
		break;

	default:
		GetKeyNameTextA(lParamValue, name, 1024);
	}

	aim_key = key;

	textBox1->Text = gcnew String(name);

	button2->Text = "Set aim key";
	button2->BackColor = SystemColors::Control;
}
private: System::Void TextBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == VK_RETURN) {
		try
		{
		if (Convert::ToInt32(Convert::ToDouble(textBox2->Text) * 10.f) > trackBar1->Maximum && Convert::ToInt32(Convert::ToDouble(textBox2->Text) * 10.f) < 10000 && Convert::ToInt32(Convert::ToDouble(textBox2->Text) * 10.f) >= 0) {
			trackBar1->Maximum = Convert::ToInt32(Convert::ToDouble(textBox2->Text) * 10.f);
		}

		if (Convert::ToInt32(Convert::ToDouble(textBox2->Text) * 10.f) < 10000 && Convert::ToInt32(Convert::ToDouble(textBox2->Text) * 10.f) >= 0) {
			trackBar1->Value = Convert::ToInt32(Convert::ToDouble(textBox2->Text) * 10.f);
		}
		else {
			if (Convert::ToInt32(Convert::ToDouble(textBox2->Text) * 10.f) < 0) {
				MessageBox::Show("Value must bigger than 0!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else {
				trackBar1->Maximum = 10000;
				trackBar1->Value = 10000;
				textBox2->Text = Convert::ToString(1000.f);
			}
		}

		}
		catch (const std::exception&)
		{
			MessageBox::Show("Invalid value", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
private: System::Void TrackBar1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox2->Text = Convert::ToString(trackBar1->Value / 10.f);
}
private: System::Void TextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox2->Text->Contains(".")) {
		textBox2->Text = textBox2->Text->Replace(".", ",");
		textBox2->SelectionStart = textBox2->Text->Length;
		textBox2->SelectionLength = 0;
	}
}
private: System::Void TrackBar2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox3->Text = Convert::ToString(trackBar2->Value);
}
private: System::Void TextBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == VK_RETURN) {
		try
		{
			if (Convert::ToInt16(textBox3->Text) <= 360 && Convert::ToInt16(textBox3->Text) > 0) {
				trackBar2->Value = Convert::ToInt16(textBox3->Text);
			}
			else {
				MessageBox::Show("Value must lower than 360 and bigger than 0!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (const std::exception&)
		{
				
		}
	}
}
private: System::Void TrackBar3_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox4->Text = Convert::ToString(trackBar3->Value / 10.f);
}
private: System::Void TextBox4_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == VK_RETURN) {
		try
		{
			if (Convert::ToInt32(Convert::ToDouble(textBox4->Text) * 10.f) <= 1000 && Convert::ToInt32(Convert::ToDouble(textBox4->Text) * 10.f) >= 0) {
				trackBar3->Value = Convert::ToInt32(Convert::ToDouble(textBox4->Text) * 10.f);
			}
			else {
				MessageBox::Show("Value must lower than 100 and bigger than 0!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (const std::exception&)
		{

		}
	}
}
private: System::Void TextBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox4->Text->Contains(".")) {
		textBox4->Text = textBox4->Text->Replace(".", ",");
		textBox4->SelectionStart = textBox4->Text->Length;
		textBox4->SelectionLength = 0;
	}
}
private: System::Void TextBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox3->Text->Contains(".") || textBox3->Text->Contains(",")) {
		textBox3->Text = textBox3->Text->Replace(".", "");
		textBox3->Text = textBox3->Text->Replace(",", "");
		textBox3->SelectionStart = textBox3->Text->Length;
		textBox3->SelectionLength = 0;
	}
}
private: System::Void ComboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		switch (comboBox2->SelectedIndex)
		{
		case 0:
			textBox1 -> Visible = false;
			button2->Visible = false;
			break;
		case 1:
			textBox1->Visible = true;
			button2->Visible = true;
			break;
		case 2:
			textBox1->Visible = false;
			button2->Visible = false;
			break;
		case 3:
			textBox1->Visible = true;
			button2->Visible = true;
			break;
		}
}
private: System::Void Panel3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (color_health->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		panel3->BackColor = color_health->Color;
	}
}
private: System::Void Panel2_Click(System::Object^ sender, System::EventArgs^ e) {
	if(color_box->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		panel2->BackColor = color_box->Color;
	}
}
private: System::Void Panel4_Click(System::Object^ sender, System::EventArgs^ e) {
	if(color_armor->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		panel4->BackColor = color_armor->Color;
	}
}
private: System::Void TrackBar5_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox5->Text = Convert::ToString(trackBar5->Value / 10.f);
}
private: System::Void TextBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox5->Text->Contains(".")) {
		textBox5->Text = textBox5->Text->Replace(".", ",");
		textBox5->SelectionStart = textBox5->Text->Length;
		textBox5->SelectionLength = 0;
	}
}
private: System::Void CheckBox19_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void TextBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox6->Text->Contains(".")) {
		textBox6->Text = textBox6->Text->Replace(".", ",");
		textBox6->SelectionStart = textBox6->Text->Length;
		textBox6->SelectionLength = 0;
	}
	if (textBox6->Text->Length > 3) {
		textBox6->Text = textBox6->Text->Substring(0,3);
		textBox6->SelectionStart = textBox6->Text->Length;
		textBox6->SelectionLength = 0;
	}
	if(textBox6->Text->Length > 0)
	if (Convert::ToInt32(textBox6->Text) > 100) {
		textBox6->Text = "100";
		textBox6->SelectionStart = textBox6->Text->Length;
		textBox6->SelectionLength = 0;
	}

}

private: System::Void TextBox6_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void TrackBar6_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	label17->Text = "Factor:" + (trackBar6->Value / 100.f);
}
private: System::Void Panel5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (color_ally_chams->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		panel5->BackColor = color_ally_chams->Color;
	}
}
private: System::Void Panel6_Click(System::Object^ sender, System::EventArgs^ e) {
	if (color_enemy_chams->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		panel6->BackColor = color_enemy_chams->Color;
	}
}
private: System::Void TextBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox7->Text->Contains(".")) {
		textBox7->Text = textBox7->Text->Replace(".", ",");
		textBox7->SelectionStart = textBox7->Text->Length;
		textBox7->SelectionLength = 0;
	}
	if (textBox7->Text->Length > 3) {
		textBox7->Text = textBox7->Text->Substring(0, 3);
		textBox7->SelectionStart = textBox7->Text->Length;
		textBox7->SelectionLength = 0;
	}
	if (textBox7->Text->Length > 0)
		if (Convert::ToInt32(textBox7->Text) > 100) {
			textBox7->Text = "100";
			textBox7->SelectionStart = textBox7->Text->Length;
			textBox7->SelectionLength = 0;
		}
}
private: System::Void TextBox7_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void TextBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == VK_RETURN) {
		try
		{
			if (Convert::ToInt32(Convert::ToDouble(textBox5->Text) * 10.f) <= 1000 && Convert::ToInt32(Convert::ToDouble(textBox5->Text) * 10.f) >= 0) {
				trackBar5->Value = Convert::ToInt32(Convert::ToDouble(textBox5->Text) * 10.f);
			}
			else {
				MessageBox::Show("Value must lower than 100 and bigger than 0!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (const std::exception&)
		{

		}
	}

	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		if(e->KeyChar != 46)
			if(e->KeyChar != 44)
		e->Handled = true;
	}
}
};
}
