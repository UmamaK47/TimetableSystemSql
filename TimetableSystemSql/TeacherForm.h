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
	/// Summary for TeacherForm
	/// </summary>
	public ref class TeacherForm : public System::Windows::Forms::Form
	{
	public:
		TeacherForm(void)
		{
			InitializeComponent();
			LoadTeacherData();
			//
			//TODO: Add the constructor code here
			//
		}
	private:
		System::Void LoadTeacherData() {
			//1. get address of sql server
			String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
			//2. establish connection
			SqlConnection^ con = gcnew SqlConnection(ConnectionString);
			//3.Open connection
			con->Open();
			//5. create sql command obj
			SqlCommand^ cmd = gcnew SqlCommand("getTeacherData", con);
			cmd->CommandType = CommandType::StoredProcedure;
			//6. create sql reader obj and execute cmd
			SqlDataReader^ reader = cmd->ExecuteReader();
			//7. create datatable
			DataTable^ teacherTable = gcnew DataTable;
			//8. Load reader in table
			teacherTable->Load(reader);
			//9. close connection and reader
			reader->Close();
			con->Close();
			//10. bind data to datagridview
			TeacherDGV->DataSource = teacherTable;

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TeacherForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ teacherIdTxt;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ teacherNameTxt;


	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Button^ UpdateBtn;

	private: System::Windows::Forms::Button^ removeBtn;

	private: System::Windows::Forms::Button^ addBtn;
	private: System::Windows::Forms::DataGridView^ TeacherDGV;



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
			this->teacherIdTxt = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->UpdateBtn = (gcnew System::Windows::Forms::Button());
			this->removeBtn = (gcnew System::Windows::Forms::Button());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->teacherNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->TeacherDGV = (gcnew System::Windows::Forms::DataGridView());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TeacherDGV))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 22.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(450, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(173, 48);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Teachers";
			// 
			// teacherIdTxt
			// 
			this->teacherIdTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->teacherIdTxt->Location = System::Drawing::Point(141, 54);
			this->teacherIdTxt->Name = L"teacherIdTxt";
			this->teacherIdTxt->Size = System::Drawing::Size(250, 27);
			this->teacherIdTxt->TabIndex = 1;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::NavajoWhite;
			this->panel1->Controls->Add(this->UpdateBtn);
			this->panel1->Controls->Add(this->removeBtn);
			this->panel1->Controls->Add(this->addBtn);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->teacherNameTxt);
			this->panel1->Controls->Add(this->teacherIdTxt);
			this->panel1->Location = System::Drawing::Point(41, 77);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(413, 403);
			this->panel1->TabIndex = 2;
			// 
			// UpdateBtn
			// 
			this->UpdateBtn->BackColor = System::Drawing::Color::BurlyWood;
			this->UpdateBtn->Location = System::Drawing::Point(278, 306);
			this->UpdateBtn->Name = L"UpdateBtn";
			this->UpdateBtn->Size = System::Drawing::Size(131, 38);
			this->UpdateBtn->TabIndex = 7;
			this->UpdateBtn->Text = L"UPDATE";
			this->UpdateBtn->UseVisualStyleBackColor = false;
			this->UpdateBtn->Click += gcnew System::EventHandler(this, &TeacherForm::UpdateBtn_Click);
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
			this->removeBtn->Click += gcnew System::EventHandler(this, &TeacherForm::removeBtn_Click);
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
			this->addBtn->Click += gcnew System::EventHandler(this, &TeacherForm::addBtn_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(-2, 121);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(137, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Teacher Name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(27, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Teacher ID:";
			this->label2->Click += gcnew System::EventHandler(this, &TeacherForm::label2_Click);
			// 
			// teacherNameTxt
			// 
			this->teacherNameTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->teacherNameTxt->Location = System::Drawing::Point(141, 118);
			this->teacherNameTxt->Name = L"teacherNameTxt";
			this->teacherNameTxt->Size = System::Drawing::Size(250, 27);
			this->teacherNameTxt->TabIndex = 2;
			// 
			// TeacherDGV
			// 
			this->TeacherDGV->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->TeacherDGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->TeacherDGV->Location = System::Drawing::Point(532, 77);
			this->TeacherDGV->Name = L"TeacherDGV";
			this->TeacherDGV->RowHeadersWidth = 51;
			this->TeacherDGV->RowTemplate->Height = 24;
			this->TeacherDGV->Size = System::Drawing::Size(517, 403);
			this->TeacherDGV->TabIndex = 3;
			this->TeacherDGV->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TeacherForm::TeacherDGV_CellClick_1);
			// 
			// TeacherForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::NavajoWhite;
			this->ClientSize = System::Drawing::Size(1119, 560);
			this->Controls->Add(this->TeacherDGV);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MinimumSize = System::Drawing::Size(1119, 560);
			this->Name = L"TeacherForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TeacherForm";
			this->Load += gcnew System::EventHandler(this, &TeacherForm::TeacherForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TeacherDGV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// 1. get address of sql server
	String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";

	//2. establish the database and VS connection
	SqlConnection^ con = gcnew SqlConnection(ConnectionString);
	try {
		//3. open the connection
		con->Open();

		//4. set up appropriate query
		String^ teacherId = teacherIdTxt->Text->ToUpper();
		String^ teacherName = teacherNameTxt->Text->ToUpper();
		String^ query = "INSERT INTO Teachers (TeacherID, TeacherName) VALUES (@teacherId, @teacherName)";

		//5. execute the query
		SqlCommand^ cmd = gcnew SqlCommand(query, con);
		cmd->Parameters->AddWithValue("@teacherId", teacherId);
		cmd->Parameters->AddWithValue("@teacherName", teacherName);
		cmd->ExecuteNonQuery();

		//6. close connection
		con->Close();
		MessageBox::Show("Teacher Added Sucessfulyy!");
		teacherIdTxt->Clear();
		teacherNameTxt->Clear();
		LoadTeacherData();

	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}
	
}
private: System::Void removeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	//1. get address of sql server
	String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";

	//2. establish connection
	SqlConnection^ con = gcnew SqlConnection(ConnectionString);

	try {
		//3.Open connection
		con->Open();
		//4. set up query
		String^ teacherId = teacherIdTxt->Text->ToUpper();
		String^ teacherName = teacherNameTxt->Text->ToUpper();
		String^ query = "DELETE FROM Teachers WHERE TeacherID=@teacherId AND TeacherName=@teacherName";

		//5. execute query
		SqlCommand^ cmd = gcnew SqlCommand(query, con);
		cmd->Parameters->AddWithValue("@teacherId", teacherId);
		cmd->Parameters->AddWithValue("@teacherName", teacherName);

		int affectedRows= cmd->ExecuteNonQuery();
		if (affectedRows > 0) {
			MessageBox::Show("Teacher Removed Sucessfulyy!");
		}
		else {
			MessageBox::Show("Teacher Not Found!");
		}
		teacherIdTxt->Clear();
		teacherNameTxt->Clear();

		//6. close connection
		con->Close();LoadTeacherData();

		
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}
}
private: System::Void TeacherForm_Load(System::Object^ sender, System::EventArgs^ e) {
	LoadTeacherData();
}
	


private: System::Void TeacherDGV_CellClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0 && e->RowIndex < TeacherDGV->Rows->Count) {
		DataGridViewRow^ selectedRow = TeacherDGV->Rows[e->RowIndex];
		teacherIdTxt->Text = selectedRow->Cells["TeacherID"]->Value->ToString();
		teacherNameTxt->Text = selectedRow->Cells["TeacherName"]->Value->ToString();
	}
}
private: System::Void UpdateBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
	SqlConnection^ con = gcnew SqlConnection(ConnectionString);
		
	for (int item = 0; item <= TeacherDGV->Rows->Count - 1;item++) {
		String^ teacherName = safe_cast<String^>(TeacherDGV->Rows[item]->Cells[1]->Value);
		if (!String::IsNullOrEmpty(teacherName)) {
			SqlCommand^ cmd = gcnew SqlCommand("UPDATE Teachers SET TeacherName=@TeacherName WHERE TeacherID=@TeacherID", con);
			cmd->Parameters->AddWithValue("@TeacherName", TeacherDGV->Rows[item]->Cells[1]->Value);
			cmd->Parameters->AddWithValue("@TeacherID", TeacherDGV->Rows[item]->Cells[0]->Value);
			con->Open();
			cmd->ExecuteNonQuery();
			con->Close();
		}
	}
	MessageBox::Show("Data Updated Sucessfully");
	teacherIdTxt->Clear();
	teacherNameTxt->Clear();
}
};
}
