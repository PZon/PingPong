//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//ball moves
int x=-7,y=-7;
int rally=0, ptsOne=0, ptsTwo=0;
AnsiString strPtsOne, strPtsTwo;
int gTime=0;

bool winner(){
      char * alert;
      if(ptsOne>=7||ptsTwo>=7){
        if(ptsOne==7) alert="The winner is player <<< ONE <<< !!!";
        else if(ptsTwo==7) alert="The winner is player >>> TWO >>> !!!";
        Application->MessageBox(alert,"Victory", MB_OK);
        return true;
      }else return false;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
   ball->Left+=x;
   ball->Top+=y;
   if(ball->Top <= background->Top) y=-y;
   if(ball->Top+ball->Height >= background->Top+background->Height) y=-y;

   if(ball->Left<=background->Left){
            ptsTwo++;
            TimerBall->Enabled=false;
            ball->Visible=false;
            btnRestart->Caption="Player TWO wins point - restart";
            btnRestart->Visible=true;
            btnReset->Caption="Reset Game";
            btnReset->Visible=true;
   }else if(ball->Left+ball->Width>=background->Left+background->Width){
            ptsOne++;
            TimerBall->Enabled=false;
            ball->Visible=false;
            btnRestart->Caption="Player ONE wins point - restart";
            btnRestart->Visible=true;
            btnReset->Caption="Reset Game";
            btnReset->Visible=true;
   }
   
   if(ball->Left <= pOne->Left+pOne->Width &&
            ball->Top+ball->Height/2 >= pOne->Top &&
            ball->Top+ball->Height/2 <= pOne->Top+pOne->Height/2){
            if(y>0){x=-x;y=-y;}
            else x=-x;
            rally++;
   }else if(ball->Left <= pOne->Left+pOne->Width &&
            ball->Top+ball->Height/2 > pOne->Top+pOne->Height/2 &&
            ball->Top+ball->Height/2 <= pOne->Top+pOne->Height){
            if(y<0){x=-x;y=-y;}
            else x=-x;
            rally++;
   }else if(ball->Left+ball->Width >= pTwo->Left&&
            ball->Top+ball->Height/2 >= pTwo->Top &&
            ball->Top+ball->Height/2 <= pTwo->Top+pTwo->Height/2){
            if(y>0){x=-x;y=-y;}
            else x=-x;
            rally++;
   }else if(ball->Left+ball->Width >= pTwo->Left &&
            ball->Top+ball->Height/2 > pTwo->Top+pTwo->Height/2 &&
            ball->Top+ball->Height/2 <= pTwo->Top+pTwo->Height){
            if(y<0){x=-x;y=-y;}
            else x=-x;
            rally++;
   }
    strPtsOne=IntToStr(ptsOne);
    strPtsTwo=IntToStr(ptsTwo);
    lblScore->Caption=strPtsOne+" : "+strPtsTwo;

   if(winner()){
        btnReset->Visible=false;
        btnRestart->Caption="Victory - restart";
        btnRestart->Visible=true;
        TimerBall->Enabled=false;
        ball->Visible=false;
        ptsOne=0;
        ptsTwo=0;
    }

   //if(rally>0&&rally%2==0) {TimerBall->Interval=TimerBall->Interval+15;}
  //if(ball->Visible==false) Points->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RUTimer(TObject *Sender)
{
  if(pTwo->Top>=background->Top+10) pTwo->Top -=10;  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RDTimer(TObject *Sender)
{
  if(pTwo->Top+pTwo->Height<=background->Height-10) pTwo->Top +=10;  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LUTimer(TObject *Sender)
{
  if(pOne->Top>=background->Top+10)pOne->Top -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LDTimer(TObject *Sender)
{
  if(pOne->Top+pOne->Height<=background->Height-10) pOne->Top +=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key==VK_UP) RU->Enabled=true;
   if(Key==VK_DOWN) RD->Enabled=true;
   if(Key==0x41) LU->Enabled=true;
   if(Key==0x5A) LD->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key==VK_UP) RU->Enabled=false;
   if(Key==VK_DOWN) RD->Enabled=false;
   if(Key==0x41) LU->Enabled=false;
   if(Key==0x5A) LD->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnRestartClick(TObject *Sender)
{
  ball->Top=260;
  ball->Left=520;
  ball->Visible=true;
  pOne->Top=200;
  pTwo->Top=200;
  TimerBall->Enabled=true;

  btnRestart->Visible=false;
  btnReset->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnResetClick(TObject *Sender)
{
  ball->Top=260;
  ball->Left=520;
  ball->Visible=true;
  pOne->Top=200;
  pTwo->Top=200;
  TimerBall->Enabled=true;
  btnRestart->Visible=false;
  btnReset->Visible=false;
  ptsOne=0;
  ptsTwo=0;
  rally=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
   if(Application->MessageBox("Do you want to Exit Game?",
    "EXIT", MB_YESNO | MB_ICONWARNING)==IDYES){
     Application->Terminate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::aboutMeClick(TObject *Sender)
{
   Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::linkClick(TObject *Sender)
{
    ShellExecute(NULL, "open", "https://github.com/PZon/PingPong", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::HowToPlayClick(TObject *Sender)
{
  Form3->ShowModal();
}
//---------------------------------------------------------------------------

