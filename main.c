#include "project.h"
#define BLACK 0x0000

//JUst reference for pi fram buffer.
int main(){
    
       
   
    openFrameBuffer();
    open_gyro();
    openJoystick();
    
    configure_gyro();

    float p0,p;
    int ang_disp;
    check_gyro(); 
    while(get_step()<3){
        checkJoystick();
      // check_gyro();      //Breakdown switch ...rg note
       printf("%d",get_p());
       printf("\nThe step = %d\n",get_step());
       if(get_step()==0){
           //checkJoystick();
           //check_gyro();
           printf("\nEntering the first if\n");
           display_grid(get_step());

           
        } 
       else if(get_step() == 1){
            //check_gyro();
            //checkJoystick();
            printf("\nEntering else if main\n"); 
            p0 = get_p0();
            printf("step 1 %f\n",p0);          //CHeck first angle
            display_grid(get_step());
        }
       else if(get_step()==2){
           //check_gyro();
           //checkJoystick();
           printf("\nEntering else else if\n");
           p = get_p();
           printf("step2 : %f",p);
           display_grid(get_step());
        }
    }
        
    sleep(3);
    clearDisplay();
    closeFrameBuffer();
    close_gyro();
    closeJoystick();
    
}

   

    
     

    



