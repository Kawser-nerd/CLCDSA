import java.util.*;
import java.io.*;
import static java.lang.System.in;

public class Main {
    static long mod = 1000000000+7;
    public static void main(String[] args)throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        int Q = Integer.parseInt(sc.next());
        long[][] dp = new long[n+1][m+1];
        int[] a = new int[n+1];

        for(int i=1;i<=n;i++) a[i]=Integer.parseInt(sc.next());
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            dp[i][0] = 1;
            for(int j=1;j<=m;j++){
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
                if(j-1-a[i]>=0) dp[i][j] -= dp[i-1][j-1-a[i]];
                dp[i][j] = (mod+dp[i][j])%mod;
            }
        }
        long[][] dp2 = new long[n+1][m+1];
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp2[i][j] = dp[n][j];
                if(j>=1) dp2[i][j] += mod-dp[n][j-1];
                if(j-1-a[i]>=0) dp2[i][j] += dp2[i][j-1-a[i]];
                dp2[i][j] = dp2[i][j]%mod;
            }
        }
        PrintWriter out = new PrintWriter(System.out);
        for(int i=0;i<Q;i++){
            int k = Integer.parseInt(sc.next());
            int x = Integer.parseInt(sc.next());
            if(x>a[k]) {
                out.println(0);
            } else{
                out.println(dp2[k][m-x]);
            }
        }
        out.flush();
        out.close();
    }
}