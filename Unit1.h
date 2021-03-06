//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *HELP;
    TMenuItem *HowToPlay;
    TMenuItem *About1;
    TShape *background;
    TImage *ball;
    TImage *pOne;
    TImage *pTwo;
    TTimer *TimerBall;
    TTimer *RD;
    TTimer *RU;
    TTimer *LU;
    TTimer *LD;
    TMenuItem *Exit1;
    TButton *btnRestart;
    TButton *btnReset;
    TLabel *lblScore;
    TMenuItem *aboutMe;
    TMenuItem *link;
    void __fastcall TimerBallTimer(TObject *Sender);
    void __fastcall RUTimer(TObject *Sender);
    void __fastcall RDTimer(TObject *Sender);
    void __fastcall LUTimer(TObject *Sender);
    void __fastcall LDTimer(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall btnRestartClick(TObject *Sender);
    void __fastcall btnResetClick(TObject *Sender);
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall aboutMeClick(TObject *Sender);
    void __fastcall linkClick(TObject *Sender);
    void __fastcall HowToPlayClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
