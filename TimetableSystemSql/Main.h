#pragma once
#include"TeacherForm.h"
#include"CoursesForm.h"
#include"RoomForm.h"
#include"TimetableForm.h"
namespace TimetableSystemSql {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
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
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ TimetableBtn;
	protected:

	private: System::Windows::Forms::Button^ RoomBtn;

	private: System::Windows::Forms::Button^ CourseBtn;

	private: System::Windows::Forms::Button^ TeacherBtn;

	private: System::Windows::Forms::Button^ HomeBtn;
	private: System::Windows::Forms::Button^ ExitBtn;
	private: System::Windows::Forms::Panel^ content;
	private: System::Windows::Forms::Label^ label1;




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
			this->ExitBtn = (gcnew System::Windows::Forms::Button());
			this->TimetableBtn = (gcnew System::Windows::Forms::Button());
			this->RoomBtn = (gcnew System::Windows::Forms::Button());
			this->CourseBtn = (gcnew System::Windows::Forms::Button());
			this->TeacherBtn = (gcnew System::Windows::Forms::Button());
			this->HomeBtn = (gcnew System::Windows::Forms::Button());
			this->content = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->content->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::SandyBrown;
			this->panel1->Controls->Add(this->ExitBtn);
			this->panel1->Controls->Add(this->TimetableBtn);
			this->panel1->Controls->Add(this->RoomBtn);
			this->panel1->Controls->Add(this->CourseBtn);
			this->panel1->Controls->Add(this->TeacherBtn);
			this->panel1->Controls->Add(this->HomeBtn);
			this->panel1->Location = System::Drawing::Point(3, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1117, 65);
			this->panel1->TabIndex = 0;
			// 
			// ExitBtn
			// 
			this->ExitBtn->BackColor = System::Drawing::Color::SandyBrown;
			this->ExitBtn->Location = System::Drawing::Point(984, 5);
			this->ExitBtn->Name = L"ExitBtn";
			this->ExitBtn->Size = System::Drawing::Size(130, 60);
			this->ExitBtn->TabIndex = 5;
			this->ExitBtn->Text = L"Exit";
			this->ExitBtn->UseVisualStyleBackColor = false;
			this->ExitBtn->Click += gcnew System::EventHandler(this, &Main::ExitBtn_Click);
			// 
			// TimetableBtn
			// 
			this->TimetableBtn->BackColor = System::Drawing::Color::SandyBrown;
			this->TimetableBtn->Location = System::Drawing::Point(787, 4);
			this->TimetableBtn->Name = L"TimetableBtn";
			this->TimetableBtn->Size = System::Drawing::Size(200, 61);
			this->TimetableBtn->TabIndex = 4;
			this->TimetableBtn->Text = L"Timetable";
			this->TimetableBtn->UseVisualStyleBackColor = false;
			this->TimetableBtn->Click += gcnew System::EventHandler(this, &Main::TimetableBtn_Click);
			// 
			// RoomBtn
			// 
			this->RoomBtn->BackColor = System::Drawing::Color::SandyBrown;
			this->RoomBtn->Location = System::Drawing::Point(590, 4);
			this->RoomBtn->Name = L"RoomBtn";
			this->RoomBtn->Size = System::Drawing::Size(200, 61);
			this->RoomBtn->TabIndex = 3;
			this->RoomBtn->Text = L"Rooms";
			this->RoomBtn->UseVisualStyleBackColor = false;
			this->RoomBtn->Click += gcnew System::EventHandler(this, &Main::RoomBtn_Click);
			// 
			// CourseBtn
			// 
			this->CourseBtn->BackColor = System::Drawing::Color::SandyBrown;
			this->CourseBtn->Location = System::Drawing::Point(393, 4);
			this->CourseBtn->Name = L"CourseBtn";
			this->CourseBtn->Size = System::Drawing::Size(200, 61);
			this->CourseBtn->TabIndex = 2;
			this->CourseBtn->Text = L"Courses";
			this->CourseBtn->UseVisualStyleBackColor = false;
			this->CourseBtn->Click += gcnew System::EventHandler(this, &Main::CourseBtn_Click);
			// 
			// TeacherBtn
			// 
			this->TeacherBtn->BackColor = System::Drawing::Color::SandyBrown;
			this->TeacherBtn->Location = System::Drawing::Point(196, 4);
			this->TeacherBtn->Name = L"TeacherBtn";
			this->TeacherBtn->Size = System::Drawing::Size(200, 61);
			this->TeacherBtn->TabIndex = 1;
			this->TeacherBtn->Text = L"Teachers";
			this->TeacherBtn->UseVisualStyleBackColor = false;
			this->TeacherBtn->Click += gcnew System::EventHandler(this, &Main::TeacherBtn_Click);
			// 
			// HomeBtn
			// 
			this->HomeBtn->BackColor = System::Drawing::Color::SandyBrown;
			this->HomeBtn->Location = System::Drawing::Point(0, 4);
			this->HomeBtn->Name = L"HomeBtn";
			this->HomeBtn->Size = System::Drawing::Size(200, 61);
			this->HomeBtn->TabIndex = 0;
			this->HomeBtn->Text = L"Home";
			this->HomeBtn->UseVisualStyleBackColor = false;
			this->HomeBtn->Click += gcnew System::EventHandler(this, &Main::HomeBtn_Click);
			// 
			// content
			// 
			this->content->BackColor = System::Drawing::Color::NavajoWhite;
			this->content->Controls->Add(this->label1);
			this->content->Location = System::Drawing::Point(3, 71);
			this->content->Name = L"content";
			this->content->Size = System::Drawing::Size(1104, 477);
			this->content->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(190, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(659, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome to the Timetable Management System";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::NavajoWhite;
			this->ClientSize = System::Drawing::Size(1119, 560);
			this->Controls->Add(this->content);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MinimumSize = System::Drawing::Size(1119, 560);
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Main";
			this->panel1->ResumeLayout(false);
			this->content->ResumeLayout(false);
			this->content->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void TeacherBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		TeacherForm^ teacher = gcnew TeacherForm();
		teacher->TopLevel = false;
		content->Controls->Clear();
		content->Controls->Add(teacher);
		teacher->Show();
	}
private: System::Void CourseBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	CoursesForm^ course = gcnew CoursesForm();
	course->TopLevel = false;
	content->Controls->Clear();
	content->Controls->Add(course);
	course->Show();
}
private: System::Void RoomBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	RoomForm^ room = gcnew RoomForm();
	room->TopLevel = false;
	content->Controls->Clear();
	content->Controls->Add(room);
	room->Show();
}
private: System::Void TimetableBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	TimetableForm^ timetable = gcnew TimetableForm();
	timetable->TopLevel = false;
	content->Controls->Clear();
	content->Controls->Add(timetable);
	timetable->Show();
}
private: System::Void ExitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void HomeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	content->Controls->Clear();
}
};
}
