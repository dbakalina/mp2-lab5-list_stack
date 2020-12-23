#include "MyForm.h"

#include <Windows.h>

using namespace Calculator;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

/*
using namespace System;
using namespace System::Windows::Forms;
 
[STAThread]
void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Calculator::MyForm form; 
    Application::Run(%form);
}*/