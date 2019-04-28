#include <stdio.h>
#include <FL/Fl_BMP_Image.H>

int main() {
    Fl_BMP_Image *img = new Fl_BMP_Image("tiny.bmp");
    if ( img->d() == 0 ) {
        perror("tiny.bmp");
        exit(1);
    }
    char r,g,b;
    for ( int y=0; y<img->h(); y++ ) {                               // X loop
        for ( int x=0; x<img->w(); x++ ) {                           // Y loop
            long index = (y * img->w() * img->d()) + (x * img->d()); // X/Y -> buf index  
            switch ( img->count() ) {
                case 1: {                                            // bitmap
                    const char *buf = img->data()[0];
                    switch ( img->d() ) {
                        case 1: {                                    // 8bit
                            r = g = b = *(buf+index);
                            break;
                        }
                        case 3:                                      // 24bit
                            r = *(buf+index+0);
                            g = *(buf+index+1);
                            b = *(buf+index+2);
                            break;
                        default:                                     // ??
                            printf("Not supported: chans=%d\n", img->d());
                            exit(1);
                    }
                    break;
                }
                default:                                             // ?? pixmap, bit vals
                    printf("Not supported: count=%d\n", img->count());
                    exit(1);
            }
            printf("%2x %2x %2x\n",                                  // hex dump r/g/b
                (unsigned char)r,
                (unsigned char)g,
                (unsigned char)b);
        }
    }
}
    