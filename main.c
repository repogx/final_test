#include "project.h"
#define BLACK 0x0000

//JUst reference for pi fram buffer.
int main(){
    
       
   
    openFrameBuffer();
    open_gyro();
    openJoystick();
    
    configure_gyro();
    
    printf("\nInitialzing devices\n");

    coordinate_t data = get_data();

    pi_i2c_t * gyro = get_device();

    int theStep = 0;

    int cnt = 0;
    
    printf("\nBefore while\n");

    while(1){
       printf("\nEntering while\n");
       getGyroPosition(gyro,&data); 
       while(1){
        if(cnt == 109){
            printf("a = %f b = %f c = %f",data.x,data.y,data.z);
            cnt = 0;
            break;
        }
        cnt++;
       }
            

       if(theStep==0){

        } 

       else if(get_step() == 1){

        }
       else if(get_step()==2){

        }
    }
        
    sleep(3);
    clearDisplay();
    closeFrameBuffer();
    close_gyro();
    closeJoystick();
    
}

   

    
     

    



