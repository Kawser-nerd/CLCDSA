import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;


public class UglyNumbers {
    static int [][][]arr;
    static long [][][][][]dp;
    static String s;
    static long go(int l, int m2, int m3, int m5, int m7, boolean f) {
        if (l == 0) {
            if (m2 == 0 || m3 == 0 || m5 == 0 || m7 == 0) return 1;
            return 0;
        }
        if (dp[l][m2+1][m3+2][m5+4][m7+6] != -1) {
            return dp[l][m2+1][m3+2][m5+4][m7+6];
        }
        long ans = 0;
        for (int i=0;i<l;i++) {
            if (f) {
                ans += go(i, arr[i][l-1][0], arr[i][l-1][1], arr[i][l-1][2], arr[i][l-1][3], false);
            } else {
                // do a plus operation
                ans += go(i, (m2 + arr[i][l-1][0])%2, (m3 + arr[i][l-1][1])%3, (m5 + arr[i][l-1][2])%5, (m7 + arr[i][l-1][3])%7, false);
                // minus operation
                ans += go(i, (-m2 + arr[i][l-1][0])%2, (-m3 + arr[i][l-1][1])%3, (-m5 + arr[i][l-1][2])%5, (-m7 + arr[i][l-1][3])%7, false);
            }
        }
        dp[l][m2+1][m3+2][m5+4][m7+6] = ans;
        return ans;
    }
    public static void main(String []args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int n = Integer.parseInt(br.readLine());
        for (int test = 1;test <= n; test++) {
            s = br.readLine();
            dp = new long[s.length()+1][3][5][9][13];
            for (int i=0;i<s.length()+1;i++)for (int j=0;j<3;j++) for (int k=0;k<5;k++)
                for (int l=0;l<9;l++) for (int m=0;m<13;m++) dp[i][j][k][l][m] = -1;
            
            arr = new int[s.length()][s.length()][4];
            for (int i=0;i<s.length();i++) {
                for (int j=0;j<=i;j++) {
                    String t = s.substring(j, i+1);
                    BigInteger bi = new BigInteger(t);
                    arr[j][i][0] = bi.mod(new BigInteger("2")).intValue();
                    arr[j][i][1] = bi.mod(new BigInteger("3")).intValue();
                    arr[j][i][2] = bi.mod(new BigInteger("5")).intValue();
                    arr[j][i][3] = bi.mod(new BigInteger("7")).intValue();
                }
            }
            long ans = go(s.length(), 0, 0, 0, 0, true);
            System.out.println("Case #"+test+": "+ans);
        }
        
        
    }
}
