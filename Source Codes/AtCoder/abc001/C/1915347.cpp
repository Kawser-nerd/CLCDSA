#include<stdio.h>
double speed_domain[]={
    0.25,1.55,3.35,5.45,7.95,10.75,13.85,17.15,20.75,24.45,28.45,32.65
};
double dir_domain[]={
    11.25,33.75,56.25,78.75,101.25,123.75,146.25,
    168.75,191.25,213.75,236.25,258.75,281.25,303.75,326.25,
    348.75,360
};
char dir_name[][4]={
    "N","NNE","NE","ENE","E","ESE","SE","SSE",
    "S","SSW","SW","WSW","W","WNW","NW","NNW","N"
};
int main(){
    double dir,speed;
    int speed_level;
    int dir_name_index;
    scanf("%lf %lf",&dir,&speed);
    speed/=60;
    dir/=10;
    for (speed_level=0;speed_level<12;speed_level++){
        if (speed<speed_domain[speed_level]){
            break;
        }
    }
    if (speed_level==0){
        printf("C 0\n");
        return 0;
    }
    for (dir_name_index=0;dir_name_index<17;dir_name_index++){
        if (dir<dir_domain[dir_name_index]){
            break;
        }
    }
    printf("%s %d\n",dir_name[dir_name_index],speed_level);
    return 0;
}