
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





int main(int argc, char **argv){
int a,i;
int p=-1,q=-1;
if (strcmp(argv[1],"checker")==0){
char *colours[]={"black","red","green","yellow","blue","magenta","cyan","white"};
for(i=0;i<=7;i++){
if(strcmp(colours[i],argv[2])==0){p=i;}

if(strcmp(colours[i],argv[3])==0){q=i;}
}
if(p<0){printf("Background color is not available\n");}
if(q<0){printf("Foreground color is not available\n");}
else if(p>=0 && q>=0) {
        int b, c, d, e;
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
int d,x,y,j,k,l;
int s=-1,t=-1;
float r,c;
char *colours[]={"black","red","green","yellow","blue","magenta","cyan","white"};

if ((strcmp(argv[1],"donut"))==0){
for(j=1;j<=7;j++){
if ((strcmp(colours[j],argv[2]))==0){s=j;}
if ((strcmp(colours[j],argv[3]))==0){t=j;}
}
if(s<0){printf("Background color is not available\n");}
if(t<0){printf("Foreground color is not available\n");}
else if(s>=0 && t>=0) {
scanf("%d",&d);
r=d/2;
c=r/2;
int n=d;
for(k=0; k<=n;k++){
for(l=0; l<=n;l++){
x=k-r;
y=l-r;
if((x*x+y*y > r*r+1)||(x*x+y*y<c*c)){
textcolor(BRIGHT, GREEN,s);
printf(" ");}
else{textcolor(BRIGHT, GREEN,t);
 printf(" ");}}
printf("\n");}
}}
	textcolor(RESET, WHITE, BLACK);	
	return 0;

}
