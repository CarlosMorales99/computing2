//---------------------------------------------------------------------------

#ifndef ventanaPrincipalH
#define ventanaPrincipalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ActnCtrls.hpp>
#include <ActnMan.hpp>
#include <ActnMenus.hpp>
#include <ToolWin.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <fstream.h>
#include <vcl.h>
#include <ComCtrls.hpp>     //Para cargar los string grids
#include <memory>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *T1;
    TMenuItem *T4;
    TMenuItem *T5;
    TMenuItem *T11;
    TMenuItem *T12;
    TMenuItem *T1_N;
    TMenuItem *T13;
    TMenuItem *T13_3;
    TMenuItem *T13_4;
    TMenuItem *T13_5;
    TMenuItem *T13_6;
    TMenuItem *T13_7;
    TMenuItem *T13_8;
    TMenuItem *T13_9;
    TMenuItem *T13_S;
	TImage *I1;
    TPanel *P1;
    TProgressBar *PB1;
    TLabel *Label1;
    void __fastcall T13_3Click(TObject *Sender);
    void __fastcall T13_4Click(TObject *Sender);
    void __fastcall T13_5Click(TObject *Sender);
    void __fastcall T13_6Click(TObject *Sender);
    void __fastcall T13_7Click(TObject *Sender);
    void __fastcall T13_8Click(TObject *Sender);
    void __fastcall T13_9Click(TObject *Sender);
    void __fastcall T11Click(TObject *Sender);
	void __fastcall T4Click(TObject *Sender);
	void __fastcall T5Click(TObject *Sender);
	void __fastcall T12Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
    int nivel,tablero[9][9],agrup[9][9],cantAgrup,colors[81],sqAgrup[81];
    char sucess,operations[81];
    int results[81];
    bool cargar;
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
