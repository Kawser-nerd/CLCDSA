import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N+1];
        for(int i=1;i<=N;i++){
            A[i]=sc.nextInt();
        }
        long ans = 0;
        for(int i=1;i<=N;i++){
            if(A[i]%2==1){
                ans += A[i]/2;
                A[i]=1;
            }
            else if(A[i]%2==0&&A[i]>=2){
                ans += (A[i]-2)/2;
                A[i]=2;
            }
        }
        for(int i=1;i<=N;i++){
            if(A[i]==0) continue;
            if(A[i]==1){
                if(A[i-1]==1){
                    ans += 1;
                    A[i-1]=0;
                    A[i]=0;
                }
            }
            else if(A[i]==2){
                if(A[i-1]==0){
                    ans += 1;
                    A[i]=0;
                }
                else{
                    ans += 1;
                    A[i-1]=0;
                    A[i]=1;
                }
            }
        }
        System.out.println(ans);
    }
}