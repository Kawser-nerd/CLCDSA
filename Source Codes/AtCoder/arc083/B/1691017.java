import java.util.*;

public class Main
{

    static Scanner sc = new Scanner(System.in);
    static int dp[][][];
    static int edges[][];
    static boolean del[][];
    public static void main(String[] args) {
        int n = sc.nextInt();

        edges = new int[n][n];
        del = new boolean[n][n];
        long total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                edges[i][j] = sc.nextInt();
                total += edges[i][j];
            }
        }
        dp = new int[n][n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][0] = edges[i][j];
            }
        }
        for (int k = 1; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j][k] = Math.min(dp[i][j][k-1], dp[i][k][k-1] + dp[k][j][k-1]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && dp[i][j][n-1] != edges[i][j]){
                    System.out.println(-1);
                    return;
                }
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i!=j&& j!=k && i !=k &&edges[i][j] == edges[i][k] + edges[k][j] && !del[i][j]) {
                        total -= edges[i][j];
                        del[i][j] = true;
                    }
                }
            }
        }

        total /= 2;
        System.out.println(total);
    }
}