#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Float_Input.H>
//
// Demonstrate creating a table of widgets without Fl_Table
//                                                   --erco Mar 8 2005
#define COLS 9
#define ROWS 20
class RateTable : public Fl_Scroll {
    void *w[ROWS][COLS];        // widget pointers
public:
    RateTable(int X, int Y, int W, int H, const char*L=0) : Fl_Scroll(X,Y,W,H,L) {  
        static const char *header[COLS] = {
            "Time",    "In Rate", "Out Rate", "Coeff A",
            "Coeff B", "Coeff C", "Std Dev",  "Pkg In",  "Pkg Out"
        };
        int cellw = 80;
        int cellh = 25;
        int xx = X, yy = Y;
        Fl_Tile *tile = new Fl_Tile(X,Y,cellw*COLS,cellh*ROWS);
        // Create widgets
        for ( int r=0; r<ROWS; r++ ) {
            for ( int c=0; c<COLS; c++ ) {
                if ( r==0 ) {
                    Fl_Box *box = new Fl_Box(xx,yy,cellw,cellh,header[c]);
                    box->box(FL_BORDER_BOX);
                    w[r][c] = (void*)box;
                } else if ( c==0 ) {
                    Fl_Input *in = new Fl_Input(xx,yy,cellw,cellh);
                    in->box(FL_BORDER_BOX);
                    in->value("");
                    w[r][c] = (void*)in;
                } else {
                    Fl_Float_Input *in = new Fl_Float_Input(xx,yy,cellw,cellh);
                    in->box(FL_BORDER_BOX);
                    in->value("0.00");
                    w[r][c] = (void*)in;
                }
                xx += cellw;
            }
            xx = X;
            yy += cellh;
        }
        tile->end();
        end();
    }
};

int main() {
    Fl_Double_Window win(720,486);
    RateTable rate(10,10,720-20,486-20);
    win.resizable(win);
    win.show();
    return(Fl::run());
}