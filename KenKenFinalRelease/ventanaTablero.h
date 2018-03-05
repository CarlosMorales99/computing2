//---------------------------------------------------------------------------

#ifndef ventanaTableroH
#define ventanaTableroH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TPanel *P1;
        TButton *B1;
    TStringGrid *SG1;
    TTimer *Timer1;
    TLabel *L1;
	TButton *B2;
	TButton *B3;
	TButton *B4;
 /*	void __fastcall DG1DrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State); */
	void __fastcall SG1SelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall LE1KeyPress(TObject *Sender, char &Key);
	void __fastcall B1Click(TObject *Sender);
    void __fastcall SG1KeyPress(TObject *Sender, char &Key);
	void __fastcall SG1DrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
	void __fastcall B4Click(TObject *Sender);
	void __fastcall B2Click(TObject *Sender);
	void __fastcall B3Click(TObject *Sender);
private:	// User declarations
public:
	int x,y,m,s,clues;
        bool fl1,check;	// User declarations
    char labeled;
    __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
