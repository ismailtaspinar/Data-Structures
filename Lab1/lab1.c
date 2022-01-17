#include<stdio.h>
#define MAX 1000
int* functionFindMin(int* array, int row, int cols, char source, char destination);

int main() {

     
   int array[10][10],row,cols;
   int i,j;
   char source,destination;
   int* result;
   for(i=0;i<10;i++){             

      for(j=0;j<10;j++){

           scanf("%d",&array[i][j]); 
             
                       }   
                   }
                     
   scanf("\n%c ",&source);
   scanf("%c",&destination);
  
   result=functionFindMin(array[0],10,10,source,destination);
   
   i=0;

   while(1){

          if(result[i]==0 && result[i+1]==0){

                printf("You cannot travel between two cities\n");
                break;
                                            }
                                            

          if(result[i]>9){

                printf(" %d\n",result[i]);
                break;
                         }
                                      
          if(result[i+1]>9){
               
                printf("%c",result[i++]+65);
                continue;
                           }
          printf("%c-",result[i++]+65);
      }

    return 0;
 }

int* functionFindMin(int* array, int row, int cols, char source, char destination){

     int i,j,k=0,l=0;
     int smallest=0;
     int results[MAX][MAX];
     int paths[MAX][2];
     int m=0,n=0;
     int temp[MAX][MAX];
     int p=0,r=0;

    
      for(i=0;i<row;i++){
           for(j=0;j<cols;j++){

                if(*((array+i*10)+j)>0){  //pairs of possible ways to go.

                      paths[k][0]=i;
                      paths[k++][1]=j;

                                       }
                                } 
                          }   
      i=0;
      while(paths[i][0]!=0 || paths[i][1]!=0 ){

           if(paths[i][0]==source-65 && paths[i][1]==destination-65){

                  results[m][n++]=paths[i][0];
                  results[m++][n++]=paths[i][1];
                                                                    }
           i++;
                                              }

      n=0;

      for(i=0;i<k;i++){

          if(paths[i][0]==source-65){
                
               for(j=0;j<k;j++){

                   if(paths[j][0]==paths[i][1]){
                        r=0;
                        
                        temp[p][r++]=paths[i][0];
                        temp[p][r++]=paths[i][1];
                        temp[p++][r++]=paths[j][1];
                      
                                               }
                               }
            
                                    }

                      }
     
      for(i=0;i<p;i++){

          if(temp[i][r-1]==destination-65){
                
                for(j=0;j<r;j++){
                       results[m][n++]=temp[i][j];
                                }
               temp[i][r]=-1;
               m++;
               n=0;
                                          }

          for(j=0;j<r-1;j++){
               
               if(temp[i][j]==destination-65){
                      temp[i][r]=-1; 
                                             }
                            }
                       }
     int limit;
     int x,y=0;
     int check;
     
      while(1){
           
         limit=p;
         check=1;

         for(i=0;i<limit;i++){
        
            if(temp[i][r]==-1){continue;}

              for(j=0;j<k;j++){

                  if(temp[i][r-1]==paths[j][0]){
                       check=0;

                       for(x=0;x<r;x++){

                            temp[p][x]=temp[i][x];
                            
                              }

                       temp[p][r]=paths[j][1];
                       temp[i][r]=-1;
                       p++;
                                               }
                   
                             }

                             }
         
          for(i=0;i<p;i++){

               for(j=0;j<r;j++){

                    for(x=j+1;x<r+1;x++){
 
                         if(temp[i][j]==temp[i][x]){

                               temp[i][r]=-1;
                                                   }
                           
                                         }
                               }
             
                            }
         
          n=0;
 
          for(i=0;i<p;i++){

                if(temp[i][r-1]==destination-65){
                
                     for(j=0;j<r;j++){
                          results[m][n++]=temp[i][j];
                                     }
               temp[i][r]=-1;
               m++;
               n=0;
                                                 }

                         }
         
         if(check){break;}
         r++;

           }

    int sum=0,place;

    for(x=0;x<m;x++){
      
      for(y=0;y<r-1;y++){
         
          sum+=*((array+results[x][y]*10)+results[x][y+1]); 
          
          if(results[x][y+1]==destination-65){

                results[x][y+2]=sum;
                
                if(smallest==0){
                     smallest=sum;
                     place=x;
                }

                if(smallest>sum){
                    smallest=sum;
                    place=x;
                                }
                sum=0;
                break;

            }
         }
       }

    int* shortestpath;

    shortestpath=results[place];

    return shortestpath;

      
}
