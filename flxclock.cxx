
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <stdio.h>
#include <time.h>
//
// Drop shadow example widget
// 1.0 erco 02/11/06
//
class DropShadowBox : public Fl_Box {
    int _levels;
    void draw() {
        Fl_Box::draw_box();
        if ( label() ) {
            // Draw label w/dropshadow effect
            fl_font(labelfont(), labelsize());
            int X = x() + Fl::box_dx(box());
            int Y = y() + Fl::box_dy(box());
            for ( int i=_levels; i>0; i-- ) {                           // loop through shades of color
                fl_color(fl_color_average(color(),                      // bg color (widget's bg)
                                          labelcolor(),                 // fg color (label)
                                          (i / (float)_levels)));       // weight between bg and fg color
                fl_draw(label(), X+i, Y+i, w(), h(), align());
            }
        }
    }
public:
    DropShadowBox(int X,int Y,int W,int H,const char*L=0) : Fl_Box(X,Y,W,H,L) {
        _levels = 5;
    }
    void levels(int val) { _levels = val; }
    int levels() { return(_levels); }
};
 
// Timer callback to update label
void Update_CB(void* userdata) {
    DropShadowBox *box = (DropShadowBox*)userdata;
    time_t lt = time(NULL);
    box->label(ctime(&lt));
    Fl::repeat_timeout(1.0, Update_CB, (void*)box);
}
 
int main() {
    Fl_Double_Window *win = new Fl_Double_Window(400, 100, "Drop Shadow Clock");
    DropShadowBox *box = new DropShadowBox(10, 10, win->w()-20, win->h()-20);
    box->labelsize(28);
    box->levels(8);
    Fl::add_timeout(1.0, Update_CB, (void*)box);
    win->show();
    Update_CB((void*)box);              // force update immediately
    return(Fl::run());
}