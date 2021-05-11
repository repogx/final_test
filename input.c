#include "project.h"


//Prototype for callback function to control program step.
void JoyStepper(unsigned int);


// All the methods down here
pi_i2c_t* device = NULL;
coordinate_t data;

// Step var to represent segment of program running:

int step =0;   //Number of times the user has pressed Enter

//variables for gyro's euler angles
float a,b,c,phi;
//initiate var(s) to hold angular position corresponding to user 'enter'.

float p0,p;
float ang_disp;

/*
 * Section 1 : Joystick
 *--------------------------
 */

// Global switch var for joystick.
pi_joystick_t* joystick =NULL;



// Open joystick if closed.
void openJoystick(void){
    if(joystick == NULL){
        joystick = getJoystickDevice();
    }
}

// Close joystick if open.
void closeJoystick(void){
    if(joystick == NULL){
        fprintf(stderr,"Attempting to close a joystick that has not been allocated");
        return;

    }
    else{
        freeJoystick(joystick);
    }
}


// Sample joystick input over a period:
int delay = 1000;

void checkJoystick(){
    //printf("Entering checkJoystick");
    //fprintf(stderr,"\nEntering poll joystick with %d code and %delay",callback,delay);
    pollJoystick(joystick,JoyStepper,delay);
}



//Joystick's callback function:


// Joystick Callback Function:
void JoyStepper(unsigned int code){
    printf("\nReceived code %d\n",code);
    if(code == KEY_ENTER){
        if(get_step()==0){
            check_gyro();
            printf("\nIncrementing step0\n");
            p0 =c;
            printf("%f",p0);   //Set the initial user angle
            step++;             // Increment to next step
        }
        else if(get_step()==1){
            check_gyro();
            printf("\nIncrementing step1\n");
            p =data.z;       // Set second user angle
            step++;
        }
        else if(get_step()==2){
            printf("\nIncrementing step2\n");
            ang_disp = p-p0;
            step++;
       }    
      // printf("\nIncrementing step\n");    
    }
}


 

/*
 * Section 2 : Gyroscope
 ----------------------------------------------------------------
*/

void open_gyro(){
    //int cnt=0;
 
    device=geti2cDevice();

    if (device){
        configureAccelGyro(device);

        /*
        printf("Please leave the Pi flat on the table for calibration\n");
        while(run && getGyroPosition(device,&data) && data.x!=0.0) {
            usleep(100);
        }
        printf("You may pick up the pi.\n");
        while (run && getGyroPosition(device,&data)){
            if (cnt==109){ //sample rate, display once per second
                cnt=0;
                printf("Gyro: %f %f %f\n",data.x,data.y,data.z);
            }
            cnt++;
        }
        */
        //printf("\nExiting...\n");
        //freei2cDevice(device);
    }
}

void close_gyro(){
    if(device == NULL){
        fprintf(stderr,"Attemtping to close an null object");
        return;
    }
    else{
        freei2cDevice(device);
    }
}

void configure_gyro(){
    int count = 0;
    while(getGyroPosition(device,&data) && data.x != 0.0){
        usleep(100);
    }
}

pi_i2c_t* get_device(){
    return device;
}

coordinate_t get_data(){
    return data;
}

void check_gyro(){
    printf("\nEntering check gyro");
    int cnt = 0;
    int times = 0;
    while(1 && getGyroPosition(device,&data)){
        if(cnt == 109){
          
            printf("\na = %f, b = %f,c = %f\n",data.x,data.y,data.z);
            cnt = 0;
            a = data.x;
            b = data.y;
            c = data.z;
        }
        cnt++;
    }
  
} 


//Define a set of functions to return the parameters containing each necessary value.

float get_phi(){
    
    return phi;
}

int get_step(){
    //printf("\nEntering getstep\n");
    return step;
}


float get_p0(){
    
    return p0;
}
float get_p(){
    
    return p;
}
int get_ang_disp(){
    
    return (int)ang_disp;
}







