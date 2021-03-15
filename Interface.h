#include "Sudoku.h"
#include <inifiles.hpp>
#include <time.h>

#ifndef SOME_UNIQUE_INTERFACE
#define SOME_UNIQUE_INTERFACE
class Interface : public Sudoku
{
  private:

    int countHelp;
    int countMistake;
    TDateTime timeStart;
    TDateTime sumaTimePause;
    TDateTime timeGame;
    int colLast;
    int rowLast;
    bool FlagStart;
    bool FlagFinish;
    int deffault;
    bool FEdited;
    bool FlagPause;
    bool FlagTime;
    AnsiString nameGamer;

  public:
    Interface()
    {
      InitInterface();
    }

    void InitInterface()
    {
      countHelp = 0;
      countMistake = 0;
      FlagStart = false;
      FEdited = false;
      FlagPause = false;
      FlagTime = false;
      FlagFinish = false;
      nameGamer = "deffault";
    }

    void printTable()
    {
      for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
          if(table[i][j] == 0) {
            Form1->StringGrid1->Cells[i][j] = "";
          } else {
            Form1->StringGrid1->Cells[i][j] = IntToStr(table[i][j]);
          }
        }
      }
    }

    void SetCountHelp(int cH)
    {
      countHelp = cH;
    }

    int GetCountHelp()
    {
      return countHelp;
    }

    void SetCountMistake(int cM)
    {
      countMistake = cM;
    }

    int GetCountMistake()
    {
      return countMistake;
    }

    void SetTime(TDateTime tS)
    {
      timeStart = tS;
    }

    TDateTime GetTime()
    {
      return timeStart;
    }

    void SetSumaTimePause(TDateTime sTP)
    {
      sumaTimePause = sTP;
    }

    TDateTime GetSumaTimePause()
    
    {
      return sumaTimePause;
    }

    void SetTimeGame(TDateTime tG)
    {
      timeGame = tG;
    }

    TDateTime GetTimeGame()
    {
      return timeGame;
    }

    void SetColLast(int cL)
    {
      colLast = cL;
    }

    int GetColLast()
    {
      return colLast;
    }

    void SetRowLast(int rL)
    {
      rowLast = rL;
    }

    int GetRowLast()
    {
      return rowLast;
    }

    void SetFlagStart(bool fS)
    {
      FlagStart = fS;
    }

    bool GetFlagStart()
    {
      return FlagStart;
    }

    void SetFlagFinish(bool fF)
    {
      FlagFinish = fF;
    }

    bool GetFlagFinish()
    {
      return FlagFinish;
    }

    void SetFEdited(bool FE)
    {
      FEdited = FE;
    }

    bool GetFEdited()
    {
      return FEdited;
    }

    void SetFlagPause(bool FP)
    {
      FlagPause = FP;
    }

    bool GetFlagPause()
    {
      return FlagPause;
    }

    void SetFlagTime(bool FT)
    {
      FlagTime = FT;
    }

    bool GetFlagTime()
    {
      return FlagTime;
    }

    void SetDeffault(int d)
    {
      deffault = d;
    }

    int GetDeffault()
    {
      return deffault;
    }

    void SetNameGamer(AnsiString nG)
    {
      nameGamer = nG;
    }

    AnsiString GetNameGamer()
    {
      return nameGamer;
    }


    void toHelp()
    {
      if(GetCountHelp()<3){
        bool flagTrue = true;
        int i, j;
        while(flagTrue){
          i = rand() % 9;
          j = rand() % 9;
          int flag = (i+1)*(j+1);
          while(flag <= 81){
              if(Form1->StringGrid1->Cells[i][j] == "") {
              Form1->StringGrid1->Cells[i][j] = IntToStr(tableSudoku[i][j]);
              flagTrue = false;
              break;
            }
            flag++;
            j = (j + 1) % 9;
            if (!j){
              i = (i + 1) % 9;
            }
          }
        }

        SetCountHelp(GetCountHelp()+1);
      }
    }

    void toMistake()
    {
      SetCountMistake(GetCountMistake()+1);
    }

    bool isTrueValue(int col, int row, int val)
    {
      if(tableSudoku[row][col] != val)
      {
        return false;
      }
      return true;
    }

    void DrawTable(int ACol, int ARow, TRect &Rect)
    {
      UINT uFormat = DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS;

      Form1->StringGrid1->Canvas->FillRect(Rect);
      DrawText(Form1->StringGrid1->Canvas->Handle,   // handle to device context
        Form1->StringGrid1->Cells[ACol][ARow].c_str(),    // pointer to string to draw
        Form1->StringGrid1->Cells[ACol][ARow].Length(),   // string length, in characters
        &Rect, // pointer to structure with formatting dimensions
        uFormat    // text-drawing flags
      );
    }

    void FormOpen()
    {
      srand(time(0));
      Form1->Height = 650;
      Form1->Width = 1000;
      Form1->StringGrid1->Visible = false;
      if(Form1->StringGrid1->Options.Contains(goEditing)) {
        Form1->StringGrid1->Options = Form1->StringGrid1->Options>>goEditing;
      }
      else {
        Form1->StringGrid1->Options = Form1->StringGrid1->Options<<goEditing;
      }
      Form1->Label1->Caption = "Гравець: " + GetNameGamer();
    }

    void DrawCircuit()
    {
      Form1->StringGrid1->Canvas->Pen->Color = clBlack;
      Form1->StringGrid1->Canvas->Pen->Width = 2;
      Form1->StringGrid1->Canvas->MoveTo(0,0);
      Form1->StringGrid1->Canvas->LineTo(0,368);
      Form1->StringGrid1->Canvas->MoveTo(0,368);
      Form1->StringGrid1->Canvas->LineTo(458,368);
      Form1->StringGrid1->Canvas->MoveTo(458,368);
      Form1->StringGrid1->Canvas->LineTo(458,0);
      Form1->StringGrid1->Canvas->LineTo(0,0);

      Form1->StringGrid1->Canvas->MoveTo(152,0);
      Form1->StringGrid1->Canvas->LineTo(152,368);
      Form1->StringGrid1->Canvas->MoveTo(306,0);
      Form1->StringGrid1->Canvas->LineTo(306,368);
      
      Form1->StringGrid1->Canvas->MoveTo(0,123);
      Form1->StringGrid1->Canvas->LineTo(460,123);
      Form1->StringGrid1->Canvas->MoveTo(0,246);
      Form1->StringGrid1->Canvas->LineTo(460,246);
    }

    void EditCells(int ACol, int ARow, const AnsiString Value)
    {

      if(table[ACol][ARow] != 0){
        Form1->StringGrid1->Cells[ACol][ARow] = table[ACol][ARow];
      } else{
      if (Form1->StringGrid1->Cells[ACol][ARow].Length() > 1) {
        Form1->StringGrid1->Cells[ACol][ARow] = Form1->StringGrid1->Cells[ACol][ARow].SubString(1,1);
      }

      if(Value != "" && isTrueValue(ARow, ACol, StrToInt(Value))) {
        isTrueValueDraw(ACol,ARow) ;
      } else if(Value == "" ){
        isTrueValueDraw(ACol,ARow) ;
      }  else if(!isTrueValue(ARow, ACol, StrToInt(Value))) {
        isFalseValueDraw(ACol,ARow) ;
        SetFEdited(true);
      }

      if(table[ACol][ARow] == 0){
        SetRowLast(ARow);
        SetColLast(ACol);
      }
      FinalGame();
      }
    }

    bool DenyInput(int row, int col)
    {
      if(table[col][row] == 0) {
        return false;
      }
      return true;
    }

    void isFalseValueDraw(int col, int row)
    {
      TRect Rect;
      Rect.Left = col * 50 + col - 1;
      Rect.Right = col * 50 + col + 52;
      Rect.Top = row * 40 + row - 1;
      Rect.Bottom = row * 40 + row + 42;
      Form1->StringGrid1->Canvas->Brush->Color=clRed;
      Form1->StringGrid1->Canvas->FillRect(Rect);
    }

    void isTrueValueDraw(int col, int row)
    {
      TRect Rect;
      Rect.Left = col * 50 + col - 1;
      Rect.Right = col * 50 + col + 52;
      Rect.Top = row * 40 + row - 1;
      Rect.Bottom = row * 40 + row + 42;
      Form1->StringGrid1->Canvas->Pen->Width = 1;
      Form1->StringGrid1->Canvas->Pen->Color = clScrollBar;
      Form1->StringGrid1->Canvas->Brush->Color=clScrollBar;
      Form1->StringGrid1->Canvas->FillRect(Rect);
    }

    void ShowMistake()
    {
      Form1->StatusBar1->Panels->Items[3]->Text = "Помилок: " +
        IntToStr(GetCountMistake()) + " / 3";
    }

    void ShowHelp()
    {
      Form1->StatusBar1->Panels->Items[2]->Text = "Підказок: " +
        IntToStr(GetCountHelp()) + " / 3";
    }

    void toBack()
    {
      if(table[GetColLast()][GetRowLast()] == 0) {
        Form1->StringGrid1->Cells[GetColLast()][GetRowLast()] = "";
        isTrueValueDraw(GetColLast(),GetRowLast()) ;
      }
    }

    void FinalGame()
    {
      int count = 0;
      for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
          if(Form1->StringGrid1->Cells[i][j] == tableSudoku[i][j])
          {
            count++;
          }
        }
        SetFlagFinish(true);
      }

      AnsiString str = "Ура!!! Ви перемогли!!!" + ShowRecordLevel() +
        "Ваш час: \n" + (Now() - GetTime() - GetSumaTimePause());

      if(count == 81)
      {
        RecordWrite();
        SetFlagPause(true);
        SetFlagStart(false);
        

        Application->MessageBox(str.c_str(),
        "Перемога!", MB_OK);
        Form1->StringGrid1->Visible = false;

      }
    }

    bool FinalGameOut()
    {
      TDateTime t = 0;
      if((GetCountMistake() >= 3) || ((GetFlagTime()) && (GetTimeGame() - Now() + GetSumaTimePause())<t))
      {
        Form1->StringGrid1->Visible = false;
        SetFlagPause(true);
        SetFlagStart(false);
        //SetFlagTime(false);
        Application->MessageBox("Шкода, але ви програли",
          "Програш", MB_OK);
      }
      SetFlagFinish(true);
    }

    AnsiString TypeGame(int type){
      switch(type){
        case 0:
          return "Легкий";
        case 1:
          return "Середній";
        case 2:
          return "Складний";
        case 3:
          return "Експертний";
        default:
          break;
      }
    }

    void NewGame(int n)
    {
      init();
      mix();
      SetDeffault(n);
      deleteCells(n);
      SetFlagStart(true);
      SetFlagTime(false);
      SetFlagPause(false);
      SetFlagFinish(false);
      Form1->StringGrid1->Visible = true;
      printTable();
      SetCountHelp(0);
      SetCountMistake(0);
      SetSumaTimePause(0);
      ShowHelp();
      ShowMistake();
      SetTime(Now());
      Form1->StatusBar1->Panels->Items[0]->Text = Now() - GetTime();
      Form1->StatusBar1->Panels->Items[1]->Text = TypeGame(GetDeffault());
    }

    void RecordWrite()
    {
      AnsiString timing = Now() - GetTime() - GetSumaTimePause();
      AnsiString record = GetNameGamer();
      AnsiString time;
      AnsiString hour1;
      AnsiString hour2;
      AnsiString min1;
      AnsiString min2;
      AnsiString sec1;
      AnsiString sec2;
      String path = ExtractFilePath(Application->ExeName);
      TIniFile *ini = new TIniFile(path+"\\Best.ini");
      time = ini->ReadString(record, IntToStr(GetDeffault()), "");
      if(time != ""){
        hour1 = time[1] + time[2];
        hour2 = timing[1] + timing[2];
        min1 = time[4] + time[5];
        min2 = timing[4] + timing[5];
        sec1 = time[7] + time[8];
        sec2 = timing[7] + timing[8];
      }

      if(time == "")  {
      ini->WriteString(record, GetDeffault(), timing);
        ini->UpdateFile();
      }  else{
      //||(StrToInt(hour2) <= StrToInt(hour1) ||
       //StrToInt(min2) <= StrToInt(min1) ||
       //StrToInt(sec2) <= StrToInt(sec1)))

      if(StrToInt(hour2) < StrToInt(hour1)){
        ini->WriteString(record, GetDeffault(), timing);
        ini->UpdateFile();
      } else if((StrToInt(hour2) == StrToInt(hour1)) && (StrToInt(min2) < StrToInt(min1))){
        ini->WriteString(record, GetDeffault(), timing);
        ini->UpdateFile();
      }else if((StrToInt(hour2) == StrToInt(hour1)) && (StrToInt(min2) == StrToInt(min1)) && (StrToInt(sec2) <= StrToInt(sec1)))
      {
        ini->WriteString(record, GetDeffault(), timing);
        ini->UpdateFile();
      }

      }
      delete ini;

    }

    void ShowRecord()
    {
      AnsiString records = "Ваші рекорди: \n";//?
      AnsiString record = GetNameGamer();
      String path = ExtractFilePath(Application->ExeName);
      TIniFile *ini = new TIniFile(path+"\\Best.ini");
      for(int i = 0; i < 4; i++){
        AnsiString time = ini->ReadString(record, IntToStr(i), "");
        if(time != ""){
          records += "Рекорд рівня \"" + TypeGame(i) + "\" :\n" + time + "\n";
        } else {
          records += "Рекорд рівня \"" + TypeGame(i) + "\" :\n Не встановлено \n";
        }
       }

       AnsiString name[4] = {"","","",""};
       AnsiString hour1[4];
       AnsiString hour2;
       AnsiString min1[4];
       AnsiString min2;
       AnsiString sec1[4];
       AnsiString sec2;


       TStringList *strIni = new TStringList;
       ini->ReadSections(strIni);

       for(int i = 0; i < 4; i++) {
         int j = 0;
         while(name[i] == "" && j < strIni->Count) {
           if(ini->ReadString(strIni->Strings[j], IntToStr(i), "") != "") {
             AnsiString str = ini->ReadString(strIni->Strings[j], IntToStr(i), "");
             name[i] = strIni->Strings[j];
             hour1[i] = IntToStr(StrToInt(str[1])) + IntToStr(StrToInt(str[2]));
             min1[i] = IntToStr(StrToInt(str[4])) + IntToStr(StrToInt(str[5]));
             sec1[i] = IntToStr(StrToInt(str[7])) + IntToStr(StrToInt(str[8]));
           }
           j++;
         }
       }

       for(int i = 0; i < 4; i++){
         for(int j = 0; j < strIni->Count; j++){
           if(ini->ReadString(strIni->Strings[j], IntToStr(i), "") != "" && name[i] != ""){

              AnsiString str = ini->ReadString(strIni->Strings[j], IntToStr(i), "");
              hour2 = IntToStr(StrToInt(str[1])) + IntToStr(StrToInt(str[2]));
              min2 = IntToStr(StrToInt(str[4])) + IntToStr(StrToInt(str[5]));
              sec2 = IntToStr(StrToInt(str[7])) + IntToStr(StrToInt(str[8]));
              //if(StrToInt(hour2) <= StrToInt(hour1[i]) &&
                 //StrToInt(min2) <= StrToInt(min1[i]) &&
                 //StrToInt(sec2) <= StrToInt(sec1[i]))
              if(StrToInt(hour2) < StrToInt(hour1[i])){
                 name[i] = strIni->Strings[j];
                 hour1[i] = hour2;
                 min1[i] = min2;
                 sec1[i] = sec2;
              } else if((StrToInt(hour2) == StrToInt(hour1[i])) && (StrToInt(min2) < StrToInt(min1[i]))){
                 name[i] = strIni->Strings[j];
                 hour1[i] = hour2;
                 min1[i] = min2;
                 sec1[i] = sec2;
              } else if((StrToInt(hour2) == StrToInt(hour1[i])) && (StrToInt(min2) == StrToInt(min1[i])) && (StrToInt(sec2) <= StrToInt(sec1[i])))
              {
                 name[i] = strIni->Strings[j];
                 hour1[i] = hour2;
                 min1[i] = min2;
                 sec1[i] = sec2;
              }
           }
         }
       }
      records += "\n\n Загальні рекорди: \n";

      for(int i = 0; i <= 3; i++){
        if(name[i] != ""){
          records += "Рекорд рівня \"" + TypeGame(i) + "\" :\n" + name[i] + ":\n" +
          hour1[i]+":"+ min1[i] + ":"+sec1[i]+"\n";
        } else {
          records += "Рекорд рівня \"" + TypeGame(i) + "\" :\n Не встановлено \n";
        }

      }
      MessageBox(NULL, records.c_str(),
        "Рекорди!", MB_OK);
      SetFlagPause(false);
      delete ini;
      delete strIni;
     }

    AnsiString ShowRecordLevel()
    {
      AnsiString records = "";
      AnsiString record = GetNameGamer();
      String path = ExtractFilePath(Application->ExeName);
      TIniFile *ini = new TIniFile(path+"\\Best.ini");
      AnsiString time = ini->ReadString(record, IntToStr(GetDeffault()), "");
      delete ini;
      if(time != ""){
        return records = "\nРекорд рівня \"" + TypeGame(GetDeffault())  + "\" :\n" + time + "\n";
      } else {
        return records;
      }
    }

     int RandDeffault()
     {
       return (rand() % 4);
     }

     void Form2Open()
     {
       Form2->StringGrid1->ColWidths[1] = 650;
       Form2->StringGrid1->Cells[0][0] = "№";
       Form2->StringGrid1->Cells[1][0] = "Ім\'я гравця";
       Form2->Label1->Caption = "Гравець: " + GetNameGamer();
       String path = ExtractFilePath(Application->ExeName);
       TIniFile *ini = new TIniFile(path+"\\Best.ini");
       TStringList *strIni = new TStringList;
       ini->ReadSections(strIni);
       Form2->StringGrid1->RowCount = strIni->Count + 1;
       for(int i=1; i <= strIni->Count; i++){
         Form2->StringGrid1->Cells[0][i] = IntToStr(i);
         Form2->StringGrid1->Cells[1][i] = strIni->Strings[i-1];
       }

       delete strIni;
       delete ini;
     }

     void AddGamer()
     {
       AnsiString str = Form2->Edit1->Text;
       str = str.TrimLeft();

       if(!str.IsEmpty()){
         String path = ExtractFilePath(Application->ExeName);
         TIniFile *ini = new TIniFile(path+"\\Best.ini");
         TStringList *strIni = new TStringList;
         ini->ReadSections(strIni);
         bool check = false;

         for(int i=0; i < strIni->Count; i++){
           if(strIni->Strings[i] == Form2->Edit1->Text){
             check = true;
           }
         }
         if(!check) {
           ini->WriteString(Form2->Edit1->Text," "," ");
           Form2->StringGrid1->RowCount = Form2->StringGrid1->RowCount + 1;
           Form2->StringGrid1->Cells[0][Form2->StringGrid1->RowCount-1] = Form2->StringGrid1->RowCount;
           Form2->StringGrid1->Cells[1][Form2->StringGrid1->RowCount-1] = Form2->Edit1->Text;
           ini->DeleteKey(Form2->Edit1->Text, " ");
         } else {
           ShowMessage("Таке ім\'я уже існує");
         }
         Form2->Edit1->Text = "";
         delete strIni;
         delete ini;
       }

     }

     void DeleteGamer()
     {
       AnsiString str = "Ви бажаєте видалити гравця "+ Form2->StringGrid1->Cells[1][Form2->StringGrid1->Row] +" ?";
       const int result = Application->MessageBox(
          str.c_str(),
          "Видалення",
          MB_YESNO | MB_ICONQUESTION
        );
        if(result == IDYES){
       if(Form2->StringGrid1->Cells[1][Form2->StringGrid1->Row] != "deffault"){
       String path = ExtractFilePath(Application->ExeName);
       TIniFile *ini = new TIniFile(path+"\\Best.ini");
       TStringList *strIni = new TStringList;
       ini->EraseSection(Form2->StringGrid1->Cells[1][Form2->StringGrid1->Row]);
       ini->ReadSections(strIni);
       Form2->StringGrid1->RowCount = strIni->Count + 1;
       for(int i=1; i <= strIni->Count; i++){
         Form2->StringGrid1->Cells[0][i] = IntToStr(i);
         Form2->StringGrid1->Cells[1][i] = strIni->Strings[i-1];
       }
       SetNameGamer("deffault");
       delete strIni;
       delete ini;
       } else {
         ShowMessage("Ви не можете видалит гравця deffault");
       }
       }
     }

};

#endif


