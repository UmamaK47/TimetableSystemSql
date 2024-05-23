#include "Main.h"

using namespace TimetableSystemSql;

[STAThreadAttribute]
int main() {

    Application::Run(gcnew Main());

    return 0;
}
/*
using namespace System;
using namespace System::Windows::Forms;

[STAThread] // Ensure the main function is marked with the STAThread attribute
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    TimetableSystemSql::Main^ form = gcnew TimetableSystemSql::Main(); // Create an instance of the form
    Application::Run(form);
}
*/
