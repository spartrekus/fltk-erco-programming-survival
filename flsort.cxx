#include <string.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Browser.H>
//
// Demo sorting an Fl_Browser with bubble sort
// erco 09/02/2005
//
void ForwardSort(Fl_Browser *b) {
    for ( int t=1; t<=b->size(); t++ ) {
        for ( int r=t+1; r<=b->size(); r++ ) {
            if ( strcmp(b->text(t), b->text(r)) > 0 ) {
                b->swap(t,r);
            }
        }
    }
}
void ReverseSort(Fl_Browser *b) {
    for ( int t=1; t<=b->size(); t++ ) {
        for ( int r=t+1; r<=b->size(); r++ ) {
            if ( strcmp(b->text(t), b->text(r)) < 0 ) {
                b->swap(t,r);
            }
        }
    }
}
void togglesort_cb(Fl_Widget *w, void*data) {
    Fl_Browser *b = (Fl_Browser*)data;
    if ( strcmp(w->label(), "Do Fwd Sort") == 0 ) {
        ForwardSort(b);
        w->label("Do Rev Sort");                // toggle
    } else {
        ReverseSort(b);
        w->label("Do Fwd Sort");                // toggle
    }
}
int main() {
    Fl_Window *win  = new Fl_Window(300,500,"Sort Example");
    Fl_Browser *b = new Fl_Browser(10,40,win->w()-20, win->h()-50);
    b->type(FL_MULTI_BROWSER);
    b->add("Papa");     b->add("Delta"); b->add("Hotel");
    b->add("Charlie");  b->add("Echo");  b->add("Foxtrot");
    b->add("Golf");     b->add("Lima");  b->add("Victor");
    b->add("Alpha");    b->add("Xray");  b->add("Yankee");
    b->add("Oscar");    b->add("India"); b->add("Juliet");
    b->add("Kilo");     b->add("Mike");  b->add("Sierra");
    b->add("November"); b->add("Tango"); b->add("Quebec");
    b->add("Bravo");    b->add("Romeo"); b->add("Uniform");
    b->add("Whisky");   b->add("Zulu");
    Fl_Button *butt = new Fl_Button(10,10,100,28,"Do Fwd Sort");
    butt->callback(togglesort_cb, (void*)b);
    win->show();
    return(Fl::run());
}