/* 
 Input
 2
 20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
 20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600
 
 
 Output
 Case #1:
 1 2
 3
 Case #2:
 3117 4210 4943
 2328 2894 7048
 
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int noOfSubsets;
int sumOfSubsets[1048576];
int subsets[1048576][20];
int getResult;
    FILE *fi,*fo;

void all_subset( int arr[], unsigned int size, int* contains, int depth )
{
    int k;int s;
    if(getResult==1) return;
    //when reach the needed length, output
    if ( depth == size )
    {
        s=0;
        for( k = 0 ; k < size ; k++ )
        {
            if( contains[k] ) {
                subsets[noOfSubsets][s++]=arr[k];
                sumOfSubsets[noOfSubsets]+=arr[k];
            }
            
        }
        //printf("s = %d ",s);
        subsets[noOfSubsets][s]=-1;
        for( k= 0 ; k < noOfSubsets ; k++ )
        {
            if(sumOfSubsets[noOfSubsets]==sumOfSubsets[k]){
                //printf("%d ",sumOfSubsets[noOfSubsets]);
                for( int j = 0 ; j < size ; j++ )
                {
                    if( contains[j] ) 
                        fprintf(fo, "%d ",arr[j]);
                }
                fprintf(fo, "\n");
                for( int j = 0 ; j < size ; j++ )
                {
                    if (subsets[k][j]<0) break;
                    fprintf(fo, "%d ",subsets[k][j]);
                }
                getResult=1;
                fprintf(fo, "\n");
                return;
            }
                
        }
        noOfSubsets++;
        //printf("\n");
        
    }
    else
    {
        // generate the result that doesn't contain arr[depth]
        contains[depth] = 0;
        all_subset( arr, size, contains, depth+1 );
        // generate the result that contains arr[depth]
        contains[depth] = 1;
        all_subset( arr, size, contains, depth+1 );                      
    }
    return;
}


int main(int argc, const char * argv[])
{
    int noOfCases, noOfNumbers;
    int nums[20];
    int i,j;
    int contains[20];

    fi = fopen ("//Users/yingwang/Downloads/C-small-attempt0 (1).in","r");
    fo = fopen ("//Users/yingwang/Downloads/A-large.out","w");
    if (fi!=NULL)
    {
        fscanf(fi,"%d",&noOfCases);
        for(i=0;i<noOfCases;i++){
            fscanf(fi,"%d",&noOfNumbers);
            for(j=0;j<20;j++){
                fscanf(fi,"%d",&nums[j]);
            }
            memset(contains,0,20*sizeof(int));
            noOfSubsets=0;
            getResult=0;
            memset(sumOfSubsets,0,1048576*sizeof(int));
            fprintf(fo,"Case #%d: \n",i+1);
            all_subset(nums, 20, contains, 0 );
            //printf("numofsubsets: %d\n",noOfSubsets);
        }     
                
        fclose (fi);
        fclose (fo);
    } 
    return 0;
}

