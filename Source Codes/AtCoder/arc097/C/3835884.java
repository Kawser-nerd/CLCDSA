import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    static int n;
    static int[] a;
    static int[][] costW, costB;
    static char[] c;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        c = new char[2*n+1];
        a = new int[2*n+1];
        for(int i=1;i<=2*n;i++){
            c[i] = sc.next().charAt(0);
            a[i] = sc.nextInt();
        }
        init();
        int[] white = new int[n+1], black = new int[n+1];
        for(int i=1;i<=2*n;i++){
            if(c[i]=='W') white[a[i]]=i;
            else black[a[i]]=i;
        }
        // dp[i][j]: put the first i black and j white balls in the idx of 1~i+j
        int[][] dp = new int[n+1][n+1];
        for(int i=1;i<=n;i++) dp[i][0] = dp[i-1][0]+costB[black[i]-1][i]+costW[black[i]-1][0];
        for(int j=1;j<=n;j++) dp[0][j] = dp[0][j-1]+costB[white[j]-1][0]+costW[white[j]-1][j];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // candidate1: put the black i as the (i+j)-th ball
                int can1 = dp[i-1][j]+costB[black[i]-1][i]+costW[black[i]-1][j];
                // candidate2: put the white j as the (i+j)-th ball
                int can2 = dp[i][j-1]+costB[white[j]-1][i]+costW[white[j]-1][j];
                dp[i][j] = Math.min(can1,can2);
            }
        }
        System.out.println(dp[n][n]);
    }
    // costW[i][j]: how many white balls with value >j that have idx<=i (1<=i<=2*n)
    static void init(){
        costW = new int[2*n+1][n+1];
        costB = new int[2*n+1][n+1];
        for(int i=1;i<=2*n;i++){
            for(int j=0;j<=n;j++){
                costW[i][j] = costW[i-1][j];
                costB[i][j] = costB[i-1][j];
            }
            if(c[i]=='W') {
                for(int j=0;j<a[i];j++) costW[i][j]++;
            }
            else{
                for(int j=0;j<a[i];j++) costB[i][j]++;
            }
        }
    }
}