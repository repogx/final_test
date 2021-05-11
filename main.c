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

    float p,p0,p1;

    int step1Stopper = 1;
    
    printf("\nBefore while\n");
    
    display_grid(theStep);

    while(1){
       printf("\nEntering while\n");
       getGyroPosition(gyro,&data);
       theStep = get_step(); 
       while(1){
        if(cnt == 109){
            printf("\n gyro while IF\n");
            printf("a = %f b = %f c = %f",data.x,data.y,data.z);
            p0 = data.z;
            cnt = 0;
            break;
        }
        cnt++;
       }
            
       checkJoystick();
       if(theStep==0){
            printf("\n\nSTEP 0 REACHED\n\n");
        } 

       else if(theStep== 1 && step1Stopper){
            display_grid(theStep);
            step1Stopper = 0;
            printf("\n\nSTEP 1 REACHED\n\n");
        }
       else if(theStep==2){
            printf("\n\nSTEP 2 REACHED\n\n");
        }
       else if(theStep == 3){
        printf("\n\nSTEP 3 REACHED\n\n");
       }
      
       printf("\nReached end of while\n");
    }
        
    sleep(3);
    clearDisplay();
    closeFrameBuffer();
    close_gyro();
    closeJoystick();
    
}

   

    
     

    



