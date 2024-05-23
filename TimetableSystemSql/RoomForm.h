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
	/// Summary for RoomForm
	/// </summary>
	public ref class RoomForm : public System::Windows::Forms::Form
	{
	public:
		RoomForm(void)
		{
			InitializeComponent();
			LoadRoomData();
			//
			//TODO: Add the constructor code here
			//
		}
	private:
		System::Void LoadRoomData() {
			String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
			SqlConnection^ con = gcnew SqlConnection(ConnectionString);
			con->Open();
			SqlCommand^ cmd = gcnew SqlCommand("getRoomData", con);
			cmd->CommandType = CommandType::StoredProcedure;
			SqlDataReader^ reader = cmd->ExecuteReader();
			DataTable^ roomTable = gcnew DataTable;
			roomTable->Load(reader);
			reader->Close();
			con->Close();
			RoomDGV->DataSource = roomTable;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RoomForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ updateBtn;
	private: System::Windows::Forms::Button^ removeBtn;
	private: System::Windows::Forms::Button^ addBtn;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ roomNameTxt;

	private: System::Windows::Forms::TextBox^ roomIdTxt;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ RoomDGV;



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
			this->updateBtn = (gcnew System::Windows::Forms::Button());
			this->removeBtn = (gcnew System::Windows::Forms::Button());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->roomNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->roomIdTxt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->RoomDGV = (gcnew System::Windows::Forms::DataGridView());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RoomDGV))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->updateBtn);
			this->panel1->Controls->Add(this->removeBtn);
			this->panel1->Controls->Add(this->addBtn);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->roomNameTxt);
			this->panel1->Controls->Add(this->roomIdTxt);
			this->panel1->Location = System::Drawing::Point(50, 82);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(413, 403);
			this->panel1->TabIndex = 7;
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
			this->updateBtn->Click += gcnew System::EventHandler(this, &RoomForm::updateBtn_Click);
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
			this->removeBtn->Click += gcnew System::EventHandler(this, &RoomForm::removeBtn_Click);
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
			this->addBtn->Click += gcnew System::EventHandler(this, &RoomForm::addBtn_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(-2, 121);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Room Number:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(44, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Room ID:";
			// 
			// roomNameTxt
			// 
			this->roomNameTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->roomNameTxt->Location = System::Drawing::Point(141, 118);
			this->roomNameTxt->Name = L"roomNameTxt";
			this->roomNameTxt->Size = System::Drawing::Size(250, 27);
			this->roomNameTxt->TabIndex = 2;
			// 
			// roomIdTxt
			// 
			this->roomIdTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->roomIdTxt->Location = System::Drawing::Point(141, 54);
			this->roomIdTxt->Name = L"roomIdTxt";
			this->roomIdTxt->Size = System::Drawing::Size(250, 27);
			this->roomIdTxt->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 22.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(450, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 48);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Rooms";
			// 
			// RoomDGV
			// 
			this->RoomDGV->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->RoomDGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->RoomDGV->Location = System::Drawing::Point(599, 82);
			this->RoomDGV->Name = L"RoomDGV";
			this->RoomDGV->RowHeadersWidth = 51;
			this->RoomDGV->RowTemplate->Height = 24;
			this->RoomDGV->Size = System::Drawing::Size(483, 403);
			this->RoomDGV->TabIndex = 8;
			this->RoomDGV->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &RoomForm::RoomDGV_CellClick);
			// 
			// RoomForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::NavajoWhite;
			this->ClientSize = System::Drawing::Size(1119, 560);
			this->Controls->Add(this->RoomDGV);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MinimumSize = System::Drawing::Size(1119, 560);
			this->Name = L"RoomForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RoomForm";
			this->Load += gcnew System::EventHandler(this, &RoomForm::RoomForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RoomDGV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
	SqlConnection^ con = gcnew SqlConnection(ConnectionString);
	try {
		con->Open();
		String^ roomId = roomIdTxt->Text->ToUpper();
		String^ roomName = roomNameTxt->Text->ToUpper();
		String^ query = "INSERT INTO Rooms (RoomID, RoomNumber) VALUES (@roomId, @roomName)";
		SqlCommand^ cmd = gcnew SqlCommand(query, con);
		cmd->Parameters->AddWithValue("@roomId", roomId);
		cmd->Parameters->AddWithValue("@roomName", roomName);
		cmd->ExecuteNonQuery();
		con->Close();
		MessageBox::Show("Room Added Sucessfulyy!");
		roomIdTxt->Clear();
		roomNameTxt->Clear();
		LoadRoomData();

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
		String^ roomId = roomIdTxt->Text->ToUpper();
		String^ roomName = roomNameTxt->Text->ToUpper();
		String^ query = "DELETE FROM Rooms WHERE RoomID=@roomId AND RoomNumber=@roomName";

		SqlCommand^ cmd = gcnew SqlCommand(query, con);
		cmd->Parameters->AddWithValue("@roomId", roomId);
		cmd->Parameters->AddWithValue("@roomNumber", roomName);

		int affectedRows = cmd->ExecuteNonQuery();
		if (affectedRows > 0) {
			MessageBox::Show("Room Removed Sucessfulyy!");
		}
		else {
			MessageBox::Show("Room Not Found!");
		}
		con->Close();
		roomIdTxt->Clear();
		roomNameTxt->Clear();
		LoadRoomData();

	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}
}
private: System::Void RoomForm_Load(System::Object^ sender, System::EventArgs^ e) {
	LoadRoomData();
}
private: System::Void RoomDGV_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0 && e->RowIndex < RoomDGV->Rows->Count) {
		DataGridViewRow^ selectedRow = RoomDGV->Rows[e->RowIndex];
		roomIdTxt->Text = selectedRow->Cells["RoomID"]->Value->ToString();
		roomNameTxt->Text = selectedRow->Cells["RoomNumber"]->Value->ToString();
	}
}
private: System::Void updateBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ConnectionString = "Data Source=DESKTOP-TNL89SE;Initial Catalog=TimetableSystem;PersistSecurityInfo=True;User ID=umama;Password=1234;TrustServerCertificate=True";
	SqlConnection^ con = gcnew SqlConnection(ConnectionString);

	for (int item = 0; item <= RoomDGV->Rows->Count - 1;item++) {
		String^ roomName = safe_cast<String^>(RoomDGV->Rows[item]->Cells[1]->Value);
		if (!String::IsNullOrEmpty(roomName)) {
			SqlCommand^ cmd = gcnew SqlCommand("UPDATE Rooms SET RoomNumber=@RoomNumber WHERE RoomID=@RoomID", con);
			cmd->Parameters->AddWithValue("@RoomNumber", RoomDGV->Rows[item]->Cells[1]->Value);
			cmd->Parameters->AddWithValue("@RoomID", RoomDGV->Rows[item]->Cells[0]->Value);
			con->Open();
			cmd->ExecuteNonQuery();
			con->Close();
		}
	}
	MessageBox::Show("Data Updated Sucessfully");
	roomIdTxt->Clear();
	roomNameTxt->Clear();
}
};
}
