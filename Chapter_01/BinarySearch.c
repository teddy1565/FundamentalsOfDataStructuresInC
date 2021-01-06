#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define COMPARE(x,y)((x)<(y))? -1 : ((x)==(y)) ? 0 : 1)

int compare(int x,int y){
    if(x<y)return -1;
    else if(x==y) return 0;
    else return 1;
}
int binsearch(int list[],int searchnum,int left,int right){
    int middle;
    while(left<=right){
        middle = (left+right)/2;
        switch(compare(list[middle],searchnum)) {
            case -1:
                left = middle+1;
                break;
            case 0:
                return middle;
            case 1:
                right = middle-1;
                break;
            default:
                break;
        }
    }
    return -1;
}
int main(){
    return 0;
}