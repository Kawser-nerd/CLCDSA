import java.util.*;

public class Main{
    
    public static Scanner sc;
    
    public static void main(String[] args){
        sc = new Scanner(System.in);
        
        final int INF = 1_000_000_000;
        
        int n = sc.nextInt();
        long c = sc.nextLong();
        long[] x = new long[n];
        long[] v = new long[n];
        
        for(int i=0; i<n; i++){
            x[i] = sc.nextLong();
            v[i] = sc.nextLong();
        }
        
        long sum1 = 0;
        long sum2 = 0;
        long[] dp1 = new long[n+1];
        long[] dp2 = new long[n+1];
        
        for(int i=0; i<n; i++){
            sum1 += v[i];
            dp1[i+1] =  sum1 - x[i];
            dp1[i+1] = Math.max(dp1[i], dp1[i+1]);
            
            sum2 += v[n-i-1];
            dp2[i+1] = sum2 - (c - x[n-i-1]);
            dp2[i+1] = Math.max(dp2[i], dp2[i+1]);
        }
        
        long ans = 0;
        
        for(int i=0; i<n; i++){
            long a1 = Math.max(dp1[i+1], dp1[i+1] - x[i] + dp2[n-i-1]);
            long a2 = Math.max(dp2[i+1], dp2[i+1] - (c-x[n-i-1]) + dp1[n-i-1]);
            long aa = Math.max(a1, a2);
            ans = Math.max(ans, aa);
        }
        
        System.out.println(ans);
    }
}