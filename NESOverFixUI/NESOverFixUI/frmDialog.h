#pragma once


namespace NESOverFixUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Form1 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class frmMainDlg : public System::Windows::Forms::Form
	{
	public:
		frmMainDlg(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~frmMainDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnSearch;
	private: System::Windows::Forms::FolderBrowserDialog^  fbdFolder;

	private: System::Windows::Forms::Button^  btnBrowse;
	private: System::Windows::Forms::ComboBox^  cbxPath;
	private: System::Windows::Forms::CheckedListBox^  clbRomList;
	private: System::Windows::Forms::ProgressBar^  pgbProgress;
	private: System::Windows::Forms::Label^  lblPrompt;




	private: System::Windows::Forms::Button^  btnFix;
	private: System::Windows::Forms::Button^  btnClose;
	protected: 

	protected: 

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->fbdFolder = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->btnBrowse = (gcnew System::Windows::Forms::Button());
			this->cbxPath = (gcnew System::Windows::Forms::ComboBox());
			this->clbRomList = (gcnew System::Windows::Forms::CheckedListBox());
			this->pgbProgress = (gcnew System::Windows::Forms::ProgressBar());
			this->lblPrompt = (gcnew System::Windows::Forms::Label());
			this->btnFix = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(228, 39);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(75, 23);
			this->btnSearch->TabIndex = 3;
			this->btnSearch->Text = L"检索(&S)";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &frmMainDlg::btnSearch_Click);
			// 
			// fbdFolder
			// 
			this->fbdFolder->ShowNewFolderButton = false;
			// 
			// btnBrowse
			// 
			this->btnBrowse->Location = System::Drawing::Point(228, 10);
			this->btnBrowse->Name = L"btnBrowse";
			this->btnBrowse->Size = System::Drawing::Size(75, 23);
			this->btnBrowse->TabIndex = 2;
			this->btnBrowse->Text = L"浏览(&B)";
			this->btnBrowse->UseVisualStyleBackColor = true;
			this->btnBrowse->Click += gcnew System::EventHandler(this, &frmMainDlg::btnBrowse_Click);
			// 
			// cbxPath
			// 
			this->cbxPath->FormattingEnabled = true;
			this->cbxPath->Location = System::Drawing::Point(12, 10);
			this->cbxPath->Name = L"cbxPath";
			this->cbxPath->Size = System::Drawing::Size(210, 20);
			this->cbxPath->TabIndex = 1;
			// 
			// clbRomList
			// 
			this->clbRomList->FormattingEnabled = true;
			this->clbRomList->Location = System::Drawing::Point(12, 39);
			this->clbRomList->Name = L"clbRomList";
			this->clbRomList->Size = System::Drawing::Size(210, 196);
			this->clbRomList->TabIndex = 4;
			// 
			// pgbProgress
			// 
			this->pgbProgress->Location = System::Drawing::Point(12, 241);
			this->pgbProgress->Name = L"pgbProgress";
			this->pgbProgress->Size = System::Drawing::Size(290, 23);
			this->pgbProgress->TabIndex = 5;
			// 
			// lblPrompt
			// 
			this->lblPrompt->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblPrompt->Location = System::Drawing::Point(12, 241);
			this->lblPrompt->Name = L"lblPrompt";
			this->lblPrompt->Size = System::Drawing::Size(290, 23);
			this->lblPrompt->TabIndex = 7;
			this->lblPrompt->Text = L"Ready!";
			this->lblPrompt->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// btnFix
			// 
			this->btnFix->Location = System::Drawing::Point(228, 68);
			this->btnFix->Name = L"btnFix";
			this->btnFix->Size = System::Drawing::Size(75, 23);
			this->btnFix->TabIndex = 5;
			this->btnFix->Text = L"修复(&F)";
			this->btnFix->UseVisualStyleBackColor = true;
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(228, 112);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 6;
			this->btnClose->Text = L"退出(&C)";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmMainDlg::btnClose_Click);
			// 
			// frmMainDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(314, 273);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnFix);
			this->Controls->Add(this->lblPrompt);
			this->Controls->Add(this->pgbProgress);
			this->Controls->Add(this->clbRomList);
			this->Controls->Add(this->cbxPath);
			this->Controls->Add(this->btnBrowse);
			this->Controls->Add(this->btnSearch);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"frmMainDlg";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NES rom Overdump Fixer";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
				 Application::Exit();
			 }
	private: System::Void btnBrowse_Click(System::Object^  sender, System::EventArgs^  e) {
				 fbdFolder->Description = "打开NES ROM所在文件夹(*.NES)";
				 fbdFolder->ShowDialog();
				 if (fbdFolder->SelectedPath != "") {
					 cbxPath->Text = fbdFolder->SelectedPath;
				 }
			 }
	private: System::Void btnSearch_Click(System::Object^  sender, System::EventArgs^  e) {
				 array<String^> ^RomFileName;
				 String^ path = cbxPath->Text;

				 if (Directory::Exists(path)) {
					 if (!cbxPath->Items->Contains(path))
						cbxPath->Items->Add(path);
					 RomFileName = Directory::GetFiles(path,"*.nes");
					 UInt32 RomFileCnt = RomFileName->Length;
					 lblPrompt->Text = "ROM file(s) found";
					 if (RomFileCnt > 0) {
						 UInt32 fcnt;
						 clbRomList->Items->Clear();
						 for(fcnt=0;fcnt<RomFileCnt;fcnt++) {
							clbRomList->Items->Add(RomFileName[fcnt],true);
						 }
					 }
				 }
			 } 
};
}

