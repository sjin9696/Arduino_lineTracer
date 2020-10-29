#ifndef Car_h
#define Car_h

#define Right_Plus  4
#define Right_Minus 5
#define Left_Plus   6
#define Left_Minus  7

#define STOP  000
#define FRONT 111
#define BACK  222
#define RIGHT 333
#define LEFT  444

void CarInit();
void led_setting(int a, int b, int c, int d);
void Right_Stop();
void Left_Stop();
void Right_Front();
void Left_Front();
void Right_Back();
void Left_Back();
void Stop();
void Front();
void Back();
void Left();
void Right();
void Controler(int n_commend);
void Car_loop(String result);
#endif
