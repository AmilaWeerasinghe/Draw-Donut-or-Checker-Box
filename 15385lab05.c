
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET		0
#define BRIGHT 		1

#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

void textcolor (int attr, int fg, int bg);

void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */

	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in
	black in white background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}
void checker(char **w){
int a,i;
int p=-1,q=-1;//assign two variables p q with minus values
char *colours[]={"black","red","green","yellow","blue","magenta","cyan","white"}; //create an array with colours given in the list 
for(i=0;i<=7;i++){
if(strcmp(colours[i],w[2])==0){p=i;}//Compare each element in the array created with the given colour list,assign the number to a variable 

if(strcmp(colours[i],w[3])==0){q=i;}//Compare each element in the array created with the given colour list,assign the number to a variable
}
if(p<0){printf("Background color is not available\n");}// use if the variables p q stays minus then print the errors
if(q<0){printf("Foreground color is not available\n");}
else if(p>=0 && q>=0) {
        int b, c, d, e;
/* Use two loops to  print the colours. Here the color in the background is given to the spaces.space is contain of size eight */
        for(c=1; c<5; c=c+1){
        for(b=1; b<8; b=b+1){
        for(a=1; a<5; a=a+1){
        textcolor(BRIGHT, RED, q);
        printf("        ");
         textcolor(BRIGHT, GREEN,p);
        printf("        ");
        }
        printf("\n");
        }
        for(e=1; e<8; e=e+1){
        for(d=1; d<5; d=d+1){
        textcolor(BRIGHT, GREEN,p);
        printf("        ");
         textcolor(BRIGHT, RED,q);
        printf("        ");
        }
        printf("\n");
        }
        }
}
}
void donut(char **g){
int d,x,y,j,k,l;
int s=-1,t=-1;//assign s t to minus values
float r,c;// take these values as float so it can store decimal numbers too
char *colours[]={"black","red","green","yellow","blue","magenta","cyan","white"};//string array with given colours in the list
for(j=1;j<=7;j++){
if ((strcmp(colours[j],g[2]))==0){s=j;}////Compare each element in the array created with the given colour list,assign the number to a variable
if ((strcmp(colours[j],g[3]))==0){t=j;}
}
if(s<0){printf("Background color is not available\n");}// use if the variables p q stays minus then print the errors

if(t<0){printf("Foreground color is not available\n");}
else if(s>=0 && t>=0) {
scanf("%d",&d);
r=d/2;
c=r/2;
int n=d;
for(k=0; k<=n;k++){
for(l=0; l<=n;l++){
/*Print a box with the given diameter as the length of the side*/
x=k-r;//take distance from the centroid to the place where the box is printing
y=l-r;
if((x*x+y*y > r*r+1)||(x*x+y*y<c*c)){
/*if the distance is greater than radius or the distance is less than half of the radius then print a colour*/
textcolor(BRIGHT, GREEN,s);
printf(" ");}
else{textcolor(BRIGHT, GREEN,t);//else print another colour
 printf(" ");}}
printf("\n");}
}

}
int main(int argc, char **argv){

if (strcmp(argv[1],"checker")==0){
/*check first argument is checker and run the checker function*/
checker(argv);
}


if ((strcmp(argv[1],"donut"))==0){
/*check first argument is donut and run the donut function*/
donut(argv);
 }

	textcolor(RESET, WHITE, BLACK);	
	return 0;

}
