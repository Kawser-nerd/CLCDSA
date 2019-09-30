import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        final int A=0,C=1,G=2,T=3,mod=1000000007;
        PrintWriter out = new PrintWriter(System.out);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        int[][][][] dp=new int[111][4][4][4];
        int ans=0;
        dp[0][0][0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    for(int l=0;l<4;l++){
                        for(int m=0;m<4;m++){
                            if(i>2) {
                                if (k == A && l == G && m == C) continue;
                                if (k == A && l == C && m == G) continue;
                                if (k == G && l == A && m == C) continue;
                            }
                            if(i>3) {
                                if (j == A && l == G && m == C) continue;
                                if (j == A && k == G && m == C) continue;
                            }
                            dp[i][k][l][m]+=dp[i-1][j][k][l];
                            dp[i][k][l][m]%=mod;
                        }
                    }
                }
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    ans+=dp[n][i][j][k];
                    ans%=mod;
                }
            }
        }
        out.println(ans);
        out.flush();
    }
}