// DEMONSTRATE HOW TO DRAW AN 'X' IN FLTK
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>

// SIMPLE WIDGET THAT DRAWS AN 'X'
class DrawX : public Fl_Widget {
public:
    DrawX(int X, int Y, int W, int H, const char*L=0) : Fl_Widget(X,Y,W,H,L) {
    }
    void draw() {
        // DRAW BLACK 'X'
        fl_color(FL_BLACK);
        int x1 = x(),       y1 = y();
        int x2 = x()+w()-1, y2 = y()+h()-1;
        fl_line(x1, y1, x2, y2);
        fl_line(x1, y2, x2, y1);
    }
};
int main() {
    Fl_Double_Window win(200,200,"Draw X");
    DrawX draw_x(0, 0, win.w(), win.h());
    win.resizable(draw_x);
    win.show();
    return(Fl::run());
}
   