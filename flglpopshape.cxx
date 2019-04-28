
#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/gl.h>
#include <math.h>

//
// Demonstrate interpolating shapes
// erco 06/10/05
//

class Playback : public Fl_Gl_Window {
    int frame;
    // Linear interpolation between two values based on 'frac' (0.0=a, 1.0=b)
    float Linterp(float frac, float a, float b) {
        return( a + ( frac * (b - a) ));
    }
    // Sinusoidal easein/easeout interpolation between two values based on 'frac' (0.0=a, 1.0=b)
    float SinInterp(float frac, float a, float b) {
        float pi = 3.14159;
        frac = (sin(pi/2 + frac*pi ) + 1.0 ) / 2.0;     // 0 ~ 1 -> 0 ~ 1
        return(Linterp(frac,a,b));
    }
    // DRAW SIMPLE SHAPE INTERPOLATION
    //     Interpolation is based on the current frame number
    //
    void DrawShape(int frame) {
        // Calculate a fraction that represents the frame# being shown
        float frac = ( frame % 48 ) / 48.0 * 2;
        if ( frac > 1.0 ) frac = 2.0-frac;      // saw tooth wave:  "/\/\/\"

        static float a_xy[9][2] = {
            { -.5, -1. }, { 0.0, -.5 }, { -.5, -1. }, { 0.0, -.5 },
            { 0.0, 0.0 },
            { 0.0, -.5 }, { +.5, -1. }, { 0.0, -.5 }, { +.5, -1. },
        };
        static float b_xy[9][2] = {
            { -.25, -1. }, { -.50, -.75 }, { -.75, -1.0 }, { -.50, -.75 },
            { 0.0, 0.0 },
            { +.50, -.75 }, { +.75, -1.0 }, { +.50, -.75 }, { +.25, -1.0 }
        };
        // Linterp a and b to form new shape c
        float c_xy[9][2];
        for ( int i=0; i<9; i++ )
            for ( int xy=0; xy<2; xy++ )
                c_xy[i][xy] = SinInterp(frac, a_xy[i][xy], b_xy[i][xy]);
        // Draw shape
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINE_STRIP);
        for ( int i=0; i<9; i++ )
            glVertex2f(c_xy[i][0], c_xy[i][1]);
        glEnd();
    }
    // DRAW THE WIDGET
    //    Each time we're called, assume
    //
    void draw() {
        if (!valid()) {
            valid(1);
            glLoadIdentity();
            glViewport(0,0,w(),h());
        }
        glClear(GL_COLOR_BUFFER_BIT);
        // Draw shape 4x, rotated at 90 degree positions
        glPushMatrix();
            DrawShape(frame); glRotatef(90.0, 0, 0, 1);
            DrawShape(frame); glRotatef(90.0, 0, 0, 1);
            DrawShape(frame); glRotatef(90.0, 0, 0, 1);
            DrawShape(frame);
        glPopMatrix();
        // Advance frame counter
        ++frame;
    }
    // 24 FPS TIMER CALLBACK
    //     Called 24x per second to redraw the widget
    //
    static void Timer_CB(void *userdata) {
        Playback *pb = (Playback*)userdata;
        pb->redraw();
        Fl::repeat_timeout(1.0/24.0, Timer_CB, userdata);
    }
public:
    // Constructor
    Playback(int X,int Y,int W,int H,const char*L=0) : Fl_Gl_Window(X,Y,W,H,L) {
        frame = 0;
        Fl::add_timeout(1.0/24.0, Timer_CB, (void*)this);       // 24fps timer
        end();
    }
};

int main() {
     Fl_Window win(500, 500);
     Playback  playback(10, 10, win.w()-20, win.h()-20);
     win.resizable(&playback);
     win.show();
     return(Fl::run());
}