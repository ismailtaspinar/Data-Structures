#include<stdio.h>
#include<string.h>

void displayWord(char words[15][15],int num1,int num2,char* query,int opr1,int opr2);
int check;

int main(){

  char words[15][15];
  char query[15];
  char c;
  int i,j,k;
  
  for(i=0;i<15;i++){
     for(j=0;j<15;j++){
         scanf("%c ",&words[i][j]);
     }
  }
  i=0;
  
  while(c!=' ' && c!='\n'){
     scanf("%c",&c);
     query[i++]=c;
  }
  query[i-1]='\0';
 
  k=1;
  int p=0,r=0;
  
     for(i=0;i<15;i++){
        for(j=0;j<15;j++){
           if(query[0]==words[i][j]){
               if(query[1]==words[i-1][j-1]){
                    displayWord(words,i,j,query,-1,-1);
                }
               if(query[1]==words[i-1][j]){
                    displayWord(words,i,j,query,-1,0);
                }
               if(query[1]==words[i-1][j+1]){
                    displayWord(words,i,j,query,-1,1);
                }
               if(query[1]==words[i][j-1]){
                    displayWord(words,i,j,query,0,-1);
                }
               if(query[1]==words[i][j+1]){
                    displayWord(words,i,j,query,0,1);
                }
               if(query[1]==words[i+1][j-1]){
                    displayWord(words,i,j,query,1,-1);
                }
               if(query[1]==words[i+1][j]){
                    displayWord(words,i,j,query,1,0);
                }
               if(query[1]==words[i+1][j+1]){
                    displayWord(words,i,j,query,1,1);
                }  
           }
           if(check){
               break;
           }
        }
        if(check){
           break;
        }
    }
   
    if(!check){
         for(i=0;i<15;i++){
           for(j=0;j<15;j++){
               printf("*");
           }
           printf("\n");
         }
    }
  return 0;
}
void displayWord(char words[15][15],int num1,int num2,char* query,int opr1,int opr2){
 
  int display[15][2];
  int k=0,p=0;
  check=1;
  int i,j;
  int q=0,r=0;
  int print[15][15];
 
  while(query[k]!='\0'){
     if(words[num1+q][num2+r]==query[k]){
          display[p][0]=num1+q;
          display[p++][1]=num2+r;
          k++;
          q+=opr1;
          r+=opr2;
     }
     else{
         check=0;
         break;
     }
  }
     
  if(check){
      for(i=0;i<15;i++){
           for(j=0;j<15;j++){
               print[i][j]='*';
           }
      }
      for(i=0;i<strlen(query);i++){
           print[display[i][0]][display[i][1]]=words[display[i][0]][display[i][1]];
      }
      for(i=0;i<15;i++){
           for(j=0;j<15;j++){
                printf("%c",print[i][j]); 
            }
            printf("\n");
       }
   }
}
