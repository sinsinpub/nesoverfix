// NESOverFixUI.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include "frmDialog.h"

using namespace NESOverFixUI;

const unsigned long MaxRomFile = 4096;

//unsigned long RomFileCnt;
//array<System::String^> ^RomFileName[MaxRomFile];
//unsigned long RomFileSize[MaxRomFile];

[STAThreadAttribute]

int main(array<System::String ^> ^args)
{
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
	Application::Run(gcnew frmMainDlg());
	return 0;
}
