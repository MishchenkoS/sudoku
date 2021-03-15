//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
extern Interface *interfaceSudoku;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
  interfaceSudoku->Form2Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
interfaceSudoku->SetFlagPause(false);
  Form1->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button1Click(TObject *Sender)
{
interfaceSudoku->AddGamer();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{

interfaceSudoku->DeleteGamer();
Form2->Label1->Caption = "ֳנאגוצü: " + interfaceSudoku->GetNameGamer();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button2Click(TObject *Sender)
{
 interfaceSudoku->SetNameGamer(Form2->StringGrid1->Cells[1][Form2->StringGrid1->Row]);
 Form2->Label1->Caption = "ֳנאגוצü: " + interfaceSudoku->GetNameGamer();
}
//---------------------------------------------------------------------------


