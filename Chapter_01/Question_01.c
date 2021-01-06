#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int HornerSplit(char *s){
    int power=0;
    for(int i=0;s[i]!='\0'&&s[i]!='\n';i++){
       if(s[i]!='^')continue;
       else{
           for(int j=i+1;s[j]!='+';j++){
               power = power*10+(s[j]-'0');
           }
           break;
       }
    }
    return power;
}
int Horner(char *s,int x){
    int size=1;
    int *C_arr;
    int power = HornerSplit(s);
    for(int i=0;s[i]!='\0'&&s[i]!='\n';i++){
        if(s[i]=='x'||s[i]=='X')size++;
    }
    C_arr = malloc(sizeof(size));
    for(int i=0,j=0,cross=0,C=0;s[i]!='\n'&&s[i]!='\0'&&j<size;i++){
        if(s[i]=='x'||s[i]=='X')cross=1;
        else if(s[i-1]=='+')cross=0;
        
        if(cross==0){
            C = C*10+(s[i]-'0');
        }else{
            if(s[i]!='x'&&s[i]!='X')continue;
            C_arr[j] = C==0?1:C;
            C=0;
            j++;
        }
        if(s[i+1]=='\n'||s[i+1]=='\0'){
            C_arr[j] = C;
            break;
        }
    }
    int result =C_arr[0]*x+C_arr[1];
    for(int i=2;i<size;i++){
        result = result*x+C_arr[i];
    }
    free(C_arr);
    C_arr=NULL;
    return result;
}
int n_sqrt(int n,int current_row,int current_col,int reverse,int dob){
    if(current_row==n)return dob==0?n_sqrt(n,0,0,0,dob+1):0;
    if(reverse==0){
        dob==0?printf("false "):printf("true ");
    }else{
        dob==0?printf("true "):printf("false ");
    }
    if((current_col+1)==n){
        printf("\n");
        return n_sqrt(n,current_row+1,0,((current_row%2)&1)==0?0:1,dob);
    }else{
        return n_sqrt(n,current_row,current_col+1,((current_row%2)&1)==0?(current_col<(current_row/2))?0:1:(current_col<(current_row/2))?1:0,dob);
    }
    return 0;
}
/**
 * 遞增印出順序，相較於對照組(nsort_match)
 * 全使用邏輯比對的方式
 * 在macbook pro 2020環境下平均節省約1%~3%的cpu使用量
*/
int n_sort(int x,int y,int z){ 
    int r[3] = {y,y,y};
    if((((x%y)&(x%z))-x)){
        if((y%z)-y){
            r[0]=z;
            if(((y%x)-y))r[1]=x;
            else r[2]=x;
        }else{
            r[1] = ((x%z)-x)?z:x;
            r[2] = (r[1]-x)?x:z;
        }
    }else{
        r[0]=x;
        r[1]=((y%z)-y)?z:y;
        r[2]=(r[1]-y)?y:z;
    }
    printf("%d %d %d\n",r[0],r[1],r[2]);
    return 0;
}
int nsort_match(int x,int y,int z){
    if(x<y&&x<z){
        if(y<z)printf("%d %d %d\n",x,y,z);
        else printf("%d %d %d\n",x,z,y); 
    }else if(y<x&&y<z){
        if(x<z)printf("%d %d %d\n",y,x,z);
        else printf("%d %d %d\n",y,z,x);
    }else{
        if(y<x)printf("%d %d %d\n",z,y,x);
        else printf("%d %d %d\n",z,x,y);
    }
    return 0;
}
int main(){
    //printf("%d",Horner("4x^3+2x^2+X^1+2",5));//Horner法則(只使用加)
    // n_sqrt(2,0,0,0,0);
    // n_sort(34,63,1);
    // nsort_match(34,63,1);
    return 0;
}