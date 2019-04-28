// Fl_Text_Display example. -erco
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Text_Display.H>

int main() {
     Fl_Window *win = new Fl_Window(640, 480);
     Fl_Text_Buffer *buff = new Fl_Text_Buffer();
     Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640-40, 480-40, "Display");
     disp->buffer(buff);
     win->resizable(*disp);
     win->show();
     buff->text("line 0\nline 1\nline 2\n"
                "line 3\nline 4\nline 5\n"
                "line 6\nline 7\nline 8\n"
                "line 9\nline 10\nline 11\n"
                "line 12\nline 13\nline 14\n"
                "line 15\nline 16\nline 17\n"
                "line 18\nline 19\nline 20\n"
                "line 21\nline 22\nline 23\n");
     return(Fl::run());
}