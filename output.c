#include "project.h"




/*
 *
 * Section 1 : Framebuffer
 *
 *
 */

// All methods opening and closing framebuffer here
#define BLUE 0x1F
#define BLACK 0x0000
#define WHITE 0xFFFF
#define RED 0xF800
#define GREEN 0x0FF0

//prototype 
void display_grid();

pi_framebuffer_t *fb = NULL;


void openFrameBuffer(){
    if(fb == NULL){
        fb = getFrameBuffer();
    }
}


void closeFrameBuffer(){
    if(fb == NULL){
        fprintf(stderr,"Trying to close an empty framebuffer");
        return;
    }
    freeFrameBuffer(fb);
    fb = NULL;
}

void clearDisplay(){
    clearFrameBuffer(fb,BLACK);
}

int ang_disp;
//display the grids for each step of program.

void display_grid(int step){
   
    ang_disp = get_ang_disp();

   clearFrameBuffer(fb,BLACK);

   sense_fb_bitmap_t *bm = fb->bitmap;
   
   if(step==0){
       //bm grid for step0
       bm->pixel[3][2]=RED;bm->pixel[4][2]=RED;
       bm->pixel[3][3]=RED;bm->pixel[4][3]=RED;
       bm->pixel[3][4]=RED;bm->pixel[4][4]=RED;
       bm->pixel[3][5]=RED;bm->pixel[4][5]=RED;
       bm->pixel[2][5]=RED;bm->pixel[5][5]=RED;
       bm->pixel[3][6]=RED;bm->pixel[4][6]=RED;
       bm->pixel[3][7]=RED;bm->pixel[4][7]=RED;
      
  }
   else if(step ==1){
       //Initial display: Orientation guide for user.

       bm->pixel[3][2]=GREEN;bm->pixel[4][2]=GREEN;
       bm->pixel[3][3]=GREEN;bm->pixel[4][3]=GREEN;
       bm->pixel[3][4]=GREEN;bm->pixel[4][4]=GREEN;
       bm->pixel[3][5]=GREEN;bm->pixel[4][5]=GREEN;
       bm->pixel[2][5]=GREEN;bm->pixel[5][5]=GREEN;
       bm->pixel[3][6]=GREEN;bm->pixel[4][6]=GREEN;
       bm->pixel[3][7]=GREEN;bm->pixel[4][7]=GREEN;
   }
   else if(step==2){
       display_diff();
   }

        
      
} 


//Function to convert int base ten angular dixplacement into a binary base two value.

void display_diff(){
    clearFrameBuffer(fb,BLACK);
    sense_fb_bitmap_t *bm = fb->bitmap;
    int *the_diff = int2binary(ang_disp);
    int j = 0;
    for(int i = 32; i >= 0; i--){
        if(j == 8){
            break;
        }
        if(the_diff[i] = 1){
            bm->pixel[j][0] = BLUE;
            bm->pixel[j][1] = BLUE;
            j++;
        }
        else{
            bm->pixel[j][0] = WHITE;
            bm->pixel[j][1] = WHITE;
            j++;
        }
    }
    
}


int * int2binary(int number){         
    int c, k; 
    int *binary_storage = (int *)malloc(sizeof(int)*32);                                                                
    int i = 0;       
    for(c = 31; c >= 0; c--){                                                                                                 
        k = number >> c;                                                                                                        
        if(k & 1){                                                                                                               
            binary_storage[i] = 1;                                                                                                  
            i++;                                                                                                                   
        }                                                                                                                       
        else{                                                                                                                   
            binary_storage[i] = 0;                                                                                                  
            i++;                                                                                                                   
        }                                                                                                                    
    }                                                                                                                       
    return binary_storage; 


}

int angle_adj(int d){
    int a =0;
    if(d<0){
        a= -1*d;
        while(a>=360){
            a = a-360;
        }
        if(a>180){
            a =360-a;
            return a;
        }
        else if(a<=180){
            return a;
        }
    }
    if(d>0){
        a = d;
        while(a>=360){
            a = a -360;
        }
        if(a>180){
            a = 360-a;
            return a;
        }
        else if(a<=180){
            return a;
        }
    }
    
}
