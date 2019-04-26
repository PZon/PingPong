//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//ball moves
int x=-13,y=-13;
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

   if((ball->Left <= pOne->Left+pOne->Width)||(ball->Left+ball->Width >= pTwo->Left)){
    TimerBall->Enabled=false;
    ball->Visible=false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RUTimer(TObject *Sender)
{
  pTwo->Top -=10;  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RDTimer(TObject *Sender)
{
  pTwo->Top +=10;  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LUTimer(TObject *Sender)
{
  pOne->Top -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LDTimer(TObject *Sender)
{
  pOne->Top +=10;
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
