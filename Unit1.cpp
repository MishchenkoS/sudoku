//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//#include "Unit2.h"

#include <DateUtils.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
Interface *interfaceSudoku = new Interface();


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
  interfaceSudoku->NewGame(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  interfaceSudoku->FormOpen();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender)
{
  interfaceSudoku->NewGame(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)
{
  interfaceSudoku->NewGame(2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N9Click(TObject *Sender)
{
  interfaceSudoku->NewGame(3);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
  interfaceSudoku->DrawTable(ACol, ARow, Rect);
  interfaceSudoku->DrawCircuit();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
  if(interfaceSudoku->GetFlagStart() || interfaceSudoku->GetFlagFinish()){
    interfaceSudoku->SetFlagStart(true);
    interfaceSudoku->SetFlagFinish(false);
    interfaceSudoku->SetFlagPause(false);
    interfaceSudoku->printTable();
    Form1->StringGrid1->Visible = true;
    interfaceSudoku->SetCountHelp(0);
    interfaceSudoku->SetCountMistake(0);
    interfaceSudoku->SetSumaTimePause(0);
    interfaceSudoku->ShowHelp();
    interfaceSudoku->ShowMistake();
    if(interfaceSudoku->GetFlagTime()){
      interfaceSudoku->SetTimeGame(Now()+120./24/60/60 + ((120. * interfaceSudoku->GetDeffault())/24/60/60));
    } else {
      interfaceSudoku->SetTime(Now());
      Form1->StatusBar1->Panels->Items[0]->Text = Now() - interfaceSudoku->GetTime();
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
if(interfaceSudoku->GetFlagStart() && !interfaceSudoku->GetFlagPause()){
  interfaceSudoku->toHelp();
  interfaceSudoku->ShowHelp();
  interfaceSudoku->FinalGame();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1SetEditText(TObject *Sender, int ACol,
      int ARow, const AnsiString Value)
{
  interfaceSudoku->EditCells(ACol, ARow, Value);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGrid1KeyPress(TObject *Sender, char &Key)
{
 if(Key == 8)  {}
  else if(Key < '1' || Key > '9') Key = 0;
}
//---------------------------------------------------------------------------





void __fastcall TForm1::StringGrid1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
  CanSelect = interfaceSudoku->DenyInput(ARow,ACol) == false;
  if(interfaceSudoku->GetFEdited())
  {
    interfaceSudoku->SetFEdited(false);
    interfaceSudoku->toMistake();
    interfaceSudoku->ShowMistake();
    interfaceSudoku->FinalGameOut();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  if(interfaceSudoku->GetFlagTime()){
    if(!interfaceSudoku->GetFlagPause()) {
        interfaceSudoku->FinalGameOut();
        Form1->StatusBar1->Panels->Items[0]->Text = interfaceSudoku->GetTimeGame() - Now() + interfaceSudoku->GetSumaTimePause();

    } else {
      interfaceSudoku->SetSumaTimePause(interfaceSudoku->GetSumaTimePause() + 1./24/60/60);
    }
  } else {
    if(!interfaceSudoku->GetFlagPause()) {
      Form1->StatusBar1->Panels->Items[0]->Text = Now() - interfaceSudoku->GetTime() - interfaceSudoku->GetSumaTimePause();
    } else {
      interfaceSudoku->SetSumaTimePause(interfaceSudoku->GetSumaTimePause() + 1./24/60/60);
    }
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N3Click(TObject *Sender)
{
  interfaceSudoku->toBack();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
if(interfaceSudoku->GetFlagStart()){
  if(interfaceSudoku->GetFlagPause()) {
    Form1->StringGrid1->Visible = true;
    interfaceSudoku->SetFlagPause(false);
  } else {
    Form1->StringGrid1->Visible = false;
    interfaceSudoku->SetFlagPause(true);
  }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  const int result = Application->MessageBox("Ви бажаєте закінчити гру?", "Вихід",
    MB_YESNO | MB_ICONQUESTION);
  if( result == IDYES){
  delete interfaceSudoku;
    Action = true;
  } else {
    Action = false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
interfaceSudoku->SetFlagPause(true);
  interfaceSudoku->ShowRecord();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{
  Form1->Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N12Click(TObject *Sender)
{
  interfaceSudoku->NewGame(interfaceSudoku->RandDeffault());
  interfaceSudoku->SetFlagTime(true);
  interfaceSudoku->SetTimeGame(Now()+120./24/60/60 + ((120. * interfaceSudoku->GetDeffault())/24/60/60));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N13Click(TObject *Sender)
{
  interfaceSudoku->toBack();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N14Click(TObject *Sender)
{
  interfaceSudoku->toHelp();
  interfaceSudoku->ShowHelp();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N15Click(TObject *Sender)
{
  if(interfaceSudoku->GetFlagPause()) {
    Form1->StringGrid1->Visible = true;
    interfaceSudoku->SetFlagPause(false);
  } else {
    Form1->StringGrid1->Visible = false;
    interfaceSudoku->SetFlagPause(true);
  }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N16Click(TObject *Sender)
{
if(!interfaceSudoku->GetFlagStart()) {
  interfaceSudoku->SetFlagPause(true);
  Form2->Show();
  Form1->Hide();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
Form1->Label1->Caption = "Гравець: " + interfaceSudoku->GetNameGamer();        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
  if(interfaceSudoku->GetFlagStart() || interfaceSudoku->GetFlagFinish()){
    interfaceSudoku->printTable();
    Form1->StringGrid1->Visible = true;
    interfaceSudoku->SetCountHelp(0);
    interfaceSudoku->SetCountMistake(0);
    interfaceSudoku->ShowHelp();
    interfaceSudoku->ShowMistake();
    interfaceSudoku->SetTime(Now());
    Form1->StatusBar1->Panels->Items[0]->Text = Now() - interfaceSudoku->GetTime();
  }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
  interfaceSudoku->toBack();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
if(interfaceSudoku->GetFlagStart() && !interfaceSudoku->GetFlagPause()){
  interfaceSudoku->toHelp();
  interfaceSudoku->ShowHelp();
  interfaceSudoku->FinalGame();
  }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
  if(interfaceSudoku->GetFlagPause()) {
    Form1->StringGrid1->Visible = true;
    interfaceSudoku->SetFlagPause(false);
  } else {
    Form1->StringGrid1->Visible = false;
    interfaceSudoku->SetFlagPause(true);
  }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
  interfaceSudoku->ShowRecord();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton6Click(TObject *Sender)
{
if(interfaceSudoku->GetFlagStart()){
Form2->Show();
Form1->Hide();
}     
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton7Click(TObject *Sender)
{
  Form1->Close();          
}
//---------------------------------------------------------------------------

