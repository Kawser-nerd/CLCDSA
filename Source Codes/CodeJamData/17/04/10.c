#include<stdio.h>

char c_ans[101][101];
char c_orig[101][101];

int diag_row[101];
int  diag_col[101];
int n;
FILE *in,*out;

#define _max 10000000


void initialise(){
    int iter1,iter2;
    for(iter1=1;iter1<=n;iter1++){
    for(iter2=1;iter2<=n;iter2++){
        c_ans[iter1][iter2]='.';
        c_orig[iter1][iter2]='.';
    }
    }
}

void print_c(){
    int iter1,iter2;
    printf("print_orig\n");
    for(iter1=1;iter1<=n;iter1++){
    for(iter2=1;iter2<=n;iter2++){
        printf("%c",c_orig[iter1][iter2]);
    }
    printf("\n");
    }

    printf("print_ans\n");
    for(iter1=1;iter1<=n;iter1++){
    for(iter2=1;iter2<=n;iter2++){
        printf("%c",c_ans[iter1][iter2]);
    }
    printf("\n");
    }
}



void diff(int test,int orig_ans){
    int iter1,iter2,ans,changed;
    ans=0;
    changed=0;
    for(iter1=1;iter1<=n;iter1++){
        for(iter2=1;iter2<=n;iter2++){
            if(c_ans[iter1][iter2] == c_orig[iter1][iter2]){
                continue;
            }
            if(c_orig[iter1][iter2] == '.' && c_ans[iter1][iter2] == 'o'){
                ans = ans+2;
            }
            else{
                ans++;
            }
            changed++;
        }
    }

    printf("Case #%d: %d %d\n",test,ans+orig_ans,changed);
    fprintf(out,"Case #%d: %d %d\n",test,ans+orig_ans,changed);
    if(changed!=0){

        for(iter1=1;iter1<=n;iter1++){
        for(iter2=1;iter2<=n;iter2++){
            if(c_ans[iter1][iter2] == c_orig[iter1][iter2]){
                continue;
            }
            printf("%c %d %d\n",c_ans[iter1][iter2],iter1,iter2);
            fprintf(out,"%c %d %d\n",c_ans[iter1][iter2],iter1,iter2);
        }
        }
    }


}



int main(){

int m,t,iter,row,col,iter1,iter2,min,min_iter1,min_iter2,t_iter,orig_ans;
char model[2];
in = fopen("D-large.in","r");
out = fopen("output.txt","w");

fscanf(in,"%d",&t);

for(t_iter=1;t_iter<=t;t_iter++){
fscanf(in,"%d %d",&n,&m);
initialise();
orig_ans=0;

for(iter=0;iter<m;iter++){
    fscanf(in,"%s",model);
    fscanf(in,"%d %d",&row,&col);
    if(model[0] == 'o'){
        orig_ans = orig_ans + 2;
    }
    else if(model[0] != '.'){
        orig_ans++;
    }
    c_orig[row][col]=model[0];
    c_ans[row][col]=model[0];
}

//print_c();
//row
for(iter=1;iter<=n;iter++){
        diag_row[iter]=1;
    for(iter1=iter,iter2=1;iter1<=n;iter1++,iter2++){
        if(c_ans[iter1][iter2]=='+' || c_ans[iter1][iter2]=='o'){
            diag_row[iter]=0;
            break;
        }
    }
}

//col
for(iter=1;iter<=n;iter++){
        diag_col[iter]=1;
        for(iter1=1,iter2=iter ; iter2<=n; iter1++,iter2++){
            if(c_ans[iter1][iter2]=='+' || c_ans[iter1][iter2]=='o'){
                diag_col[iter]=0;
                break;
            }
        }
}

for(iter=1;iter<=n;iter++){
    min = _max;
    for(iter1=iter,iter2=1; iter1>=1 ; iter1--,iter2++){

        if(c_ans[iter1][iter2] == '+' || c_ans[iter1][iter2] == 'o'){
            break;
        }

        if(iter1>=iter2){
            if(diag_row[iter1-iter2+1] == 0){
                continue;
            }
            if(min > n-iter1){
                min = n-iter1;
                min_iter1=iter1;
                min_iter2=iter2;
            }
        }
        else{
            if(diag_col[iter2-iter1+1] == 0 ){
                continue;
            }
            if(min > n-iter2){
                min = n - iter2;
                min_iter1=iter1;
                min_iter2=iter2;
            }
        }
    }

    if(iter1 ==0 && min < _max){
            if(c_ans[min_iter1][min_iter2] == 'x'){
                c_ans[min_iter1][min_iter2] = 'o';
            }
            else{
                c_ans[min_iter1][min_iter2] = '+';
            }
            if(min_iter1>=min_iter2){
                diag_row[min_iter1-min_iter2+1]=0;
            }
            else{
                diag_col[min_iter2-min_iter1+1]=0;
            }
    }

}

for(iter=2;iter<=n;iter++){
    min = _max;
    for(iter1=n,iter2=iter; iter2<=n ; iter1--,iter2++){

        if(c_ans[iter1][iter2] == '+' || c_ans[iter1][iter2] == 'o'){
            break;
        }

        if(iter1>=iter2){
            if(diag_row[iter1-iter2+1] == 0){
                continue;
            }
            if(min > n-iter1){
                min = n-iter1;
                min_iter1=iter1;
                min_iter2=iter2;
            }
        }
        else{
            if(diag_col[iter2-iter1+1] == 0 ){
                continue;
            }
            if(min > n-iter2){
                min = n - iter2;
                min_iter1=iter1;
                min_iter2=iter2;
            }
        }
    }

    if(iter2>n && min < _max){
            if(c_ans[min_iter1][min_iter2] == 'x'){
                c_ans[min_iter1][min_iter2] = 'o';
            }
            else{
                c_ans[min_iter1][min_iter2] = '+';
            }
            if(min_iter1>=min_iter2){
                diag_row[min_iter1-min_iter2+1]=0;
            }
            else{
                diag_col[min_iter2-min_iter1+1]=0;
            }
    }

}

//print_c();


for(iter=1;iter<=n;iter++){
        diag_col[iter]=1;
        for(iter1=1,iter2=iter ; iter1<=n; iter1++){
            if(c_ans[iter1][iter2]=='x' || c_ans[iter1][iter2]=='o'){
                diag_col[iter]=0;
                break;
            }
        }
}

for(iter=1;iter<=n;iter++){
    min_iter1=-1;
    for(iter1=iter,iter2=1 ; iter2<=n ; iter2++){
        if(c_ans[iter1][iter2] == 'x' || c_ans[iter1][iter2] == 'o'){
            break;
        }

        if(diag_col[iter2] == 0){
            continue;
        }
        min_iter1=iter1;
        min_iter2=iter2;
    }

    if(iter2 > n && min_iter1 != -1){
        if(c_ans[min_iter1][min_iter2] == '+'){
            c_ans[min_iter1][min_iter2] = 'o';
        }
        else{
            c_ans[min_iter1][min_iter2] = 'x';
        }
        diag_col[min_iter2]=0;
    }
}

//print_c();

//find differnence
diff(t_iter,orig_ans);

}


return 0;
}
