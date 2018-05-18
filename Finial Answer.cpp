/*  
                      .     Fig. 1
                      |\
                      | \
                      |  \
                      |   \
                      |    \
                     A|     \ C
                      |      \
                      |       \
                      |        \
                      |         \
                    __|__________\_______________________
                          B

*/
#include <iostream>
#include <cmath>
using namespace std;
// recursive function for finding position and velocity
void MyAns(double x_initial,double y_initial,double Vx_initial,double Vy_initial,int n){
    /*
    after on collision
    position if particle is (x_finial,y_finial)
    velocity of particle is (Vx_finial,Vy_finial)
    */
    double x_finial,y_finial,l=((4-x_initial)*3)/double(5);
	double Vx_finial,Vy_finial;
	double V=(Vy_initial*4+Vx_initial*3)/double(5);
	
        if(Vx_initial<0&&Vy_initial>=0&&V>=0){
            if(x_initial/abs(Vx_initial)>l/(V)){
                //when particle collide with side C
                Vx_finial=-(Vx_initial*24+Vy_initial*7)/double(25);
                Vy_finial=-(Vy_initial*24+Vx_initial*7)/double(25);
                x_finial=x_initial+Vx_initial*(l/V);
                y_finial=y_initial+Vy_initial*(l/V);
            }
            else{
                //when particle collide with side A
                Vx_finial=-Vx_initial;
                Vy_finial= Vy_initial;
                y_finial=y_initial+x_initial*(Vy_initial/Vx_finial);
                x_finial=0;
            }
        }
        else if(Vx_initial>=0&&Vy_initial<0&&V>=0){
            if(y_initial/abs(Vy_initial)>l/(V)){
                //when particle collide with side C
                Vx_finial=-(Vx_initial*24+Vy_initial*7)/double(25);
                Vy_finial=-(Vy_initial*24+Vx_initial*7)/double(25);
                x_finial=x_initial+Vx_initial*(l/V);
                y_finial=y_initial+Vy_initial*(l/V);
            }
            else{
                //when particle collide with side B
                Vx_finial= Vx_initial;
                Vy_finial=-Vy_initial;
                x_finial= x_initial+y_initial*(Vx_initial/Vy_finial);
                y_finial=0;
            }
        }
        else if(Vx_initial<0&&Vy_initial<0){
            if((x_initial/abs(Vx_initial))>(y_initial/abs(Vy_initial))){
                //when particle collide with side B
                Vx_finial= Vx_initial;
                Vy_finial=-Vy_initial;
                x_finial= x_initial+y_initial*(Vx_initial/Vy_finial);
                y_finial=0;
            }
            else{
                //when particle collide with side A
                Vx_finial=-Vx_initial;
                Vy_finial= Vy_initial;
                y_finial=y_initial+x_initial*(Vy_initial/Vx_finial);
                x_finial=0;
            }
        }
        else if(Vx_initial>=0&&Vy_initial>=0){
            //when particle collide with side C
            Vx_finial=-(Vx_initial*24+Vy_initial*7)/double(25);
            Vy_finial=-(Vy_initial*24+Vx_initial*7)/double(25);
            x_finial=x_initial+Vx_initial*(l/V);
            y_finial=y_initial+Vy_initial*(l/V);
        }
        else if(Vx_initial<0&&Vy_initial>=0&&V<0){
            //when particle collide with side B
            Vx_finial=-Vx_initial;
            Vy_finial= Vy_initial;
            y_finial=y_initial+x_initial*(Vy_initial/Vx_finial);
            x_finial=0;
        }
        else if(Vx_initial>=0&&Vy_initial<0&&V<0){
            //when particle collide with side A
            Vx_finial= Vx_initial;
            Vy_finial=-Vy_initial;
            x_finial= x_initial+y_initial*(Vx_initial/Vy_finial);
            y_finial=0;
        }
        if(n==1){
            // if one collision left recursive function will end
            cout<<"Position of particle => ("<<x_finial<<","<<y_finial<<")\n";
            cout<<"Velocity of particle => ("<<Vx_finial<<","<<Vy_finial<<")";
        }
        else{
         MyAns(x_finial,y_finial,Vx_finial,Vy_finial,n-1);
        }
}
int main() {
	// your code goes here
	/*
	Here
	x_initial=initial X coordinate
	y_initial=initial Y coordinate
	Vx_initial=initial velocity in X direction
	Vy_initial=initial velocity in Y direction
	n= number of collisions
	*/
	double x_initial,y_initial;
	double Vx_initial,Vy_initial;
	int n;
	cin>>x_initial>>y_initial>>Vx_initial>>Vy_initial;
	cin>>n;
	MyAns(x_initial,y_initial,Vx_initial,Vy_initial,n);
	return 0;
}