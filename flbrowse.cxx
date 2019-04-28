#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_File_Browser.H>
//
// Demonstrate simple use of Fl_File_Browser with selection -- erco 6/4/11
//
int main(int argc, char **argv) {
    Fl_Window win(300, 400, "Fl_File_Browser");
        Fl_File_Browser fbrow(10,10,300-20,400-20);
        fbrow.load(".");                    // load directory listing of current directory
        fbrow.type(FL_HOLD_BROWSER);        // use for single selection
        //fbrow.type(FL_MULTI_BROWSER);     // use for multiple selection
    win.end();
    win.resizable(fbrow);
    win.show(argc,argv);
    return(Fl::run());
}