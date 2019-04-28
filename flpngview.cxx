#include <errno.h>
#include <FL/fl_ask.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Box.H>
// COMPILE: fltk-config --use-images --compile load-jpeg.cxx
int main() {
    fl_register_images();                       // initialize image lib
    Fl_Window     win(720,486);                 // make a window
    Fl_Box        box(10,10,720-20,486-20);     // widget that will contain image
    Fl_JPEG_Image jpg("/var/tmp/foo.jpg");      // load jpeg image into ram 
    // Error checking
    switch ( jpg.fail() ) {
	case Fl_Image::ERR_NO_IMAGE:
	case Fl_Image::ERR_FILE_ACCESS:
	    fl_alert("%s: %s", filename, strerror(errno));    // shows actual os error to user    
	    return 1;
	case Fl_Image::ERR_FORMAT:
	    fl_alert("%s: couldn't decode image", filename);
	    return 1;
    } 
    box.image(jpg);                             // attach jpg image to box
    win.show();
    return(Fl::run());
} 
