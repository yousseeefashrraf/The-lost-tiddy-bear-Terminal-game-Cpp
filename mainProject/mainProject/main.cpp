
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <cstdio> // Include for getchar()
#include <unistd.h>

using namespace std;


struct Hero {
    int rherob;
    int rheroe;
    int cherob;
    int cheroe;
    int flagGump;
    int ctJump;
    int IsNoObstacle;
    int flagGumpRight;
    int flagGumpLft;
    int dir;
    int flagShooting;
    int isWalking;
    int ctLostBullets;
    int jumpFrames;
    int walkingFrames;
    int flagInElevator;
    int health;
    int inAirplane;
    int inLadder;
    int walkingFrames2;
};
struct Hero2{
    int r;
    int c;
};
struct Bullet{
    int rBullet;
    int cBullet;
    int dir;
    int stopBullet;
};
struct Elevator{
    int rb;
    int rStand;
    int cb;
    int cStand;
    int frames;
    int dir;

};
struct Laser{
    int frames;
    int dir;
    int LRowE;
    int LRowE2;
 
};
struct Bat {
    int r;
    int c;
    int health;
    int dir;
    int frames;
    int rBullet;
    int cBullet;
};

struct Enemy{
    int rb;

    int cb;
    int dir;
    int frames;
    int health;
    
};

struct Snail{
    int rb;
    int cb;
    int cEndOfMove;
    int frames;
    int health;
    
};

bool kbhit() {
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}
void setNonCanonicalMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
// Function to restore terminal attributes
void restoreTerminalSettings() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void drawFixedGround(wchar_t x[][1190])
{

    //set fixed objects
    //Set ground
    int r=148-4;
    int c=0;
    
    int i;
    
    for(;;){
        for(i=0;i<33;i++){
          x[r+0][c+1+i]='-';
         }
       x[r+1][c+0]='|';
       x[r+1][c+1]='_';
       x[r+1][c+2]='|';
        for(i=0;i<3;i++){
          x[r+1][c+3+i]='_';
         }
       x[r+1][c+6]='|';
        for(i=0;i<7;i++){
          x[r+1][c+7+i]='_';
         }
       x[r+1][c+14]='|';
        for(i=0;i<2;i++){
          x[r+1][c+15+i]='_';
         }
       x[r+1][c+17]='|';
        for(i=0;i<3;i++){
          x[r+1][c+18+i]='_';
         }
       x[r+1][c+21]='|';
        for(i=0;i<2;i++){
          x[r+1][c+22+i]='_';
         }
       x[r+1][c+24]='|';
        for(i=0;i<4;i++){
          x[r+1][c+25+i]='_';
         }
       x[r+1][c+29]='|';
        for(i=0;i<4;i++){
          x[r+1][c+30+i]='_';
         }
       x[r+2][c+0]='|';
       x[r+2][c+1]='_';
       x[r+2][c+2]='|';
        for(i=0;i<4;i++){
          x[r+2][c+3+i]='_';
         }
       x[r+2][c+7]='|';
        for(i=0;i<2;i++){
          x[r+2][c+8+i]='_';
         }
       x[r+2][c+10]='|';
        for(i=0;i<2;i++){
          x[r+2][c+11+i]='_';
         }
       x[r+2][c+13]='|';
        for(i=0;i<3;i++){
          x[r+2][c+14+i]='_';
         }
       x[r+2][c+17]='|';
        for(i=0;i<4;i++){
          x[r+2][c+18+i]='_';
         }
       x[r+2][c+22]='|';
        for(i=0;i<4;i++){
          x[r+2][c+23+i]='_';
         }
       x[r+2][c+27]='|';
        for(i=0;i<4;i++){
          x[r+2][c+28+i]='_';
         }
       x[r+2][c+32]='|';
       x[r+2][c+33]='_';
       x[r+3][c+0]='|';
       x[r+3][c+1]='_';
       x[r+3][c+2]='|';
        for(i=0;i<4;i++){
          x[r+3][c+3+i]='_';
         }
       x[r+3][c+7]='|';
        for(i=0;i<2;i++){
          x[r+3][c+8+i]='_';
         }
       x[r+3][c+10]='|';
        for(i=0;i<2;i++){
          x[r+3][c+11+i]='_';
         }
       x[r+3][c+13]='|';
        for(i=0;i<3;i++){
          x[r+3][c+14+i]='_';
         }
       x[r+3][c+17]='|';
        for(i=0;i<4;i++){
          x[r+3][c+18+i]='_';
         }
       x[r+3][c+22]='|';
        for(i=0;i<3;i++){
          x[r+3][c+23+i]='_';
         }
       x[r+3][c+26]='|';
        for(i=0;i<4;i++){
          x[r+3][c+27+i]='_';
         }
       x[r+3][c+31]='|';
        for(i=0;i<2;i++){
          x[r+3][c+32+i]='_';
         }
        break;
    }
        for(c=34;c<1190-34*14;c+=34){
            for(i=0;i<34;i++){
              x[r+0][c+0+i]='-';
             }
           x[r+1][c+0]='_';
           x[r+1][c+1]='|';
            for(i=0;i<3;i++){
              x[r+1][c+2+i]='_';
             }
           x[r+1][c+5]='|';
            for(i=0;i<7;i++){
              x[r+1][c+6+i]='_';
             }
           x[r+1][c+13]='|';
            for(i=0;i<2;i++){
              x[r+1][c+14+i]='_';
             }
           x[r+1][c+16]='|';
            for(i=0;i<3;i++){
              x[r+1][c+17+i]='_';
             }
           x[r+1][c+20]='|';
            for(i=0;i<2;i++){
              x[r+1][c+21+i]='_';
             }
           x[r+1][c+23]='|';
            for(i=0;i<4;i++){
              x[r+1][c+24+i]='_';
             }
           x[r+1][c+28]='|';
            for(i=0;i<3;i++){
              x[r+1][c+29+i]='_';
             }
           x[r+1][c+32]='|';
           x[r+1][c+33]='_';
           x[r+2][c+0]='_';
           x[r+2][c+1]='|';
            for(i=0;i<4;i++){
              x[r+2][c+2+i]='_';
             }
           x[r+2][c+6]='|';
            for(i=0;i<2;i++){
              x[r+2][c+7+i]='_';
             }
           x[r+2][c+9]='|';
            for(i=0;i<2;i++){
              x[r+2][c+10+i]='_';
             }
           x[r+2][c+12]='|';
            for(i=0;i<3;i++){
              x[r+2][c+13+i]='_';
             }
           x[r+2][c+16]='|';
            for(i=0;i<4;i++){
              x[r+2][c+17+i]='_';
             }
           x[r+2][c+21]='|';
            for(i=0;i<4;i++){
              x[r+2][c+22+i]='_';
             }
           x[r+2][c+26]='|';
            for(i=0;i<3;i++){
              x[r+2][c+27+i]='_';
             }
           x[r+2][c+30]='|';
            for(i=0;i<3;i++){
              x[r+2][c+31+i]='_';
             }
           x[r+3][c+0]='_';
           x[r+3][c+1]='|';
            for(i=0;i<5;i++){
              x[r+3][c+2+i]='_';
             }
           x[r+3][c+7]='|';
            for(i=0;i<2;i++){
              x[r+3][c+8+i]='_';
             }
           x[r+3][c+10]='|';
            for(i=0;i<2;i++){
              x[r+3][c+11+i]='_';
             }
           x[r+3][c+13]='|';
            for(i=0;i<3;i++){
              x[r+3][c+14+i]='_';
             }
           x[r+3][c+17]='|';
            for(i=0;i<4;i++){
              x[r+3][c+18+i]='_';
             }
           x[r+3][c+22]='|';
            for(i=0;i<2;i++){
              x[r+3][c+23+i]='_';
             }
           x[r+3][c+25]='|';
            for(i=0;i<3;i++){
              x[r+3][c+26+i]='_';
             }
           x[r+3][c+29]='|';
            for(i=0;i<2;i++){
              x[r+3][c+30+i]='_';
             }
           x[r+3][c+32]='|';
           x[r+3][c+33]='_';
        }
    
    for(r=148;r<222-4;r+=4){
        for(c=34;c<1190-34*14;c+=34){
            x[r+0][c+0]='_';
            x[r+0][c+1]='|';
             for(i=0;i<3;i++){
               x[r+0][c+2+i]='_';
              }
            x[r+0][c+5]='|';
             for(i=0;i<7;i++){
               x[r+0][c+6+i]='_';
              }
            x[r+0][c+13]='|';
             for(i=0;i<2;i++){
               x[r+0][c+14+i]='_';
              }
            x[r+0][c+16]='|';
             for(i=0;i<3;i++){
               x[r+0][c+17+i]='_';
              }
            x[r+0][c+20]='|';
             for(i=0;i<2;i++){
               x[r+0][c+21+i]='_';
              }
            x[r+0][c+23]='|';
             for(i=0;i<4;i++){
               x[r+0][c+24+i]='_';
              }
            x[r+0][c+28]='|';
             for(i=0;i<3;i++){
               x[r+0][c+29+i]='_';
              }
            x[r+0][c+32]='|';
            x[r+0][c+33]='_';
            x[r+1][c+0]='_';
            x[r+1][c+1]='|';
             for(i=0;i<4;i++){
               x[r+1][c+2+i]='_';
              }
            x[r+1][c+6]='|';
             for(i=0;i<2;i++){
               x[r+1][c+7+i]='_';
              }
            x[r+1][c+9]='|';
             for(i=0;i<2;i++){
               x[r+1][c+10+i]='_';
              }
            x[r+1][c+12]='|';
             for(i=0;i<3;i++){
               x[r+1][c+13+i]='_';
              }
            x[r+1][c+16]='|';
             for(i=0;i<4;i++){
               x[r+1][c+17+i]='_';
              }
            x[r+1][c+21]='|';
             for(i=0;i<4;i++){
               x[r+1][c+22+i]='_';
              }
            x[r+1][c+26]='|';
             for(i=0;i<3;i++){
               x[r+1][c+27+i]='_';
              }
            x[r+1][c+30]='|';
             for(i=0;i<3;i++){
               x[r+1][c+31+i]='_';
              }
            x[r+2][c+0]='_';
            x[r+2][c+1]='|';
             for(i=0;i<5;i++){
               x[r+2][c+2+i]='_';
              }
            x[r+2][c+7]='|';
             for(i=0;i<2;i++){
               x[r+2][c+8+i]='_';
              }
            x[r+2][c+10]='|';
             for(i=0;i<2;i++){
               x[r+2][c+11+i]='_';
              }
            x[r+2][c+13]='|';
             for(i=0;i<3;i++){
               x[r+2][c+14+i]='_';
              }
            x[r+2][c+17]='|';
             for(i=0;i<4;i++){
               x[r+2][c+18+i]='_';
              }
            x[r+2][c+22]='|';
             for(i=0;i<2;i++){
               x[r+2][c+23+i]='_';
              }
            x[r+2][c+25]='|';
             for(i=0;i<3;i++){
               x[r+2][c+26+i]='_';
              }
            x[r+2][c+29]='|';
             for(i=0;i<2;i++){
               x[r+2][c+30+i]='_';
              }
            x[r+2][c+32]='|';
            x[r+2][c+33]='_';
            x[r+3][c+0]='_';
            x[r+3][c+1]='|';
             for(i=0;i<4;i++){
               x[r+3][c+2+i]='_';
              }
            x[r+3][c+6]='|';
             for(i=0;i<2;i++){
               x[r+3][c+7+i]='_';
              }
            x[r+3][c+9]='|';
             for(i=0;i<2;i++){
               x[r+3][c+10+i]='_';
              }
            x[r+3][c+12]='|';
             for(i=0;i<3;i++){
               x[r+3][c+13+i]='_';
              }
            x[r+3][c+16]='|';
             for(i=0;i<4;i++){
               x[r+3][c+17+i]='_';
              }
            x[r+3][c+21]='|';
             for(i=0;i<4;i++){
               x[r+3][c+22+i]='_';
              }
            x[r+3][c+26]='|';
             for(i=0;i<3;i++){
               x[r+3][c+27+i]='_';
              }
            x[r+3][c+30]='|';
             for(i=0;i<3;i++){
               x[r+3][c+31+i]='_';
              }
        }
    }
    //to make the ground even
        r=222-4;
    
    for(c=34;c<1190-34*14;c+=34){
        x[r+0][c+0]='_';
        x[r+0][c+1]='|';
         for(i=0;i<3;i++){
           x[r+0][c+2+i]='_';
          }
        x[r+0][c+5]='|';
         for(i=0;i<7;i++){
           x[r+0][c+6+i]='_';
          }
        x[r+0][c+13]='|';
         for(i=0;i<2;i++){
           x[r+0][c+14+i]='_';
          }
        x[r+0][c+16]='|';
         for(i=0;i<3;i++){
           x[r+0][c+17+i]='_';
          }
        x[r+0][c+20]='|';
         for(i=0;i<2;i++){
           x[r+0][c+21+i]='_';
          }
        x[r+0][c+23]='|';
         for(i=0;i<4;i++){
           x[r+0][c+24+i]='_';
          }
        x[r+0][c+28]='|';
         for(i=0;i<3;i++){
           x[r+0][c+29+i]='_';
          }
        x[r+0][c+32]='|';
        x[r+0][c+33]='_';
        x[r+1][c+0]='_';
        x[r+1][c+1]='|';
         for(i=0;i<4;i++){
           x[r+1][c+2+i]='_';
          }
        x[r+1][c+6]='|';
         for(i=0;i<2;i++){
           x[r+1][c+7+i]='_';
          }
        x[r+1][c+9]='|';
         for(i=0;i<2;i++){
           x[r+1][c+10+i]='_';
          }
        x[r+1][c+12]='|';
         for(i=0;i<3;i++){
           x[r+1][c+13+i]='_';
          }
        x[r+1][c+16]='|';
         for(i=0;i<4;i++){
           x[r+1][c+17+i]='_';
          }
        x[r+1][c+21]='|';
         for(i=0;i<4;i++){
           x[r+1][c+22+i]='_';
          }
        x[r+1][c+26]='|';
         for(i=0;i<3;i++){
           x[r+1][c+27+i]='_';
          }
        x[r+1][c+30]='|';
         for(i=0;i<3;i++){
           x[r+1][c+31+i]='_';
          }
        x[r+2][c+0]='_';
        x[r+2][c+1]='|';
         for(i=0;i<5;i++){
           x[r+2][c+2+i]='_';
          }
        x[r+2][c+7]='|';
         for(i=0;i<2;i++){
           x[r+2][c+8+i]='_';
          }
        x[r+2][c+10]='|';
         for(i=0;i<2;i++){
           x[r+2][c+11+i]='_';
          }
        x[r+2][c+13]='|';
         for(i=0;i<3;i++){
           x[r+2][c+14+i]='_';
          }
        x[r+2][c+17]='|';
         for(i=0;i<4;i++){
           x[r+2][c+18+i]='_';
          }
        x[r+2][c+22]='|';
         for(i=0;i<2;i++){
           x[r+2][c+23+i]='_';
          }
        x[r+2][c+25]='|';
         for(i=0;i<3;i++){
           x[r+2][c+26+i]='_';
          }
        x[r+2][c+29]='|';
         for(i=0;i<2;i++){
           x[r+2][c+30+i]='_';
          }
        x[r+2][c+32]='|';
        x[r+2][c+33]='_';
        x[r+3][c+0]='_';
        x[r+3][c+1]='|';
         for(i=0;i<4;i++){
           x[r+3][c+2+i]='_';
          }
        x[r+3][c+6]='|';
         for(i=0;i<2;i++){
           x[r+3][c+7+i]='_';
          }
        x[r+3][c+9]='|';
         for(i=0;i<2;i++){
           x[r+3][c+10+i]='_';
          }
        x[r+3][c+12]='|';
         for(i=0;i<3;i++){
           x[r+3][c+13+i]='_';
          }
        x[r+3][c+16]='|';
         for(i=0;i<4;i++){
           x[r+3][c+17+i]='_';
          }
        x[r+3][c+21]='|';
         for(i=0;i<4;i++){
           x[r+3][c+22+i]='_';
          }
        x[r+3][c+26]='|';
         for(i=0;i<3;i++){
           x[r+3][c+27+i]='_';
          }
        x[r+3][c+30]='|';
         for(i=0;i<3;i++){
           x[r+3][c+31+i]='_';
          }
    }
    int z=c;

    
   
        for(c=1190-34;z<=c;c-=34){
            for(i=0;i<34;i++){
              x[r+0][c+0+i]='-';
             }
           x[r+1][c+0]='_';
           x[r+1][c+1]='|';
            for(i=0;i<3;i++){
              x[r+1][c+2+i]='_';
             }
           x[r+1][c+5]='|';
            for(i=0;i<7;i++){
              x[r+1][c+6+i]='_';
             }
           x[r+1][c+13]='|';
            for(i=0;i<2;i++){
              x[r+1][c+14+i]='_';
             }
           x[r+1][c+16]='|';
            for(i=0;i<3;i++){
              x[r+1][c+17+i]='_';
             }
           x[r+1][c+20]='|';
            for(i=0;i<2;i++){
              x[r+1][c+21+i]='_';
             }
           x[r+1][c+23]='|';
            for(i=0;i<4;i++){
              x[r+1][c+24+i]='_';
             }
           x[r+1][c+28]='|';
            for(i=0;i<3;i++){
              x[r+1][c+29+i]='_';
             }
           x[r+1][c+32]='|';
           x[r+1][c+33]='_';
           x[r+2][c+0]='_';
           x[r+2][c+1]='|';
            for(i=0;i<4;i++){
              x[r+2][c+2+i]='_';
             }
           x[r+2][c+6]='|';
            for(i=0;i<2;i++){
              x[r+2][c+7+i]='_';
             }
           x[r+2][c+9]='|';
            for(i=0;i<2;i++){
              x[r+2][c+10+i]='_';
             }
           x[r+2][c+12]='|';
            for(i=0;i<3;i++){
              x[r+2][c+13+i]='_';
             }
           x[r+2][c+16]='|';
            for(i=0;i<4;i++){
              x[r+2][c+17+i]='_';
             }
           x[r+2][c+21]='|';
            for(i=0;i<4;i++){
              x[r+2][c+22+i]='_';
             }
           x[r+2][c+26]='|';
            for(i=0;i<3;i++){
              x[r+2][c+27+i]='_';
             }
           x[r+2][c+30]='|';
            for(i=0;i<3;i++){
              x[r+2][c+31+i]='_';
             }
           x[r+3][c+0]='_';
           x[r+3][c+1]='|';
            for(i=0;i<5;i++){
              x[r+3][c+2+i]='_';
             }
           x[r+3][c+7]='|';
            for(i=0;i<2;i++){
              x[r+3][c+8+i]='_';
             }
           x[r+3][c+10]='|';
            for(i=0;i<2;i++){
              x[r+3][c+11+i]='_';
             }
           x[r+3][c+13]='|';
            for(i=0;i<3;i++){
              x[r+3][c+14+i]='_';
             }
           x[r+3][c+17]='|';
            for(i=0;i<4;i++){
              x[r+3][c+18+i]='_';
             }
           x[r+3][c+22]='|';
            for(i=0;i<2;i++){
              x[r+3][c+23+i]='_';
             }
           x[r+3][c+25]='|';
            for(i=0;i<3;i++){
              x[r+3][c+26+i]='_';
             }
           x[r+3][c+29]='|';
            for(i=0;i<2;i++){
              x[r+3][c+30+i]='_';
             }
           x[r+3][c+32]='|';
           x[r+3][c+33]='_';
        }
    
    c=z+34*2;
    r=148-4;
    

        for(c=1190-34;z+34*2<=c;c-=34){
            for(i=0;i<34;i++){
              x[r+0][c+0+i]='-';
             }
           x[r+1][c+0]='_';
           x[r+1][c+1]='|';
            for(i=0;i<3;i++){
              x[r+1][c+2+i]='_';
             }
           x[r+1][c+5]='|';
            for(i=0;i<7;i++){
              x[r+1][c+6+i]='_';
             }
           x[r+1][c+13]='|';
            for(i=0;i<2;i++){
              x[r+1][c+14+i]='_';
             }
           x[r+1][c+16]='|';
            for(i=0;i<3;i++){
              x[r+1][c+17+i]='_';
             }
           x[r+1][c+20]='|';
            for(i=0;i<2;i++){
              x[r+1][c+21+i]='_';
             }
           x[r+1][c+23]='|';
            for(i=0;i<4;i++){
              x[r+1][c+24+i]='_';
             }
           x[r+1][c+28]='|';
            for(i=0;i<3;i++){
              x[r+1][c+29+i]='_';
             }
           x[r+1][c+32]='|';
           x[r+1][c+33]='_';
           x[r+2][c+0]='_';
           x[r+2][c+1]='|';
            for(i=0;i<4;i++){
              x[r+2][c+2+i]='_';
             }
           x[r+2][c+6]='|';
            for(i=0;i<2;i++){
              x[r+2][c+7+i]='_';
             }
           x[r+2][c+9]='|';
            for(i=0;i<2;i++){
              x[r+2][c+10+i]='_';
             }
           x[r+2][c+12]='|';
            for(i=0;i<3;i++){
              x[r+2][c+13+i]='_';
             }
           x[r+2][c+16]='|';
            for(i=0;i<4;i++){
              x[r+2][c+17+i]='_';
             }
           x[r+2][c+21]='|';
            for(i=0;i<4;i++){
              x[r+2][c+22+i]='_';
             }
           x[r+2][c+26]='|';
            for(i=0;i<3;i++){
              x[r+2][c+27+i]='_';
             }
           x[r+2][c+30]='|';
            for(i=0;i<3;i++){
              x[r+2][c+31+i]='_';
             }
           x[r+3][c+0]='_';
           x[r+3][c+1]='|';
            for(i=0;i<5;i++){
              x[r+3][c+2+i]='_';
             }
           x[r+3][c+7]='|';
            for(i=0;i<2;i++){
              x[r+3][c+8+i]='_';
             }
           x[r+3][c+10]='|';
            for(i=0;i<2;i++){
              x[r+3][c+11+i]='_';
             }
           x[r+3][c+13]='|';
            for(i=0;i<3;i++){
              x[r+3][c+14+i]='_';
             }
           x[r+3][c+17]='|';
            for(i=0;i<4;i++){
              x[r+3][c+18+i]='_';
             }
           x[r+3][c+22]='|';
            for(i=0;i<2;i++){
              x[r+3][c+23+i]='_';
             }
           x[r+3][c+25]='|';
            for(i=0;i<3;i++){
              x[r+3][c+26+i]='_';
             }
           x[r+3][c+29]='|';
            for(i=0;i<2;i++){
              x[r+3][c+30+i]='_';
             }
           x[r+3][c+32]='|';
           x[r+3][c+33]='_';
        }
    for(r=148;r<160;r+=4){
        for(c=34;c<1190-34*14;c+=34){
            x[r+0][c+0]='_';
            x[r+0][c+1]='|';
             for(i=0;i<3;i++){
               x[r+0][c+2+i]='_';
              }
            x[r+0][c+5]='|';
             for(i=0;i<7;i++){
               x[r+0][c+6+i]='_';
              }
            x[r+0][c+13]='|';
             for(i=0;i<2;i++){
               x[r+0][c+14+i]='_';
              }
            x[r+0][c+16]='|';
             for(i=0;i<3;i++){
               x[r+0][c+17+i]='_';
              }
            x[r+0][c+20]='|';
             for(i=0;i<2;i++){
               x[r+0][c+21+i]='_';
              }
            x[r+0][c+23]='|';
             for(i=0;i<4;i++){
               x[r+0][c+24+i]='_';
              }
            x[r+0][c+28]='|';
             for(i=0;i<3;i++){
               x[r+0][c+29+i]='_';
              }
            x[r+0][c+32]='|';
            x[r+0][c+33]='_';
            x[r+1][c+0]='_';
            x[r+1][c+1]='|';
             for(i=0;i<4;i++){
               x[r+1][c+2+i]='_';
              }
            x[r+1][c+6]='|';
             for(i=0;i<2;i++){
               x[r+1][c+7+i]='_';
              }
            x[r+1][c+9]='|';
             for(i=0;i<2;i++){
               x[r+1][c+10+i]='_';
              }
            x[r+1][c+12]='|';
             for(i=0;i<3;i++){
               x[r+1][c+13+i]='_';
              }
            x[r+1][c+16]='|';
             for(i=0;i<4;i++){
               x[r+1][c+17+i]='_';
              }
            x[r+1][c+21]='|';
             for(i=0;i<4;i++){
               x[r+1][c+22+i]='_';
              }
            x[r+1][c+26]='|';
             for(i=0;i<3;i++){
               x[r+1][c+27+i]='_';
              }
            x[r+1][c+30]='|';
             for(i=0;i<3;i++){
               x[r+1][c+31+i]='_';
              }
            x[r+2][c+0]='_';
            x[r+2][c+1]='|';
             for(i=0;i<5;i++){
               x[r+2][c+2+i]='_';
              }
            x[r+2][c+7]='|';
             for(i=0;i<2;i++){
               x[r+2][c+8+i]='_';
              }
            x[r+2][c+10]='|';
             for(i=0;i<2;i++){
               x[r+2][c+11+i]='_';
              }
            x[r+2][c+13]='|';
             for(i=0;i<3;i++){
               x[r+2][c+14+i]='_';
              }
            x[r+2][c+17]='|';
             for(i=0;i<4;i++){
               x[r+2][c+18+i]='_';
              }
            x[r+2][c+22]='|';
             for(i=0;i<2;i++){
               x[r+2][c+23+i]='_';
              }
            x[r+2][c+25]='|';
             for(i=0;i<3;i++){
               x[r+2][c+26+i]='_';
              }
            x[r+2][c+29]='|';
             for(i=0;i<2;i++){
               x[r+2][c+30+i]='_';
              }
            x[r+2][c+32]='|';
            x[r+2][c+33]='_';
            x[r+3][c+0]='_';
            x[r+3][c+1]='|';
             for(i=0;i<4;i++){
               x[r+3][c+2+i]='_';
              }
            x[r+3][c+6]='|';
             for(i=0;i<2;i++){
               x[r+3][c+7+i]='_';
              }
            x[r+3][c+9]='|';
             for(i=0;i<2;i++){
               x[r+3][c+10+i]='_';
              }
            x[r+3][c+12]='|';
             for(i=0;i<3;i++){
               x[r+3][c+13+i]='_';
              }
            x[r+3][c+16]='|';
             for(i=0;i<4;i++){
               x[r+3][c+17+i]='_';
              }
            x[r+3][c+21]='|';
             for(i=0;i<4;i++){
               x[r+3][c+22+i]='_';
              }
            x[r+3][c+26]='|';
             for(i=0;i<3;i++){
               x[r+3][c+27+i]='_';
              }
            x[r+3][c+30]='|';
             for(i=0;i<3;i++){
               x[r+3][c+31+i]='_';
              }
        }
    }
    
  }

bool checkAllMobsDead(Hero&hero, Bat & bat, Enemy &enemy1,Enemy &enemy2, Snail snail[], int NSnails){
    if(hero.health!=5 || bat.health!=0  || enemy1.health!=0  || enemy2.health!=0){
        for(int i=0; i<NSnails;i++){
            if(snail[i].health==0){
                return true;
            }
            
        }
    }
    return false;
}
bool playerArrived(Hero &hero){
    if(hero.cherob>1100){
        return true;
    }
    return false;
}
void drawDoor(wchar_t x[][1190]){
    int r=148-4-11;
    int c=0;
    int i;
    
    
    for(i=0;i<6;i++){
      x[r+0][c+6+i]='_';
     }
   x[r+1][c+3]=',';
   x[r+1][c+4]='-';
   x[r+1][c+5]=39;
   x[r+1][c+7]=';';
   x[r+1][c+10]='!';
   x[r+1][c+12]='`';
   x[r+1][c+13]='-';
   x[r+1][c+14]='.';
   x[r+2][c+2]='/';
   x[r+2][c+4]=':';
   x[r+2][c+7]='!';
   x[r+2][c+10]=':';
   x[r+2][c+13]='.';
   x[r+2][c+15]=92;
   x[r+3][c+1]='|';
   x[r+3][c+2]='_';
   x[r+3][c+4]=';';
    for(i=0;i<2;i++){
      x[r+3][c+8+i]='_';
     }
   x[r+3][c+10]=':';
   x[r+3][c+13]=';';
   x[r+3][c+16]='|';
   x[r+4][c+1]=')';
   x[r+4][c+2]='|';
   x[r+4][c+4]='.';
   x[r+4][c+7]=':';
   x[r+4][c+8]=')';
   x[r+4][c+9]='(';
   x[r+4][c+10]='.';
   x[r+4][c+13]='!';
   x[r+4][c+16]='|';
   x[r+5][c+1]='|';
   x[r+5][c+2]='"';
   x[r+5][c+7]='(';
    for(i=0;i<2;i++){
      x[r+5][c+8+i]='#';
     }
   x[r+5][c+10]=')';
   x[r+5][c+13]='_';
   x[r+5][c+16]='|';
   x[r+6][c+1]='|';
   x[r+6][c+4]=':';
   x[r+6][c+7]=';';
   x[r+6][c+8]='`';
   x[r+6][c+9]=39;
   x[r+6][c+12]='(';
   x[r+6][c+13]='_';
   x[r+6][c+14]=')';
   x[r+6][c+16]='(';
   x[r+7][c+1]='|';
   x[r+7][c+4]=':';
   x[r+7][c+7]=':';
   x[r+7][c+10]='.';
   x[r+7][c+16]='|';
   x[r+8][c+1]=')';
   x[r+8][c+2]='_';
   x[r+8][c+4]='!';
   x[r+8][c+7]=',';
   x[r+8][c+10]=';';
   x[r+8][c+13]=';';
   x[r+8][c+16]='|';
    for(i=0;i<2;i++){
      x[r+9][c+1+i]='|';
     }
   x[r+9][c+4]='.';
   x[r+9][c+7]='.';
   x[r+9][c+10]=':';
   x[r+9][c+13]=':';
   x[r+9][c+16]='|';
   x[r+10][c+1]='|';
   x[r+10][c+2]='"';
   x[r+10][c+4]='.';
   x[r+10][c+7]='|';
   x[r+10][c+10]=':';
   x[r+10][c+13]='.';
   x[r+10][c+16]='|';
   x[r+11][c+1]='|';
   x[r+11][c+2]='m';
   x[r+11][c+3]='t';
   x[r+11][c+4]='-';
   x[r+11][c+5]='2';
   x[r+11][c+6]='_';
   x[r+11][c+7]=';';
    for(i=0;i<4;i++){
      x[r+11][c+8+i]='-';
     }
   x[r+11][c+12]='.';
    for(i=0;i<3;i++){
      x[r+11][c+13+i]='_';
     }
   x[r+11][c+16]='|';
}
void drawPortal(wchar_t x[][1190], Hero &hero){
    int r=133;
    int c=340;
    int i;
    x[r+0][c+5]='|';
    x[r+1][c+5]='|';
    x[r+2][c+4]=92;
    x[r+2][c+5]='*';
    x[r+2][c+6]='/';
    x[r+3][c+1]='-';
     for(i=0;i<2;i++){
       x[r+3][c+2+i]='=';
      }
    x[r+3][c+5]='+';
     for(i=0;i<2;i++){
       x[r+3][c+7+i]='=';
      }
    x[r+3][c+9]='-';
    x[r+4][c+4]='/';
    x[r+4][c+5]='*';
    x[r+4][c+6]=92;
    x[r+5][c+5]='|';
    x[r+6][c+5]='|';
    
    if(hero.cheroe>=330 && hero.cheroe<=370){
        hero.cherob=120;
        hero.cheroe=141;
        hero.rherob=84;
        hero.rheroe=99;
        
    }
}



void drawEnemyLft(wchar_t x[][1190], Enemy & enemy){
    int r=enemy.rb;
    int c=enemy.cb;
    int i;
    
    x[r+0][c+1]='.';
       x[r+0][c+2]='-';
       x[r+0][c+3]='.';
        for(i=0;i<3;i++){
          x[r+0][c+7+i]=92;
         }
       x[r+0][c+10]='V';
        for(i=0;i<3;i++){
          x[r+0][c+11+i]='/';
         }
       x[r+1][c+0]='(';
       x[r+1][c+1]='0';
       x[r+1][c+2]='.';
       x[r+1][c+3]='0';
       x[r+1][c+4]=')';
        for(i=0;i<2;i++){
          x[r+1][c+7+i]='/';
         }
       x[r+1][c+9]='6';
       x[r+1][c+11]='6';
        for(i=0;i<2;i++){
          x[r+1][c+12+i]=92;
         }
       x[r+2][c+1]='{';
       x[r+2][c+2]='=';
       x[r+2][c+3]='}';
        for(i=0;i<2;i++){
          x[r+2][c+6+i]='/';
         }
       x[r+2][c+10]='=';
        for(i=0;i<2;i++){
          x[r+2][c+13+i]=92;
         }
       x[r+3][c+2]='T';
        for(i=0;i<3;i++){
          x[r+3][c+3+i]='_';
         }
       x[r+3][c+6]='.';
       x[r+3][c+7]='-';
       x[r+3][c+8]='`';
       x[r+3][c+9]='~';
       x[r+3][c+10]='@';
       x[r+3][c+11]='~';
       x[r+3][c+12]='`';
       x[r+3][c+13]='-';
       x[r+3][c+14]='.';
       x[r+4][c+1]='(';
       x[r+4][c+2]='3';
        for(i=0;i<4;i++){
          x[r+4][c+3+i]='-';
         }
       x[r+4][c+7]='|';
       x[r+4][c+8]=39;
       x[r+4][c+12]=39;
       x[r+4][c+13]='|';
        for(i=0;i<2;i++){
          x[r+4][c+14+i]=92;
         }
       x[r+5][c+2]='|';
       x[r+5][c+7]=92;
        for(i=0;i<2;i++){
          x[r+5][c+8+i]='_';
         }
       x[r+5][c+10]='.';
        for(i=0;i<2;i++){
          x[r+5][c+11+i]='_';
         }
        for(i=0;i<3;i++){
          x[r+5][c+13+i]='/';
         }
       x[r+6][c+2]='|';
       x[r+6][c+7]='/';
       x[r+6][c+8]='=';
       x[r+6][c+9]='[';
       x[r+6][c+10]='_';
       x[r+6][c+11]=']';
       x[r+6][c+12]='=';
       x[r+6][c+13]=92;
       x[r+6][c+14]='/';
       x[r+7][c+2]='|';
       x[r+7][c+6]='/';
       x[r+7][c+9]='/';
       x[r+7][c+11]=92;
       x[r+7][c+14]=92;
       x[r+8][c+2]='|';
       x[r+8][c+6]=92;
       x[r+8][c+8]=92;
       x[r+8][c+12]='/';
       x[r+8][c+14]='/';
       x[r+9][c+2]='|';
       x[r+9][c+5]='(';
        for(i=0;i<3;i++){
          x[r+9][c+6+i]='_';
         }
       x[r+9][c+9]=92;
       x[r+9][c+11]='/';
        for(i=0;i<3;i++){
          x[r+9][c+12+i]='_';
         }
       x[r+9][c+15]=')';
}
void drawEnemyRight(wchar_t x[][1190], Enemy & enemy){
    int r=enemy.rb;
    int c=enemy.cb;
    int i;
    
    for(i=0;i<3;i++){
          x[r+0][c+2+i]=92;
         }
       x[r+0][c+5]='W';
        for(i=0;i<3;i++){
          x[r+0][c+6+i]='/';
         }
       x[r+0][c+12]='.';
       x[r+0][c+13]='-';
       x[r+0][c+14]='.';
        for(i=0;i<2;i++){
          x[r+1][c+2+i]='/';
         }
       x[r+1][c+4]='9';
       x[r+1][c+6]='9';
        for(i=0;i<2;i++){
          x[r+1][c+7+i]=92;
         }
       x[r+1][c+11]='(';
       x[r+1][c+12]='0';
       x[r+1][c+13]='.';
       x[r+1][c+14]='0';
       x[r+1][c+15]=')';
        for(i=0;i<2;i++){
          x[r+2][c+1+i]='/';
         }
       x[r+2][c+5]='=';
        for(i=0;i<2;i++){
          x[r+2][c+8+i]=92;
         }
       x[r+2][c+12]='{';
       x[r+2][c+13]='=';
       x[r+2][c+14]='}';
       x[r+3][c+1]='.';
       x[r+3][c+2]='-';
       x[r+3][c+3]='`';
       x[r+3][c+4]='~';
       x[r+3][c+5]='&';
       x[r+3][c+6]='~';
       x[r+3][c+7]='`';
       x[r+3][c+8]='-';
       x[r+3][c+9]='.';
        for(i=0;i<3;i++){
          x[r+3][c+10+i]='_';
         }
       x[r+3][c+13]='T';
        for(i=0;i<2;i++){
          x[r+4][c+0+i]='/';
         }
       x[r+4][c+2]='|';
       x[r+4][c+3]=39;
       x[r+4][c+7]=39;
       x[r+4][c+8]='|';
        for(i=0;i<4;i++){
          x[r+4][c+9+i]='-';
         }
       x[r+4][c+13]='8';
       x[r+4][c+14]=')';
        for(i=0;i<3;i++){
          x[r+5][c+0+i]=92;
         }
        for(i=0;i<2;i++){
          x[r+5][c+3+i]='_';
         }
       x[r+5][c+5]='.';
        for(i=0;i<2;i++){
          x[r+5][c+6+i]='_';
         }
       x[r+5][c+8]='/';
       x[r+5][c+13]='|';
       x[r+6][c+1]=92;
       x[r+6][c+2]='/';
       x[r+6][c+3]='=';
       x[r+6][c+4]='[';
       x[r+6][c+5]='_';
       x[r+6][c+6]=']';
       x[r+6][c+7]='=';
       x[r+6][c+8]=92;
       x[r+6][c+13]='|';
       x[r+7][c+1]='/';
       x[r+7][c+4]='/';
       x[r+7][c+6]=92;
       x[r+7][c+9]=92;
       x[r+7][c+13]='|';
       x[r+8][c+1]=92;
       x[r+8][c+3]=92;
       x[r+8][c+7]='/';
       x[r+8][c+9]='/';
       x[r+8][c+13]='|';
       x[r+9][c+0]='(';
        for(i=0;i<3;i++){
          x[r+9][c+1+i]='_';
         }
       x[r+9][c+4]=92;
       x[r+9][c+6]='/';
        for(i=0;i<3;i++){
          x[r+9][c+7+i]='_';
         }
       x[r+9][c+10]=')';
       x[r+9][c+13]='|';
}

void moveEnemy(wchar_t x[][1190], Enemy & enemy){

        
    if(enemy.frames%10==0){
        if(enemy.cb==640){
            enemy.dir*=-1;
        }
        else{
            if(enemy.cb>650 &&enemy.rb<=144){
                enemy.rb++;
            }
           
        }
        
        if(enemy.cb==640-60){
            enemy.dir*=-1;
        }
        
        enemy.cb+=enemy.dir*1;
    }
    
}


void drawHealthBar(wchar_t x[][1190], Hero&hero, int startOfScreen,int startOfScreen2, Snail &snail){
    int i,j;
    
    if(snail.health!=0){
        int r=snail.rb-5;
        int c=snail.cb-10;
        for(j=0;j<snail.health;j++){
            x[r+0][c+1]='^';
             for(i=0;i<2;i++){
               x[r+0][c+2+i]='.';
              }
            x[r+0][c+4]='^';
            x[r+1][c+1]=92;
            x[r+1][c+4]='/';
            x[r+2][c+2]=92;
            x[r+2][c+3]='/';
            
            c+=10;
        }
    }

}

void drawHealthBar(wchar_t x[][1190], Hero&hero, int startOfScreen,int startOfScreen2, Bat& bat, Enemy &enemy, Enemy &enemy2){
    int i,j;
    for(i=startOfScreen2;i<startOfScreen2+10;i++){
        for(j=startOfScreen;j<startOfScreen+150;j++){
            x[i][j]=' ';
        }
    }
    i=0;
    int r=startOfScreen2+1;
    int c=startOfScreen+2;
    x[r+0][c+1]='_';
    x[r+0][c+5]='_';
     for(i=0;i<5;i++){
       x[r+0][c+7+i]='_';
      }
    x[r+0][c+16]='_';
    x[r+0][c+21]='_';
     for(i=0;i<5;i++){
       x[r+0][c+25+i]='_';
      }
    x[r+0][c+31]='_';
    x[r+0][c+35]='_';
    x[r+1][c+0]='|';
    x[r+1][c+2]='|';
    x[r+1][c+4]='|';
    x[r+1][c+6]='|';
     for(i=0;i<4;i++){
       x[r+1][c+8+i]='_';
      }
    x[r+1][c+12]='|';
    x[r+1][c+15]='/';
    x[r+1][c+17]=92;
    x[r+1][c+20]='|';
    x[r+1][c+22]='|';
    x[r+1][c+24]='|';
    x[r+1][c+25]='_';
    x[r+1][c+29]='_';
    x[r+1][c+30]='|';
    x[r+1][c+32]='|';
    x[r+1][c+34]='|';
    x[r+1][c+36]='|';
    x[r+2][c+0]='|';
    x[r+2][c+2]='|';
    x[r+2][c+3]='_';
    x[r+2][c+4]='|';
    x[r+2][c+6]='|';
    x[r+2][c+9]='_';
    x[r+2][c+10]='|';
    x[r+2][c+14]='/';
    x[r+2][c+16]='_';
    x[r+2][c+18]=92;
    x[r+2][c+20]='|';
    x[r+2][c+22]='|';
    x[r+2][c+26]='|';
    x[r+2][c+28]='|';
    x[r+2][c+30]='|';
    x[r+2][c+32]='|';
    x[r+2][c+33]='_';
    x[r+2][c+34]='|';
    x[r+2][c+36]='|';
    x[r+3][c+0]='|';
    x[r+3][c+3]='_';
    x[r+3][c+6]='|';
    x[r+3][c+8]='|';
     for(i=0;i<3;i++){
       x[r+3][c+9+i]='_';
      }
    x[r+3][c+13]='/';
     for(i=0;i<3;i++){
       x[r+3][c+15+i]='_';
      }
    x[r+3][c+19]=92;
    x[r+3][c+20]='|';
    x[r+3][c+22]='|';
     for(i=0;i<3;i++){
       x[r+3][c+23+i]='_';
      }
    x[r+3][c+26]='|';
    x[r+3][c+28]='|';
    x[r+3][c+30]='|';
    x[r+3][c+33]='_';
    x[r+3][c+36]='|';
    x[r+4][c+0]='|';
    x[r+4][c+1]='_';
    x[r+4][c+2]='|';
    x[r+4][c+4]='|';
    x[r+4][c+5]='_';
    x[r+4][c+6]='|';
     for(i=0;i<5;i++){
       x[r+4][c+7+i]='_';
      }
    x[r+4][c+12]='/';
    x[r+4][c+13]='_';
    x[r+4][c+14]='/';
    x[r+4][c+18]=92;
    x[r+4][c+19]='_';
    x[r+4][c+20]=92;
     for(i=0;i<5;i++){
       x[r+4][c+21+i]='_';
      }
    x[r+4][c+26]='|';
    x[r+4][c+27]='_';
    x[r+4][c+28]='|';
    x[r+4][c+30]='|';
    x[r+4][c+31]='_';
    x[r+4][c+32]='|';
    x[r+4][c+34]='|';
    x[r+4][c+35]='_';
    x[r+4][c+36]='|';
    
     r=startOfScreen2+2;
     c=startOfScreen+50;
    
 
    for(j=0;j<hero.health && j<5;j++){
        x[r+0][c+1]='^';
         for(i=0;i<2;i++){
           x[r+0][c+2+i]='.';
          }
        x[r+0][c+4]='^';
        x[r+1][c+1]=92;
        x[r+1][c+4]='/';
        x[r+2][c+2]=92;
        x[r+2][c+3]='/';
        
        c+=10;
    }
    if(hero.inAirplane){
        r=bat.r-5;
        c=bat.c-4;
        for(j=0;j<bat.health;j++){
            x[r+0][c+1]='^';
             for(i=0;i<2;i++){
               x[r+0][c+2+i]='.';
              }
            x[r+0][c+4]='^';
            x[r+1][c+1]=92;
            x[r+1][c+4]='/';
            x[r+2][c+2]=92;
            x[r+2][c+3]='/';
            
            c+=10;
        }
    }
    
    if(enemy.health!=0){
        r=enemy.rb-5;
        c=enemy.cb-10;
        for(j=0;j<enemy.health;j++){
            x[r+0][c+1]='^';
             for(i=0;i<2;i++){
               x[r+0][c+2+i]='.';
              }
            x[r+0][c+4]='^';
            x[r+1][c+1]=92;
            x[r+1][c+4]='/';
            x[r+2][c+2]=92;
            x[r+2][c+3]='/';
            
            c+=10;
        }
    }
    if(enemy2.health!=0){
        r=enemy2.rb-5;
        c=enemy2.cb-10;
        for(j=0;j<enemy2.health;j++){
            x[r+0][c+1]='^';
             for(i=0;i<2;i++){
               x[r+0][c+2+i]='.';
              }
            x[r+0][c+4]='^';
            x[r+1][c+1]=92;
            x[r+1][c+4]='/';
            x[r+2][c+2]=92;
            x[r+2][c+3]='/';
            
            c+=10;
        }
    }
    
    }



void drawBulletBar(wchar_t x[][1190], int startOfScreen,int startOfScreen2,int ctBullets, int ctBulletFrames, int & ctLoad){
    int i,j;
    int ct = 4-ctBullets;
    for(i=startOfScreen2;i<startOfScreen2+10;i++){
        for(j=startOfScreen+150;j<startOfScreen+238;j++){
            x[i][j]=' ';
        }
    }
    i=0;
    int r=startOfScreen2+1;
    int c=startOfScreen+238-47-2-40;
    
    for(i=0;i<4;i++){
      x[r+0][c+1+i]='_';
     }
   x[r+0][c+7]='_';
   x[r+0][c+11]='_';
   x[r+0][c+13]='_';
   x[r+0][c+19]='_';
    for(i=0;i<5;i++){
      x[r+0][c+25+i]='_';
     }
    for(i=0;i<5;i++){
      x[r+0][c+31+i]='_';
     }
    for(i=0;i<4;i++){
      x[r+0][c+37+i]='_';
     }
   x[r+1][c+0]='|';
    for(i=0;i<2;i++){
      x[r+1][c+2+i]='_';
     }
   x[r+1][c+5]=')';
   x[r+1][c+6]='|';
   x[r+1][c+8]='|';
   x[r+1][c+10]='|';
   x[r+1][c+12]='|';
   x[r+1][c+14]='|';
   x[r+1][c+18]='|';
   x[r+1][c+20]='|';
   x[r+1][c+24]='|';
    for(i=0;i<4;i++){
      x[r+1][c+26+i]='_';
     }
   x[r+1][c+30]='|';
   x[r+1][c+31]='_';
   x[r+1][c+35]='_';
   x[r+1][c+36]='/';
    for(i=0;i<3;i++){
      x[r+1][c+38+i]='_';
     }
   x[r+1][c+41]='|';
   x[r+1][c+42]='_';
   x[r+2][c+0]='|';
   x[r+2][c+3]='_';
   x[r+2][c+5]=92;
   x[r+2][c+6]='|';
   x[r+2][c+8]='|';
   x[r+2][c+10]='|';
   x[r+2][c+12]='|';
   x[r+2][c+14]='|';
   x[r+2][c+18]='|';
   x[r+2][c+20]='|';
   x[r+2][c+24]='|';
   x[r+2][c+27]='_';
   x[r+2][c+28]='|';
   x[r+2][c+32]='|';
   x[r+2][c+34]='|';
   x[r+2][c+36]=92;
    for(i=0;i<3;i++){
      x[r+2][c+37+i]='_';
     }
   x[r+2][c+41]='(';
   x[r+2][c+42]='_';
   x[r+2][c+43]=')';
   x[r+3][c+0]='|';
   x[r+3][c+2]='|';
   x[r+3][c+3]='_';
   x[r+3][c+4]=')';
   x[r+3][c+6]='|';
   x[r+3][c+8]='|';
   x[r+3][c+9]='_';
   x[r+3][c+10]='|';
   x[r+3][c+12]='|';
   x[r+3][c+14]='|';
    for(i=0;i<3;i++){
      x[r+3][c+15+i]='_';
     }
   x[r+3][c+18]='|';
   x[r+3][c+20]='|';
    for(i=0;i<3;i++){
      x[r+3][c+21+i]='_';
     }
   x[r+3][c+24]='|';
   x[r+3][c+26]='|';
    for(i=0;i<3;i++){
      x[r+3][c+27+i]='_';
     }
   x[r+3][c+32]='|';
   x[r+3][c+34]='|';
    for(i=0;i<3;i++){
      x[r+3][c+37+i]='_';
     }
   x[r+3][c+40]=')';
   x[r+3][c+42]='|';
   x[r+4][c+0]='|';
    for(i=0;i<4;i++){
      x[r+4][c+1+i]='_';
     }
   x[r+4][c+5]='/';
   x[r+4][c+7]=92;
    for(i=0;i<3;i++){
      x[r+4][c+8+i]='_';
     }
   x[r+4][c+11]='/';
   x[r+4][c+12]='|';
    for(i=0;i<5;i++){
      x[r+4][c+13+i]='_';
     }
   x[r+4][c+18]='|';
    for(i=0;i<5;i++){
      x[r+4][c+19+i]='_';
     }
   x[r+4][c+24]='|';
    for(i=0;i<5;i++){
      x[r+4][c+25+i]='_';
     }
   x[r+4][c+30]='|';
   x[r+4][c+32]='|';
   x[r+4][c+33]='_';
   x[r+4][c+34]='|';
   x[r+4][c+36]='|';
    for(i=0;i<4;i++){
      x[r+4][c+37+i]='_';
     }
   x[r+4][c+41]='(';
   x[r+4][c+42]='_';
   x[r+4][c+43]=')';
    
    c+=47;
    r+=1;
    
    
    if(ctBulletFrames<5 || ctBulletFrames>450){
        for(j=0;j<ct;j++){
            for(i=0;i<2;i++){
                x[r+0][c+2+i]='/';
            }
            x[r+0][c+4]=92;
            x[r+1][c+1]='|';
            x[r+1][c+2]='/';
            x[r+1][c+3]='_';
            x[r+1][c+4]=92;
            x[r+1][c+5]='|';
            x[r+2][c+1]='/';
            x[r+2][c+3]='_';
            x[r+2][c+5]=92;
            
            c+=10;
        }
    }
    else{
        if(ctBulletFrames>=3 && ctBulletFrames<450){
            for(j=0;j<ctLoad;j++){
                x[r+0][c+1]='_';
                x[r+1][c+0]='(';
                x[r+1][c+1]='_';
                x[r+1][c+2]=')';
                c+=5;
            }
            if(ctBulletFrames%55==0){
                ctLoad++;
            }
        }
        if (ctBulletFrames>=450){
            ctLoad=0;
        }
        }


    }
        
    


void drawMastabaWithLadder(wchar_t x[][1190]){
    int r=100;
    int c=480;
    int i;
    for(i=0;i<44;i++){
        x[r+0][c+1+i]='-';
    }
    x[r+1][c+0]='|';
    x[r+1][c+1]='_';
    x[r+1][c+2]='|';
    for(i=0;i<3;i++){
        x[r+1][c+3+i]='_';
    }
    x[r+1][c+6]='|';
    for(i=0;i<7;i++){
        x[r+1][c+7+i]='_';
    }
    x[r+1][c+14]='|';
    for(i=0;i<2;i++){
        x[r+1][c+15+i]='_';
    }
    x[r+1][c+17]='|';
    for(i=0;i<3;i++){
        x[r+1][c+18+i]='_';
    }
    x[r+1][c+21]='|';
    for(i=0;i<2;i++){
        x[r+1][c+22+i]='_';
    }
    x[r+1][c+24]='|';
    for(i=0;i<4;i++){
        x[r+1][c+25+i]='_';
    }
    x[r+1][c+29]='|';
    for(i=0;i<4;i++){
        x[r+1][c+30+i]='_';
    }
    x[r+1][c+34]='|';
    for(i=0;i<4;i++){
        x[r+1][c+35+i]='_';
    }
    x[r+1][c+39]='|';
    for(i=0;i<5;i++){
        x[r+1][c+40+i]='_';
    }
    x[r+2][c+0]='|';
    x[r+2][c+1]='_';
    x[r+2][c+2]='|';
    for(i=0;i<4;i++){
        x[r+2][c+3+i]='_';
    }
    x[r+2][c+7]='|';
    for(i=0;i<2;i++){
        x[r+2][c+8+i]='_';
    }
    x[r+2][c+10]='|';
    for(i=0;i<2;i++){
        x[r+2][c+11+i]='_';
    }
    x[r+2][c+13]='|';
    for(i=0;i<3;i++){
        x[r+2][c+14+i]='_';
    }
    x[r+2][c+17]='|';
    for(i=0;i<4;i++){
        x[r+2][c+18+i]='_';
    }
    x[r+2][c+22]='|';
    for(i=0;i<4;i++){
        x[r+2][c+23+i]='_';
    }
    x[r+2][c+27]='|';
    for(i=0;i<5;i++){
        x[r+2][c+28+i]='_';
    }
    x[r+2][c+33]='|';
    for(i=0;i<3;i++){
        x[r+2][c+34+i]='_';
    }
    x[r+2][c+37]='|';
    for(i=0;i<4;i++){
        x[r+2][c+38+i]='_';
    }
    x[r+2][c+42]='|';
    for(i=0;i<2;i++){
        x[r+2][c+43+i]='_';
    }
    for(c=480+45;c<480+34*4;c+=34){
        for(i=0;i<34;i++){
            x[r+0][c+0+i]='-';
        }
        x[r+1][c+0]='_';
        x[r+1][c+1]='|';
        for(i=0;i<3;i++){
            x[r+1][c+2+i]='_';
        }
        x[r+1][c+5]='|';
        for(i=0;i<7;i++){
            x[r+1][c+6+i]='_';
        }
        x[r+1][c+13]='|';
        for(i=0;i<2;i++){
            x[r+1][c+14+i]='_';
        }
        x[r+1][c+16]='|';
        for(i=0;i<3;i++){
            x[r+1][c+17+i]='_';
        }
        x[r+1][c+20]='|';
        for(i=0;i<2;i++){
            x[r+1][c+21+i]='_';
        }
        x[r+1][c+23]='|';
        for(i=0;i<4;i++){
            x[r+1][c+24+i]='_';
        }
        x[r+1][c+28]='|';
        for(i=0;i<3;i++){
            x[r+1][c+29+i]='_';
        }
        x[r+1][c+32]='|';
        x[r+1][c+33]='_';
        x[r+2][c+0]='_';
        x[r+2][c+1]='|';
        for(i=0;i<4;i++){
            x[r+2][c+2+i]='_';
        }
        x[r+2][c+6]='|';
        for(i=0;i<2;i++){
            x[r+2][c+7+i]='_';
        }
        x[r+2][c+9]='|';
        for(i=0;i<2;i++){
            x[r+2][c+10+i]='_';
        }
        x[r+2][c+12]='|';
        for(i=0;i<3;i++){
            x[r+2][c+13+i]='_';
        }
        x[r+2][c+16]='|';
        for(i=0;i<4;i++){
            x[r+2][c+17+i]='_';
        }
        x[r+2][c+21]='|';
        for(i=0;i<4;i++){
            x[r+2][c+22+i]='_';
        }
        x[r+2][c+26]='|';
        for(i=0;i<3;i++){
            x[r+2][c+27+i]='_';
        }
        x[r+2][c+30]='|';
        for(i=0;i<3;i++){
            x[r+2][c+31+i]='_';
        }
        
    }
    
    for(i=0;i<32;i++){
        x[r+0][c+0+i]='-';
    }
    x[r+1][c+0]='_';
    x[r+1][c+1]='|';
    for(i=0;i<3;i++){
        x[r+1][c+2+i]='_';
    }
    x[r+1][c+5]='|';
    for(i=0;i<7;i++){
        x[r+1][c+6+i]='_';
    }
    x[r+1][c+13]='|';
    for(i=0;i<2;i++){
        x[r+1][c+14+i]='_';
    }
    x[r+1][c+16]='|';
    for(i=0;i<3;i++){
        x[r+1][c+17+i]='_';
    }
    x[r+1][c+20]='|';
    for(i=0;i<2;i++){
        x[r+1][c+21+i]='_';
    }
    x[r+1][c+23]='|';
    for(i=0;i<4;i++){
        x[r+1][c+24+i]='_';
    }
    x[r+1][c+28]='|';
    for(i=0;i<3;i++){
        x[r+1][c+29+i]='_';
    }
    x[r+1][c+32]='|';
    x[r+2][c+0]='_';
    x[r+2][c+1]='|';
    for(i=0;i<4;i++){
        x[r+2][c+2+i]='_';
    }
    x[r+2][c+6]='|';
    for(i=0;i<2;i++){
        x[r+2][c+7+i]='_';
    }
    x[r+2][c+9]='|';
    for(i=0;i<2;i++){
        x[r+2][c+10+i]='_';
    }
    x[r+2][c+12]='|';
    for(i=0;i<3;i++){
        x[r+2][c+13+i]='_';
    }
    x[r+2][c+16]='|';
    for(i=0;i<4;i++){
        x[r+2][c+17+i]='_';
    }
    x[r+2][c+21]='|';
    for(i=0;i<4;i++){
        x[r+2][c+22+i]='_';
    }
    x[r+2][c+26]='|';
    for(i=0;i<5;i++){
        x[r+2][c+27+i]='_';
    }
    x[r+2][c+32]='|';
    
    r=100-23-1;
    c=480+20;
    
    
    for(i=0;i<2;i++){
          x[r+0][c+0+i]='.';
         }
        for(i=0;i<2;i++){
          x[r+0][c+19+i]='.';
         }
        for(i=0;i<2;i++){
          x[r+1][c+0+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+1][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+2][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+2][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+2][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+3][c+0+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+3][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+4][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+4][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+4][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+5][c+0+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+5][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+6][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+6][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+6][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+7][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+7][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+7][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+8][c+0+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+8][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+9][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+9][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+9][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+10][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+10][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+10][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+11][c+0+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+11][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+12][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+12][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+12][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+13][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+13][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+13][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+14][c+0+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+14][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+15][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+15][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+15][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+16][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+16][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+16][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+17][c+0+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+17][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+18][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+18][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+18][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+19][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+19][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+19][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+20][c+0+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+20][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+21][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+21][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+21][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+22][c+0+i]='|';
         }
        for(i=0;i<17;i++){
          x[r+22][c+2+i]='=';
         }
        for(i=0;i<2;i++){
          x[r+22][c+19+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+23][c+0+i]='|';
         }
        for(i=0;i<2;i++){
          x[r+23][c+19+i]='|';
         }
    
    
    
    
  
}

void drawHeroInRev(wchar_t x[][1190], Hero & hero){
    int r=hero.rherob, c=hero.cherob,i;
   
    x[r+0][c+2]='_';
     for(i=0;i<2;i++){
       x[r+0][c+3+i]='-';
      }
    x[r+0][c+5]='_';
    x[r+0][c+11]='_';
     for(i=0;i<2;i++){
       x[r+0][c+12+i]='-';
      }
    x[r+0][c+14]='_';
    x[r+1][c+1]='(';
    x[r+1][c+3]='(';
    x[r+1][c+4]=')';
    x[r+1][c+6]=')';
     for(i=0;i<3;i++){
       x[r+1][c+7+i]='_';
      }
    x[r+1][c+10]='(';
    x[r+1][c+12]='(';
    x[r+1][c+13]=')';
    x[r+1][c+15]=')';
    x[r+2][c+2]=92;
    x[r+2][c+6]='-';
    x[r+2][c+10]='-';
    x[r+2][c+14]='/';
    x[r+3][c+3]='(';
    x[r+3][c+6]='O';
    x[r+3][c+10]='O';
    x[r+3][c+13]=')';
    x[r+4][c+4]=92;
    x[r+4][c+12]='/';
    x[r+5][c+5]='(';
    x[r+5][c+7]='`';
    x[r+5][c+8]='-';
    x[r+5][c+9]=39;
    x[r+5][c+11]=')';
     for(i=0;i<2;i++){
       x[r+5][c+12+i]='_';
      }
    x[r+5][c+14]='.';
    x[r+6][c+4]='/';
    x[r+6][c+6]=39;
     for(i=0;i<3;i++){
       x[r+6][c+7+i]='-';
      }
    x[r+6][c+10]=39;
    x[r+6][c+13]='!';
    x[r+6][c+15]=92;
    x[r+7][c+3]='!';
    x[r+7][c+13]='/';
    x[r+7][c+16]=92;
    x[r+8][c+3]='!';
    x[r+8][c+12]='/';
    x[r+8][c+13]=92;
    x[r+8][c+17]='!';
    x[r+9][c+2]='/';
    x[r+9][c+4]=92;
     for(i=0;i<6;i++){
       x[r+9][c+5+i]='_';
      }
    x[r+9][c+11]='/';
    x[r+9][c+12]='!';
    x[r+9][c+13]='_';
    x[r+9][c+17]='!';
    x[r+10][c+1]='/';
    x[r+10][c+4]='!';
    x[r+10][c+12]='/';
    x[r+10][c+17]='/';
    x[r+11][c+1]=92;
     for(i=0;i<2;i++){
       x[r+11][c+2+i]='_';
      }
    x[r+11][c+4]=92;
    x[r+11][c+8]='(';
    x[r+11][c+12]=92;
     for(i=0;i<3;i++){
       x[r+11][c+13+i]='_';
      }
    x[r+11][c+16]='/';
    x[r+12][c+4]='!';
    x[r+12][c+9]='/';
    x[r+12][c+13]='/';
    x[r+13][c+5]=92;
    x[r+13][c+10]='!';
    x[r+13][c+13]=92;
     for(i=0;i<3;i++){
       x[r+14][c+3+i]='_';
      }
    x[r+14][c+6]=92;
    x[r+14][c+10]=92;
    x[r+14][c+14]='!';
    x[r+15][c+2]='(';
     for(i=0;i<6;i++){
       x[r+15][c+3+i]='_';
      }
    x[r+15][c+9]='(';
     for(i=0;i<4;i++){
       x[r+15][c+10+i]='_';
      }
    x[r+15][c+14]=')';
}
void drawPortal2(wchar_t x[][1190], Hero &hero){
    int r=90;
    int c=40;
    int i;
    x[r+0][c+5]='|';
    x[r+1][c+5]='|';
    x[r+2][c+4]=92;
    x[r+2][c+5]='*';
    x[r+2][c+6]='/';
    x[r+3][c+1]='-';
     for(i=0;i<2;i++){
       x[r+3][c+2+i]='=';
      }
    x[r+3][c+5]='+';
     for(i=0;i<2;i++){
       x[r+3][c+7+i]='=';
      }
    x[r+3][c+9]='-';
    x[r+4][c+4]='/';
    x[r+4][c+5]='*';
    x[r+4][c+6]=92;
    x[r+5][c+5]='|';
    x[r+6][c+5]='|';
    
    if(hero.rherob>=20 &&hero.rheroe<=110 &&hero.cherob>=20 && hero.cherob<=50){
        //c=21;
        //r=15;
        
        hero.cherob=540;
        hero.cheroe=555;
        hero.rherob=84;
        hero.rheroe=99;
        
    }
}


void drawMastabaHidden(wchar_t x[][1190]){
    int r=100;
    int c=0;
    int i;
    for(i=0;i<44;i++){
        x[r+0][c+1+i]='-';
    }
    x[r+1][c+0]='|';
    x[r+1][c+1]='_';
    x[r+1][c+2]='|';
    for(i=0;i<3;i++){
        x[r+1][c+3+i]='_';
    }
    x[r+1][c+6]='|';
    for(i=0;i<7;i++){
        x[r+1][c+7+i]='_';
    }
    x[r+1][c+14]='|';
    for(i=0;i<2;i++){
        x[r+1][c+15+i]='_';
    }
    x[r+1][c+17]='|';
    for(i=0;i<3;i++){
        x[r+1][c+18+i]='_';
    }
    x[r+1][c+21]='|';
    for(i=0;i<2;i++){
        x[r+1][c+22+i]='_';
    }
    x[r+1][c+24]='|';
    for(i=0;i<4;i++){
        x[r+1][c+25+i]='_';
    }
    x[r+1][c+29]='|';
    for(i=0;i<4;i++){
        x[r+1][c+30+i]='_';
    }
    x[r+1][c+34]='|';
    for(i=0;i<4;i++){
        x[r+1][c+35+i]='_';
    }
    x[r+1][c+39]='|';
    for(i=0;i<5;i++){
        x[r+1][c+40+i]='_';
    }
    x[r+2][c+0]='|';
    x[r+2][c+1]='_';
    x[r+2][c+2]='|';
    for(i=0;i<4;i++){
        x[r+2][c+3+i]='_';
    }
    x[r+2][c+7]='|';
    for(i=0;i<2;i++){
        x[r+2][c+8+i]='_';
    }
    x[r+2][c+10]='|';
    for(i=0;i<2;i++){
        x[r+2][c+11+i]='_';
    }
    x[r+2][c+13]='|';
    for(i=0;i<3;i++){
        x[r+2][c+14+i]='_';
    }
    x[r+2][c+17]='|';
    for(i=0;i<4;i++){
        x[r+2][c+18+i]='_';
    }
    x[r+2][c+22]='|';
    for(i=0;i<4;i++){
        x[r+2][c+23+i]='_';
    }
    x[r+2][c+27]='|';
    for(i=0;i<5;i++){
        x[r+2][c+28+i]='_';
    }
    x[r+2][c+33]='|';
    for(i=0;i<3;i++){
        x[r+2][c+34+i]='_';
    }
    x[r+2][c+37]='|';
    for(i=0;i<4;i++){
        x[r+2][c+38+i]='_';
    }
    x[r+2][c+42]='|';
    for(i=0;i<2;i++){
        x[r+2][c+43+i]='_';
    }
    for(c=4;c<100+34*4;c+=34){
        for(i=0;i<34;i++){
            x[r+0][c+0+i]='-';
        }
        x[r+1][c+0]='_';
        x[r+1][c+1]='|';
        for(i=0;i<3;i++){
            x[r+1][c+2+i]='_';
        }
        x[r+1][c+5]='|';
        for(i=0;i<7;i++){
            x[r+1][c+6+i]='_';
        }
        x[r+1][c+13]='|';
        for(i=0;i<2;i++){
            x[r+1][c+14+i]='_';
        }
        x[r+1][c+16]='|';
        for(i=0;i<3;i++){
            x[r+1][c+17+i]='_';
        }
        x[r+1][c+20]='|';
        for(i=0;i<2;i++){
            x[r+1][c+21+i]='_';
        }
        x[r+1][c+23]='|';
        for(i=0;i<4;i++){
            x[r+1][c+24+i]='_';
        }
        x[r+1][c+28]='|';
        for(i=0;i<3;i++){
            x[r+1][c+29+i]='_';
        }
        x[r+1][c+32]='|';
        x[r+1][c+33]='_';
        x[r+2][c+0]='_';
        x[r+2][c+1]='|';
        for(i=0;i<4;i++){
            x[r+2][c+2+i]='_';
        }
        x[r+2][c+6]='|';
        for(i=0;i<2;i++){
            x[r+2][c+7+i]='_';
        }
        x[r+2][c+9]='|';
        for(i=0;i<2;i++){
            x[r+2][c+10+i]='_';
        }
        x[r+2][c+12]='|';
        for(i=0;i<3;i++){
            x[r+2][c+13+i]='_';
        }
        x[r+2][c+16]='|';
        for(i=0;i<4;i++){
            x[r+2][c+17+i]='_';
        }
        x[r+2][c+21]='|';
        for(i=0;i<4;i++){
            x[r+2][c+22+i]='_';
        }
        x[r+2][c+26]='|';
        for(i=0;i<3;i++){
            x[r+2][c+27+i]='_';
        }
        x[r+2][c+30]='|';
        for(i=0;i<3;i++){
            x[r+2][c+31+i]='_';
        }
        
    }
    
    for(i=0;i<32;i++){
        x[r+0][c+0+i]='-';
    }
    x[r+1][c+0]='_';
    x[r+1][c+1]='|';
    for(i=0;i<3;i++){
        x[r+1][c+2+i]='_';
    }
    x[r+1][c+5]='|';
    for(i=0;i<7;i++){
        x[r+1][c+6+i]='_';
    }
    x[r+1][c+13]='|';
    for(i=0;i<2;i++){
        x[r+1][c+14+i]='_';
    }
    x[r+1][c+16]='|';
    for(i=0;i<3;i++){
        x[r+1][c+17+i]='_';
    }
    x[r+1][c+20]='|';
    for(i=0;i<2;i++){
        x[r+1][c+21+i]='_';
    }
    x[r+1][c+23]='|';
    for(i=0;i<4;i++){
        x[r+1][c+24+i]='_';
    }
    x[r+1][c+28]='|';
    for(i=0;i<3;i++){
        x[r+1][c+29+i]='_';
    }
    x[r+1][c+32]='|';
    x[r+2][c+0]='_';
    x[r+2][c+1]='|';
    for(i=0;i<4;i++){
        x[r+2][c+2+i]='_';
    }
    x[r+2][c+6]='|';
    for(i=0;i<2;i++){
        x[r+2][c+7+i]='_';
    }
    x[r+2][c+9]='|';
    for(i=0;i<2;i++){
        x[r+2][c+10+i]='_';
    }
    x[r+2][c+12]='|';
    for(i=0;i<3;i++){
        x[r+2][c+13+i]='_';
    }
    x[r+2][c+16]='|';
    for(i=0;i<4;i++){
        x[r+2][c+17+i]='_';
    }
    x[r+2][c+21]='|';
    for(i=0;i<4;i++){
        x[r+2][c+22+i]='_';
    }
    x[r+2][c+26]='|';
    for(i=0;i<5;i++){
        x[r+2][c+27+i]='_';
    }
    x[r+2][c+32]='|';
    

    
    //mastaba with ladder
    r=100-23-1;
     c=600;
    
    for(i=0;i<44;i++){
        x[r+0][c+1+i]='-';
    }
    x[r+1][c+0]='|';
    x[r+1][c+1]='_';
    x[r+1][c+2]='|';
    for(i=0;i<3;i++){
        x[r+1][c+3+i]='_';
    }
    x[r+1][c+6]='|';
    for(i=0;i<7;i++){
        x[r+1][c+7+i]='_';
    }
    x[r+1][c+14]='|';
    for(i=0;i<2;i++){
        x[r+1][c+15+i]='_';
    }
    x[r+1][c+17]='|';
    for(i=0;i<3;i++){
        x[r+1][c+18+i]='_';
    }
    x[r+1][c+21]='|';
    for(i=0;i<2;i++){
        x[r+1][c+22+i]='_';
    }
    x[r+1][c+24]='|';
    for(i=0;i<4;i++){
        x[r+1][c+25+i]='_';
    }
    x[r+1][c+29]='|';
    for(i=0;i<4;i++){
        x[r+1][c+30+i]='_';
    }
    x[r+1][c+34]='|';
    for(i=0;i<4;i++){
        x[r+1][c+35+i]='_';
    }
    x[r+1][c+39]='|';
    for(i=0;i<5;i++){
        x[r+1][c+40+i]='_';
    }
    x[r+2][c+0]='|';
    x[r+2][c+1]='_';
    x[r+2][c+2]='|';
    for(i=0;i<4;i++){
        x[r+2][c+3+i]='_';
    }
    x[r+2][c+7]='|';
    for(i=0;i<2;i++){
        x[r+2][c+8+i]='_';
    }
    x[r+2][c+10]='|';
    for(i=0;i<2;i++){
        x[r+2][c+11+i]='_';
    }
    x[r+2][c+13]='|';
    for(i=0;i<3;i++){
        x[r+2][c+14+i]='_';
    }
    x[r+2][c+17]='|';
    for(i=0;i<4;i++){
        x[r+2][c+18+i]='_';
    }
    x[r+2][c+22]='|';
    for(i=0;i<4;i++){
        x[r+2][c+23+i]='_';
    }
    x[r+2][c+27]='|';
    for(i=0;i<5;i++){
        x[r+2][c+28+i]='_';
    }
    x[r+2][c+33]='|';
    for(i=0;i<3;i++){
        x[r+2][c+34+i]='_';
    }
    x[r+2][c+37]='|';
    for(i=0;i<4;i++){
        x[r+2][c+38+i]='_';
    }
    x[r+2][c+42]='|';
    for(i=0;i<2;i++){
        x[r+2][c+43+i]='_';
    }
    for(c=480+45;c<480+34*4;c+=34){
        for(i=0;i<34;i++){
            x[r+0][c+0+i]='-';
        }
        x[r+1][c+0]='_';
        x[r+1][c+1]='|';
        for(i=0;i<3;i++){
            x[r+1][c+2+i]='_';
        }
        x[r+1][c+5]='|';
        for(i=0;i<7;i++){
            x[r+1][c+6+i]='_';
        }
        x[r+1][c+13]='|';
        for(i=0;i<2;i++){
            x[r+1][c+14+i]='_';
        }
        x[r+1][c+16]='|';
        for(i=0;i<3;i++){
            x[r+1][c+17+i]='_';
        }
        x[r+1][c+20]='|';
        for(i=0;i<2;i++){
            x[r+1][c+21+i]='_';
        }
        x[r+1][c+23]='|';
        for(i=0;i<4;i++){
            x[r+1][c+24+i]='_';
        }
        x[r+1][c+28]='|';
        for(i=0;i<3;i++){
            x[r+1][c+29+i]='_';
        }
        x[r+1][c+32]='|';
        x[r+1][c+33]='_';
        x[r+2][c+0]='_';
        x[r+2][c+1]='|';
        for(i=0;i<4;i++){
            x[r+2][c+2+i]='_';
        }
        x[r+2][c+6]='|';
        for(i=0;i<2;i++){
            x[r+2][c+7+i]='_';
        }
        x[r+2][c+9]='|';
        for(i=0;i<2;i++){
            x[r+2][c+10+i]='_';
        }
        x[r+2][c+12]='|';
        for(i=0;i<3;i++){
            x[r+2][c+13+i]='_';
        }
        x[r+2][c+16]='|';
        for(i=0;i<4;i++){
            x[r+2][c+17+i]='_';
        }
        x[r+2][c+21]='|';
        for(i=0;i<4;i++){
            x[r+2][c+22+i]='_';
        }
        x[r+2][c+26]='|';
        for(i=0;i<3;i++){
            x[r+2][c+27+i]='_';
        }
        x[r+2][c+30]='|';
        for(i=0;i<3;i++){
            x[r+2][c+31+i]='_';
        }
        
    }
    
    for(i=0;i<32;i++){
        x[r+0][c+0+i]='-';
    }
    x[r+1][c+0]='_';
    x[r+1][c+1]='|';
    for(i=0;i<3;i++){
        x[r+1][c+2+i]='_';
    }
    x[r+1][c+5]='|';
    for(i=0;i<7;i++){
        x[r+1][c+6+i]='_';
    }
    x[r+1][c+13]='|';
    for(i=0;i<2;i++){
        x[r+1][c+14+i]='_';
    }
    x[r+1][c+16]='|';
    for(i=0;i<3;i++){
        x[r+1][c+17+i]='_';
    }
    x[r+1][c+20]='|';
    for(i=0;i<2;i++){
        x[r+1][c+21+i]='_';
    }
    x[r+1][c+23]='|';
    for(i=0;i<4;i++){
        x[r+1][c+24+i]='_';
    }
    x[r+1][c+28]='|';
    for(i=0;i<3;i++){
        x[r+1][c+29+i]='_';
    }
    x[r+1][c+32]='|';
    x[r+2][c+0]='_';
    x[r+2][c+1]='|';
    for(i=0;i<4;i++){
        x[r+2][c+2+i]='_';
    }
    x[r+2][c+6]='|';
    for(i=0;i<2;i++){
        x[r+2][c+7+i]='_';
    }
    x[r+2][c+9]='|';
    for(i=0;i<2;i++){
        x[r+2][c+10+i]='_';
    }
    x[r+2][c+12]='|';
    for(i=0;i<3;i++){
        x[r+2][c+13+i]='_';
    }
    x[r+2][c+16]='|';
    for(i=0;i<4;i++){
        x[r+2][c+17+i]='_';
    }
    x[r+2][c+21]='|';
    for(i=0;i<4;i++){
        x[r+2][c+22+i]='_';
    }
    x[r+2][c+26]='|';
    for(i=0;i<5;i++){
        x[r+2][c+27+i]='_';
    }
    x[r+2][c+32]='|';
  
}


void drawBlocker(wchar_t x[][1190]){
    int i;
   
    
    int r=4;
    int c=120+35*3+250;
    
    for(i=0;i<16;i++){
      x[r+0][c+0+i]='-';
     }
   x[r+1][c+0]='|';
   x[r+1][c+1]='_';
   x[r+1][c+2]='|';
    for(i=0;i<3;i++){
      x[r+1][c+3+i]='_';
     }
   x[r+1][c+6]='|';
    for(i=0;i<4;i++){
      x[r+1][c+7+i]='_';
     }
   x[r+1][c+11]='|';
    for(i=0;i<4;i++){
      x[r+1][c+12+i]='_';
     }
   x[r+1][c+16]='|';
   x[r+2][c+0]='|';
   x[r+2][c+1]='_';
   x[r+2][c+2]='|';
    for(i=0;i<5;i++){
      x[r+2][c+3+i]='_';
     }
   x[r+2][c+8]='|';
    for(i=0;i<4;i++){
      x[r+2][c+9+i]='_';
     }
   x[r+2][c+13]='|';
    for(i=0;i<2;i++){
      x[r+2][c+14+i]='_';
     }
   x[r+2][c+16]='|';
    r+=3;
    int z=r;
    
   
    for(r=144-3;r>=z-3;r-=3){
        
        x[r+0][c+0]='|';
        x[r+0][c+1]='_';
        x[r+0][c+2]='|';
         for(i=0;i<3;i++){
           x[r+0][c+3+i]='_';
          }
        x[r+0][c+6]='|';
         for(i=0;i<4;i++){
           x[r+0][c+7+i]='_';
          }
        x[r+0][c+11]='|';
         for(i=0;i<4;i++){
           x[r+0][c+12+i]='_';
          }
        x[r+0][c+16]='|';
        x[r+1][c+0]='|';
        x[r+1][c+1]='_';
        x[r+1][c+2]='|';
         for(i=0;i<5;i++){
           x[r+1][c+3+i]='_';
          }
        x[r+1][c+8]='|';
         for(i=0;i<4;i++){
           x[r+1][c+9+i]='_';
          }
        x[r+1][c+13]='|';
         for(i=0;i<2;i++){
           x[r+1][c+14+i]='_';
          }
        x[r+1][c+16]='|';
        x[r+2][c+0]='|';
        x[r+2][c+1]='_';
        x[r+2][c+2]='|';
         for(i=0;i<3;i++){
           x[r+2][c+3+i]='_';
          }
        x[r+2][c+6]='|';
         for(i=0;i<4;i++){
           x[r+2][c+7+i]='_';
          }
        x[r+2][c+11]='|';
         for(i=0;i<4;i++){
           x[r+2][c+12+i]='_';
          }
        x[r+2][c+16]='|';
    }
}
void drawMastabaWithLaser(wchar_t x[][1190]){
    int r=100;
    int c=110;
    int i;
    for(i=0;i<44;i++){
      x[r+0][c+1+i]='-';
     }
   x[r+1][c+0]='|';
   x[r+1][c+1]='_';
   x[r+1][c+2]='|';
    for(i=0;i<3;i++){
      x[r+1][c+3+i]='_';
     }
   x[r+1][c+6]='|';
    for(i=0;i<7;i++){
      x[r+1][c+7+i]='_';
     }
   x[r+1][c+14]='|';
    for(i=0;i<2;i++){
      x[r+1][c+15+i]='_';
     }
   x[r+1][c+17]='|';
    for(i=0;i<3;i++){
      x[r+1][c+18+i]='_';
     }
   x[r+1][c+21]='|';
    for(i=0;i<2;i++){
      x[r+1][c+22+i]='_';
     }
   x[r+1][c+24]='|';
    for(i=0;i<4;i++){
      x[r+1][c+25+i]='_';
     }
   x[r+1][c+29]='|';
    for(i=0;i<4;i++){
      x[r+1][c+30+i]='_';
     }
   x[r+1][c+34]='|';
    for(i=0;i<4;i++){
      x[r+1][c+35+i]='_';
     }
   x[r+1][c+39]='|';
    for(i=0;i<5;i++){
      x[r+1][c+40+i]='_';
     }
   x[r+2][c+0]='|';
   x[r+2][c+1]='_';
   x[r+2][c+2]='|';
    for(i=0;i<4;i++){
      x[r+2][c+3+i]='_';
     }
   x[r+2][c+7]='|';
    for(i=0;i<2;i++){
      x[r+2][c+8+i]='_';
     }
   x[r+2][c+10]='|';
    for(i=0;i<2;i++){
      x[r+2][c+11+i]='_';
     }
   x[r+2][c+13]='|';
    for(i=0;i<3;i++){
      x[r+2][c+14+i]='_';
     }
   x[r+2][c+17]='|';
    for(i=0;i<4;i++){
      x[r+2][c+18+i]='_';
     }
   x[r+2][c+22]='|';
    for(i=0;i<4;i++){
      x[r+2][c+23+i]='_';
     }
   x[r+2][c+27]='|';
    for(i=0;i<5;i++){
      x[r+2][c+28+i]='_';
     }
   x[r+2][c+33]='|';
    for(i=0;i<3;i++){
      x[r+2][c+34+i]='_';
     }
   x[r+2][c+37]='|';
    for(i=0;i<4;i++){
      x[r+2][c+38+i]='_';
     }
   x[r+2][c+42]='|';
    for(i=0;i<2;i++){
      x[r+2][c+43+i]='_';
     }
    for(c=120+30;c<120+45+34*2;c+=34){
        for(i=0;i<34;i++){
          x[r+0][c+0+i]='-';
         }
       x[r+1][c+0]='_';
       x[r+1][c+1]='|';
        for(i=0;i<3;i++){
          x[r+1][c+2+i]='_';
         }
       x[r+1][c+5]='|';
        for(i=0;i<7;i++){
          x[r+1][c+6+i]='_';
         }
       x[r+1][c+13]='|';
        for(i=0;i<2;i++){
          x[r+1][c+14+i]='_';
         }
       x[r+1][c+16]='|';
        for(i=0;i<3;i++){
          x[r+1][c+17+i]='_';
         }
       x[r+1][c+20]='|';
        for(i=0;i<2;i++){
          x[r+1][c+21+i]='_';
         }
       x[r+1][c+23]='|';
        for(i=0;i<4;i++){
          x[r+1][c+24+i]='_';
         }
       x[r+1][c+28]='|';
        for(i=0;i<3;i++){
          x[r+1][c+29+i]='_';
         }
       x[r+1][c+32]='|';
       x[r+1][c+33]='_';
       x[r+2][c+0]='_';
       x[r+2][c+1]='|';
        for(i=0;i<4;i++){
          x[r+2][c+2+i]='_';
         }
       x[r+2][c+6]='|';
        for(i=0;i<2;i++){
          x[r+2][c+7+i]='_';
         }
       x[r+2][c+9]='|';
        for(i=0;i<2;i++){
          x[r+2][c+10+i]='_';
         }
       x[r+2][c+12]='|';
        for(i=0;i<3;i++){
          x[r+2][c+13+i]='_';
         }
       x[r+2][c+16]='|';
        for(i=0;i<4;i++){
          x[r+2][c+17+i]='_';
         }
       x[r+2][c+21]='|';
        for(i=0;i<4;i++){
          x[r+2][c+22+i]='_';
         }
       x[r+2][c+26]='|';
        for(i=0;i<3;i++){
          x[r+2][c+27+i]='_';
         }
       x[r+2][c+30]='|';
        for(i=0;i<3;i++){
          x[r+2][c+31+i]='_';
         }
       
    }
    
    for(i=0;i<32;i++){
      x[r+0][c+0+i]='-';
     }
   x[r+1][c+0]='_';
   x[r+1][c+1]='|';
    for(i=0;i<3;i++){
      x[r+1][c+2+i]='_';
     }
   x[r+1][c+5]='|';
    for(i=0;i<7;i++){
      x[r+1][c+6+i]='_';
     }
   x[r+1][c+13]='|';
    for(i=0;i<2;i++){
      x[r+1][c+14+i]='_';
     }
   x[r+1][c+16]='|';
    for(i=0;i<3;i++){
      x[r+1][c+17+i]='_';
     }
   x[r+1][c+20]='|';
    for(i=0;i<2;i++){
      x[r+1][c+21+i]='_';
     }
   x[r+1][c+23]='|';
    for(i=0;i<4;i++){
      x[r+1][c+24+i]='_';
     }
   x[r+1][c+28]='|';
    for(i=0;i<3;i++){
      x[r+1][c+29+i]='_';
     }
   x[r+1][c+32]='|';
   x[r+2][c+0]='_';
   x[r+2][c+1]='|';
    for(i=0;i<4;i++){
      x[r+2][c+2+i]='_';
     }
   x[r+2][c+6]='|';
    for(i=0;i<2;i++){
      x[r+2][c+7+i]='_';
     }
   x[r+2][c+9]='|';
    for(i=0;i<2;i++){
      x[r+2][c+10+i]='_';
     }
   x[r+2][c+12]='|';
    for(i=0;i<3;i++){
      x[r+2][c+13+i]='_';
     }
   x[r+2][c+16]='|';
    for(i=0;i<4;i++){
      x[r+2][c+17+i]='_';
     }
   x[r+2][c+21]='|';
    for(i=0;i<4;i++){
      x[r+2][c+22+i]='_';
     }
   x[r+2][c+26]='|';
    for(i=0;i<5;i++){
      x[r+2][c+27+i]='_';
     }
   x[r+2][c+32]='|';
    
    
    
    // draw laser holder
    int cLaser;
    cLaser=120;
    for(;cLaser<=120+35*5;cLaser+=37){
       
        if(cLaser==159-2){
            x[143][cLaser]=92;
            x[143][cLaser+1]='-';
            x[143][cLaser+2]='-';
            x[143][cLaser+3]='-';
            x[143][cLaser+4]='/';
        }
        else{
            
            if(cLaser==233-2){
                x[143][cLaser]=92;
                x[143][cLaser+1]='-';
                x[143][cLaser+2]='-';
                x[143][cLaser+3]='-';
                x[143][cLaser+4]='/';
            }
            else{
                x[103][cLaser]=92;
                x[103][cLaser+1]='_';
                x[103][cLaser+2]='_';
                x[103][cLaser+3]='_';
                x[103][cLaser+4]='/';
            }
        }
    
    }
  
    

    
   
    
}
void drawLaser(wchar_t x[][1190], Laser&laser){
    int i;
  
    if(laser.frames%20==0 &&laser.frames<=20*39*2){
     

        
        if(laser.LRowE==104){
            laser.dir*=-1;
        }
        if(laser.LRowE==143){
            laser.dir*=-1;
        }
        laser.LRowE+=laser.dir;
        laser.LRowE2+=laser.dir*-1;
 
    }
    if(laser.frames<=20*39*2){
        for(i=104;i<=laser.LRowE;i++){
            x[i][122]=219;
    //        x[i][159]=219;
            x[i][196]=219;
    //        x[i][233]=219;
            x[i][270]=219;
        }
        for(i=142;i>=laser.LRowE2;i--){

            x[i][159]=219;
            x[i][233]=219;

        }
    }
    if(laser.frames==20*44*2){
        laser.frames=-1;
    }
      
    
    
    laser.frames++;
}

void initializechar(wchar_t x[][1190]) {
    // Initialize all cells to '.'
    for (int i = 0; i < 222; i++) {
        for (int j = 0; j < 1190; j++) {
            x[i][j] = ' ';
        }
    }

   
}


void GameOVer(wchar_t x[][1190]){
    int r=7,c=85,i;
    x[r+0][c+28]=40;
    x[r+1][c+16]=46;
    x[r+1][c+29]=41;
    x[r+1][c+38]=41;
    x[r+2][c+25]=40;
    x[r+2][c+28]=40;
    x[r+2][c+29]=124;
    x[r+2][c+44]=46;
    x[r+3][c+21]=41;
    x[r+3][c+25]=41;
    x[r+3][c+26]=92;
    x[r+3][c+27]=47;
    x[r+3][c+29]=40;
    x[r+3][c+31]=40;
    x[r+3][c+33]=40;
    x[r+4][c+13]=42;
    x[r+4][c+16]=40;
     for(i=0;i<2;i++){
       x[r+4][c+20+i]=40;
      }
    x[r+4][c+24]=47;
     for(i=0;i<2;i++){
       x[r+4][c+30+i]=41;
      }
    x[r+4][c+32]=92;
     for(i=0;i<2;i++){
       x[r+4][c+33+i]=41;
      }
    x[r+4][c+37]=40;
    x[r+4][c+40]=41;
    x[r+4][c+45]=41;
    x[r+5][c+11]=40;
    x[r+5][c+17]=92;
    x[r+5][c+21]=41;
    x[r+5][c+22]=92;
    x[r+5][c+23]=40;
    x[r+5][c+34]=124;
     for(i=0;i<2;i++){
       x[r+5][c+37+i]=41;
      }
    x[r+5][c+39]=40;
    x[r+5][c+41]=41;
    x[r+5][c+44]=40;
    x[r+5][c+45]=124;
    x[r+6][c+11]=62;
    x[r+6][c+12]=41;
     for(i=0;i<2;i++){
       x[r+6][c+18+i]=41;
      }
    x[r+6][c+20]=47;
    x[r+6][c+24]=124;
    x[r+6][c+35]=41;
    x[r+6][c+36]=47;
    x[r+6][c+39]=92;
     for(i=0;i<2;i++){
       x[r+6][c+40+i]=40;
      }
    x[r+6][c+44]=41;
    x[r+6][c+46]=92;
    x[r+7][c+11]=40;
    x[r+7][c+17]=40;
    x[r+7][c+24]=46;
    x[r+7][c+33]=45;
    x[r+7][c+34]=46;
    x[r+7][c+40]=86;
    x[r+7][c+42]=41;
    x[r+7][c+43]=47;
    x[r+7][c+47]=41;
    x[r+7][c+48]=40;
    x[r+7][c+53]=40;
    x[r+8][c+12]=92;
    x[r+8][c+16]=47;
    x[r+8][c+22]=46;
    x[r+8][c+26]=92;
    x[r+8][c+39]=46;
    x[r+8][c+47]=92;
     for(i=0;i<2;i++){
       x[r+8][c+48+i]=41;
      }
     for(i=0;i<2;i++){
       x[r+8][c+53+i]=41;
      }
    x[r+9][c+14]=41;
    x[r+9][c+15]=40;
    x[r+9][c+22]=40;
    x[r+9][c+25]=124;
    x[r+9][c+27]=124;
    x[r+9][c+31]=41;
    x[r+9][c+44]=46;
    x[r+9][c+49]=40;
    x[r+9][c+52]=47;
    x[r+10][c+13]=41;
    x[r+10][c+14]=40;
    x[r+10][c+19]=44;
    x[r+10][c+20]=39;
     for(i=0;i<2;i++){
       x[r+10][c+21+i]=41;
      }
    x[r+10][c+28]=92;
    x[r+10][c+30]=47;
    x[r+10][c+41]=92;
    x[r+10][c+42]=40;
    x[r+10][c+44]=96;
    x[r+10][c+45]=46;
    x[r+10][c+50]=41;
    x[r+11][c+13]=40;
    x[r+11][c+14]=92;
    x[r+11][c+15]=62;
    x[r+11][c+18]=44;
    x[r+11][c+19]=39;
    x[r+11][c+20]=47;
     for(i=0;i<2;i++){
       x[r+11][c+21+i]=95;
      }
     for(i=0;i<2;i++){
       x[r+11][c+29+i]=41;
      }
     for(i=0;i<2;i++){
       x[r+11][c+43+i]=95;
      }
    x[r+11][c+45]=96;
    x[r+11][c+46]=46;
    x[r+11][c+49]=47;
    x[r+12][c+12]=40;
    x[r+12][c+14]=92;
    x[r+12][c+18]=124;
    x[r+12][c+20]=47;
     for(i=0;i<3;i++){
       x[r+12][c+23+i]=95;
      }
    x[r+12][c+29]=40;
    x[r+12][c+31]=92;
    x[r+12][c+32]=47;
     for(i=0;i<3;i++){
       x[r+12][c+38+i]=95;
      }
    x[r+12][c+44]=92;
    x[r+12][c+46]=124;
    x[r+12][c+48]=40;
    x[r+12][c+50]=40;
    x[r+13][c+13]=92;
    x[r+13][c+14]=46;
    x[r+13][c+15]=41;
    x[r+13][c+18]=124;
    x[r+13][c+19]=47;
    x[r+13][c+22]=47;
    x[r+13][c+26]=92;
     for(i=0;i<2;i++){
       x[r+13][c+27+i]=95;
      }
     for(i=0;i<2;i++){
       x[r+13][c+35+i]=95;
      }
    x[r+13][c+37]=47;
    x[r+13][c+41]=92;
    x[r+13][c+45]=92;
    x[r+13][c+46]=124;
     for(i=0;i<2;i++){
       x[r+13][c+49+i]=41;
      }
    x[r+14][c+12]=46;
    x[r+14][c+15]=92;
    x[r+14][c+16]=46;
    x[r+14][c+18]=124;
    x[r+14][c+19]=62;
    x[r+14][c+22]=92;
    x[r+14][c+29]=124;
     for(i=0;i<2;i++){
       x[r+14][c+31+i]=95;
      }
    x[r+14][c+34]=124;
    x[r+14][c+41]=47;
    x[r+14][c+45]=60;
    x[r+14][c+46]=124;
    x[r+14][c+49]=47;
    x[r+15][c+17]=41;
    x[r+15][c+18]=47;
    x[r+15][c+23]=92;
     for(i=0;i<4;i++){
       x[r+15][c+24+i]=95;
      }
    x[r+15][c+28]=47;
    x[r+15][c+30]=58;
     for(i=0;i<2;i++){
       x[r+15][c+31+i]=46;
      }
    x[r+15][c+33]=58;
    x[r+15][c+35]=92;
     for(i=0;i<4;i++){
       x[r+15][c+36+i]=95;
      }
    x[r+15][c+40]=47;
    x[r+15][c+46]=92;
    x[r+15][c+48]=60;
    x[r+16][c+10]=41;
    x[r+16][c+14]=92;
    x[r+16][c+16]=40;
    x[r+16][c+17]=124;
     for(i=0;i<2;i++){
       x[r+16][c+18+i]=95;
      }
    x[r+16][c+22]=46;
    x[r+16][c+29]=47;
    x[r+16][c+31]=59;
    x[r+16][c+32]=58;
    x[r+16][c+34]=92;
     for(i=0;i<2;i++){
       x[r+16][c+45+i]=95;
      }
    x[r+16][c+47]=124;
    x[r+16][c+49]=41;
    x[r+16][c+52]=40;
     for(i=0;i<2;i++){
       x[r+17][c+9+i]=40;
      }
    x[r+17][c+15]=41;
    x[r+17][c+16]=92;
    x[r+17][c+17]=41;
    x[r+17][c+20]=126;
     for(i=0;i<2;i++){
       x[r+17][c+21+i]=45;
      }
    x[r+17][c+23]=95;
     for(i=0;i<2;i++){
       x[r+17][c+29+i]=45;
      }
     for(i=0;i<2;i++){
       x[r+17][c+33+i]=45;
      }
    x[r+17][c+41]=95;
     for(i=0;i<2;i++){
       x[r+17][c+42+i]=45;
      }
    x[r+17][c+44]=126;
    x[r+17][c+49]=47;
     for(i=0;i<2;i++){
       x[r+17][c+52+i]=41;
      }
    x[r+18][c+10]=92;
    x[r+18][c+15]=40;
    x[r+18][c+20]=124;
     for(i=0;i<2;i++){
       x[r+18][c+23+i]=124;
      }
     for(i=0;i<2;i++){
       x[r+18][c+40+i]=124;
      }
    x[r+18][c+44]=124;
    x[r+18][c+48]=40;
    x[r+18][c+51]=47;
    x[r+19][c+16]=92;
    x[r+19][c+17]=46;
    x[r+19][c+20]=124;
     for(i=0;i<2;i++){
       x[r+19][c+23+i]=124;
      }
    x[r+19][c+25]=95;
    x[r+19][c+39]=95;
     for(i=0;i<2;i++){
       x[r+19][c+40+i]=124;
      }
    x[r+19][c+44]=124;
    x[r+19][c+47]=47;
    x[r+20][c+18]=62;
    x[r+20][c+20]=58;
    x[r+20][c+23]=124;
    x[r+20][c+26]=126;
    x[r+20][c+27]=86;
    x[r+20][c+28]=43;
    x[r+20][c+29]=45;
    x[r+20][c+30]=73;
    x[r+20][c+31]=95;
    x[r+20][c+32]=73;
    x[r+20][c+33]=95;
    x[r+20][c+34]=73;
    x[r+20][c+35]=45;
    x[r+20][c+36]=43;
    x[r+20][c+37]=86;
    x[r+20][c+38]=126;
    x[r+20][c+41]=124;
    x[r+20][c+44]=58;
    x[r+20][c+46]=40;
    x[r+20][c+47]=46;
    x[r+21][c+17]=40;
    x[r+21][c+20]=92;
    x[r+21][c+21]=58;
    x[r+21][c+24]=84;
    x[r+21][c+25]=92;
    x[r+21][c+29]=95;
    x[r+21][c+35]=95;
    x[r+21][c+39]=47;
    x[r+21][c+40]=84;
    x[r+21][c+43]=58;
    x[r+21][c+45]=46;
    x[r+21][c+46]=47;
    x[r+22][c+18]=92;
    x[r+22][c+21]=58;
    x[r+22][c+26]=84;
    x[r+22][c+27]=94;
    x[r+22][c+28]=84;
    x[r+22][c+30]=84;
    x[r+22][c+31]=45;
    x[r+22][c+32]=43;
    x[r+22][c+33]=45;
    x[r+22][c+34]=84;
    x[r+22][c+36]=84;
    x[r+22][c+37]=94;
    x[r+22][c+38]=84;
    x[r+22][c+43]=59;
    x[r+22][c+44]=60;
    x[r+23][c+19]=92;
     for(i=0;i<2;i++){
       x[r+23][c+20+i]=46;
      }
    x[r+23][c+22]=96;
    x[r+23][c+23]=95;
    x[r+23][c+31]=45;
    x[r+23][c+32]=43;
    x[r+23][c+33]=45;
    x[r+23][c+41]=95;
    x[r+23][c+42]=39;
    x[r+23][c+45]=41;
    x[r+24][c+9]=41;
    x[r+24][c+22]=46;
    x[r+24][c+24]=96;
     for(i=0;i<2;i++){
       x[r+24][c+25+i]=45;
      }
    x[r+24][c+27]=61;
     for(i=0;i<2;i++){
       x[r+24][c+28+i]=46;
      }
     for(i=0;i<5;i++){
       x[r+24][c+30+i]=95;
      }
     for(i=0;i<2;i++){
       x[r+24][c+35+i]=46;
      }
    x[r+24][c+37]=61;
     for(i=0;i<2;i++){
       x[r+24][c+38+i]=45;
      }
    x[r+24][c+40]=39;
    x[r+24][c+41]=46;
    x[r+24][c+43]=46;
    x[r+24][c+44]=47;
    x[r+24][c+54]=40;
     for(i=0;i<2;i++){
       x[r+25][c+8+i]=40;
      }
    x[r+25][c+15]=41;
    x[r+25][c+17]=40;
    x[r+25][c+28]=41;
    x[r+25][c+42]=40;
    x[r+25][c+48]=41;
    x[r+25][c+50]=40;
    x[r+25][c+54]=41;
    x[r+25][c+55]=62;
    x[r+26][c+9]=62;
    x[r+26][c+11]=92;
    x[r+26][c+12]=47;
    x[r+26][c+13]=94;
    x[r+26][c+14]=47;
    x[r+26][c+15]=41;
     for(i=0;i<2;i++){
       x[r+26][c+17+i]=41;
      }
    x[r+26][c+20]=40;
    x[r+26][c+24]=40;
    x[r+26][c+26]=47;
    x[r+26][c+27]=40;
    x[r+26][c+28]=46;
     for(i=0;i<2;i++){
       x[r+26][c+35+i]=41;
      }
     for(i=0;i<2;i++){
       x[r+26][c+42+i]=41;
      }
    x[r+26][c+44]=46;
    x[r+26][c+45]=95;
    x[r+26][c+46]=47;
    x[r+26][c+47]=40;
     for(i=0;i<2;i++){
       x[r+26][c+48+i]=95;
      }
     for(i=0;i<2;i++){
       x[r+26][c+50+i]=41;
      }
    x[r+26][c+52]=46;
    x[r+26][c+53]=47;
    x[r+26][c+55]=40;
    x[r+26][c+56]=95;
    x[r+26][c+57]=46;
    x[r+27][c+8]=40;
    x[r+27][c+11]=95;
     for(i=0;i<2;i++){
       x[r+27][c+12+i]=46;
      }
    x[r+27][c+14]=47;
    x[r+27][c+16]=40;
    x[r+27][c+18]=92;
     for(i=0;i<2;i++){
       x[r+27][c+19+i]=41;
      }
    x[r+27][c+25]=41;
    x[r+27][c+29]=92;
    x[r+27][c+31]=40;
    x[r+27][c+34]=47;
    x[r+27][c+36]=92;
    x[r+27][c+37]=46;
    x[r+27][c+40]=46;
    x[r+27][c+41]=47;
     for(i=0;i<2;i++){
       x[r+27][c+43+i]=124;
      }
     for(i=0;i<2;i++){
       x[r+27][c+47+i]=46;
      }
     for(i=0;i<2;i++){
       x[r+27][c+49+i]=95;
      }
    x[r+27][c+51]=58;
    x[r+27][c+52]=124;
    x[r+27][c+55]=95;
    x[r+27][c+56]=46;
    x[r+27][c+58]=92;
    x[r+28][c+8]=124;
    x[r+28][c+11]=92;
     for(i=0;i<2;i++){
       x[r+28][c+12+i]=95;
      }
    x[r+28][c+14]=46;
    x[r+28][c+17]=41;
    x[r+28][c+19]=124;
    x[r+28][c+23]=40;
    x[r+28][c+24]=47;
    x[r+28][c+27]=47;
    x[r+28][c+28]=58;
    x[r+28][c+30]=58;
     for(i=0;i<2;i++){
       x[r+28][c+31+i]=41;
      }
    x[r+28][c+34]=124;
    x[r+28][c+38]=92;
    x[r+28][c+39]=47;
    x[r+28][c+43]=124;
    x[r+28][c+44]=40;
    x[r+28][c+47]=60;
     for(i=0;i<2;i++){
       x[r+28][c+48+i]=46;
      }
    x[r+28][c+50]=95;
    x[r+28][c+53]=41;
    x[r+28][c+54]=124;
    x[r+28][c+57]=41;
    x[r+28][c+59]=41;
     for(i=0;i<2;i++){
       x[r+29][c+7+i]=41;
      }
    x[r+29][c+11]=95;
    x[r+29][c+12]=46;
    x[r+29][c+13]=47;
    x[r+29][c+17]=124;
    x[r+29][c+20]=41;
     for(i=0;i<2;i++){
       x[r+29][c+23+i]=41;
      }
     for(i=0;i<2;i++){
       x[r+29][c+27+i]=95;
      }
    x[r+29][c+31]=60;
    x[r+29][c+34]=124;
    x[r+29][c+36]=58;
    x[r+29][c+37]=40;
    x[r+29][c+43]=58;
     for(i=0;i<2;i++){
       x[r+29][c+44+i]=41;
      }
    x[r+29][c+49]=46;
     for(i=0;i<2;i++){
       x[r+29][c+50+i]=47;
      }
    x[r+29][c+52]=40;
    x[r+29][c+54]=58;
    x[r+29][c+57]=58;
    x[r+29][c+59]=124;
    x[r+30][c+7]=40;
    x[r+30][c+8]=58;
    x[r+30][c+10]=60;
    x[r+30][c+16]=41;
    x[r+30][c+17]=58;
     for(i=0;i<2;i++){
       x[r+30][c+20+i]=45;
      }
    x[r+30][c+22]=58;
    x[r+30][c+26]=94;
    x[r+30][c+29]=92;
    x[r+30][c+32]=41;
    x[r+30][c+33]=40;
    x[r+30][c+37]=41;
    x[r+30][c+38]=92;
    x[r+30][c+39]=47;
    x[r+30][c+40]=58;
    x[r+30][c+44]=47;
    x[r+30][c+48]=47;
    x[r+30][c+49]=95;
    x[r+30][c+50]=47;
    x[r+30][c+52]=41;
    x[r+30][c+54]=58;
    x[r+30][c+55]=46;
    x[r+30][c+56]=95;
    x[r+30][c+57]=41;
    x[r+30][c+59]=58;
    x[r+31][c+8]=92;
     for(i=0;i<2;i++){
       x[r+31][c+9+i]=46;
      }
    x[r+31][c+11]=41;
    x[r+31][c+15]=40;
    x[r+31][c+16]=95;
     for(i=0;i<2;i++){
       x[r+31][c+17+i]=46;
      }
     for(i=0;i<2;i++){
       x[r+31][c+21+i]=46;
      }
    x[r+31][c+25]=58;
    x[r+31][c+30]=58;
    x[r+31][c+33]=58;
    x[r+31][c+35]=46;
    x[r+31][c+36]=40;
    x[r+31][c+40]=92;
     for(i=0;i<2;i++){
       x[r+31][c+41+i]=46;
      }
    x[r+31][c+43]=58;
     for(i=0;i<2;i++){
       x[r+31][c+44+i]=46;
      }
    x[r+31][c+50]=46;
    x[r+31][c+51]=47;
     for(i=0;i<2;i++){
       x[r+31][c+52+i]=95;
      }
    x[r+31][c+54]=46;
    x[r+31][c+57]=46;
    x[r+31][c+58]=47;
    x[r+32][c+19]=94;
    x[r+32][c+24]=94;
    x[r+32][c+31]=92;
    x[r+32][c+32]=94;
    x[r+32][c+34]=94;
    x[r+32][c+46]=94;
    x[r+32][c+47]=92;
    x[r+32][c+48]=47;
    x[r+32][c+49]=94;
    x[r+32][c+55]=94;
    
    
    //    WANT TO PLAY AGAIN?
        
        
        
        r +=40;
        c-=21;
        
        
       
    x[r+0][c+0]='.';
     for(i=0;i<2;i++){
       x[r+0][c+3+i]='.';
      }
     for(i=0;i<2;i++){
       x[r+0][c+5+i]='_';
      }
     for(i=0;i<2;i++){
       x[r+0][c+7+i]='.';
      }
     for(i=0;i<2;i++){
       x[r+0][c+11+i]='.';
      }
     for(i=0;i<3;i++){
       x[r+0][c+13+i]='_';
      }
    x[r+0][c+16]='.';
    x[r+0][c+21]='.';
     for(i=0;i<3;i++){
       x[r+0][c+22+i]='_';
      }
     for(i=0;i<2;i++){
       x[r+0][c+25+i]='.';
      }
     for(i=0;i<2;i++){
       x[r+0][c+27+i]='_';
      }
    x[r+0][c+29]='.';
    x[r+0][c+34]='.';
     for(i=0;i<2;i++){
       x[r+0][c+35+i]='_';
      }
    x[r+0][c+38]='.';
    x[r+0][c+42]='.';
     for(i=0;i<2;i++){
       x[r+0][c+43+i]='_';
      }
     for(i=0;i<2;i++){
       x[r+0][c+45+i]='.';
      }
    x[r+0][c+50]=',';
    x[r+0][c+55]='.';
     for(i=0;i<2;i++){
       x[r+0][c+56+i]='_';
      }
     for(i=0;i<2;i++){
       x[r+0][c+58+i]='.';
      }
     for(i=0;i<2;i++){
       x[r+0][c+60+i]='_';
      }
    x[r+0][c+63]='.';
     for(i=0;i<2;i++){
       x[r+0][c+64+i]='_';
      }
     for(i=0;i<2;i++){
       x[r+0][c+66+i]='.';
      }
    x[r+0][c+68]='_';
     for(i=0;i<2;i++){
       x[r+0][c+69+i]='.';
      }
    x[r+0][c+73]='.';
    x[r+0][c+75]='_';
    x[r+0][c+81]='[';
    x[r+0][c+82]='~';
    x[r+0][c+86]='.';
    x[r+0][c+90]=',';
    x[r+0][c+95]='/';
    x[r+0][c+99]='.';
    x[r+0][c+102]='.';
    x[r+0][c+106]='~';
    x[r+0][c+107]=']';
    x[r+1][c+0]='|';
    x[r+1][c+3]='|';
    x[r+1][c+4]='[';
     for(i=0;i<2;i++){
       x[r+1][c+5+i]='_';
      }
    x[r+1][c+7]=']';
    x[r+1][c+8]='|';
    x[r+1][c+9]=92;
    x[r+1][c+11]='|';
    x[r+1][c+14]='|';
    x[r+1][c+23]='|';
    x[r+1][c+26]='|';
    x[r+1][c+29]='|';
    x[r+1][c+34]='[';
     for(i=0;i<2;i++){
       x[r+1][c+35+i]='_';
      }
    x[r+1][c+37]=')';
    x[r+1][c+38]='|';
    x[r+1][c+42]='[';
     for(i=0;i<2;i++){
       x[r+1][c+43+i]='_';
      }
    x[r+1][c+45]=']';
    x[r+1][c+47]=92;
    x[r+1][c+48]='.';
    x[r+1][c+49]='/';
    x[r+1][c+55]='[';
     for(i=0;i<2;i++){
       x[r+1][c+56+i]='_';
      }
    x[r+1][c+58]=']';
    x[r+1][c+59]='[';
     for(i=0;i<2;i++){
       x[r+1][c+61+i]='_';
      }
    x[r+1][c+63]='[';
     for(i=0;i<2;i++){
       x[r+1][c+64+i]='_';
      }
    x[r+1][c+66]=']';
    x[r+1][c+68]='|';
    x[r+1][c+70]='|';
    x[r+1][c+71]=92;
    x[r+1][c+73]='|';
    x[r+1][c+74]=39;
    x[r+1][c+76]=')';
    x[r+1][c+81]='[';
    x[r+1][c+87]=92;
    x[r+1][c+88]='.';
    x[r+1][c+89]='/';
    x[r+1][c+94]='/';
    x[r+1][c+99]='|';
    x[r+1][c+100]=92;
    x[r+1][c+102]='|';
    x[r+1][c+107]=']';
    x[r+2][c+0]='|';
    x[r+2][c+1]='/';
    x[r+2][c+2]=92;
     for(i=0;i<2;i++){
       x[r+2][c+3+i]='|';
      }
     for(i=0;i<2;i++){
       x[r+2][c+7+i]='|';
      }
    x[r+2][c+10]=92;
    x[r+2][c+11]='|';
    x[r+2][c+14]='|';
    x[r+2][c+23]='|';
    x[r+2][c+26]='|';
     for(i=0;i<2;i++){
       x[r+2][c+27+i]='_';
      }
    x[r+2][c+29]='|';
    x[r+2][c+34]='|';
    x[r+2][c+38]='|';
     for(i=0;i<3;i++){
       x[r+2][c+39+i]='_';
      }
    x[r+2][c+42]='|';
    x[r+2][c+45]='|';
    x[r+2][c+48]='|';
    x[r+2][c+55]='|';
    x[r+2][c+58]='|';
    x[r+2][c+59]='[';
    x[r+2][c+60]='_';
    x[r+2][c+61]='.';
    x[r+2][c+62]='/';
    x[r+2][c+63]='|';
    x[r+2][c+66]='|';
    x[r+2][c+67]='_';
    x[r+2][c+68]='|';
    x[r+2][c+69]='_';
    x[r+2][c+70]='|';
    x[r+2][c+72]=92;
    x[r+2][c+73]='|';
    x[r+2][c+75]=';';
    x[r+2][c+81]='[';
    x[r+2][c+82]='_';
    x[r+2][c+88]='|';
    x[r+2][c+93]='/';
    x[r+2][c+99]='|';
    x[r+2][c+101]=92;
    x[r+2][c+102]='|';
    x[r+2][c+106]='_';
    x[r+2][c+107]=']';
}
void congrats(wchar_t x[][1190]){
    int r=20,c=85,i;
   
    
    x[r+0][c+0]='.';
    x[r+1][c+18]='.';
    x[r+1][c+26]='|';
    x[r+1][c+36]='.';
    x[r+1][c+41]='.';
    x[r+2][c+12]='.';
    x[r+2][c+15]='*';
    x[r+2][c+25]='-';
    x[r+2][c+26]='*';
    x[r+2][c+27]='-';
    x[r+2][c+38]='*';
    x[r+3][c+17]=92;
    x[r+3][c+26]='|';
    x[r+3][c+36]='/';
    x[r+3][c+40]='.';
    x[r+4][c+0]='.';
    x[r+4][c+5]='.';
    x[r+4][c+18]='.';
    x[r+4][c+25]='/';
    x[r+4][c+26]='^';
    x[r+4][c+27]=92;
    x[r+4][c+33]='.';
    x[r+4][c+48]='.';
    x[r+4][c+53]='.';
    x[r+5][c+3]='*';
    x[r+5][c+8]='|';
    x[r+5][c+9]=92;
    x[r+5][c+13]='/';
    x[r+5][c+14]=92;
    x[r+5][c+19]='/';
    x[r+5][c+20]=92;
    x[r+5][c+23]='/';
    x[r+5][c+25]='/';
    x[r+5][c+27]=92;
    x[r+5][c+29]=92;
    x[r+5][c+32]='/';
    x[r+5][c+33]=92;
    x[r+5][c+38]='/';
    x[r+5][c+39]=92;
    x[r+5][c+43]='/';
    x[r+5][c+44]='|';
    x[r+5][c+49]='*';
    x[r+6][c+1]='.';
    x[r+6][c+5]='.';
    x[r+6][c+8]='|';
    x[r+6][c+11]=92;
    x[r+6][c+13]=92;
    x[r+6][c+14]='/';
    x[r+6][c+16]='/';
    x[r+6][c+17]=92;
    x[r+6][c+19]=92;
    x[r+6][c+21]='/';
    x[r+6][c+23]='/';
    x[r+6][c+29]=92;
    x[r+6][c+31]=92;
    x[r+6][c+33]='/';
    x[r+6][c+35]='/';
    x[r+6][c+36]=92;
    x[r+6][c+38]=92;
    x[r+6][c+39]='/';
    x[r+6][c+41]='/';
    x[r+6][c+44]='|';
    x[r+6][c+46]='.';
    x[r+6][c+52]='.';
    x[r+7][c+9]=92;
    x[r+7][c+11]='|';
    x[r+7][c+13]='_';
    x[r+7][c+15]='_';
    x[r+7][c+16]=92;
    x[r+7][c+17]='/';
    x[r+7][c+18]='_';
    x[r+7][c+20]='_';
    x[r+7][c+22]=92;
    x[r+7][c+23]='_';
    x[r+7][c+24]=92;
    x[r+7][c+25]='_';
    x[r+7][c+27]='_';
    x[r+7][c+29]='/';
    x[r+7][c+30]='_';
    x[r+7][c+31]='/';
    x[r+7][c+32]='_';
    x[r+7][c+34]='_';
    x[r+7][c+35]=92;
    x[r+7][c+36]='/';
    x[r+7][c+37]='_';
    x[r+7][c+39]='_';
    x[r+7][c+41]=92;
    x[r+7][c+42]='_';
    x[r+7][c+43]='/';
    x[r+8][c+11]=92;
    x[r+8][c+14]='*';
    x[r+8][c+17]='*';
    x[r+8][c+20]='*';
    x[r+8][c+24]=92;
    x[r+8][c+26]=92;
    x[r+8][c+27]='/';
    x[r+8][c+29]='/';
    x[r+8][c+32]='*';
    x[r+8][c+35]='*';
    x[r+8][c+38]='*';
    x[r+8][c+41]='/';
    
        r +=20;
        c-=21;
        
        
       
    x[r+0][c+0]='.';
     for(i=0;i<2;i++){
       x[r+0][c+3+i]='.';
      }
     for(i=0;i<2;i++){
       x[r+0][c+5+i]='_';
      }
     for(i=0;i<2;i++){
       x[r+0][c+7+i]='.';
      }
     for(i=0;i<2;i++){
       x[r+0][c+11+i]='.';
      }
     for(i=0;i<3;i++){
       x[r+0][c+13+i]='_';
      }
    x[r+0][c+16]='.';
    x[r+0][c+21]='.';
     for(i=0;i<3;i++){
       x[r+0][c+22+i]='_';
      }
     for(i=0;i<2;i++){
       x[r+0][c+25+i]='.';
      }
     for(i=0;i<2;i++){
       x[r+0][c+27+i]='_';
      }
    x[r+0][c+29]='.';
    x[r+0][c+34]='.';
     for(i=0;i<2;i++){
       x[r+0][c+35+i]='_';
      }
    x[r+0][c+38]='.';
    x[r+0][c+42]='.';
     for(i=0;i<2;i++){
       x[r+0][c+43+i]='_';
      }
     for(i=0;i<2;i++){
       x[r+0][c+45+i]='.';
      }
    x[r+0][c+50]=',';
    x[r+0][c+55]='.';
     for(i=0;i<2;i++){
       x[r+0][c+56+i]='_';
      }
     for(i=0;i<2;i++){
       x[r+0][c+58+i]='.';
      }
     for(i=0;i<2;i++){
       x[r+0][c+60+i]='_';
      }
    x[r+0][c+63]='.';
     for(i=0;i<2;i++){
       x[r+0][c+64+i]='_';
      }
     for(i=0;i<2;i++){
       x[r+0][c+66+i]='.';
      }
    x[r+0][c+68]='_';
     for(i=0;i<2;i++){
       x[r+0][c+69+i]='.';
      }
    x[r+0][c+73]='.';
    x[r+0][c+75]='_';
    x[r+0][c+81]='[';
    x[r+0][c+82]='~';
    x[r+0][c+86]='.';
    x[r+0][c+90]=',';
    x[r+0][c+95]='/';
    x[r+0][c+99]='.';
    x[r+0][c+102]='.';
    x[r+0][c+106]='~';
    x[r+0][c+107]=']';
    x[r+1][c+0]='|';
    x[r+1][c+3]='|';
    x[r+1][c+4]='[';
     for(i=0;i<2;i++){
       x[r+1][c+5+i]='_';
      }
    x[r+1][c+7]=']';
    x[r+1][c+8]='|';
    x[r+1][c+9]=92;
    x[r+1][c+11]='|';
    x[r+1][c+14]='|';
    x[r+1][c+23]='|';
    x[r+1][c+26]='|';
    x[r+1][c+29]='|';
    x[r+1][c+34]='[';
     for(i=0;i<2;i++){
       x[r+1][c+35+i]='_';
      }
    x[r+1][c+37]=')';
    x[r+1][c+38]='|';
    x[r+1][c+42]='[';
     for(i=0;i<2;i++){
       x[r+1][c+43+i]='_';
      }
    x[r+1][c+45]=']';
    x[r+1][c+47]=92;
    x[r+1][c+48]='.';
    x[r+1][c+49]='/';
    x[r+1][c+55]='[';
     for(i=0;i<2;i++){
       x[r+1][c+56+i]='_';
      }
    x[r+1][c+58]=']';
    x[r+1][c+59]='[';
     for(i=0;i<2;i++){
       x[r+1][c+61+i]='_';
      }
    x[r+1][c+63]='[';
     for(i=0;i<2;i++){
       x[r+1][c+64+i]='_';
      }
    x[r+1][c+66]=']';
    x[r+1][c+68]='|';
    x[r+1][c+70]='|';
    x[r+1][c+71]=92;
    x[r+1][c+73]='|';
    x[r+1][c+74]=39;
    x[r+1][c+76]=')';
    x[r+1][c+81]='[';
    x[r+1][c+87]=92;
    x[r+1][c+88]='.';
    x[r+1][c+89]='/';
    x[r+1][c+94]='/';
    x[r+1][c+99]='|';
    x[r+1][c+100]=92;
    x[r+1][c+102]='|';
    x[r+1][c+107]=']';
    x[r+2][c+0]='|';
    x[r+2][c+1]='/';
    x[r+2][c+2]=92;
     for(i=0;i<2;i++){
       x[r+2][c+3+i]='|';
      }
     for(i=0;i<2;i++){
       x[r+2][c+7+i]='|';
      }
    x[r+2][c+10]=92;
    x[r+2][c+11]='|';
    x[r+2][c+14]='|';
    x[r+2][c+23]='|';
    x[r+2][c+26]='|';
     for(i=0;i<2;i++){
       x[r+2][c+27+i]='_';
      }
    x[r+2][c+29]='|';
    x[r+2][c+34]='|';
    x[r+2][c+38]='|';
     for(i=0;i<3;i++){
       x[r+2][c+39+i]='_';
      }
    x[r+2][c+42]='|';
    x[r+2][c+45]='|';
    x[r+2][c+48]='|';
    x[r+2][c+55]='|';
    x[r+2][c+58]='|';
    x[r+2][c+59]='[';
    x[r+2][c+60]='_';
    x[r+2][c+61]='.';
    x[r+2][c+62]='/';
    x[r+2][c+63]='|';
    x[r+2][c+66]='|';
    x[r+2][c+67]='_';
    x[r+2][c+68]='|';
    x[r+2][c+69]='_';
    x[r+2][c+70]='|';
    x[r+2][c+72]=92;
    x[r+2][c+73]='|';
    x[r+2][c+75]=';';
    x[r+2][c+81]='[';
    x[r+2][c+82]='_';
    x[r+2][c+88]='|';
    x[r+2][c+93]='/';
    x[r+2][c+99]='|';
    x[r+2][c+101]=92;
    x[r+2][c+102]='|';
    x[r+2][c+106]='_';
    x[r+2][c+107]=']';
}
void HomeScreen(wchar_t x[][1190]){
    
    int r, c, i;
    r =5;
    c=80;
    
    x[r+0][c+2]='_';
    x[r+0][c+7]='_';
    x[r+0][c+12]='_';
    x[r+0][c+17]='_';
    x[r+0][c+22]='_';
    x[r+0][c+27]='_';
    x[r+0][c+32]='_';
    x[r+0][c+37]='_';
    x[r+0][c+42]='_';
    x[r+0][c+47]='_';
    x[r+0][c+52]='_';
    x[r+0][c+57]='_';
    x[r+0][c+62]='_';
    x[r+0][c+67]='_';
    x[r+1][c+0]='{';
    x[r+1][c+1]=92;
    x[r+1][c+2]='o';
    x[r+1][c+3]='/';
    x[r+1][c+4]='}';
    x[r+1][c+5]='{';
    x[r+1][c+6]=92;
    x[r+1][c+7]='o';
    x[r+1][c+8]='/';
    x[r+1][c+9]='}';
    x[r+1][c+10]='{';
    x[r+1][c+11]=92;
    x[r+1][c+12]='o';
    x[r+1][c+13]='/';
    x[r+1][c+14]='}';
    x[r+1][c+15]='{';
    x[r+1][c+16]=92;
    x[r+1][c+17]='o';
    x[r+1][c+18]='/';
    x[r+1][c+19]='}';
    x[r+1][c+20]='{';
    x[r+1][c+21]=92;
    x[r+1][c+22]='o';
    x[r+1][c+23]='/';
    x[r+1][c+24]='}';
    x[r+1][c+25]='{';
    x[r+1][c+26]=92;
    x[r+1][c+27]='o';
    x[r+1][c+28]='/';
    x[r+1][c+29]='}';
    x[r+1][c+30]='{';
    x[r+1][c+31]=92;
    x[r+1][c+32]='o';
    x[r+1][c+33]='/';
    x[r+1][c+34]='}';
    x[r+1][c+35]='{';
    x[r+1][c+36]=92;
    x[r+1][c+37]='o';
    x[r+1][c+38]='/';
    x[r+1][c+39]='}';
    x[r+1][c+40]='{';
    x[r+1][c+41]=92;
    x[r+1][c+42]='o';
    x[r+1][c+43]='/';
    x[r+1][c+44]='}';
    x[r+1][c+45]='{';
    x[r+1][c+46]=92;
    x[r+1][c+47]='o';
    x[r+1][c+48]='/';
    x[r+1][c+49]='}';
    x[r+1][c+50]='{';
    x[r+1][c+51]=92;
    x[r+1][c+52]='o';
    x[r+1][c+53]='/';
    x[r+1][c+54]='}';
    x[r+1][c+55]='{';
    x[r+1][c+56]=92;
    x[r+1][c+57]='o';
    x[r+1][c+58]='/';
    x[r+1][c+59]='}';
    x[r+1][c+60]='{';
    x[r+1][c+61]=92;
    x[r+1][c+62]='o';
    x[r+1][c+63]='/';
    x[r+1][c+64]='}';
    x[r+1][c+65]='{';
    x[r+1][c+66]=92;
    x[r+1][c+67]='o';
    x[r+1][c+68]='/';
    x[r+1][c+69]='}';
    x[r+2][c+1]='/';
    x[r+2][c+2]='_';
    x[r+2][c+3]=92;
    x[r+2][c+6]='/';
    x[r+2][c+7]='_';
    x[r+2][c+8]=92;
    x[r+2][c+11]='/';
    x[r+2][c+12]='_';
    x[r+2][c+13]=92;
    x[r+2][c+16]='/';
    x[r+2][c+17]='_';
    x[r+2][c+18]=92;
    x[r+2][c+21]='/';
    x[r+2][c+22]='_';
    x[r+2][c+23]=92;
    x[r+2][c+26]='/';
    x[r+2][c+27]='_';
    x[r+2][c+28]=92;
    x[r+2][c+31]='/';
    x[r+2][c+32]='_';
    x[r+2][c+33]=92;
    x[r+2][c+36]='/';
    x[r+2][c+37]='_';
    x[r+2][c+38]=92;
    x[r+2][c+41]='/';
    x[r+2][c+42]='_';
    x[r+2][c+43]=92;
    x[r+2][c+46]='/';
    x[r+2][c+47]='_';
    x[r+2][c+48]=92;
    x[r+2][c+51]='/';
    x[r+2][c+52]='_';
    x[r+2][c+53]=92;
    x[r+2][c+56]='/';
    x[r+2][c+57]='_';
    x[r+2][c+58]=92;
    x[r+2][c+61]='/';
    x[r+2][c+62]='_';
    x[r+2][c+63]=92;
    x[r+2][c+66]='/';
    x[r+2][c+67]='_';
    x[r+2][c+68]=92;
    x[r+3][c+2]='_';
     for(i=0;i<3;i++){
       x[r+3][c+5+i]='~';
      }
     for(i=0;i<3;i++){
       x[r+3][c+8+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+3][c+11+i]='~';
      }
     for(i=0;i<3;i++){
       x[r+3][c+15+i]='8';
      }
    x[r+3][c+21]='|';
     for(i=0;i<3;i++){
       x[r+3][c+23+i]='8';
      }
     for(i=0;i<2;i++){
       x[r+3][c+26+i]='~';
      }
    x[r+3][c+67]='_';
    x[r+4][c+0]='{';
    x[r+4][c+1]=92;
    x[r+4][c+2]='o';
    x[r+4][c+3]='/';
    x[r+4][c+4]='}';
     for(i=0;i<3;i++){
       x[r+4][c+8+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+4][c+15+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+4][c+18+i]='_';
      }
    x[r+4][c+21]='|';
     for(i=0;i<3;i++){
       x[r+4][c+23+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+4][c+26+i]='_';
      }
    x[r+4][c+65]='{';
    x[r+4][c+66]=92;
    x[r+4][c+67]='o';
    x[r+4][c+68]='/';
    x[r+4][c+69]='}';
    x[r+5][c+1]='/';
    x[r+5][c+2]='_';
    x[r+5][c+3]=92;
     for(i=0;i<3;i++){
       x[r+5][c+8+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+5][c+15+i]='8';
      }
    x[r+5][c+21]='|';
     for(i=0;i<3;i++){
       x[r+5][c+23+i]='8';
      }
    x[r+5][c+66]='/';
    x[r+5][c+67]='_';
    x[r+5][c+68]=92;
    x[r+6][c+2]='_';
     for(i=0;i<3;i++){
       x[r+6][c+8+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+6][c+15+i]='8';
      }
    x[r+6][c+21]='|';
     for(i=0;i<3;i++){
       x[r+6][c+23+i]='8';
      }
    x[r+6][c+67]='_';
    x[r+7][c+0]='{';
    x[r+7][c+1]=92;
    x[r+7][c+2]='o';
    x[r+7][c+3]='/';
    x[r+7][c+4]='}';
     for(i=0;i<3;i++){
       x[r+7][c+8+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+7][c+15+i]='8';
      }
    x[r+7][c+21]='|';
     for(i=0;i<3;i++){
       x[r+7][c+23+i]='8';
      }
    x[r+7][c+65]='{';
    x[r+7][c+66]=92;
    x[r+7][c+67]='o';
    x[r+7][c+68]='/';
    x[r+7][c+69]='}';
    x[r+8][c+1]='/';
    x[r+8][c+2]='_';
    x[r+8][c+3]=92;
     for(i=0;i<3;i++){
       x[r+8][c+8+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+8][c+15+i]='8';
      }
    x[r+8][c+21]='|';
     for(i=0;i<3;i++){
       x[r+8][c+23+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+8][c+26+i]='_';
      }
    x[r+8][c+66]='/';
    x[r+8][c+67]='_';
    x[r+8][c+68]=92;
    
    r+=9;
    
    
    x[r+0][c+2]='_';
    x[r+0][c+67]='_';
    x[r+1][c+0]='{';
    x[r+1][c+1]=92;
    x[r+1][c+2]='o';
    x[r+1][c+3]='/';
    x[r+1][c+4]='}';
     for(i=0;i<3;i++){
       x[r+1][c+11+i]='8';
      }
    x[r+1][c+21]=',';
     for(i=0;i<2;i++){
       x[r+1][c+22+i]='8';
      }
    x[r+1][c+24]='~';
    x[r+1][c+25]='-';
    x[r+1][c+26]='_';
    x[r+1][c+30]=',';
    x[r+1][c+31]='d';
     for(i=0;i<2;i++){
       x[r+1][c+32+i]='8';
      }
     for(i=0;i<2;i++){
       x[r+1][c+34+i]='~';
      }
    x[r+1][c+36]=92;
     for(i=0;i<3;i++){
       x[r+1][c+38+i]='~';
      }
     for(i=0;i<3;i++){
       x[r+1][c+41+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+1][c+44+i]='~';
      }
    x[r+1][c+65]='{';
    x[r+1][c+66]=92;
    x[r+1][c+67]='o';
    x[r+1][c+68]='/';
    x[r+1][c+69]='}';
    x[r+2][c+1]='/';
    x[r+2][c+2]='_';
    x[r+2][c+3]=92;
     for(i=0;i<3;i++){
       x[r+2][c+11+i]='8';
      }
    x[r+2][c+20]='d';
     for(i=0;i<3;i++){
       x[r+2][c+21+i]='8';
      }
    x[r+2][c+27]=92;
     for(i=0;i<4;i++){
       x[r+2][c+30+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+2][c+41+i]='8';
      }
    x[r+2][c+66]='/';
    x[r+2][c+67]='_';
    x[r+2][c+68]=92;
    x[r+3][c+2]='_';
     for(i=0;i<3;i++){
       x[r+3][c+11+i]='8';
      }
     for(i=0;i<5;i++){
       x[r+3][c+19+i]='8';
      }
    x[r+3][c+28]='|';
    x[r+3][c+30]='`';
    x[r+3][c+31]='Y';
     for(i=0;i<2;i++){
       x[r+3][c+32+i]='8';
      }
    x[r+3][c+34]='b';
     for(i=0;i<3;i++){
       x[r+3][c+41+i]='8';
      }
    x[r+3][c+67]='_';
    x[r+4][c+0]='{';
    x[r+4][c+1]=92;
    x[r+4][c+2]='o';
    x[r+4][c+3]='/';
    x[r+4][c+4]='}';
     for(i=0;i<3;i++){
       x[r+4][c+11+i]='8';
      }
     for(i=0;i<5;i++){
       x[r+4][c+19+i]='8';
      }
    x[r+4][c+28]='|';
    x[r+4][c+31]='`';
    x[r+4][c+32]='Y';
     for(i=0;i<2;i++){
       x[r+4][c+33+i]='8';
      }
    x[r+4][c+35]='b';
    x[r+4][c+36]=',';
     for(i=0;i<3;i++){
       x[r+4][c+41+i]='8';
      }
    x[r+4][c+65]='{';
    x[r+4][c+66]=92;
    x[r+4][c+67]='o';
    x[r+4][c+68]='/';
    x[r+4][c+69]='}';
    x[r+5][c+1]='/';
    x[r+5][c+2]='_';
    x[r+5][c+3]=92;
     for(i=0;i<3;i++){
       x[r+5][c+11+i]='8';
      }
    x[r+5][c+20]='Y';
     for(i=0;i<3;i++){
       x[r+5][c+21+i]='8';
      }
    x[r+5][c+27]='/';
     for(i=0;i<4;i++){
       x[r+5][c+33+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+5][c+41+i]='8';
      }
    x[r+5][c+66]='/';
    x[r+5][c+67]='_';
    x[r+5][c+68]=92;
    x[r+6][c+2]='_';
     for(i=0;i<3;i++){
       x[r+6][c+11+i]='8';
      }
     for(i=0;i<4;i++){
       x[r+6][c+14+i]='_';
      }
    x[r+6][c+21]='`';
     for(i=0;i<2;i++){
       x[r+6][c+22+i]='8';
      }
    x[r+6][c+24]='_';
    x[r+6][c+25]='-';
    x[r+6][c+26]='~';
    x[r+6][c+30]=92;
     for(i=0;i<2;i++){
       x[r+6][c+31+i]='_';
      }
     for(i=0;i<2;i++){
       x[r+6][c+33+i]='8';
      }
    x[r+6][c+35]='P';
    x[r+6][c+36]=39;
     for(i=0;i<3;i++){
       x[r+6][c+41+i]='8';
      }
    x[r+6][c+67]='_';
    
    r += 7;
    
    x[r+0][c+0]='{';
    x[r+0][c+1]=92;
    x[r+0][c+2]='o';
    x[r+0][c+3]='/';
    x[r+0][c+4]='}';
    x[r+0][c+65]='{';
    x[r+0][c+66]=92;
    x[r+0][c+67]='o';
    x[r+0][c+68]='/';
    x[r+0][c+69]='}';
    x[r+1][c+1]='/';
    x[r+1][c+2]='_';
    x[r+1][c+3]=92;
     for(i=0;i<3;i++){
       x[r+1][c+5+i]='~';
      }
     for(i=0;i<3;i++){
       x[r+1][c+8+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+1][c+11+i]='~';
      }
     for(i=0;i<3;i++){
       x[r+1][c+15+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+1][c+19+i]='8';
      }
    x[r+1][c+22]='~';
    x[r+1][c+23]='-';
    x[r+1][c+24]='_';
     for(i=0;i<3;i++){
       x[r+1][c+28+i]='8';
      }
    x[r+1][c+31]='~';
    x[r+1][c+32]='-';
    x[r+1][c+33]='_';
    x[r+1][c+37]='Y';
     for(i=0;i<2;i++){
       x[r+1][c+38+i]='8';
      }
    x[r+1][c+40]='b';
    x[r+1][c+45]='/';
    x[r+1][c+53]=',';
    x[r+1][c+55]='8';
    x[r+1][c+57]=',';
    x[r+1][c+66]='/';
    x[r+1][c+67]='_';
    x[r+1][c+68]=92;
    x[r+2][c+2]='_';
     for(i=0;i<3;i++){
       x[r+2][c+8+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+2][c+15+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+2][c+19+i]='8';
      }
    x[r+2][c+25]=92;
     for(i=0;i<3;i++){
       x[r+2][c+28+i]='8';
      }
    x[r+2][c+34]=92;
    x[r+2][c+38]='Y';
     for(i=0;i<2;i++){
       x[r+2][c+39+i]='8';
      }
    x[r+2][c+41]='b';
    x[r+2][c+44]='/';
    x[r+2][c+54]='"';
    x[r+2][c+55]='8';
    x[r+2][c+56]='"';
    x[r+2][c+67]='_';
    x[r+3][c+0]='{';
    x[r+3][c+1]=92;
    x[r+3][c+2]='o';
    x[r+3][c+3]='/';
    x[r+3][c+4]='}';
     for(i=0;i<3;i++){
       x[r+3][c+8+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+3][c+15+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+3][c+19+i]='8';
      }
    x[r+3][c+26]='|';
     for(i=0;i<3;i++){
       x[r+3][c+28+i]='8';
      }
    x[r+3][c+35]='|';
    x[r+3][c+39]='Y';
     for(i=0;i<2;i++){
       x[r+3][c+40+i]='8';
      }
    x[r+3][c+42]='b';
    x[r+3][c+43]='/';
    x[r+3][c+53]='e';
    x[r+3][c+54]='"';
    x[r+3][c+56]='"';
    x[r+3][c+57]='e';
    x[r+3][c+65]='{';
    x[r+3][c+66]=92;
    x[r+3][c+67]='o';
    x[r+3][c+68]='/';
    x[r+3][c+69]='}';
    x[r+4][c+1]='/';
    x[r+4][c+2]='_';
    x[r+4][c+3]=92;
     for(i=0;i<3;i++){
       x[r+4][c+8+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+4][c+15+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+4][c+19+i]='8';
      }
    x[r+4][c+26]='|';
     for(i=0;i<3;i++){
       x[r+4][c+28+i]='8';
      }
    x[r+4][c+35]='|';
    x[r+4][c+40]='Y';
    x[r+4][c+41]='8';
    x[r+4][c+42]='Y';
    x[r+4][c+66]='/';
    x[r+4][c+67]='_';
    x[r+4][c+68]=92;
    x[r+5][c+2]='_';
     for(i=0;i<3;i++){
       x[r+5][c+8+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+5][c+15+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+5][c+19+i]='8';
      }
    x[r+5][c+25]='/';
     for(i=0;i<3;i++){
       x[r+5][c+28+i]='8';
      }
    x[r+5][c+34]='/';
    x[r+5][c+41]='Y';
    x[r+5][c+67]='_';
    x[r+6][c+0]='{';
    x[r+6][c+1]=92;
    x[r+6][c+2]='o';
    x[r+6][c+3]='/';
    x[r+6][c+4]='}';
     for(i=0;i<3;i++){
       x[r+6][c+8+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+6][c+15+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+6][c+19+i]='8';
      }
    x[r+6][c+22]='_';
    x[r+6][c+23]='-';
    x[r+6][c+24]='~';
     for(i=0;i<3;i++){
       x[r+6][c+28+i]='8';
      }
    x[r+6][c+31]='_';
    x[r+6][c+32]='-';
    x[r+6][c+33]='~';
    x[r+6][c+40]='/';
    x[r+6][c+65]='{';
    x[r+6][c+66]=92;
    x[r+6][c+67]='o';
    x[r+6][c+68]='/';
    x[r+6][c+69]='}';
    x[r+7][c+1]='/';
    x[r+7][c+2]='_';
    x[r+7][c+3]=92;
    x[r+7][c+66]='/';
    x[r+7][c+67]='_';
    x[r+7][c+68]=92;
    
    r+=8;
    
    x[r+0][c+2]='_';
     for(i=0;i<3;i++){
       x[r+0][c+11+i]='8';
      }
     for(i=0;i<2;i++){
       x[r+0][c+14+i]='~';
      }
    x[r+0][c+16]=92;
     for(i=0;i<3;i++){
       x[r+0][c+19+i]='8';
      }
     for(i=0;i<2;i++){
       x[r+0][c+22+i]='~';
      }
    x[r+0][c+31]='e';
     for(i=0;i<3;i++){
       x[r+0][c+38+i]='8';
      }
    x[r+0][c+41]='~';
    x[r+0][c+42]='-';
    x[r+0][c+43]='_';
    x[r+0][c+62]='_';
    x[r+0][c+63]='-';
    x[r+0][c+67]='_';
    x[r+1][c+0]='{';
    x[r+1][c+1]=92;
    x[r+1][c+2]='o';
    x[r+1][c+3]='/';
    x[r+1][c+4]='}';
     for(i=0;i<3;i++){
       x[r+1][c+11+i]='8';
      }
    x[r+1][c+17]='|';
     for(i=0;i<3;i++){
       x[r+1][c+19+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+1][c+22+i]='_';
      }
    x[r+1][c+30]='d';
    x[r+1][c+31]='8';
    x[r+1][c+32]='b';
     for(i=0;i<3;i++){
       x[r+1][c+38+i]='8';
      }
    x[r+1][c+44]=92;
    x[r+1][c+53]='d';
     for(i=0;i<2;i++){
       x[r+1][c+54+i]='8';
      }
    x[r+1][c+56]='b';
    x[r+1][c+59]='_';
    x[r+1][c+60]='-';
    x[r+1][c+61]='~';
    x[r+1][c+65]='{';
    x[r+1][c+66]=92;
    x[r+1][c+67]='o';
    x[r+1][c+68]='/';
    x[r+1][c+69]='}';
    x[r+2][c+1]='/';
    x[r+2][c+2]='_';
    x[r+2][c+3]=92;
     for(i=0;i<3;i++){
       x[r+2][c+11+i]='8';
      }
    x[r+2][c+15]='_';
    x[r+2][c+16]='/';
     for(i=0;i<3;i++){
       x[r+2][c+19+i]='8';
      }
    x[r+2][c+29]='/';
    x[r+2][c+30]='Y';
     for(i=0;i<2;i++){
       x[r+2][c+31+i]='8';
      }
    x[r+2][c+33]='b';
     for(i=0;i<3;i++){
       x[r+2][c+38+i]='8';
      }
    x[r+2][c+45]='|';
    x[r+2][c+53]='Y';
     for(i=0;i<2;i++){
       x[r+2][c+54+i]='8';
      }
    x[r+2][c+56]='P';
    x[r+2][c+58]='<';
    x[r+2][c+66]='/';
    x[r+2][c+67]='_';
    x[r+2][c+68]=92;
    x[r+3][c+2]='_';
     for(i=0;i<3;i++){
       x[r+3][c+11+i]='8';
      }
    x[r+3][c+16]=92;
     for(i=0;i<3;i++){
       x[r+3][c+19+i]='8';
      }
    x[r+3][c+28]='/';
    x[r+3][c+31]='Y';
     for(i=0;i<2;i++){
       x[r+3][c+32+i]='8';
      }
    x[r+3][c+34]='b';
     for(i=0;i<3;i++){
       x[r+3][c+38+i]='8';
      }
    x[r+3][c+44]='/';
    x[r+3][c+59]='~';
    x[r+3][c+60]='-';
    x[r+3][c+61]='_';
    x[r+3][c+67]='_';
    x[r+4][c+0]='{';
    x[r+4][c+1]=92;
    x[r+4][c+2]='o';
    x[r+4][c+3]='/';
    x[r+4][c+4]='}';
     for(i=0;i<3;i++){
       x[r+4][c+11+i]='8';
      }
    x[r+4][c+17]='|';
     for(i=0;i<3;i++){
       x[r+4][c+19+i]='8';
      }
    x[r+4][c+27]='/';
     for(i=0;i<4;i++){
       x[r+4][c+28+i]='_';
      }
    x[r+4][c+32]='Y';
     for(i=0;i<2;i++){
       x[r+4][c+33+i]='8';
      }
    x[r+4][c+35]='b';
     for(i=0;i<3;i++){
       x[r+4][c+38+i]='8';
      }
    x[r+4][c+41]='_';
    x[r+4][c+42]='-';
    x[r+4][c+43]='~';
    x[r+4][c+53]='d';
     for(i=0;i<2;i++){
       x[r+4][c+54+i]='8';
      }
    x[r+4][c+56]='b';
    x[r+4][c+62]='~';
    x[r+4][c+63]='-';
    x[r+4][c+65]='{';
    x[r+4][c+66]=92;
    x[r+4][c+67]='o';
    x[r+4][c+68]='/';
    x[r+4][c+69]='}';
    x[r+5][c+1]='/';
    x[r+5][c+2]='_';
    x[r+5][c+3]=92;
     for(i=0;i<3;i++){
       x[r+5][c+11+i]='8';
      }
     for(i=0;i<2;i++){
       x[r+5][c+14+i]='_';
      }
    x[r+5][c+16]='/';
     for(i=0;i<3;i++){
       x[r+5][c+19+i]='8';
      }
     for(i=0;i<3;i++){
       x[r+5][c+22+i]='_';
      }
    x[r+5][c+26]='/';
    x[r+5][c+33]='Y';
     for(i=0;i<2;i++){
       x[r+5][c+34+i]='8';
      }
    x[r+5][c+36]='b';
     for(i=0;i<3;i++){
       x[r+5][c+38+i]='8';
      }
    x[r+5][c+42]='~';
    x[r+5][c+43]='-';
    x[r+5][c+44]='_';
    x[r+5][c+53]='Y';
     for(i=0;i<2;i++){
       x[r+5][c+54+i]='8';
      }
    x[r+5][c+56]='P';
    x[r+5][c+66]='/';
    x[r+5][c+67]='_';
    x[r+5][c+68]=92;
    x[r+6][c+2]='_';
    x[r+6][c+7]='_';
    x[r+6][c+12]='_';
    x[r+6][c+17]='_';
    x[r+6][c+22]='_';
    x[r+6][c+27]='_';
    x[r+6][c+32]='_';
    x[r+6][c+37]='_';
    x[r+6][c+42]='_';
    x[r+6][c+47]='_';
    x[r+6][c+52]='_';
    x[r+6][c+57]='_';
    x[r+6][c+62]='_';
    x[r+6][c+67]='_';
    x[r+7][c+0]='{';
    x[r+7][c+1]=92;
    x[r+7][c+2]='o';
    x[r+7][c+3]='/';
    x[r+7][c+4]='}';
    x[r+7][c+5]='{';
    x[r+7][c+6]=92;
    x[r+7][c+7]='o';
    x[r+7][c+8]='/';
    x[r+7][c+9]='}';
    x[r+7][c+10]='{';
    x[r+7][c+11]=92;
    x[r+7][c+12]='o';
    x[r+7][c+13]='/';
    x[r+7][c+14]='}';
    x[r+7][c+15]='{';
    x[r+7][c+16]=92;
    x[r+7][c+17]='o';
    x[r+7][c+18]='/';
    x[r+7][c+19]='}';
    x[r+7][c+20]='{';
    x[r+7][c+21]=92;
    x[r+7][c+22]='o';
    x[r+7][c+23]='/';
    x[r+7][c+24]='}';
    x[r+7][c+25]='{';
    x[r+7][c+26]=92;
    x[r+7][c+27]='o';
    x[r+7][c+28]='/';
    x[r+7][c+29]='}';
    x[r+7][c+30]='{';
    x[r+7][c+31]=92;
    x[r+7][c+32]='o';
    x[r+7][c+33]='/';
    x[r+7][c+34]='}';
    x[r+7][c+35]='{';
    x[r+7][c+36]=92;
    x[r+7][c+37]='o';
    x[r+7][c+38]='/';
    x[r+7][c+39]='}';
    x[r+7][c+40]='{';
    x[r+7][c+41]=92;
    x[r+7][c+42]='o';
    x[r+7][c+43]='/';
    x[r+7][c+44]='}';
    x[r+7][c+45]='{';
    x[r+7][c+46]=92;
    x[r+7][c+47]='o';
    x[r+7][c+48]='/';
    x[r+7][c+49]='}';
    x[r+7][c+50]='{';
    x[r+7][c+51]=92;
    x[r+7][c+52]='o';
    x[r+7][c+53]='/';
    x[r+7][c+54]='}';
    x[r+7][c+55]='{';
    x[r+7][c+56]=92;
    x[r+7][c+57]='o';
    x[r+7][c+58]='/';
    x[r+7][c+59]='}';
    x[r+7][c+60]='{';
    x[r+7][c+61]=92;
    x[r+7][c+62]='o';
    x[r+7][c+63]='/';
    x[r+7][c+64]='}';
    x[r+7][c+65]='{';
    x[r+7][c+66]=92;
    x[r+7][c+67]='o';
    x[r+7][c+68]='/';
    x[r+7][c+69]='}';
    x[r+8][c+1]='/';
    x[r+8][c+2]='_';
    x[r+8][c+3]=92;
    x[r+8][c+6]='/';
    x[r+8][c+7]='_';
    x[r+8][c+8]=92;
    x[r+8][c+11]='/';
    x[r+8][c+12]='_';
    x[r+8][c+13]=92;
    x[r+8][c+16]='/';
    x[r+8][c+17]='_';
    x[r+8][c+18]=92;
    x[r+8][c+21]='/';
    x[r+8][c+22]='_';
    x[r+8][c+23]=92;
    x[r+8][c+26]='/';
    x[r+8][c+27]='_';
    x[r+8][c+28]=92;
    x[r+8][c+31]='/';
    x[r+8][c+32]='_';
    x[r+8][c+33]=92;
    x[r+8][c+36]='/';
    x[r+8][c+37]='_';
    x[r+8][c+38]=92;
    x[r+8][c+41]='/';
    x[r+8][c+42]='_';
    x[r+8][c+43]=92;
    x[r+8][c+46]='/';
    x[r+8][c+47]='_';
    x[r+8][c+48]=92;
    x[r+8][c+51]='/';
    x[r+8][c+52]='_';
    x[r+8][c+53]=92;
    x[r+8][c+56]='/';
    x[r+8][c+57]='_';
    x[r+8][c+58]=92;
    x[r+8][c+61]='/';
    x[r+8][c+62]='_';
    x[r+8][c+63]=92;
    x[r+8][c+66]='/';
    x[r+8][c+67]='_';
    x[r+8][c+68]=92;
    
    
//    PRESS ANY KEY TO START
    
    
    
    r +=20;
    c-=25;
    
    
    x[r+0][c+0]='.';
     for(i=0;i<2;i++){
       x[r+0][c+1+i]='-';
      }
    x[r+0][c+3]='.';
    x[r+0][c+5]='.';
     for(i=0;i<2;i++){
       x[r+0][c+6+i]='-';
      }
    x[r+0][c+8]='.';
    x[r+0][c+10]='.';
     for(i=0;i<3;i++){
       x[r+0][c+11+i]='-';
      }
     for(i=0;i<2;i++){
       x[r+0][c+14+i]='.';
      }
    x[r+0][c+16]='-';
    x[r+0][c+17]='.';
    x[r+0][c+20]='.';
    x[r+0][c+21]='-';
    x[r+0][c+22]='.';
    x[r+0][c+36]='.';
    x[r+0][c+41]='.';
     for(i=0;i<2;i++){
       x[r+0][c+45+i]='.';
      }
    x[r+0][c+50]='.';
    x[r+0][c+59]='.';
     for(i=0;i<2;i++){
       x[r+0][c+63+i]='.';
      }
     for(i=0;i<3;i++){
       x[r+0][c+65+i]='-';
      }
     for(i=0;i<2;i++){
       x[r+0][c+68+i]='.';
      }
    x[r+0][c+73]='.';
    x[r+0][c+82]='.';
     for(i=0;i<3;i++){
       x[r+0][c+83+i]='-';
      }
     for(i=0;i<2;i++){
       x[r+0][c+86+i]='.';
      }
     for(i=0;i<2;i++){
       x[r+0][c+88+i]='-';
      }
    x[r+0][c+90]='.';
    x[r+0][c+101]='.';
    x[r+0][c+102]='-';
     for(i=0;i<2;i++){
       x[r+0][c+103+i]='.';
      }
     for(i=0;i<3;i++){
       x[r+0][c+105+i]='-';
      }
    x[r+0][c+108]='.';
    x[r+0][c+111]='.';
    x[r+0][c+116]='.';
     for(i=0;i<2;i++){
       x[r+0][c+117+i]='-';
      }
     for(i=0;i<2;i++){
       x[r+0][c+119+i]='.';
      }
     for(i=0;i<3;i++){
       x[r+0][c+121+i]='-';
      }
    x[r+0][c+124]='.';
    x[r+1][c+0]='|';
    x[r+1][c+4]=')';
    x[r+1][c+5]='|';
    x[r+1][c+9]=')';
    x[r+1][c+10]='|';
    x[r+1][c+14]='(';
    x[r+1][c+18]=')';
    x[r+1][c+19]='(';
    x[r+1][c+23]=')';
    x[r+1][c+35]='/';
    x[r+1][c+37]=92;
    x[r+1][c+41]='|';
    x[r+1][c+42]=92;
    x[r+1][c+45]='|';
    x[r+1][c+47]=92;
    x[r+1][c+49]='/';
    x[r+1][c+59]='|';
    x[r+1][c+62]='/';
    x[r+1][c+64]='|';
    x[r+1][c+70]=92;
    x[r+1][c+72]='/';
    x[r+1][c+84]='|';
    x[r+1][c+86]=':';
    x[r+1][c+91]=':';
    x[r+1][c+100]='(';
    x[r+1][c+104]=')';
    x[r+1][c+106]='|';
    x[r+1][c+110]='/';
    x[r+1][c+112]=92;
    x[r+1][c+116]='|';
    x[r+1][c+120]=')';
    x[r+1][c+122]='|';
    x[r+2][c+0]='|';
     for(i=0;i<2;i++){
       x[r+2][c+1+i]='-';
      }
    x[r+2][c+3]=39;
    x[r+2][c+5]='|';
     for(i=0;i<2;i++){
       x[r+2][c+6+i]='-';
      }
    x[r+2][c+8]=39;
    x[r+2][c+10]='|';
     for(i=0;i<3;i++){
       x[r+2][c+11+i]='-';
      }
    x[r+2][c+15]='`';
    x[r+2][c+16]='-';
    x[r+2][c+17]='.';
    x[r+2][c+20]='`';
    x[r+2][c+21]='-';
    x[r+2][c+22]='.';
    x[r+2][c+34]='/';
     for(i=0;i<3;i++){
       x[r+2][c+35+i]='_';
      }
    x[r+2][c+38]=92;
    x[r+2][c+41]='|';
    x[r+2][c+43]=92;
    x[r+2][c+45]='|';
    x[r+2][c+48]=':';
    x[r+2][c+59]='|';
    x[r+2][c+60]='-';
    x[r+2][c+61]=39;
    x[r+2][c+64]='|';
     for(i=0;i<3;i++){
       x[r+2][c+65+i]='-';
      }
    x[r+2][c+71]=':';
    x[r+2][c+84]='|';
    x[r+2][c+86]='|';
    x[r+2][c+91]='|';
    x[r+2][c+101]='`';
    x[r+2][c+102]='-';
    x[r+2][c+103]='.';
    x[r+2][c+106]='|';
    x[r+2][c+109]='/';
     for(i=0;i<3;i++){
       x[r+2][c+110+i]='_';
      }
    x[r+2][c+113]=92;
    x[r+2][c+116]='|';
     for(i=0;i<2;i++){
       x[r+2][c+117+i]='-';
      }
    x[r+2][c+119]=39;
    x[r+2][c+122]='|';
    x[r+3][c+0]='|';
    x[r+3][c+5]='|';
    x[r+3][c+8]=92;
    x[r+3][c+10]='|';
    x[r+3][c+14]='(';
    x[r+3][c+18]=')';
    x[r+3][c+19]='(';
    x[r+3][c+23]=')';
    x[r+3][c+33]='/';
    x[r+3][c+39]=92;
    x[r+3][c+41]='|';
    x[r+3][c+44]=92;
    x[r+3][c+45]='|';
    x[r+3][c+48]='|';
    x[r+3][c+59]='|';
    x[r+3][c+62]=92;
    x[r+3][c+64]='|';
    x[r+3][c+71]='|';
    x[r+3][c+84]='|';
    x[r+3][c+86]=':';
    x[r+3][c+91]=';';
    x[r+3][c+100]='(';
    x[r+3][c+104]=')';
    x[r+3][c+106]='|';
    x[r+3][c+108]='/';
    x[r+3][c+114]=92;
    x[r+3][c+116]='|';
    x[r+3][c+119]=92;
    x[r+3][c+122]='|';
    x[r+4][c+0]=39;
    x[r+4][c+5]=39;
    x[r+4][c+9]='`';
    x[r+4][c+10]=39;
     for(i=0;i<3;i++){
       x[r+4][c+11+i]='-';
      }
    x[r+4][c+14]=39;
    x[r+4][c+15]='`';
    x[r+4][c+16]='-';
    x[r+4][c+17]=39;
    x[r+4][c+20]='`';
    x[r+4][c+21]='-';
    x[r+4][c+22]=39;
    x[r+4][c+32]=39;
    x[r+4][c+40]='`';
    x[r+4][c+41]=39;
    x[r+4][c+45]=39;
    x[r+4][c+48]=39;
    x[r+4][c+59]=39;
    x[r+4][c+63]='`';
    x[r+4][c+64]=39;
     for(i=0;i<3;i++){
       x[r+4][c+65+i]='-';
      }
    x[r+4][c+68]=39;
    x[r+4][c+71]=39;
    x[r+4][c+84]=39;
    x[r+4][c+87]='`';
     for(i=0;i<2;i++){
       x[r+4][c+88+i]='-';
      }
    x[r+4][c+90]=39;
    x[r+4][c+101]='`';
    x[r+4][c+102]='-';
    x[r+4][c+103]=39;
     for(i=0;i<2;i++){
       x[r+4][c+106+i]=39;
      }
    x[r+4][c+115]='`';
    x[r+4][c+116]=39;
    x[r+4][c+120]='`';
    x[r+4][c+122]=39;
    
}
void COUT(wchar_t x[][1190]){
    for(int i=0;i<74;i++){
        for(int j=0;j<238;j++){
            wcout<<x[i][j];
        }
        cout<<endl;
    }
}

void printMapToScreen( wchar_t x[][1190], int startOfScreen, int endOfScreen, int startOfScreen2, int endOfScreen2) {
    
    
    
    system("clear");

    
    setlocale( LC_ALL, "en_US.UTF-8" );
    for (int i = startOfScreen2; i < endOfScreen2; i++)
    {
             
        for (int j = startOfScreen; j < endOfScreen; j++)
        {
            wprintf( L"%lc", x[i][j], x[i][j]);
        }
             cout<<endl;
             
    }
    
    
    
//    for (int i = 0; i < 222; i++)
//    {
//
//        for (int j = 0; j < 1190; j++)
//        {
//            wprintf( L"%lc", x[i][j], x[i][j]);
//        }
//             cout<<endl;
//
//    }
    
         
}

void drawBat(wchar_t x[][1190], Bat& bat){
    int r=bat.r;
    int c=bat.c;
    int i;


    if( bat.health!=0 ){
        x[r+0][c+2]=')';
        x[r+0][c+4]=92;
        x[r+0][c+10]='/';
        x[r+0][c+12]='(';
        x[r+1][c+1]=')';
        x[r+1][c+2]='_';
        x[r+1][c+5]=92;
        x[r+1][c+6]='_';
        x[r+1][c+7]='V';
        x[r+1][c+8]='_';
        x[r+1][c+9]='/';
        x[r+1][c+12]='_';
        x[r+1][c+13]='(';
        x[r+2][c+3]=')';
         for(i=0;i<2;i++){
           x[r+2][c+4+i]='_';
          }
         for(i=0;i<2;i++){
           x[r+2][c+9+i]='_';
          }
        x[r+2][c+11]='(';
        x[r+3][c+6]='`';
        x[r+3][c+7]='-';
        x[r+3][c+8]=39;
    }
}
void drawSnail(wchar_t x[][1190], Snail& snail){
    int r=snail.rb;
    int c=snail.cb;
    int i;


    if( snail.health!=0 ){
        x[r+0][c+3]='/';
        x[r+0][c+4]='^';
        x[r+0][c+5]=92;
        x[r+0][c+10]='/';
        x[r+0][c+11]='^';
        x[r+0][c+12]=92;
        x[r+1][c+2]='{';
        x[r+1][c+3]='O';
        x[r+1][c+6]='}';
        x[r+1][c+9]='{';
        x[r+1][c+10]='O';
        x[r+1][c+13]='}';
        x[r+2][c+3]=92;
        x[r+2][c+5]='/';
        x[r+2][c+10]=92;
        x[r+2][c+12]='/';
         for(i=0;i<2;i++){
           x[r+3][c+4+i]='|';
          }
         for(i=0;i<2;i++){
           x[r+3][c+10+i]='|';
          }
        x[r+3][c+20]='_';
         for(i=0;i<6;i++){
           x[r+3][c+21+i]='-';
          }
        x[r+3][c+27]='_';
         for(i=0;i<2;i++){
           x[r+4][c+4+i]='|';
          }
         for(i=0;i<2;i++){
           x[r+4][c+10+i]='|';
          }
        x[r+4][c+17]='.';
        x[r+4][c+18]='/';
        x[r+4][c+19]='~';
        x[r+4][c+28]='~';
        x[r+4][c+29]='-';
        x[r+4][c+30]='_';
        x[r+5][c+3]='/';
        x[r+5][c+5]='~';
         for(i=0;i<4;i++){
           x[r+5][c+6+i]='-';
          }
        x[r+5][c+10]='~';
        x[r+5][c+11]='/';
        x[r+5][c+17]='/';
        x[r+5][c+32]=92;
        x[r+6][c+1]='/';
        x[r+6][c+11]=':';
        x[r+6][c+15]='.';
        x[r+6][c+16]='/';
        x[r+6][c+24]='_';
         for(i=0;i<3;i++){
           x[r+6][c+25+i]='-';
          }
        x[r+6][c+28]='_';
        x[r+6][c+33]='~';
        x[r+6][c+34]='-';
        x[r+7][c+0]='(';
         for(i=0;i<8;i++){
           x[r+7][c+1+i]='_';
          }
        x[r+7][c+9]='/';
        x[r+7][c+11]='|';
        x[r+7][c+15]=':';
        x[r+7][c+23]='/';
        x[r+7][c+24]='~';
        x[r+7][c+30]='~';
        x[r+7][c+31]=92;
        x[r+7][c+35]='|';
        x[r+8][c+0]='|';
        x[r+8][c+9]='/';
        x[r+8][c+14]='|';
        x[r+8][c+21]='|';
        x[r+8][c+24]=':';
         for(i=0;i<2;i++){
           x[r+8][c+25+i]='~';
          }
        x[r+8][c+27]=92;
        x[r+8][c+30]='|';
        x[r+8][c+34]='|';
        x[r+9][c+0]='|';
        x[r+9][c+8]='|';
        x[r+9][c+14]='|';
        x[r+9][c+21]='|';
        x[r+9][c+24]=92;
         for(i=0;i<3;i++){
           x[r+9][c+25+i]='_';
          }
        x[r+9][c+28]='-';
        x[r+9][c+29]='~';
        x[r+9][c+34]='|';
        x[r+10][c+0]='|';
        x[r+10][c+9]=92;
         for(i=0;i<2;i++){
           x[r+10][c+11+i]='_';
          }
        x[r+10][c+13]='/';
        x[r+10][c+14]='`';
        x[r+10][c+15]='^';
        x[r+10][c+16]=92;
         for(i=0;i<6;i++){
           x[r+10][c+17+i]='_';
          }
        x[r+10][c+23]=92;
        x[r+10][c+24]='.';
        x[r+10][c+33]='.';
        x[r+10][c+34]='/';
        x[r+11][c+1]=92;
        x[r+11][c+23]='~';
        x[r+11][c+24]='-';
         for(i=0;i<6;i++){
           x[r+11][c+25+i]='_';
          }
        x[r+11][c+31]='-';
        x[r+11][c+32]='~';
        x[r+11][c+33]=92;
        x[r+11][c+34]='.';
        x[r+12][c+1]='.';
        x[r+12][c+2]='|';
        x[r+12][c+35]='~';
        x[r+12][c+36]='-';
        x[r+12][c+37]='_';
        x[r+13][c+0]='/';
         for(i=0;i<37;i++){
           x[r+13][c+1+i]='_';
          }
         for(i=0;i<2;i++){
           x[r+13][c+38+i]='~';
          }
         for(i=0;i<4;i++){
           x[r+13][c+40+i]='_';
          }
    }
}

void moveSnail(wchar_t x[][1190], Snail& snail){
    if(snail.frames%30==0){
        if(snail.cb>=snail.cEndOfMove){
            snail.cb-=3;
        }
    }

    snail.frames++;
    if(snail.frames> 30 *100000){
        snail.frames=0;
    }
}

void moveBat(wchar_t x[][1190], Bat& bat){
    

    if(bat.frames%10==0){
        if(bat.r==148-60){
            bat.dir*=-1;
        }
        
        if(bat.r==148-30){
            bat.dir*=-1;
        }
        
        bat.r+=bat.dir;
       
    }
    
   

}

void drawBulletBat(wchar_t x[][1190], Bat& bat){
    x[bat.r][bat.cBullet]='*';
}
void moveBulletBat(wchar_t x[][1190], Bat& bat){
    if(bat.frames%10==0 && x[bat.rBullet][bat.cBullet]==' '){
        if(x[bat.r][bat.cBullet-2]==' ' &&bat.cBullet>=0 && bat.cBullet<1190 ){
            bat.cBullet--;
        }
        else{
            bat.rBullet=bat.r+2;
            bat.cBullet=bat.c-3;
        }
      
    }
   
  
}



void drawHero(wchar_t x[][1190], Hero& hero){
    int r,c,i;

         r = hero.rherob;
         c = hero.cherob;
   
    
    
    
    x[r+0][c+3]='_';
     for(i=0;i<2;i++){
       x[r+0][c+4+i]='-';
      }
    x[r+0][c+6]='_';
    x[r+0][c+12]='_';
     for(i=0;i<2;i++){
       x[r+0][c+13+i]='-';
      }
    x[r+0][c+15]='_';
    x[r+1][c+2]='(';
    x[r+1][c+4]='(';
    x[r+1][c+5]=')';
    x[r+1][c+7]=')';
     for(i=0;i<3;i++){
       x[r+1][c+8+i]='_';
      }
    x[r+1][c+11]='(';
    x[r+1][c+13]='(';
    x[r+1][c+14]=')';
    x[r+1][c+16]=')';
    x[r+2][c+3]=92;
    x[r+2][c+7]='-';
    x[r+2][c+11]='-';
    x[r+2][c+15]='/';
    x[r+3][c+4]='(';
    x[r+3][c+7]='O';
    x[r+3][c+11]='O';
    x[r+3][c+14]=')';
    x[r+4][c+5]=92;
    x[r+4][c+13]='/';
    x[r+5][c+3]='.';
     for(i=0;i<2;i++){
       x[r+5][c+4+i]='_';
      }
    x[r+5][c+6]='(';
    x[r+5][c+8]='`';
    x[r+5][c+9]='-';
    x[r+5][c+10]=39;
    x[r+5][c+12]=')';
    x[r+6][c+2]='/';
    x[r+6][c+4]='!';
    x[r+6][c+7]='`';
     for(i=0;i<3;i++){
       x[r+6][c+8+i]='-';
      }
    x[r+6][c+11]=39;
    x[r+6][c+13]=92;
    x[r+7][c+1]='/';
    x[r+7][c+4]=92;
    x[r+7][c+14]='!';
    x[r+8][c+0]='!';
    x[r+8][c+4]='/';
    x[r+8][c+5]=92;
    x[r+8][c+14]='!';
    x[r+9][c+0]='!';
    x[r+9][c+4]='!';
    x[r+9][c+5]='_';
    x[r+9][c+6]=92;
     for(i=0;i<6;i++){
       x[r+9][c+7+i]='_';
      }
    x[r+9][c+13]='/';
    x[r+9][c+14]=92;
    x[r+9][c+15]='.';
    x[r+10][c+0]=92;
    x[r+10][c+5]=92;
    x[r+10][c+13]='!';
    x[r+10][c+15]=92;
    x[r+11][c+1]=92;
     for(i=0;i<3;i++){
       x[r+11][c+2+i]='_';
      }
    x[r+11][c+5]='/';
    x[r+11][c+9]=')';
    x[r+11][c+12]='/';
     for(i=0;i<2;i++){
       x[r+11][c+13+i]='_';
      }
    x[r+11][c+15]='/';
    x[r+12][c+3]=92;
    x[r+12][c+8]='/';
    x[r+12][c+12]='!';
    x[r+13][c+3]='/';
    x[r+13][c+7]='!';
    x[r+13][c+11]='/';
    x[r+14][c+3]='!';
    x[r+14][c+7]='/';
     for(i=0;i<2;i++){
       x[r+14][c+8+i]='_';
      }
    x[r+14][c+11]='/';
     for(i=0;i<3;i++){
       x[r+14][c+12+i]='_';
      }
    x[r+15][c+3]='(';
     for(i=0;i<6;i++){
       x[r+15][c+4+i]='_';
      }
    x[r+15][c+10]=')';
     for(i=0;i<4;i++){
       x[r+15][c+11+i]='_';
      }
    x[r+15][c+15]=')';
    }
void drawHeroJump (wchar_t x[][1190], Hero& hero){
    int r,c,i;
    // row: 105 -> 121    // column: 11 -> 27
         r = hero.rherob;
         c = hero.cherob;
   
    
    x[r+0][c+4]='/';
    x[r+0][c+9]=92;
    x[r+0][c+13]='/';
    x[r+1][c+3]='_';
     for(i=0;i<2;i++){
       x[r+1][c+4+i]='-';
      }
    x[r+1][c+6]='_';
    x[r+1][c+12]='_';
     for(i=0;i<2;i++){
       x[r+1][c+13+i]='-';
      }
    x[r+1][c+15]='_';
    x[r+2][c+2]='(';
    x[r+2][c+4]='(';
    x[r+2][c+5]=')';
    x[r+2][c+7]=')';
     for(i=0;i<3;i++){
       x[r+2][c+8+i]='_';
      }
    x[r+2][c+11]='(';
    x[r+2][c+13]='(';
    x[r+2][c+14]=')';
    x[r+2][c+16]=')';
    x[r+3][c+3]=92;
    x[r+3][c+7]='-';
    x[r+3][c+11]='-';
    x[r+3][c+15]='/';
    x[r+4][c+4]='(';
    x[r+4][c+7]='X';
    x[r+4][c+11]='X';
    x[r+4][c+14]=')';
    x[r+5][c+5]=92;
    x[r+5][c+13]='/';
    x[r+6][c+3]='.';
     for(i=0;i<2;i++){
       x[r+6][c+4+i]='_';
      }
    x[r+6][c+6]='(';
    x[r+6][c+8]='`';
    x[r+6][c+9]='-';
    x[r+6][c+10]=39;
    x[r+6][c+12]=')';
     for(i=0;i<2;i++){
       x[r+6][c+13+i]='_';
      }
    x[r+6][c+15]='.';
    x[r+7][c+2]='/';
    x[r+7][c+4]='!';
    x[r+7][c+7]='`';
     for(i=0;i<3;i++){
       x[r+7][c+8+i]='-';
      }
    x[r+7][c+11]=39;
    x[r+7][c+14]='!';
    x[r+7][c+16]=92;
    x[r+8][c+1]='/';
    x[r+8][c+4]=92;
    x[r+8][c+14]='/';
    x[r+8][c+17]=92;
    x[r+9][c+0]='!';
    x[r+9][c+4]='/';
    x[r+9][c+5]=92;
    x[r+9][c+13]='/';
    x[r+9][c+14]=92;
    x[r+9][c+18]='!';
    x[r+10][c+0]='!';
    x[r+10][c+4]=92;
    x[r+10][c+6]=92;
     for(i=0;i<5;i++){
       x[r+10][c+7+i]='_';
      }
    x[r+10][c+12]='/';
    x[r+10][c+14]='/';
    x[r+10][c+18]='!';
    x[r+11][c+0]=92;
    x[r+11][c+5]=92;
    x[r+11][c+13]='!';
    x[r+11][c+18]='/';
    x[r+12][c+1]=92;
     for(i=0;i<3;i++){
       x[r+12][c+2+i]='_';
      }
    x[r+12][c+5]='/';
    x[r+12][c+9]=')';
    x[r+12][c+12]='/';
    x[r+12][c+13]=92;
     for(i=0;i<3;i++){
       x[r+12][c+14+i]='_';
      }
    x[r+12][c+17]='/';
     for(i=0;i<3;i++){
       x[r+13][c+2+i]='_';
      }
    x[r+13][c+5]='>';
    x[r+13][c+6]='-';
    x[r+13][c+7]='_';
    x[r+13][c+13]=92;
    x[r+13][c+17]='/';
    x[r+13][c+18]='-';
    x[r+13][c+19]=92;
    x[r+14][c+1]='/';
    x[r+14][c+8]='`';
    x[r+14][c+9]='-';
    x[r+14][c+10]='_';
    x[r+14][c+14]='`';
    x[r+14][c+15]='-';
    x[r+14][c+16]='/';
    x[r+14][c+19]='/';
    x[r+15][c+0]='(';
    x[r+15][c+3]=92;
     for(i=0;i<3;i++){
       x[r+15][c+4+i]='-';
      }
     for(i=0;i<2;i++){
       x[r+15][c+7+i]='_';
      }
    x[r+15][c+9]='/';
    x[r+15][c+11]='`';
    x[r+15][c+12]='-';
    x[r+15][c+13]='_';
    x[r+15][c+18]='/';
    x[r+16][c+1]=92;
     for(i=0;i<2;i++){
       x[r+16][c+2+i]='_';
      }
    x[r+16][c+4]=')';
    x[r+16][c+14]='`';
    x[r+16][c+15]='-';
    x[r+16][c+16]='_';
    x[r+16][c+17]='/';
    }


void applyGravity(wchar_t x[][1190], Hero& hero, int & isFalling){
    int c;
    int f=0;
    for(c=hero.cherob;c<=hero.cheroe;c++){
        if(x[hero.rheroe+1][c]!=' '){
            f=1;
        }
        if(x[hero.rheroe+1][c]==219){
            hero.health--;
            hero.rherob=128;
            hero.rheroe=143;
            hero.cherob=20;
            hero.cheroe=41;
        }
        if(x[hero.rherob-1][c]==219){
            hero.health--;
            hero.rherob=128;
            hero.rheroe=143;
            hero.cherob=20;
            hero.cheroe=41;
        }
    }
    if(f){
        isFalling=0;
        hero.jumpFrames=0;
    }
    else{
        isFalling=1;
        hero.rherob++;
        hero.rheroe++;
    }
}
int AntiGravity(wchar_t x[][1190], Hero& hero){
    int c;
    int f=0;
    for(c=hero.cherob+4;c<=hero.cheroe-4;c++){

        
         if(x[hero.rherob-1][c]!=' '){
            f=1;
        }
        
    }

    if(f){
        return 0;

    }


    return 1;
}


void checkHealth(wchar_t x[][1190], Hero &hero, wchar_t sim, Hero2&hero2, int whichHero){
    int i;
    if(whichHero==1){
        for(i=hero.cherob;i<=hero.cheroe;i++){
            if(x[hero.rherob-1][i]==sim){
               
                hero.rherob=128;
                hero.rheroe=143;
                hero.cherob=20;
                hero.cheroe=41;
                
            }
        }
        
        for(i=hero.rherob;i<=hero.rheroe;i++){
            if(x[i][hero.cheroe+1]==sim){
                hero.health--;
                hero.rherob=128;
                hero.rheroe=143;
                hero.cherob=20;
                hero.cheroe=41;
            }
        }
    }
    
    
    if(whichHero==2){
        for(i=hero2.c;i<=hero2.c+38;i++){
            if(x[hero2.r-1][i]==sim){
                hero.inAirplane=0;
                hero.rherob=128;
                hero.rheroe=143;
                hero.cherob=20;
                hero.cheroe=41;
                hero.health--;

                
            }
        }
        
        for(i=hero2.r;i<=hero2.r+13;i++){
            if(x[i][hero2.c+33+1]==sim){
                hero.inAirplane=0;
                hero.rherob=128;
                hero.rheroe=143;
                hero.cherob=20;
                hero.cheroe=41;
                hero.health--;

            }
        }
    }
}

int checkNoObstacle(wchar_t  x[] [1190],Hero & hero, int heroDiriction){

    //CHECK NO OBSTACLE, RIGHT SIDE.
   int r= hero.rherob;
   int c= hero.cherob;
    
//    if( hero.cheroe>=550 &&  hero.cheroe<=630 &&hero.rherob>=70 &&hero.rheroe<=100 && hero.cherob>=550 &&  hero.cherob<=630  ){
//        return 1;
//    }
    
    
        
    if(heroDiriction==1){
        if( hero.cheroe>=500 &&  hero.cheroe<=580){
            hero.inLadder=1;
            return 1;
        }
        if(x[r+0][c+15+1]==' ' && x[r+1][c+16+1]==' ' && x[r+2][c+15+1]==' ' && x[r+3][c+14+1]==' ' && x[r+4][c+13+1]==' ' && x[r+5][c+12+1]==' ' && x[r+6][c+13+1]==' ' && x[r+7][c+14+1]==' ' && x[r+8][c+14+1]==' ' && x[r+9][c+15+1]==' ' && x[r+10][c+15+1]==' ' && x[r+11][c+15+1]==' ' && x[r+12][c+12+1]==' ' && x[r+13][c+11+1]==' ' && x[r+14][c+14+1]==' ' && x[r+15][c+15+1]==' ' && hero.cheroe<1190-1 ){
            hero.inLadder=0;
            return 1;
        }
    }
    //CHECK NO OBSTACLE, LEFT SIDE.
    if(heroDiriction==-1){
        
        if( hero.cherob>=500 &&  hero.cherob<=580){
            hero.inLadder=1;
            return 1;
        }
        if(x[r+0][c+3-1]==' ' && x[r+1][c+2-1]==' ' && x[r+2][c+3-1]==' ' && x[r+3][c+4-1]==' ' && x[r+4][c+5-1]==' ' && x[r+5][c+3-1]==' ' && x[r+6][c+2-1]==' ' && x[r+7][c+1-1]==' ' && x[r+8][c+0-1]==' ' && x[r+9][c+0-1]==' ' && x[r+10][c+0-1]==' ' && x[r+11][c+1-1]==' ' && x[r+12][c+3-1]==' ' && x[r+13][c+3-1]==' ' && x[r+14][c+3-1]==' ' && x[r+15][c+3-1]==' ' &&  hero.cherob>0 ){
            hero.inLadder=0;
            return 1;
        }
    }
    
    hero.inLadder=0;
    return 0;
}
int checkNoObstacleForSnale(wchar_t  x[] [1190],Snail & snail){

    //CHECK NO OBSTACLE, RIGHT SIDE.
    int r= snail.rb;
   int c= snail.cb;
    
    
    
        

    //CHECK NO OBSTACLE, LEFT SIDE.

        
        if(x[r+0][c+3-2]==' ' && x[r+1][c+2-2]==' ' && x[r+2][c+3-2]==' ' && x[r+3][c+4-2]==' ' && x[r+4][c+4-2]==' ' && x[r+5][c+3-2]==' ' && x[r+6][c+1-2]==' ' && x[r+7][c+0-2]==' ' && x[r+8][c+0-2]==' ' && x[r+9][c+0-2]==' ' && x[r+10][c+0-2]==' ' && x[r+11][c+1-2]==' ' && x[r+12][c+1-2]==' ' && x[r+13][c+0-2]==' ' ){
            return 1;
        }
    

    return 0;
}


void jumpHero(wchar_t x[][1190], Hero& hero, int & isFalling){
    
    if(hero.flagGumpRight==0 && hero.flagGump==0 && hero.flagGumpLft==0){
        applyGravity(x, hero, isFalling);
    }
    else
    {
        if(hero.flagGump==1){
            if (hero.ctJump < 9 && AntiGravity(x, hero) && hero.jumpFrames%10==0)
            {
                hero.rherob--;
                hero.rheroe--;
                hero.ctJump++;
            }
            else
            {
                if(hero.jumpFrames==115){
                    hero.ctJump = 0;
                    hero.flagGump = 0;
                   
                }
             
                
                
            }
           
            hero.jumpFrames++;
        }
        
    }

}
void jumpHeroLft(wchar_t x[][1190], Hero& hero, int & isFalling){
    if(hero.flagGumpRight==0 && hero.flagGump==0 && hero.flagGumpLft==0){
        applyGravity(x, hero, isFalling);
    }
    else
    {
        if(hero.flagGumpLft==1){
            
            if (hero.ctJump < 10 && AntiGravity(x, hero) && hero.jumpFrames%2==0)
            {
                
                for(int i=0;i<3;i++){
                    for(int j=hero.rherob;j<=hero.rheroe;j++){
                        if(x[j][hero.cheroe-1]==219){
                            hero.health--;
                            hero.rherob=128;
                            hero.rheroe=143;
                            hero.cherob=20;
                            hero.cheroe=41;
                        }
                    }
                    if(checkNoObstacle(x, hero, hero.dir)){
                        hero.cherob--;
                        hero.cheroe--;
                    }
                }
                hero.rherob--;
                hero.rheroe--;
                hero.ctJump++;
            }
            else
            {
                if(hero.jumpFrames==55){
                    hero.ctJump = 0;
                    hero.flagGumpLft=0;

                }
                
                
                
            }
            
            hero.jumpFrames++;
        }
    }
    

}
void jumpHeroRight(wchar_t x[][1190], Hero& hero, int & isFalling){
    if(hero.flagGumpRight==0 && hero.flagGump==0 && hero.flagGumpLft==0){
        applyGravity(x, hero, isFalling);
    }
    else
    {
        if(hero.flagGumpRight==1){
            
            if (hero.ctJump < 10 && AntiGravity(x, hero) && hero.jumpFrames%2==0)
            {
             
                for(int i=0;i<3;i++){
                    for(int j=hero.rherob;j<=hero.rheroe;j++){
                        if(x[j][hero.cheroe+1]==219){
                            hero.health--;
                            hero.rherob=128;
                            hero.rheroe=143;
                            hero.cherob=20;
                            hero.cheroe=41;
                        }
                        
                    }
                    if(checkNoObstacle(x, hero, hero.dir)){
                        hero.cherob++;
                        hero.cheroe++;
                    }
                }
                
                
             
            
           
                hero.rherob--;
                hero.rheroe--;
                hero.ctJump++;
            }
            else
            {
                if(hero.jumpFrames==55){
                    hero.ctJump = 0;
                    hero.flagGumpRight = 0;
 
                }
                
                
                
            }
            
            hero.jumpFrames++;
        }
        
    }

}



void drawGun(wchar_t x[][1190], Hero & hero){
    int i;
   int r = hero.rherob+7;
   int c = hero.cherob+16;
    for(i=0;i<2;i++){
      x[r+0][c+2+i]='_';
     }
   x[r+0][c+4]=',';
    for(i=0;i<5;i++){
      x[r+0][c+5+i]='_';
     }
   x[r+1][c+1]='/';
    for(i=0;i<2;i++){
      x[r+1][c+3+i]='_';
     }
   x[r+1][c+5]='.';
    for(i=0;i<2;i++){
      x[r+1][c+6+i]='=';
     }
    for(i=0;i<2;i++){
      x[r+1][c+8+i]='-';
     }
   x[r+1][c+10]='"';
   x[r+2][c+0]='/';
   x[r+2][c+1]='#';
   x[r+2][c+2]='(';
   x[r+2][c+3]='-';
   x[r+2][c+4]=39;
   x[r+3][c+0]='`';
   x[r+3][c+1]='-';
   x[r+3][c+2]=39;
}
void shooting1(wchar_t x[][1190], Hero & hero){
   int r = hero.rherob;
   int c = hero.cherob;
    int i;
    
    x[r+0][c+3]='_';
     for(i=0;i<2;i++){
       x[r+0][c+4+i]='-';
      }
    x[r+0][c+6]='_';
    x[r+0][c+12]='_';
     for(i=0;i<2;i++){
       x[r+0][c+13+i]='-';
      }
    x[r+0][c+15]='_';
    x[r+1][c+2]='(';
    x[r+1][c+4]='(';
    x[r+1][c+5]=')';
    x[r+1][c+7]=')';
     for(i=0;i<3;i++){
       x[r+1][c+8+i]='_';
      }
    x[r+1][c+11]='(';
    x[r+1][c+13]='(';
    x[r+1][c+14]=')';
    x[r+1][c+16]=')';
    x[r+2][c+3]=92;
    x[r+2][c+7]=92;
    x[r+2][c+11]='/';
    x[r+2][c+15]='/';
    x[r+3][c+4]='(';
    x[r+3][c+7]='O';
    x[r+3][c+11]='O';
    x[r+3][c+14]=')';
    x[r+4][c+5]=92;
    x[r+4][c+13]='/';
    x[r+5][c+3]='.';
     for(i=0;i<2;i++){
       x[r+5][c+4+i]='_';
      }
    x[r+5][c+6]='(';
    x[r+5][c+8]='`';
    x[r+5][c+9]='-';
    x[r+5][c+10]=39;
    x[r+5][c+12]=')';
    x[r+6][c+2]='/';
    x[r+6][c+4]='!';
    x[r+6][c+7]='`';
     for(i=0;i<3;i++){
       x[r+6][c+8+i]='-';
      }
    x[r+6][c+11]=39;
    x[r+6][c+13]=92;
    x[r+6][c+14]='_';
    x[r+7][c+1]='/';
    x[r+7][c+4]=92;
     for(i=0;i<2;i++){
       x[r+7][c+15+i]=39;
      }
    x[r+7][c+17]=92;
    x[r+8][c+0]='!';
    x[r+8][c+4]='/';
    x[r+8][c+5]=92;
    x[r+8][c+14]='!';
    x[r+8][c+15]=92;
    x[r+8][c+18]=92;
    x[r+9][c+0]='!';
    x[r+9][c+4]='!';
    x[r+9][c+5]='_';
    x[r+9][c+6]=92;
     for(i=0;i<6;i++){
       x[r+9][c+7+i]='_';
      }
    x[r+9][c+13]='/';
    x[r+9][c+16]=92;
    x[r+9][c+19]=92;
    x[r+10][c+0]=92;
    x[r+10][c+5]=92;
    x[r+10][c+13]='!';
    x[r+10][c+16]='/';
    x[r+10][c+19]='/';
    x[r+11][c+1]=92;
     for(i=0;i<3;i++){
       x[r+11][c+2+i]='_';
      }
    x[r+11][c+5]='/';
    x[r+11][c+9]=')';
    x[r+11][c+12]='/';
     for(i=0;i<2;i++){
       x[r+11][c+15+i]='(';
      }
    x[r+11][c+17]=';';
     for(i=0;i<2;i++){
       x[r+11][c+18+i]=')';
      }
    x[r+12][c+3]=92;
    x[r+12][c+8]='/';
    x[r+12][c+12]='!';
    x[r+13][c+3]='/';
    x[r+13][c+7]='!';
    x[r+13][c+11]='/';
    x[r+14][c+3]='!';
    x[r+14][c+7]='/';
     for(i=0;i<2;i++){
       x[r+14][c+8+i]='_';
      }
    x[r+14][c+11]='/';
     for(i=0;i<3;i++){
       x[r+14][c+12+i]='_';
      }
    x[r+15][c+3]='(';
     for(i=0;i<6;i++){
       x[r+15][c+4+i]='_';
      }
    x[r+15][c+10]=')';
     for(i=0;i<4;i++){
       x[r+15][c+11+i]='_';
      }
    x[r+15][c+15]=')';
}
void shooting2(wchar_t x[][1190], Hero & hero){
   int r = hero.rherob;
   int c = hero.cherob;
    int i;
    
    
    x[r+0][c+3]='_';
     for(i=0;i<2;i++){
       x[r+0][c+4+i]='-';
      }
    x[r+0][c+6]='_';
    x[r+0][c+12]='_';
     for(i=0;i<2;i++){
       x[r+0][c+13+i]='-';
      }
    x[r+0][c+15]='_';
    x[r+1][c+2]='(';
    x[r+1][c+4]='(';
    x[r+1][c+5]=')';
    x[r+1][c+7]=')';
     for(i=0;i<3;i++){
       x[r+1][c+8+i]='_';
      }
    x[r+1][c+11]='(';
    x[r+1][c+13]='(';
    x[r+1][c+14]=')';
    x[r+1][c+16]=')';
    x[r+2][c+3]=92;
    x[r+2][c+7]=92;
    x[r+2][c+11]='/';
    x[r+2][c+15]='/';
    x[r+3][c+4]='(';
    x[r+3][c+7]='O';
    x[r+3][c+11]='O';
    x[r+3][c+14]=')';
    x[r+4][c+5]=92;
    x[r+4][c+13]='/';
    x[r+5][c+3]='.';
     for(i=0;i<2;i++){
       x[r+5][c+4+i]='_';
      }
    x[r+5][c+6]='(';
    x[r+5][c+8]='`';
    x[r+5][c+9]='-';
    x[r+5][c+10]=39;
    x[r+5][c+12]=')';
    x[r+6][c+2]='/';
    x[r+6][c+4]='!';
    x[r+6][c+7]='`';
     for(i=0;i<3;i++){
       x[r+6][c+8+i]='-';
      }
    x[r+6][c+11]=39;
    x[r+6][c+13]=92;
    x[r+6][c+14]='_';
    x[r+7][c+1]='/';
    x[r+7][c+4]=92;
     for(i=0;i<2;i++){
       x[r+7][c+15+i]=39;
      }
    x[r+7][c+17]=92;
    x[r+8][c+0]='!';
    x[r+8][c+4]='/';
    x[r+8][c+5]=92;
    x[r+8][c+14]='!';
    x[r+8][c+15]=92;
    x[r+8][c+18]=92;
    x[r+9][c+0]='!';
    x[r+9][c+4]='!';
    x[r+9][c+5]='_';
    x[r+9][c+6]=92;
     for(i=0;i<6;i++){
       x[r+9][c+7+i]='_';
      }
    x[r+9][c+13]='/';
    x[r+9][c+16]=92;
    x[r+9][c+19]=92;
    x[r+9][c+20]='_';
    x[r+10][c+0]=92;
    x[r+10][c+5]=92;
    x[r+10][c+13]='!';
    x[r+10][c+17]=92;
     for(i=0;i<3;i++){
       x[r+10][c+18+i]='_';
      }
    x[r+10][c+21]='(';
    x[r+11][c+1]=92;
     for(i=0;i<3;i++){
       x[r+11][c+2+i]='_';
      }
    x[r+11][c+5]='/';
    x[r+11][c+9]=')';
    x[r+11][c+12]='/';
    x[r+12][c+3]=92;
    x[r+12][c+8]='/';
    x[r+12][c+12]='!';
    x[r+13][c+3]='/';
    x[r+13][c+7]='!';
    x[r+13][c+11]='/';
    x[r+14][c+3]='!';
    x[r+14][c+7]='/';
     for(i=0;i<2;i++){
       x[r+14][c+8+i]='_';
      }
    x[r+14][c+11]='/';
     for(i=0;i<3;i++){
       x[r+14][c+12+i]='_';
      }
    x[r+15][c+3]='(';
     for(i=0;i<6;i++){
       x[r+15][c+4+i]='_';
      }
    x[r+15][c+10]=')';
     for(i=0;i<4;i++){
       x[r+15][c+11+i]='_';
      }
    x[r+15][c+15]=')';
}
void shooting3(wchar_t x[][1190], Hero & hero){
  int  r = hero.rherob;
  int  c = hero.cherob;
    int i;

    
    x[r+0][c+3]='_';
     for(i=0;i<2;i++){
       x[r+0][c+4+i]='-';
      }
    x[r+0][c+6]='_';
    x[r+0][c+12]='_';
     for(i=0;i<2;i++){
       x[r+0][c+13+i]='-';
      }
    x[r+0][c+15]='_';
    x[r+1][c+2]='(';
    x[r+1][c+4]='(';
    x[r+1][c+5]=')';
    x[r+1][c+7]=')';
     for(i=0;i<3;i++){
       x[r+1][c+8+i]='_';
      }
    x[r+1][c+11]='(';
    x[r+1][c+13]='(';
    x[r+1][c+14]=')';
    x[r+1][c+16]=')';
    x[r+2][c+3]=92;
    x[r+2][c+7]=92;
    x[r+2][c+11]='/';
    x[r+2][c+15]='/';
    x[r+3][c+4]='(';
    x[r+3][c+7]='O';
    x[r+3][c+11]='O';
    x[r+3][c+14]=')';
    x[r+4][c+5]=92;
    x[r+4][c+13]='/';
    x[r+5][c+3]='.';
     for(i=0;i<2;i++){
       x[r+5][c+4+i]='_';
      }
    x[r+5][c+6]='(';
    x[r+5][c+8]='`';
    x[r+5][c+9]='-';
    x[r+5][c+10]=39;
    x[r+5][c+12]=')';
    x[r+6][c+2]='/';
    x[r+6][c+4]='!';
    x[r+6][c+7]='`';
     for(i=0;i<3;i++){
       x[r+6][c+8+i]='-';
      }
    x[r+6][c+11]=39;
    x[r+6][c+13]=92;
    x[r+6][c+14]='_';
    x[r+7][c+1]='/';
    x[r+7][c+4]=92;
    x[r+7][c+15]=39;
    x[r+7][c+16]=92;
    x[r+8][c+0]='!';
    x[r+8][c+4]='/';
    x[r+8][c+5]=92;
    x[r+8][c+14]='!';
    x[r+8][c+15]=92;
    x[r+8][c+17]=92;
    x[r+8][c+18]='_';
    x[r+8][c+19]='/';
    x[r+8][c+20]='(';
    x[r+9][c+0]='!';
    x[r+9][c+4]='!';
    x[r+9][c+5]='_';
    x[r+9][c+6]=92;
     for(i=0;i<6;i++){
       x[r+9][c+7+i]='_';
      }
    x[r+9][c+13]='/';
    x[r+9][c+16]=92;
     for(i=0;i<3;i++){
       x[r+9][c+17+i]='_';
      }
    x[r+9][c+20]='/';
    x[r+10][c+0]=92;
    x[r+10][c+5]=92;
    x[r+10][c+13]='!';
    x[r+11][c+1]=92;
     for(i=0;i<3;i++){
       x[r+11][c+2+i]='_';
      }
    x[r+11][c+5]='/';
    x[r+11][c+9]=')';
    x[r+11][c+12]='/';
    x[r+12][c+3]=92;
    x[r+12][c+8]='/';
    x[r+12][c+12]='!';
    x[r+13][c+3]='/';
    x[r+13][c+7]='!';
    x[r+13][c+11]='/';
    x[r+14][c+3]='!';
    x[r+14][c+7]='/';
     for(i=0;i<2;i++){
       x[r+14][c+8+i]='_';
      }
    x[r+14][c+11]='/';
     for(i=0;i<3;i++){
       x[r+14][c+12+i]='_';
      }
    x[r+15][c+3]='(';
     for(i=0;i<6;i++){
       x[r+15][c+4+i]='_';
      }
    x[r+15][c+10]=')';
     for(i=0;i<4;i++){
       x[r+15][c+11+i]='_';
      }
    x[r+15][c+15]=')';
}
void gunWithSmoke(wchar_t x[][1190], Hero & hero){
  int  r = hero.rherob+5;
  int  c = hero.cherob+16;
  int i;
    
    x[r+0][c+13]=')';
    x[r+1][c+12]='(';
     for(i=0;i<2;i++){
       x[r+2][c+2+i]='_';
      }
    x[r+2][c+4]=',';
     for(i=0;i<5;i++){
       x[r+2][c+5+i]='_';
      }
    x[r+2][c+11]=')';
    x[r+3][c+1]='/';
     for(i=0;i<2;i++){
       x[r+3][c+3+i]='_';
      }
    x[r+3][c+5]='.';
     for(i=0;i<2;i++){
       x[r+3][c+6+i]='=';
      }
     for(i=0;i<2;i++){
       x[r+3][c+8+i]='-';
      }
    x[r+3][c+10]='"';
    x[r+4][c+0]='/';
    x[r+4][c+1]='#';
    x[r+4][c+2]='(';
    x[r+4][c+3]='-';
    x[r+4][c+4]=39;
    x[r+5][c+0]='`';
    x[r+5][c+1]='-';
    x[r+5][c+2]=39;
    
    
}
void drawBullet(wchar_t x[][1190], Hero & hero,Bullet & bullet){
   int r= bullet.rBullet;
   int c= bullet.cBullet;
    
    if(bullet.dir==1){
        x[r][c]=x[r][c+1]=':';
        x[r][c+2]='>';
    }
    if(bullet.dir==-1){
        x[r][c]=x[r][c-1]=':';
        x[r][c-2]='<';
    }
}
void checkNoObstacleBullet(wchar_t x[][1190], Bullet & bullet, int endOfScreen, Hero & hero){
    if(x[bullet.rBullet][bullet.cBullet+3]!=' ' || bullet.cBullet>=1190){
        bullet.stopBullet=1;
        hero.ctLostBullets++;
    }
    else{
        bullet.stopBullet=0;
    }
}
void moveBullet(wchar_t x[][1190], Hero & hero,Bullet * bullet, int ctBullets, int endOfScreen,Bat &bat){
    for(int i=0; i<ctBullets;i++){
        
        checkNoObstacleBullet(x, bullet[i], endOfScreen, hero);
        if(bullet[i].dir==1 && !bullet[i].stopBullet){
            drawBullet(x, hero, bullet[i]);
            bullet[i].cBullet++;
        }
       
            
        
        
    
        
    }
}

void checkSnail(wchar_t x[][1190], Hero & hero,Bullet * bullet, int ctBullets, Snail& snail){
    
    for(int i=0; i<ctBullets;i++){
        
        if(bullet[i].cBullet+5>=snail.cb &&bullet[i].cBullet<=snail.cb+15 && bullet[i].rBullet >=snail.rb){
            snail.health--;
            if(snail.health==0 &&hero.health<=5){
                hero.health++;
            }
            
            
            
            
        }
    }
}
void checkBatDie(wchar_t x[][1190], Hero & hero,Bullet * bullet, int ctBullets, int endOfScreen,Bat &bat){
    for(int i=0; i<ctBullets;i++){
        if(bullet[i].rBullet>=bat.r &&bullet[i].rBullet<=bat.r+6 && bullet[i].cBullet-5>=bat.c &&bullet[i].cBullet<=bat.c+5){
            bat.health--;
            if(bat.health==0 &&hero.health<=5){
                hero.health++;
            }
            bat.frames=690000+150;
            
        }
        
    
        
    }
}

void checkEnemyDie(wchar_t x[][1190], Hero & hero,Bullet * bullet, int ctBullets, int endOfScreen,Enemy &enemy){
    for(int i=0; i<ctBullets;i++){
        
       
        if(bullet[i].rBullet>=enemy.rb-2 &&bullet[i].rBullet<=enemy.rb+6 && bullet[i].cBullet>=enemy.cb-10 &&bullet[i].cBullet<=enemy.cb+15){
            enemy.health--;
            enemy.cb+=enemy.dir*2;
            if(enemy.health==0 &&hero.health<=5){
                hero.health++;
                
            }
            enemy.frames=690000+150;
            
        }
        
        
            enemy.frames=690000+150;
            
        }
        
    
        
    }



void mainShooting(wchar_t x[][1190], Hero & hero){
    if(hero.flagShooting==1){
        shooting1(x, hero);
   
    }
    if(hero.flagShooting==2){
        shooting2(x, hero);
        
    }
    if(hero.flagShooting==3){
        shooting3(x, hero);
        drawGun(x, hero);
        
    }
    if(hero.flagShooting>=4){
        shooting3(x, hero);
   
    }
    hero.flagShooting++;
  }
//walking animation
void walking2(wchar_t x[][1190], Hero & hero){
    int r = hero.rherob;
    int c = hero.cherob;
     int i;
   

   
    x[r+0][c+2]='_';
     for(i=0;i<2;i++){
       x[r+0][c+3+i]='-';
      }
    x[r+0][c+5]='_';
    x[r+0][c+11]='_';
     for(i=0;i<2;i++){
       x[r+0][c+12+i]='-';
      }
    x[r+0][c+14]='_';
    x[r+1][c+1]='(';
    x[r+1][c+3]='(';
    x[r+1][c+4]=')';
    x[r+1][c+6]=')';
     for(i=0;i<3;i++){
       x[r+1][c+7+i]='_';
      }
    x[r+1][c+10]='(';
    x[r+1][c+12]='(';
    x[r+1][c+13]=')';
    x[r+1][c+15]=')';
    x[r+2][c+2]=92;
    x[r+2][c+6]=92;
    x[r+2][c+10]='/';
    x[r+2][c+14]='/';
    x[r+3][c+3]='(';
    x[r+3][c+6]='O';
    x[r+3][c+10]='O';
    x[r+3][c+13]=')';
    x[r+4][c+4]=92;
    x[r+4][c+12]='/';
    x[r+5][c+5]='(';
    x[r+5][c+7]='`';
    x[r+5][c+8]='-';
    x[r+5][c+9]=39;
    x[r+5][c+11]=')';
    x[r+6][c+3]='_';
     for(i=0;i<2;i++){
       x[r+6][c+4+i]='-';
      }
    x[r+6][c+6]=39;
    x[r+6][c+7]='`';
     for(i=0;i<3;i++){
       x[r+6][c+8+i]='-';
      }
    x[r+6][c+11]='_';
    x[r+7][c+2]='/';
    x[r+7][c+12]=92;
     for(i=0;i<3;i++){
       x[r+7][c+13+i]='_';
      }
    x[r+8][c+1]='/';
    x[r+8][c+5]='/';
    x[r+8][c+13]='!';
    x[r+8][c+16]=92;
    x[r+9][c+0]='(';
    x[r+9][c+4]='<';
    x[r+9][c+13]='!';
     for(i=0;i<2;i++){
       x[r+9][c+14+i]='_';
      }
    x[r+9][c+16]='/';
    x[r+10][c+1]=92;
    x[r+10][c+5]=92;
    x[r+10][c+12]='/';
    x[r+10][c+13]=92;
    x[r+11][c+2]=92;
     for(i=0;i<2;i++){
       x[r+11][c+3+i]='-';
      }
    x[r+11][c+5]='/';
    x[r+11][c+9]=92;
    x[r+11][c+11]='/';
    x[r+11][c+14]=92;
    x[r+11][c+17]='.';
    x[r+11][c+18]='_';
    x[r+12][c+4]='`';
    x[r+12][c+5]='.';
    x[r+12][c+10]=')';
    x[r+12][c+11]='-';
    x[r+12][c+15]=92;
    x[r+12][c+16]='/';
    x[r+12][c+19]=')';
    x[r+13][c+5]='!';
    x[r+13][c+9]='!';
    x[r+13][c+12]='`';
    x[r+13][c+13]='.';
    x[r+13][c+18]='/';
    x[r+14][c+5]='/';
    x[r+14][c+8]='/';
     for(i=0;i<2;i++){
       x[r+14][c+9+i]='_';
      }
    x[r+14][c+14]=92;
     for(i=0;i<2;i++){
       x[r+14][c+15+i]='_';
      }
    x[r+14][c+17]='/';
    x[r+15][c+4]='(';
     for(i=0;i<6;i++){
       x[r+15][c+5+i]='_';
      }
    x[r+15][c+11]=')';
}
void walking2InRev(wchar_t x[][1190], Hero & hero){
    int r = hero.rherob;
    int c = hero.cherob;
     int i;
   

    
    x[r+0][c+10]='_';
     for(i=0;i<2;i++){
       x[r+0][c+11+i]='-';
      }
    x[r+0][c+13]='_';
    x[r+0][c+19]='_';
     for(i=0;i<2;i++){
       x[r+0][c+20+i]='-';
      }
    x[r+0][c+22]='_';
    x[r+1][c+9]='(';
    x[r+1][c+11]='(';
    x[r+1][c+12]=')';
    x[r+1][c+14]=')';
     for(i=0;i<3;i++){
       x[r+1][c+15+i]='_';
      }
    x[r+1][c+18]='(';
    x[r+1][c+20]='(';
    x[r+1][c+21]=')';
    x[r+1][c+23]=')';
    x[r+2][c+10]=92;
    x[r+2][c+14]=92;
    x[r+2][c+18]='/';
    x[r+2][c+22]='/';
    x[r+3][c+11]='(';
    x[r+3][c+14]='O';
    x[r+3][c+18]='O';
    x[r+3][c+21]=')';
    x[r+4][c+12]=92;
    x[r+4][c+20]='/';
    x[r+5][c+13]='(';
    x[r+5][c+15]='`';
    x[r+5][c+16]='-';
    x[r+5][c+17]=39;
    x[r+5][c+19]=')';
     for(i=0;i<2;i++){
       x[r+5][c+20+i]='_';
      }
    x[r+5][c+22]='.';
    x[r+6][c+12]='_';
    x[r+6][c+14]=39;
     for(i=0;i<3;i++){
       x[r+6][c+15+i]='-';
      }
    x[r+6][c+18]=39;
    x[r+6][c+23]=92;
     for(i=0;i<3;i++){
       x[r+7][c+7+i]='_';
      }
    x[r+7][c+11]='/';
    x[r+7][c+20]=92;
    x[r+7][c+25]=92;
    x[r+8][c+5]='/';
    x[r+8][c+9]='!';
    x[r+8][c+20]='>';
    x[r+8][c+26]=')';
    x[r+9][c+5]=92;
     for(i=0;i<2;i++){
       x[r+9][c+6+i]='_';
      }
    x[r+9][c+9]='!';
    x[r+9][c+10]='_';
    x[r+9][c+21]='/';
    x[r+9][c+25]='/';
    x[r+10][c+9]='(';
    x[r+10][c+11]=39;
    x[r+10][c+21]=92;
     for(i=0;i<2;i++){
       x[r+10][c+22+i]='-';
      }
    x[r+10][c+24]='/';
    x[r+11][c+10]='/';
    x[r+11][c+13]=92;
    x[r+11][c+16]='/';
    x[r+11][c+20]='!';
    x[r+12][c+5]='_';
    x[r+12][c+6]='.';
    x[r+12][c+9]='/';
    x[r+12][c+15]='-';
    x[r+12][c+17]='!';
    x[r+12][c+20]='!';
    x[r+13][c+4]='(';
    x[r+13][c+8]=92;
    x[r+13][c+13]='_';
    x[r+13][c+14]='-';
     for(i=0;i<2;i++){
       x[r+13][c+16+i]='_';
      }
    x[r+13][c+18]=92;
    x[r+13][c+22]=92;
    x[r+14][c+5]=92;
    x[r+14][c+10]='.';
    x[r+14][c+11]=39;
     for(i=0;i<2;i++){
       x[r+14][c+15+i]='_';
      }
    x[r+14][c+18]='/';
    x[r+14][c+22]='/';
    x[r+15][c+6]=92;
     for(i=0;i<2;i++){
       x[r+15][c+7+i]='_';
      }
    x[r+15][c+9]='/';
    x[r+15][c+14]='(';
     for(i=0;i<7;i++){
       x[r+15][c+15+i]='_';
      }
    x[r+15][c+22]=')';
}

void walking3(wchar_t x[][1190], Hero & hero){
    int r = hero.rherob;
    int c = hero.cherob;
    int i;
    
    
    
    x[r+0][c+2]='_';
     for(i=0;i<2;i++){
       x[r+0][c+3+i]='-';
      }
    x[r+0][c+5]='_';
    x[r+0][c+11]='_';
     for(i=0;i<2;i++){
       x[r+0][c+12+i]='-';
      }
    x[r+0][c+14]='_';
    x[r+1][c+1]='(';
    x[r+1][c+3]='(';
    x[r+1][c+4]=')';
    x[r+1][c+6]=')';
     for(i=0;i<3;i++){
       x[r+1][c+7+i]='_';
      }
    x[r+1][c+10]='(';
    x[r+1][c+12]='(';
    x[r+1][c+13]=')';
    x[r+1][c+15]=')';
    x[r+2][c+2]=92;
    x[r+2][c+6]=92;
    x[r+2][c+10]='/';
    x[r+2][c+14]='/';
    x[r+3][c+3]='(';
    x[r+3][c+6]='O';
    x[r+3][c+10]='O';
    x[r+3][c+13]=')';
    x[r+4][c+4]=92;
    x[r+4][c+12]='/';
    x[r+5][c+5]='(';
    x[r+5][c+7]='`';
    x[r+5][c+8]='-';
    x[r+5][c+9]=39;
    x[r+5][c+11]=')';
    x[r+6][c+3]='.';
     for(i=0;i<2;i++){
       x[r+6][c+4+i]='-';
      }
    x[r+6][c+6]='`';
     for(i=0;i<3;i++){
       x[r+6][c+7+i]='-';
      }
    x[r+6][c+10]=39;
    x[r+6][c+11]=92;
    x[r+7][c+2]='/';
    x[r+7][c+11]='_';
    x[r+7][c+12]='>';
    x[r+7][c+13]=92;
    x[r+8][c+1]='/';
    x[r+8][c+4]='/';
    x[r+8][c+5]='-';
     for(i=0;i<3;i++){
       x[r+8][c+6+i]='_';
      }
    x[r+8][c+9]='-';
    x[r+8][c+10]=39;
    x[r+8][c+14]=')';
    x[r+9][c+0]='/';
    x[r+9][c+1]=39;
    x[r+9][c+4]='(';
    x[r+9][c+13]='_';
    x[r+9][c+14]='/';
    x[r+10][c+0]=92;
     for(i=0;i<3;i++){
       x[r+10][c+1+i]='_';
      }
    x[r+10][c+4]='/';
    x[r+10][c+5]='`';
     for(i=0;i<6;i++){
       x[r+10][c+6+i]='-';
      }
    x[r+10][c+12]=39;
    x[r+10][c+14]=')';
    x[r+11][c+4]=92;
    x[r+11][c+11]='`';
    x[r+11][c+12]='<';
     for(i=0;i<3;i++){
       x[r+12][c+2+i]='_';
      }
    x[r+12][c+5]='>';
    x[r+12][c+6]='-';
    x[r+12][c+7]='_';
    x[r+12][c+13]=92;
    x[r+12][c+17]='/';
    x[r+12][c+18]='-';
    x[r+12][c+19]=92;
    x[r+13][c+1]='/';
    x[r+13][c+8]='`';
    x[r+13][c+9]='-';
    x[r+13][c+10]='_';
    x[r+13][c+14]='`';
    x[r+13][c+15]='-';
    x[r+13][c+16]='/';
    x[r+13][c+19]='/';
    x[r+14][c+0]='(';
    x[r+14][c+3]=92;
     for(i=0;i<3;i++){
       x[r+14][c+4+i]='-';
      }
     for(i=0;i<2;i++){
       x[r+14][c+7+i]='_';
      }
    x[r+14][c+9]='/';
    x[r+14][c+11]='`';
    x[r+14][c+12]='-';
    x[r+14][c+13]='_';
    x[r+14][c+18]='/';
    x[r+15][c+1]=92;
     for(i=0;i<2;i++){
       x[r+15][c+2+i]='_';
      }
    x[r+15][c+4]=')';
    x[r+15][c+14]='`';
    x[r+15][c+15]='-';
    x[r+15][c+16]='_';
    x[r+15][c+17]='/';
}
void walking3InRev(wchar_t x[][1190], Hero & hero){
    int r = hero.rherob;
    int c = hero.cherob;
    int i;
    
    
    
    
    x[r+0][c+10]='_';
     for(i=0;i<2;i++){
       x[r+0][c+11+i]='-';
      }
    x[r+0][c+13]='_';
    x[r+0][c+19]='_';
     for(i=0;i<2;i++){
       x[r+0][c+20+i]='-';
      }
    x[r+0][c+22]='_';
    x[r+1][c+9]='(';
    x[r+1][c+11]='(';
    x[r+1][c+12]=')';
    x[r+1][c+14]=')';
     for(i=0;i<3;i++){
       x[r+1][c+15+i]='_';
      }
    x[r+1][c+18]='(';
    x[r+1][c+20]='(';
    x[r+1][c+21]=')';
    x[r+1][c+23]=')';
    x[r+2][c+10]=92;
    x[r+2][c+14]=92;
    x[r+2][c+18]='/';
    x[r+2][c+22]='/';
    x[r+3][c+11]='(';
    x[r+3][c+14]='O';
    x[r+3][c+18]='O';
    x[r+3][c+21]=')';
    x[r+4][c+12]=92;
    x[r+4][c+20]='/';
    x[r+5][c+13]='(';
    x[r+5][c+15]='`';
    x[r+5][c+16]='-';
    x[r+5][c+17]=39;
    x[r+5][c+19]=')';
     for(i=0;i<2;i++){
       x[r+5][c+20+i]='_';
      }
    x[r+5][c+22]='.';
    x[r+6][c+12]='/';
    x[r+6][c+14]=39;
     for(i=0;i<3;i++){
       x[r+6][c+15+i]='-';
      }
    x[r+6][c+18]=39;
    x[r+6][c+23]=92;
    x[r+7][c+10]='/';
    x[r+7][c+12]='<';
    x[r+7][c+13]='_';
    x[r+7][c+24]=92;
    x[r+8][c+9]='(';
    x[r+8][c+14]=39;
    x[r+8][c+15]='-';
     for(i=0;i<3;i++){
       x[r+8][c+16+i]='_';
      }
    x[r+8][c+19]='-';
    x[r+8][c+20]=92;
    x[r+8][c+25]=92;
    x[r+9][c+9]=92;
    x[r+9][c+10]='_';
    x[r+9][c+21]=')';
    x[r+9][c+25]=39;
    x[r+9][c+26]=92;
    x[r+10][c+9]='(';
    x[r+10][c+11]=39;
     for(i=0;i<9;i++){
       x[r+10][c+12+i]='_';
      }
    x[r+10][c+21]='`';
    x[r+10][c+22]=92;
     for(i=0;i<3;i++){
       x[r+10][c+23+i]='_';
      }
    x[r+10][c+26]='/';
    x[r+11][c+11]='>';
    x[r+11][c+12]=39;
    x[r+11][c+21]='/';
    x[r+12][c+6]='/';
    x[r+12][c+7]='-';
    x[r+12][c+8]=92;
    x[r+12][c+11]='/';
    x[r+12][c+19]='_';
    x[r+12][c+20]='-';
    x[r+12][c+21]='<';
     for(i=0;i<3;i++){
       x[r+12][c+22+i]='_';
      }
    x[r+13][c+6]=92;
    x[r+13][c+9]=92;
    x[r+13][c+10]='-';
    x[r+13][c+11]=39;
    x[r+13][c+17]='_';
    x[r+13][c+18]='-';
    x[r+13][c+19]=39;
    x[r+13][c+25]=92;
    x[r+14][c+7]=92;
    x[r+14][c+12]='_';
    x[r+14][c+13]='-';
    x[r+14][c+14]=39;
    x[r+14][c+15]=92;
     for(i=0;i<2;i++){
       x[r+14][c+16+i]='_';
      }
     for(i=0;i<3;i++){
       x[r+14][c+18+i]='-';
      }
    x[r+14][c+21]='/';
    x[r+14][c+26]=')';
    x[r+15][c+8]=92;
    x[r+15][c+9]='_';
    x[r+15][c+10]='-';
    x[r+15][c+11]=39;
    x[r+15][c+21]='(';
     for(i=0;i<3;i++){
       x[r+15][c+22+i]='_';
      }
    x[r+15][c+25]='/';
}

void walkingMain(wchar_t x[][1190], Hero & hero){
    
    if(hero.walkingFrames<30){
       
        if(checkNoObstacle(x, hero, hero.dir) ){
            walking2(x, hero);
            if(hero.walkingFrames==29){
                hero.cherob+=4;
                hero.cheroe+=4;
            }
        
        }
    }
    
    if(hero.walkingFrames<60 && hero.walkingFrames>30){
        walking3(x, hero);
        if(checkNoObstacle(x, hero, hero.dir)){
          
            if(hero.walkingFrames==30){
                hero.cherob+=4;
                hero.cheroe+=4;
            }
            
        }
    }
    hero.walkingFrames++;
    if(hero.walkingFrames>=60){
        hero.walkingFrames=0;
        hero.isWalking=0;
        
    }
}

void walkingMainInRev(wchar_t x[][1190], Hero & hero){
    
    if(hero.walkingFrames2<30){
       
        if(checkNoObstacle(x, hero, hero.dir) ){
            walking2InRev(x, hero);
            if(hero.walkingFrames2==29){
                hero.cherob-=4;
                hero.cheroe-=4;
            }
        
        }
    }
    
    if(hero.walkingFrames2<60 && hero.walkingFrames2>30){
        walking3InRev(x, hero);
        if(checkNoObstacle(x, hero, hero.dir)){
          
            if(hero.walkingFrames2==30){
                hero.cherob-=4;
                hero.cheroe-=4;
            }
            
        }
    }
    hero.walkingFrames2++;
    if(hero.walkingFrames2>=60){
        hero.walkingFrames2=0;
        hero.isWalking=0;
        
    }
}






void moveHero(wchar_t x[][1190], Hero& hero, char  move, int f, Elevator& elevator) {
    
    if (move == 'a')
        
    {
        
        hero.dir=-1;

         hero.isWalking=1;
     
        for(int i=0;i<4;i++){
            for(int j=hero.rherob;j<hero.rheroe;j++){
                if(x[j][hero.cherob-1]==219){
                    hero.health--;
                    hero.rherob=128;
                    hero.rheroe=143;
                    hero.cherob=20;
                    hero.cheroe=41;
                }
            
             
            }

        }
        
       
     
        
    }
    else
    {
        if (move == 'd')
        {
            for(int i=hero.rherob;i<hero.rheroe;i++){
                if(x[i][hero.cheroe+1]==219){
                    hero.health--;
                    hero.rherob=128;
                    hero.rheroe=143;
                    hero.cherob=20;
                    hero.cheroe=41;
                }
                
                if(x[i][hero.cheroe+1]=='*'){
                    hero.health--;
                    hero.rherob=128;
                    hero.rheroe=143;
                    hero.cherob=20;
                    hero.cheroe=41;
                }
                
               
              
             
            }
            hero.dir=1;
            hero.isWalking=1;
            
         
        }
        else
        {
            if (move == 'w' && f==0 && !hero.jumpFrames)
            {
                
                hero.flagGump = 1;
                hero.jumpFrames=0;
            }
            
            else{
                if (move == 'e'&& f==0 && !hero.jumpFrames)
                {
                    hero.dir=1;
                    hero.flagGumpRight = 1;
                    hero.jumpFrames=0;
                   
                   
                }
                
                else{
                    if (move == 'q' && f==0 &&!hero.jumpFrames )
                    {
                        hero.dir=-1;
                        hero.flagGumpLft = 1;
                        hero.jumpFrames=0;
                       
                    }
                    else{
                        if(move=='m'){
                            if(hero.cherob>=690 && hero.cherob<=735 && hero.rherob>=elevator.rb && hero.rherob<=elevator.rb+22&& hero.flagInElevator==0){
                                hero.cherob=elevator.cb+5;
                                hero.cheroe=elevator.cb+5+16;
                                hero.rherob=elevator.rb+2;
                                hero.rheroe=elevator.rb+2+15;
                                hero.flagInElevator=1;
                            }
                            
                           else if(hero.flagInElevator==1){
                               hero.cherob=elevator.cb+33;
                               hero.cheroe=elevator.cb+33+16;
                               hero.flagInElevator=0;
                            }
                        }
                        
                        else{
                            if(move=='n')
                                if(hero.cherob>=735 && hero.cherob<=770 && hero.rherob>=elevator.rb && hero.rherob<=elevator.rb+22&& hero.flagInElevator==0){
                                    hero.cherob=elevator.cb+5;
                                    hero.cheroe=elevator.cb+5+16;
                                    hero.rherob=elevator.rb+2;
                                    hero.rheroe=elevator.rb+2+15;
                                    hero.flagInElevator=1;
                                }
                            if(hero.flagInElevator==1 && hero.rherob<130 && hero.rherob>100){
                                
                                hero.cherob=elevator.cb-33;
                                hero.cheroe=elevator.cb-33+16;
                                hero.flagInElevator=0;
                                 
                                 }
                        }
                    }
                    
              
                 
                }
            }
        }
            
                
    }
    
    
}
void isScrollingLftToRight(wchar_t  x[] [1190], int &startOfScreen, int cherob, int &endOfScreen){
    
    
        startOfScreen = 0;
        endOfScreen=238;

        if(cherob>1190-238){
            endOfScreen=1190;
            startOfScreen=1190-238;
            
        }
    
        else{
            if(cherob<100){
                    startOfScreen = 0;
                    endOfScreen=238;
                }
                if(cherob>startOfScreen+100){
                    startOfScreen = cherob-100 ;
                    endOfScreen=startOfScreen+238;

                }
            
         
               
            }
        
    }
void isScrollingBtmTop(wchar_t  x[][1190], int& startOfScreen, int rherob, int& endOfScreen) {


    startOfScreen = 74;
    endOfScreen = 148;

    if (rherob > 222 - 74) {
        endOfScreen = 222;
        startOfScreen = 222 - 74;

    }

    else {
        if (rherob < startOfScreen + 20) {
            startOfScreen = rherob - 20;
            endOfScreen = startOfScreen + 74;

        }



    }

}


void drawElevator(wchar_t  x[][1190], Elevator& elevator){
   int r=elevator.rb;
    int c=elevator.cb;
    int i;
    
    for(i=0;i<14;i++){
      x[r+0][c+1+i]=45;
     }
   x[r+0][c+15]=124;
    for(i=0;i<13;i++){
      x[r+0][c+16+i]=45;
     }
   x[r+1][c+0]=124;
   x[r+1][c+29]=124;
   x[r+2][c+0]=124;
   x[r+2][c+29]=124;
   x[r+3][c+0]=124;
   x[r+3][c+29]=124;
   x[r+4][c+0]=124;
   x[r+4][c+29]=124;
   x[r+5][c+0]=124;
   x[r+5][c+29]=124;
   x[r+6][c+0]=124;
   x[r+6][c+29]=124;
   x[r+7][c+0]=124;
   x[r+7][c+29]=124;
   x[r+8][c+0]=124;
   x[r+8][c+29]=124;
   x[r+9][c+0]=124;
   x[r+9][c+29]=124;
   x[r+10][c+0]=124;
   x[r+10][c+29]=124;
   x[r+11][c+0]=124;
   x[r+11][c+29]=124;
   x[r+12][c+0]=124;
   x[r+12][c+29]=124;
   x[r+13][c+0]=124;
   x[r+13][c+29]=124;
   x[r+14][c+0]=124;
   x[r+14][c+29]=124;
   x[r+15][c+0]=124;
   x[r+15][c+29]=124;
   x[r+16][c+0]=124;
   x[r+16][c+29]=124;
   x[r+17][c+0]=124;
   x[r+17][c+29]=124;
   x[r+18][c+0]=124;
   x[r+18][c+29]=124;
   x[r+19][c+0]=124;
   x[r+19][c+29]=124;
   x[r+20][c+0]=124;
   x[r+20][c+29]=124;
   x[r+21][c+0]=124;
   x[r+21][c+29]=124;
   x[r+22][c+0]=124;
   x[r+22][c+29]=124;
    for(i=0;i<28;i++){
      x[r+23][c+1+i]=45;
     }
}

void drawElevatorStand(wchar_t  x[][1190], Elevator& elevator){
    int r=elevator.rStand;
     int c=elevator.cStand;
     int i;
    
    for(i=0;i<82;i++){
      x[r+0][c+8+i]=95;
     }
   x[r+1][c+15]=124;
    for(i=0;i<2;i++){
      x[r+1][c+80+i]=124;
     }
   x[r+2][c+15]=124;
    for(i=0;i<2;i++){
      x[r+2][c+80+i]=124;
     }
   x[r+3][c+14]=47;
   x[r+3][c+16]=92;
    for(i=0;i<2;i++){
      x[r+3][c+80+i]=124;
     }
   x[r+4][c+13]=47;
   x[r+4][c+15]=48;
   x[r+4][c+17]=92;
    for(i=0;i<2;i++){
      x[r+4][c+80+i]=124;
     }
   x[r+5][c+13]=92;
   x[r+5][c+17]=47;
    for(i=0;i<2;i++){
      x[r+5][c+80+i]=124;
     }
   x[r+6][c+14]=92;
   x[r+6][c+15]=124;
   x[r+6][c+16]=47;
    for(i=0;i<2;i++){
      x[r+6][c+80+i]=124;
     }
   x[r+7][c+15]=124;
    for(i=0;i<2;i++){
      x[r+7][c+80+i]=124;
     }
   x[r+8][c+15]=124;
    for(i=0;i<2;i++){
      x[r+8][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+9][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+10][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+11][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+12][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+13][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+14][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+15][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+16][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+17][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+18][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+19][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+20][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+21][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+22][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+23][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+24][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+25][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+26][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+27][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+28][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+29][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+30][c+80+i]=124;
     }
    for(i=0;i<2;i++){
      x[r+31][c+80+i]=124;
     }
    for(i=0;i<6;i++){
      x[r+32][c+74+i]=95;
     }
    for(i=0;i<2;i++){
      x[r+32][c+80+i]=124;
     }
    for(i=0;i<6;i++){
      x[r+32][c+82+i]=95;
     }

}

void moveElevator(wchar_t  x[][1190], Elevator& elevator, Hero& hero){
    

    if(elevator.frames%15==0){
        if(elevator.rb==120){
            elevator.dir*=-1;
        }
        if(elevator.dir==1){
            elevator.rb+=elevator.dir;
            
        }
        
        if(elevator.rb+23==222-5){
            elevator.dir*=-1;
        }
     
    
        if(elevator.dir==-1){
            x[elevator.rb-1][elevator.cb+15]=' ';
            elevator.rb+=elevator.dir;
           
        }
        if(hero.cherob>=elevator.cb &&hero.cherob<=elevator.cb+30 && hero.rherob>=elevator.rb-20 && hero.rherob<elevator.rb+24){
            hero.rherob+=elevator.dir;
            hero.rheroe+=elevator.dir;
        }
    }
    
    for(int f=120-1; f<=elevator.rb;f++){
        x[f][elevator.cb+15]='|';
    }
    
    if(hero.cherob>=690 && hero.cherob<=736 && hero.rherob>=elevator.rb && hero.rherob<=elevator.rb+27&& hero.flagInElevator==0){
        hero.cherob=elevator.cb+5;
        hero.cheroe=elevator.cb+5+16;
        hero.rherob=elevator.rb+2;
        hero.rheroe=elevator.rb+2+15;
        hero.flagInElevator=1;
    }
   
  
    
    elevator.frames++;
    
}




void drawPlane(wchar_t x[][1190], Hero & hero){
    int i;
    int r=100;
    int c=120+35*5;
    
    for(i=0;i<3;i++){
      x[r+0][c+36+i]='_';
     }
   x[r+0][c+40]='-';
   x[r+0][c+41]='(';
   x[r+1][c+0]='_';
   x[r+1][c+33]='_';
   x[r+1][c+34]='(';
    for(i=0;i<4;i++){
      x[r+1][c+35+i]='_';
     }
   x[r+1][c+39]='-';
   x[r+1][c+40]='(';
    for(i=0;i<2;i++){
      x[r+2][c+0+i]=92;
     }
    for(i=0;i<2;i++){
      x[r+2][c+32+i]='/';
     }
    for(i=0;i<2;i++){
      x[r+3][c+1+i]=92;
     }
    for(i=0;i<2;i++){
      x[r+3][c+31+i]='/';
     }
    for(i=0;i<2;i++){
      x[r+4][c+2+i]=92;
     }
    for(i=0;i<26;i++){
      x[r+4][c+4+i]='=';
     }
    for(i=0;i<2;i++){
      x[r+4][c+30+i]='/';
     }
 
}
void drawHero2(wchar_t x[][1190], Hero2 & hero2){
    int i;
    int r=hero2.r;
    int c=hero2.c;
    x[r+0][c+14]='_';
     for(i=0;i<2;i++){
       x[r+0][c+15+i]='-';
      }
    x[r+0][c+17]='_';
    x[r+0][c+23]='_';
     for(i=0;i<2;i++){
       x[r+0][c+24+i]='-';
      }
    x[r+0][c+26]='_';
    x[r+1][c+13]='(';
    x[r+1][c+15]='(';
    x[r+1][c+16]=')';
    x[r+1][c+18]=')';
     for(i=0;i<3;i++){
       x[r+1][c+19+i]='_';
      }
    x[r+1][c+22]='(';
    x[r+1][c+24]='(';
    x[r+1][c+25]=')';
    x[r+1][c+27]=')';
    x[r+2][c+14]=92;
    x[r+2][c+18]=92;
    x[r+2][c+22]='/';
    x[r+2][c+26]='/';
    x[r+3][c+15]='(';
    x[r+3][c+18]='O';
    x[r+3][c+22]='O';
    x[r+3][c+25]=')';
    x[r+4][c+16]=92;
    x[r+4][c+24]='/';
    x[r+5][c+14]='.';
     for(i=0;i<2;i++){
       x[r+5][c+15+i]='_';
      }
    x[r+5][c+17]='(';
    x[r+5][c+19]='`';
    x[r+5][c+20]='-';
    x[r+5][c+21]=39;
    x[r+5][c+23]=')';
    x[r+6][c+13]='/';
    x[r+6][c+15]='!';
    x[r+6][c+18]='`';
     for(i=0;i<3;i++){
       x[r+6][c+19+i]='-';
      }
    x[r+6][c+22]=39;
    x[r+6][c+24]=92;
    x[r+6][c+25]='_';
    x[r+7][c+12]='/';
    x[r+7][c+15]=92;
    x[r+7][c+26]=39;
    x[r+7][c+27]=92;
    x[r+8][c+11]='!';
    x[r+8][c+15]='/';
    x[r+8][c+16]=92;
    x[r+8][c+25]='!';
    x[r+8][c+26]=92;
    x[r+8][c+28]=92;
     for(i=0;i<2;i++){
       x[r+8][c+29+i]='_';
      }
    x[r+8][c+31]='-';
    x[r+8][c+32]='(';
    x[r+9][c+3]='_';
    x[r+9][c+11]='!';
    x[r+9][c+15]='!';
    x[r+9][c+16]='_';
    x[r+9][c+17]=92;
     for(i=0;i<6;i++){
       x[r+9][c+18+i]='_';
      }
    x[r+9][c+24]='/';
    x[r+9][c+27]=92;
     for(i=0;i<4;i++){
       x[r+9][c+28+i]='_';
      }
    x[r+9][c+32]='-';
    x[r+9][c+33]='(';
     for(i=0;i<2;i++){
       x[r+10][c+3+i]=92;
      }
    x[r+10][c+11]=92;
    x[r+10][c+16]=92;
    x[r+10][c+24]='!';
     for(i=0;i<2;i++){
       x[r+10][c+31+i]='/';
      }
     for(i=0;i<2;i++){
       x[r+11][c+4+i]=92;
      }
    x[r+11][c+12]=92;
     for(i=0;i<3;i++){
       x[r+11][c+13+i]='_';
      }
    x[r+11][c+16]='/';
    x[r+11][c+20]=')';
    x[r+11][c+23]='/';
     for(i=0;i<2;i++){
       x[r+11][c+30+i]='/';
      }
     for(i=0;i<2;i++){
       x[r+12][c+7+i]=92;
      }
     for(i=0;i<22;i++){
       x[r+12][c+9+i]='=';
      }
     for(i=0;i<2;i++){
       x[r+12][c+31+i]='/';
      }
    
}
int main() {
    
    setNonCanonicalMode();


    char move2 = 'y';
    while(move2=='y'){
        
        int i;
        wchar_t x[222][1190];
        int isFalling=0;
        int startoOfScreen=0;
        int endOfScreen=238;
        int startoOfScreen2 = 74;
        int endOfScreen2    = 148;
        int ctBullets=0;
        Bullet * bullet = NULL;
        int flagDraw=0;

        i=0;
        Hero hero = {128 , 143, 20, 41 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,3,0 ,0,0};
        Elevator elevator ={120,112,718,718,0, -1};
        Laser laser ={0,-1,105,143};
        Hero2 hero2={98,118+35*5};
        Bat bat;
        bat.frames=0;
        bat.health=3;
        bat.r=148-60;
        bat.c=120+35*3+160;
        Snail snail[4]={ {204,1000,760,0,5}, {204,1050,770,0,5},{204,1120,780,0,5},{204,1150,790,0,5}};

        bat.frames=0;
        bat.health=3;
        bat.r=148-60;
        bat.c=120+35*3+160;
        bat.rBullet=bat.r+2;
        bat.cBullet=bat.c-3;
        bat.dir=-1;
        hero.jumpFrames=0;
        Enemy enemy;
        enemy.rb=90;
        enemy.cb=640;
        enemy.dir=1;
        enemy.frames=0;
        enemy.health=10;
        char move;
        Enemy enemy2;
        enemy2.rb=66;
        enemy2.cb=640;
        enemy2.dir=1;
        enemy2.frames=0;
        enemy2.health=5;
        int ctFrames =0;
        int ctLoad =0 ;
        int ctBulletFrames=0;
        initializechar(x);
    while(!kbhit()){
        
        initializechar(x);
        if(ctFrames<300){
            HomeScreen(x);
        }
        else if (ctFrames==370){
            ctFrames=0;
        }
        printMapToScreen(x,0, 238, 0, 74);
        ctFrames++;
    }

        usleep(1000000);


    for (;;) {

        move2='a';


        while (!kbhit()) {
            
            initializechar(x);
            drawFixedGround(x);
            drawDoor(x);
            drawPortal(x, hero);
            drawMastabaWithLaser(x);
            for(int j=0; j<4; j++){
                if(snail[j].health!=0){
                    drawSnail(x, snail[j]);
                    if(hero.rherob<222 && hero.rherob>130 && checkNoObstacleForSnale(x, snail[j])){
          
                        moveSnail(x, snail[j]);
                        checkSnail(x, hero, bullet, ctBullets, snail[j]);
                        if(hero.cheroe>=snail[j].cb-5 ||( hero.rheroe < snail[j].rb-5 && hero.cheroe>=snail[j].cb-5 && hero.cheroe<=snail[j].cb+15)){
                            hero.health--;
                            hero.cherob-=10;
                            hero.cheroe-=10;
                           
                        }
                    }
                   
                   
                }
            }

            
            
            if(enemy.health!=0){
                
                if(enemy.dir==-1){
                    drawEnemyLft(x, enemy);
                }
                if(enemy.dir==1){
                    drawEnemyRight(x, enemy);
                }
             
                    
                        checkEnemyDie(x, hero, bullet, ctBullets,  endOfScreen, enemy);
                        
                        moveEnemy(x, enemy);
                        enemy.frames++;
                    
                    
                    
                    
                    
                    if(enemy.rb>=hero.rherob-17 &&enemy.rb<=hero.rheroe+7 &&  enemy.cb>=hero.cherob-10 &&enemy.cb<=hero.cheroe+5){
                        enemy.dir*=-1;
                        enemy.cb+=enemy.dir;
                        
                        hero.health--;
                        hero.cherob-=20;
                        hero.cheroe-=20;
                        if(enemy.frames==690000+250){
                            enemy.frames=0;
                        }
                        
                        
                    
                    enemy.frames++;
                }
            }
            if(enemy2.health!=0){
                
                if(enemy2.dir==-1){
                    drawEnemyLft(x, enemy2);
                }
                if(enemy2.dir==1){
                    drawEnemyRight(x, enemy2);
                }
             
                    
                        checkEnemyDie(x, hero, bullet, ctBullets,  endOfScreen, enemy2);


                        
                        moveEnemy(x, enemy2);
                        enemy2.frames++;
                    
                    
                    
                    
                    
                    if(enemy2.rb>=hero.rherob-17 &&enemy2.rb<=hero.rheroe+7 &&  enemy2.cb>=hero.cherob-10 &&enemy2.cb<=hero.cheroe+5){
                        enemy2.dir*=-1;
                        enemy2.cb+=enemy2.dir;
                        
                        hero.health--;
                        hero.cherob-=20;
                        hero.cheroe-=20;
                        if(enemy2.frames==690000+250){
                            enemy2.frames=0;
                        }
                        
                        
                    
                    enemy2.frames++;
                }
            }
            if(bat.health==0){
                drawMastabaHidden(x);
                drawPortal2(x, hero);
            }
            
            
            drawMastabaWithLadder(x);
            drawBlocker(x);

            
            drawLaser(x, laser);
            drawElevatorStand(x, elevator);
            moveElevator(x, elevator, hero);
            drawElevator(x, elevator);
            if(bat.health!=0){
                if(bat.frames<690000){
                    drawBat(x, bat);
                    moveBat(x, bat);
                    if(hero.inAirplane){
                        drawBulletBat(x, bat);
                        
                    }
               
                    if(bat.rBullet>=hero2.r-17 &&bat.rBullet<=hero2.r+7 && hero.inAirplane && bat.cBullet>=hero2.c-10 &&bat.cBullet<=hero2.c+34){
                    hero.inAirplane=0;
                    hero.rherob=128;
                    hero.rheroe=143;
                    hero.cherob=20;
                    hero.cheroe=41;
                    hero.health--;
                    bat.rBullet=bat.r+2;
                    bat.cBullet=bat.c-3;
                        }
                    if(hero.inAirplane && bat.frames%5==0){
                        moveBulletBat(x, bat);
                    }
                    
                    
                checkBatDie(x, hero, bullet, ctBullets, endOfScreen, bat);
                }
                 
           
            
                if(bat.frames==690000+250){
                    bat.frames=0;
                }
                bat.frames++;
                if(bat.rBullet<=hero.rherob-1 &&bat.rBullet+1>=hero.rheroe && bat.cBullet>=hero.cherob-2 &&bat.cBullet<=hero.cheroe+2){
                    hero.health--;

                }
                
                
             
                
                     
               
            

                }
           
                
            
          
            
         
           
            if(hero.flagGump!=1 && hero.flagGumpRight!=1 && hero.flagGumpLft!=1 ){
                if(hero.flagShooting && hero.inAirplane==0){
                    mainShooting(x, hero);
                    gunWithSmoke(x, hero);
                    
                }
                
                else{
                    if(hero.isWalking){
                        if(hero.dir==1)
                        walkingMain(x, hero);
                        if(hero.dir==-1)
                        walkingMainInRev(x, hero);
                        
                        
                    }
                    else{
                        if(hero.cherob>=120+35*4 &&hero.cherob<=120+35*7 &&hero.rherob>70 &&hero.rheroe<=120 ){
                            hero.inAirplane=1;
                            
                            drawHero2(x, hero2);
                            
                        }
                        else{
                            if(hero.dir==1)
                            drawHero(x, hero);
                            else
                                if(hero.dir==-1)
                                drawHeroInRev(x, hero);
                            drawPlane(x, hero);
                            
                        }
                        
                    }
                    
                }
                
            }
       
            if(ctBullets){

                moveBullet(x, hero, bullet, ctBullets, endOfScreen, bat);
                if(hero.ctLostBullets>=ctBullets){
                    hero.flagShooting=0;
                    hero.ctLostBullets=0;
                    ctBullets=0;
                 
                }
            }
            
            if(ctBulletFrames>0){
                ctBulletFrames++;
            }
            
        
            
            jumpHero(x, hero, isFalling);
            jumpHeroRight(x, hero, isFalling);
            jumpHeroLft(x, hero, isFalling);
            if(hero.flagGump==1 || hero.flagGumpRight==1 || hero.flagGumpLft==1){

                drawHeroJump(x, hero);
            }
           
            isScrollingLftToRight(x, startoOfScreen, hero.cherob, endOfScreen);
            isScrollingBtmTop(x, startoOfScreen2, hero.rherob, endOfScreen2);
            drawHealthBar(x, hero,startoOfScreen, startoOfScreen2, bat, enemy,enemy2);
  
            drawBulletBar(x, startoOfScreen, startoOfScreen2, ctBullets, ctBulletFrames, ctLoad);

            for(int j=0; j<4;j++){
                drawHealthBar(x, hero,startoOfScreen, startoOfScreen2,snail[j]);
            }




            printMapToScreen(x,startoOfScreen,endOfScreen,startoOfScreen2,endOfScreen2);
            usleep(100);
            
            
            
            if(hero.health==0){
                break;
            }
        }
        if(hero.health==0){
            break;
        }
        
        if(playerArrived(hero) && checkAllMobsDead(hero, bat, enemy, enemy2, snail, 4)){
            break;
        }

         move = getchar ();
        
        if(move=='z' && ctBulletFrames<4){
            if(ctBullets>3){
                ctBulletFrames++;
                ctBullets=3;
            }
            
            
            
            Bullet *newBullet = new Bullet[ctBullets+1];
            for (int i = 0; i < ctBullets; i++) {
                    newBullet [i] = bullet[i];
                }
                delete[] bullet;
                bullet = newBullet;
                hero.flagShooting=1;
            
           
                bullet[ctBullets].dir=hero.dir;
                bullet[ctBullets].stopBullet=0;
            if(hero.inAirplane==0){
                bullet[ctBullets].cBullet=hero.cherob+27;
                bullet[ctBullets].rBullet=hero.rherob+8;
            }
            if(hero.inAirplane==1){
                bullet[ctBullets].cBullet=hero2.c+34;
                bullet[ctBullets].rBullet=hero2.r+9;
            }
            
                ctBullets++;
        
        }
        
        else if (ctBulletFrames>450){
            ctBulletFrames=0;
            
        }
        else{
            hero.flagShooting=0;

        }
        
        
        
        if(hero.inAirplane==0){
            moveHero(x, hero, move, isFalling, elevator);

        }
       
        if(hero.inAirplane==1){
            if(move=='m'){
                hero.inAirplane=0;
                hero.cherob=120+35*3;
                hero.cheroe=120+35*3+16;
            }
            else{
                if(move=='t' &&hero2.r>=startoOfScreen2+15 ){
                
                    hero2.r-=2;
                }
                if(move=='g'&& hero2.r<=startoOfScreen2+50){
                
                    hero2.r+=2;
                }
            }
            
        }
        
        if(hero.inLadder==1){
          
                if(move=='t'&& hero.rheroe<150 ){
                
                    hero.rherob-=2;
                    hero.rheroe-=2;
                }
                if(move=='g'&& hero.rheroe<98 ){
                
                    hero.rherob+=2;
                    hero.rheroe+=2;
                }
            }
            
        
        drawHero(x, hero);
     
       
       
    }
    while(move2 != 'y' && move2 != 'n'){
        while (!kbhit()){
            initializechar(x);
            if(ctFrames<300){
                if (hero.health==0)
                GameOVer(x);
               if (hero.health==5)
                congrats(x);
                
                
            }
            else if (ctFrames==370){
                ctFrames=0;
            }
            printMapToScreen(x,0, 238, 0, 74);
            ctFrames++;
        }
        move2 = getchar();
    }
        
    }
restoreTerminalSettings();

    return 0;
}
