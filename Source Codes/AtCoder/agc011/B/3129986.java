import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] A = new long[n];
        for(int i=0;i<n;i++) A[i]=sc.nextLong();
        Arrays.sort(A);
        long[] sum = new long[n];
        sum[0]=A[0];
        for(int i=1;i<n;i++) sum[i]=sum[i-1]+A[i];
        int ans = 1;
        for(int i=n-1;i>=1;i--){
            if(A[i]<=2*sum[i-1]) ans++;
            else break;
        }
        System.out.println(ans);
    }
}