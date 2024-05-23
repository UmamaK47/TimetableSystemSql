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
	/// Summary for TimetableForm
	/// </summary>
	public ref class TimetableForm : public System::Windows::Forms::Form
	{
	public:
		TimetableForm(void)
		{
			InitializeComponent();
			LoadTimetableData();
			//
			//TODO: Add the constructor code here
			//
		}
	private:
		System::Void LoadTimetableData() {
			String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
			SqlConnection^ con = gcnew SqlConnection(ConnectionString);
			con->Open();
			SqlCommand^ cmd = gcnew SqlCommand("getTimetableData", con);
			cmd->CommandType = CommandType::StoredProcedure;
			SqlDataReader^ reader = cmd->ExecuteReader();
			DataTable^ timetable = gcnew DataTable;
			timetable->Load(reader);
			reader->Close();
			con->Close();
			timetableDGV->DataSource = timetable;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TimetableForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ displayBtn;
	protected:


	private: System::Windows::Forms::Button^ makeBtn;





	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Panel^ makePanel;
	private: System::Windows::Forms::Panel^ displayPanel;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ timetableDGV;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::DataGridView^ displayTimetableDGV;

	private: System::Windows::Forms::ComboBox^ timeCB;

	private: System::Windows::Forms::ComboBox^ roomCB;

	private: System::Windows::Forms::ComboBox^ courseCB;

	private: System::Windows::Forms::ComboBox^ teacherCB;

	private: System::Windows::Forms::ComboBox^ dayCB;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ selectTeacherCB;


private: System::Windows::Forms::Button^ submitBtn;
	private: System::Windows::Forms::Button^ showBtn;










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
			this->displayBtn = (gcnew System::Windows::Forms::Button());
			this->makeBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->makePanel = (gcnew System::Windows::Forms::Panel());
			this->submitBtn = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->timeCB = (gcnew System::Windows::Forms::ComboBox());
			this->roomCB = (gcnew System::Windows::Forms::ComboBox());
			this->courseCB = (gcnew System::Windows::Forms::ComboBox());
			this->teacherCB = (gcnew System::Windows::Forms::ComboBox());
			this->dayCB = (gcnew System::Windows::Forms::ComboBox());
			this->timetableDGV = (gcnew System::Windows::Forms::DataGridView());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->displayPanel = (gcnew System::Windows::Forms::Panel());
			this->showBtn = (gcnew System::Windows::Forms::Button());
			this->selectTeacherCB = (gcnew System::Windows::Forms::ComboBox());
			this->displayTimetableDGV = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->makePanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timetableDGV))->BeginInit();
			this->displayPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->displayTimetableDGV))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::SandyBrown;
			this->panel1->Controls->Add(this->displayBtn);
			this->panel1->Controls->Add(this->makeBtn);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(273, 560);
			this->panel1->TabIndex = 7;
			// 
			// displayBtn
			// 
			this->displayBtn->BackColor = System::Drawing::Color::BurlyWood;
			this->displayBtn->Location = System::Drawing::Point(3, 124);
			this->displayBtn->Name = L"displayBtn";
			this->displayBtn->Size = System::Drawing::Size(267, 38);
			this->displayBtn->TabIndex = 6;
			this->displayBtn->Text = L"DISPLAY";
			this->displayBtn->UseVisualStyleBackColor = false;
			this->displayBtn->Click += gcnew System::EventHandler(this, &TimetableForm::displayBtn_Click);
			// 
			// makeBtn
			// 
			this->makeBtn->BackColor = System::Drawing::Color::BurlyWood;
			this->makeBtn->Location = System::Drawing::Point(3, 61);
			this->makeBtn->Name = L"makeBtn";
			this->makeBtn->Size = System::Drawing::Size(269, 38);
			this->makeBtn->TabIndex = 5;
			this->makeBtn->Text = L"MAKE";
			this->makeBtn->UseVisualStyleBackColor = false;
			this->makeBtn->Click += gcnew System::EventHandler(this, &TimetableForm::makeBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 22.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(450, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(195, 48);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Timetable";
			// 
			// makePanel
			// 
			this->makePanel->BackColor = System::Drawing::Color::NavajoWhite;
			this->makePanel->Controls->Add(this->submitBtn);
			this->makePanel->Controls->Add(this->label9);
			this->makePanel->Controls->Add(this->timeCB);
			this->makePanel->Controls->Add(this->roomCB);
			this->makePanel->Controls->Add(this->courseCB);
			this->makePanel->Controls->Add(this->teacherCB);
			this->makePanel->Controls->Add(this->dayCB);
			this->makePanel->Controls->Add(this->timetableDGV);
			this->makePanel->Controls->Add(this->label7);
			this->makePanel->Controls->Add(this->label6);
			this->makePanel->Controls->Add(this->label5);
			this->makePanel->Controls->Add(this->label4);
			this->makePanel->Controls->Add(this->label2);
			this->makePanel->Location = System::Drawing::Point(313, 61);
			this->makePanel->Name = L"makePanel";
			this->makePanel->Size = System::Drawing::Size(774, 397);
			this->makePanel->TabIndex = 8;
			this->makePanel->Visible = false;
			// 
			// submitBtn
			// 
			this->submitBtn->BackColor = System::Drawing::Color::BurlyWood;
			this->submitBtn->Location = System::Drawing::Point(0, 302);
			this->submitBtn->Name = L"submitBtn";
			this->submitBtn->Size = System::Drawing::Size(212, 38);
			this->submitBtn->TabIndex = 7;
			this->submitBtn->Text = L"SUBMIT";
			this->submitBtn->UseVisualStyleBackColor = false;
			this->submitBtn->Click += gcnew System::EventHandler(this, &TimetableForm::submitBtn_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(3, 32);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(185, 20);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Select the Following:";
			// 
			// timeCB
			// 
			this->timeCB->FormattingEnabled = true;
			this->timeCB->Location = System::Drawing::Point(67, 245);
			this->timeCB->Name = L"timeCB";
			this->timeCB->Size = System::Drawing::Size(145, 24);
			this->timeCB->TabIndex = 10;
			// 
			// roomCB
			// 
			this->roomCB->FormattingEnabled = true;
			this->roomCB->Location = System::Drawing::Point(67, 198);
			this->roomCB->Name = L"roomCB";
			this->roomCB->Size = System::Drawing::Size(145, 24);
			this->roomCB->TabIndex = 9;
			// 
			// courseCB
			// 
			this->courseCB->FormattingEnabled = true;
			this->courseCB->Location = System::Drawing::Point(67, 154);
			this->courseCB->Name = L"courseCB";
			this->courseCB->Size = System::Drawing::Size(145, 24);
			this->courseCB->TabIndex = 8;
			// 
			// teacherCB
			// 
			this->teacherCB->FormattingEnabled = true;
			this->teacherCB->Location = System::Drawing::Point(67, 111);
			this->teacherCB->Name = L"teacherCB";
			this->teacherCB->Size = System::Drawing::Size(142, 24);
			this->teacherCB->TabIndex = 7;
			// 
			// dayCB
			// 
			this->dayCB->FormattingEnabled = true;
			this->dayCB->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Monday", L"Tuesday", L"Wednesday", L"Thursday", L"Friday" });
			this->dayCB->Location = System::Drawing::Point(67, 70);
			this->dayCB->Name = L"dayCB";
			this->dayCB->Size = System::Drawing::Size(142, 24);
			this->dayCB->TabIndex = 6;
			// 
			// timetableDGV
			// 
			this->timetableDGV->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->timetableDGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->timetableDGV->Location = System::Drawing::Point(218, 32);
			this->timetableDGV->Name = L"timetableDGV";
			this->timetableDGV->RowHeadersWidth = 51;
			this->timetableDGV->RowTemplate->Height = 24;
			this->timetableDGV->Size = System::Drawing::Size(553, 362);
			this->timetableDGV->TabIndex = 5;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(23, 245);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(38, 16);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Time";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(17, 198);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 16);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Room";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(11, 154);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 16);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Course";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 111);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 16);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Teacher";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Day";
			// 
			// displayPanel
			// 
			this->displayPanel->Controls->Add(this->showBtn);
			this->displayPanel->Controls->Add(this->selectTeacherCB);
			this->displayPanel->Controls->Add(this->displayTimetableDGV);
			this->displayPanel->Controls->Add(this->label3);
			this->displayPanel->Location = System::Drawing::Point(313, 61);
			this->displayPanel->Name = L"displayPanel";
			this->displayPanel->Size = System::Drawing::Size(774, 397);
			this->displayPanel->TabIndex = 1;
			this->displayPanel->Visible = false;
			// 
			// showBtn
			// 
			this->showBtn->BackColor = System::Drawing::Color::BurlyWood;
			this->showBtn->Location = System::Drawing::Point(0, 236);
			this->showBtn->Name = L"showBtn";
			this->showBtn->Size = System::Drawing::Size(198, 38);
			this->showBtn->TabIndex = 8;
			this->showBtn->Text = L"SHOW";
			this->showBtn->UseVisualStyleBackColor = false;
			this->showBtn->Click += gcnew System::EventHandler(this, &TimetableForm::showBtn_Click);
			// 
			// selectTeacherCB
			// 
			this->selectTeacherCB->FormattingEnabled = true;
			this->selectTeacherCB->Location = System::Drawing::Point(15, 55);
			this->selectTeacherCB->Name = L"selectTeacherCB";
			this->selectTeacherCB->Size = System::Drawing::Size(183, 24);
			this->selectTeacherCB->TabIndex = 3;
			// 
			// displayTimetableDGV
			// 
			this->displayTimetableDGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->displayTimetableDGV->Location = System::Drawing::Point(204, 32);
			this->displayTimetableDGV->Name = L"displayTimetableDGV";
			this->displayTimetableDGV->RowHeadersWidth = 51;
			this->displayTimetableDGV->RowTemplate->Height = 24;
			this->displayTimetableDGV->Size = System::Drawing::Size(570, 365);
			this->displayTimetableDGV->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(11, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(136, 20);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Select Teacher";
			// 
			// TimetableForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::NavajoWhite;
			this->ClientSize = System::Drawing::Size(1119, 560);
			this->Controls->Add(this->makePanel);
			this->Controls->Add(this->displayPanel);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MinimumSize = System::Drawing::Size(1119, 560);
			this->Name = L"TimetableForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TimetableForm";
			this->Load += gcnew System::EventHandler(this, &TimetableForm::TimetableForm_Load);
			this->panel1->ResumeLayout(false);
			this->makePanel->ResumeLayout(false);
			this->makePanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timetableDGV))->EndInit();
			this->displayPanel->ResumeLayout(false);
			this->displayPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->displayTimetableDGV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

private: System::Void makeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	displayPanel->Visible = false;
	makePanel->Visible = true;
	makePanel->BringToFront();
}
private: System::Void displayBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	makePanel->Visible=false;
	displayPanel->Visible=true;
	displayPanel->BringToFront();
}
private: System::Void TimetableForm_Load(System::Object^ sender, System::EventArgs^ e) {
	populateTeacherCB();
	populateCourseCB();
	populateRoomCB();
	populateTimeCB();
	populateSelectTeacherCB();
}
private: System::Void submitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
	SqlConnection^ con = gcnew SqlConnection(ConnectionString);
	try {
		con->Open();
		SqlCommand^ cmd = gcnew SqlCommand("MakeTimetable", con);
		cmd->CommandType = CommandType::StoredProcedure;
		cmd->Parameters->AddWithValue("@teacherid", teacherCB->SelectedValue);
		cmd->Parameters->AddWithValue("@courseid", courseCB->SelectedValue);
		cmd->Parameters->AddWithValue("@roomid", roomCB->SelectedValue);
		cmd->Parameters->AddWithValue("@timeslotid", timeCB->SelectedValue);
		cmd->Parameters->AddWithValue("@day", dayCB->SelectedItem);
		cmd->ExecuteNonQuery();
		if (teacherCB->SelectedValue == nullptr || courseCB->SelectedValue==nullptr||roomCB->SelectedValue==nullptr||timeCB->SelectedValue==nullptr) {
			MessageBox::Show("Please select all fields.");
			con->Close();
			return;
		}
		con->Close();
		MessageBox::Show("Data Inserted Sucessfully");

	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}
}
	   private: DataTable^ populateTeacherCB() {
		   DataTable^ dt = gcnew DataTable();
		   String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
		   SqlConnection^ con = gcnew SqlConnection(ConnectionString);
		   SqlCommand^ cmd = gcnew SqlCommand("getTeachData", con);
		   try {
			   con->Open();
			   cmd->CommandType = CommandType::StoredProcedure;
			   SqlDataReader^ reader = cmd->ExecuteReader();
			   dt->Load(reader);
			   con->Close();
			   teacherCB->DataSource = dt;
			   teacherCB->DisplayMember = "TeacherName";
			   teacherCB->ValueMember = "TeacherID";
			   return dt;
		   }
		   catch (Exception^ ex) {
			   MessageBox::Show("Error: " + ex->Message);
		   }
	}
	private: DataTable^ populateCourseCB() {
		DataTable^ dt = gcnew DataTable();
		String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
		SqlConnection^ con = gcnew SqlConnection(ConnectionString);
		SqlCommand^ cmd = gcnew SqlCommand("courseData", con);
		try {
			con->Open();
			cmd->CommandType = CommandType::StoredProcedure;
			SqlDataReader^ reader = cmd->ExecuteReader();
			dt->Load(reader);
			con->Close();
			courseCB->DataSource = dt;
			courseCB->DisplayMember = "CourseName";
			courseCB->ValueMember = "CourseID";
			return dt;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}
	private: DataTable^ populateRoomCB() {
		DataTable^ dt = gcnew DataTable();
		String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
		SqlConnection^ con = gcnew SqlConnection(ConnectionString);
		SqlCommand^ cmd = gcnew SqlCommand("roomData", con);
		try {
			con->Open();
			cmd->CommandType = CommandType::StoredProcedure;
			SqlDataReader^ reader = cmd->ExecuteReader();
			dt->Load(reader);
			con->Close();
			roomCB->DataSource = dt;
			roomCB->DisplayMember = "RoomNumber";
			roomCB->ValueMember = "RoomID";
			return dt;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}
	private: DataTable^ populateTimeCB() {
		DataTable^ dt = gcnew DataTable();
		String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
		SqlConnection^ con = gcnew SqlConnection(ConnectionString);
		SqlCommand^ cmd = gcnew SqlCommand("timeslotData", con);
		try {
			con->Open();
			cmd->CommandType = CommandType::StoredProcedure;
			SqlDataReader^ reader = cmd->ExecuteReader();
			dt->Load(reader);
			con->Close();
			timeCB->DataSource = dt;
			timeCB->DisplayMember = "StartTime";
			timeCB->ValueMember = "TimeslotID";
			return dt;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}		
	private: DataTable^ populateSelectTeacherCB() {
		DataTable^ dt = gcnew DataTable();
		String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
		SqlConnection^ con = gcnew SqlConnection(ConnectionString);
		SqlCommand^ cmd = gcnew SqlCommand("getTeachData", con);
		try {
			con->Open();
			cmd->CommandType = CommandType::StoredProcedure;
			SqlDataReader^ reader = cmd->ExecuteReader();
			dt->Load(reader);
			con->Close();
			selectTeacherCB->DataSource = dt;
			selectTeacherCB->DisplayMember = "TeacherName";
			selectTeacherCB->ValueMember = "TeacherID";
			return dt;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}
private: System::Void updateBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
	SqlConnection^ con = gcnew SqlConnection(ConnectionString);

	for (int item = 0; item < displayTimetableDGV->Rows->Count - 1; item++) {
		String^ timetableID = safe_cast<String^>(displayTimetableDGV->Rows[item]->Cells["TimetableID"]->Value);
		if (!String::IsNullOrEmpty(timetableID)) {
			SqlCommand^ cmd = gcnew SqlCommand("UPDATE Timetable SET TeacherID=@teacherID, CourseID=@courseID, RoomID=@roomID, TimeslotID=@timeID, WeekDay=@day WHERE TimetableID=@timetableID", con);

			cmd->Parameters->AddWithValue("@teacherID", displayTimetableDGV->Rows[item]->Cells["TeacherID"]->Value);
			cmd->Parameters->AddWithValue("@courseID", displayTimetableDGV->Rows[item]->Cells["CourseID"]->Value);
			cmd->Parameters->AddWithValue("@roomID", displayTimetableDGV->Rows[item]->Cells["RoomID"]->Value);
			cmd->Parameters->AddWithValue("@timeID", displayTimetableDGV->Rows[item]->Cells["TimeslotID"]->Value);
			cmd->Parameters->AddWithValue("@day", displayTimetableDGV->Rows[item]->Cells["WeekDay"]->Value);
			cmd->Parameters->AddWithValue("@timetableID", timetableID);

			con->Open();
			cmd->ExecuteNonQuery();
			con->Close();
		}
	}
}
private: System::Void showBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
	SqlConnection^ con = gcnew SqlConnection(ConnectionString);
	String^ selectedTeacher = selectTeacherCB->SelectedValue->ToString();
	try {
		con->Open();
		String^ query = "SELECT TimetableID, TeacherName, CourseName, RoomNumber, StartTime, WeekDay FROM Timetable INNER JOIN Teachers ON Timetable.TeacherID = Teachers.TeacherID INNER JOIN Courses ON Timetable.CourseID = Courses.CourseID INNER JOIN Rooms ON Timetable.RoomID = Rooms.RoomID INNER JOIN Timeslots ON Timetable.TimeslotID=Timeslots.TimeslotID WHERE Timetable.TeacherID=@teacherID";
		SqlCommand^ cmd = gcnew SqlCommand(query, con);
		cmd->Parameters->AddWithValue("@teacherID", selectedTeacher);


		SqlDataReader^ reader = cmd->ExecuteReader();
		DataTable^ dt = gcnew DataTable();
		dt->Load(reader);
		displayTimetableDGV->DataSource = dt;
		con->Close();
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}
}
};
}

