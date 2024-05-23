#pragma once

namespace TimetableSystemSql {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for CoursesForm
	/// </summary>
	public ref class CoursesForm : public System::Windows::Forms::Form
	{
	public:
		CoursesForm(void)
		{
			InitializeComponent();
			LoadCourseData();
			//
			//TODO: Add the constructor code here
			//
		}
	private:
		System::Void LoadCourseData() {
			String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
			SqlConnection^ con = gcnew SqlConnection(ConnectionString);
			con->Open();
			SqlCommand^ cmd = gcnew SqlCommand("getCourseData", con);
			cmd->CommandType = CommandType::StoredProcedure;
			SqlDataReader^ reader = cmd->ExecuteReader();
			DataTable^ courseTable = gcnew DataTable;
			courseTable->Load(reader);
			reader->Close();
			con->Close();
			CourseDGV->DataSource = courseTable;

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CoursesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ updateBtn;

	private: System::Windows::Forms::Button^ removeBtn;

	private: System::Windows::Forms::Button^ addBtn;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ courseNameTxt;

	private: System::Windows::Forms::TextBox^ courseIdtxt;
	private: System::Windows::Forms::DataGridView^ CourseDGV;




	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->updateBtn = (gcnew System::Windows::Forms::Button());
			this->removeBtn = (gcnew System::Windows::Forms::Button());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->courseNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->courseIdtxt = (gcnew System::Windows::Forms::TextBox());
			this->CourseDGV = (gcnew System::Windows::Forms::DataGridView());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CourseDGV))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 22.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(450, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 48);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Courses";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::NavajoWhite;
			this->panel1->Controls->Add(this->updateBtn);
			this->panel1->Controls->Add(this->removeBtn);
			this->panel1->Controls->Add(this->addBtn);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->courseNameTxt);
			this->panel1->Controls->Add(this->courseIdtxt);
			this->panel1->Location = System::Drawing::Point(50, 55);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(413, 403);
			this->panel1->TabIndex = 4;
			// 
			// updateBtn
			// 
			this->updateBtn->BackColor = System::Drawing::Color::BurlyWood;
			this->updateBtn->Location = System::Drawing::Point(278, 306);
			this->updateBtn->Name = L"updateBtn";
			this->updateBtn->Size = System::Drawing::Size(131, 38);
			this->updateBtn->TabIndex = 7;
			this->updateBtn->Text = L"UPDATE";
			this->updateBtn->UseVisualStyleBackColor = false;
			this->updateBtn->Click += gcnew System::EventHandler(this, &CoursesForm::updateBtn_Click);
			// 
			// removeBtn
			// 
			this->removeBtn->BackColor = System::Drawing::Color::BurlyWood;
			this->removeBtn->Location = System::Drawing::Point(141, 306);
			this->removeBtn->Name = L"removeBtn";
			this->removeBtn->Size = System::Drawing::Size(131, 38);
			this->removeBtn->TabIndex = 6;
			this->removeBtn->Text = L"REMOVE";
			this->removeBtn->UseVisualStyleBackColor = false;
			this->removeBtn->Click += gcnew System::EventHandler(this, &CoursesForm::removeBtn_Click);
			// 
			// addBtn
			// 
			this->addBtn->BackColor = System::Drawing::Color::BurlyWood;
			this->addBtn->Location = System::Drawing::Point(4, 306);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(131, 38);
			this->addBtn->TabIndex = 5;
			this->addBtn->Text = L"ADD";
			this->addBtn->UseVisualStyleBackColor = false;
			this->addBtn->Click += gcnew System::EventHandler(this, &CoursesForm::addBtn_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(-2, 121);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Course Name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(27, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Course ID:";
			// 
			// courseNameTxt
			// 
			this->courseNameTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->courseNameTxt->Location = System::Drawing::Point(141, 118);
			this->courseNameTxt->Name = L"courseNameTxt";
			this->courseNameTxt->Size = System::Drawing::Size(250, 27);
			this->courseNameTxt->TabIndex = 2;
			// 
			// courseIdtxt
			// 
			this->courseIdtxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->courseIdtxt->Location = System::Drawing::Point(141, 54);
			this->courseIdtxt->Name = L"courseIdtxt";
			this->courseIdtxt->Size = System::Drawing::Size(250, 27);
			this->courseIdtxt->TabIndex = 1;
			// 
			// CourseDGV
			// 
			this->CourseDGV->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->CourseDGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->CourseDGV->Location = System::Drawing::Point(562, 55);
			this->CourseDGV->Name = L"CourseDGV";
			this->CourseDGV->RowHeadersWidth = 51;
			this->CourseDGV->RowTemplate->Height = 24;
			this->CourseDGV->Size = System::Drawing::Size(518, 390);
			this->CourseDGV->TabIndex = 5;
			this->CourseDGV->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CoursesForm::CourseDGV_CellClick);
			// 
			// CoursesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::NavajoWhite;
			this->ClientSize = System::Drawing::Size(1119, 560);
			this->Controls->Add(this->CourseDGV);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MinimumSize = System::Drawing::Size(1119, 560);
			this->Name = L"CoursesForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CoursesForm";
			this->Load += gcnew System::EventHandler(this, &CoursesForm::CoursesForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CourseDGV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
	SqlConnection^ con = gcnew SqlConnection(ConnectionString);
	try {
		con->Open();
		String^ courseId = courseIdtxt->Text->ToUpper();
		String^ courseName = courseNameTxt->Text->ToUpper();
		String^ query = "INSERT INTO Courses (CourseID, CourseName) VALUES (@courseId, @courseName)";
		SqlCommand^ cmd = gcnew SqlCommand(query, con);
		cmd->Parameters->AddWithValue("@courseId", courseId);
		cmd->Parameters->AddWithValue("@courseName", courseName);
		cmd->ExecuteNonQuery();
		con->Close();
		MessageBox::Show("Course Added Sucessfulyy!");
		LoadCourseData();
		courseIdtxt->Clear();
		courseNameTxt->Clear();

	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}
}
private: System::Void removeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";

	SqlConnection^ con = gcnew SqlConnection(ConnectionString);

	try {
		con->Open();
		String^ courseId = courseIdtxt->Text->ToUpper();
		String^ courseName = courseNameTxt->Text->ToUpper();
		String^ query = "DELETE FROM Courses WHERE CourseID=@courseId AND CourseName=@courseName";

		SqlCommand^ cmd = gcnew SqlCommand(query, con);
		cmd->Parameters->AddWithValue("@courseId", courseId);
		cmd->Parameters->AddWithValue("@courseName", courseName);

		int affectedRows = cmd->ExecuteNonQuery();
		if (affectedRows > 0) {
			MessageBox::Show("Course Removed Sucessfulyy!");
		}
		else {
			MessageBox::Show("Course Not Found!");
		}
		con->Close();LoadCourseData();
		courseIdtxt->Clear();
		courseNameTxt->Clear();
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}
}
private: System::Void updateBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
	SqlConnection^ con = gcnew SqlConnection(ConnectionString);

	for (int item = 0; item <= CourseDGV->Rows->Count - 1;item++) {
		String^ courseName = safe_cast<String^>(CourseDGV->Rows[item]->Cells[1]->Value);
		if (!String::IsNullOrEmpty(courseName)) {
			SqlCommand^ cmd = gcnew SqlCommand("UPDATE Courses SET CourseName=@CourseName WHERE CourseID=@CourseID", con);
			cmd->Parameters->AddWithValue("@CourseName", CourseDGV->Rows[item]->Cells[1]->Value);
			cmd->Parameters->AddWithValue("@CourseID", CourseDGV->Rows[item]->Cells[0]->Value);
			con->Open();
			cmd->ExecuteNonQuery();
			con->Close();
		}
	}
	MessageBox::Show("Data Updated Sucessfully");
	courseIdtxt->Clear();
	courseNameTxt->Clear();
}
private: System::Void CourseDGV_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0 && e->RowIndex < CourseDGV->Rows->Count) {
		DataGridViewRow^ selectedRow = CourseDGV->Rows[e->RowIndex];
		courseIdtxt->Text = selectedRow->Cells["CourseID"]->Value->ToString();
		courseNameTxt->Text = selectedRow->Cells["CourseName"]->Value->ToString();
	}
}
private: System::Void CoursesForm_Load(System::Object^ sender, System::EventArgs^ e) {
	LoadCourseData();
}
};
}
