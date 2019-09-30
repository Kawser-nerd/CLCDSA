import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n+1];
        for(int i=1;i<=n;i++) A[i]=sc.nextInt();
        System.out.println(help(n,A));
    }
    static long help(int n,int[] A){
        for(int i=1;i<=n;i++){
            if(A[i]>i-1) return -1;
        }
        for(int i=1;i<=n-1;i++){
            if(A[i]<A[i+1]-1) return -1;
        }
        long ans = 0;
        ans += A[n];
        for(int i=n-1;i>=1;i--){
            if(A[i]+1==A[i+1]) continue;
            ans += A[i];
        }
        return ans;
    }
}