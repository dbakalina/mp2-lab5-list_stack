#include "MyForm.h"

#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Calculator::MyForm form;
    Application::Run(% form);

    return 0;
}