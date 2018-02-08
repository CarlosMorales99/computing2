//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ageKeyPress(TObject *Sender, char &Key)
{
    if((Key<'0'||Key>'9')&&Key!=8)Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::nameKeyPress(TObject *Sender, char &Key)
{
    if((Key<65||Key>90)&&(Key<97||Key>122)&&Key!=8&&Key!=' ')Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    name->SetFocus();
}
//---------------------------------------------------------------------------
