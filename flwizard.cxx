#include <stdlib.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Wizard.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Multiline_Output.H>

// Simple 'wizard' using fltk's new Fl_Wizard widget

Fl_Window *G_win = 0;
Fl_Wizard *G_wiz = 0;

void back_cb(Fl_Widget*,void*) { G_wiz->prev(); }
void next_cb(Fl_Widget*,void*) { G_wiz->next(); }
void done_cb(Fl_Widget*,void*) { exit(0); }

int main(int argc, char **argv) {
    G_win = new Fl_Window(400,300,"Example Wizard");
    G_wiz = new Fl_Wizard(0,0,400,300);

    // Wizard: page 1
    {
        Fl_Group *g = new Fl_Group(0,0,400,300);
        Fl_Button *next = new Fl_Button(290,265,100,25,"Next"); next->callback(next_cb);
        Fl_Multiline_Output *out = new Fl_Multiline_Output(10,30,400-20,300-80,"Welcome");
        out->labelsize(20);
        out->align(FL_ALIGN_TOP|FL_ALIGN_LEFT);
        out->value("This is First page");
        g->end();
    }
    // Wizard: page 2
    {
        Fl_Group *g = new Fl_Group(0,0,400,300);
        Fl_Button *next = new Fl_Button(290,265,100,25,"Next"); next->callback(next_cb);
        Fl_Button *back = new Fl_Button(180,265,100,25,"Back"); back->callback(back_cb);
        Fl_Multiline_Output *out = new Fl_Multiline_Output(10,30,400-20,300-80,"Terms And Conditions");
        out->labelsize(20);
        out->align(FL_ALIGN_TOP|FL_ALIGN_LEFT);
        out->value("This is the Second page");
        g->end();
    }
    // Wizard: page 3
    {
        Fl_Group *g = new Fl_Group(0,0,400,300);
        Fl_Button *done = new Fl_Button(290,265,100,25,"Finish"); done->callback(done_cb);
        Fl_Button *back = new Fl_Button(180,265,100,25,"Back"); back->callback(back_cb);
        Fl_Multiline_Output *out = new Fl_Multiline_Output(10,30,400-20,300-80,"Finish");
        out->labelsize(20);
        out->align(FL_ALIGN_TOP|FL_ALIGN_LEFT);
        out->value("This is the Last page");
        g->end();
    }
    G_wiz->end();
    G_win->end();
    G_win->show(argc, argv);
    return Fl::run();
}
    