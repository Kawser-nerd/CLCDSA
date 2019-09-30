import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] takoyaki = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                takoyaki[i][j] = sc.nextInt();
            }
        }

        int[][] acum = new int[n+1][n+1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(acum[i], 0);
        }

        int[] ans = new int[2501];
        Arrays.fill(ans, 0);

        cumulativeSum(n, takoyaki, acum, ans);

        for(int i=1; i<=2500; i++) {
            ans[i] = Math.max(ans[i], ans[i-1]);
        }

        int q = sc.nextInt();

        for (int i = 0; i < q; i++) {
            int p = sc.nextInt();
            System.out.println(ans[p]);
        }

    }

    private static void cumulativeSum(int n, int[][] takoyaki, int[][] acum, int[] ans) {

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x = takoyaki[i - 1][j - 1];
                acum[i][j] = x + acum[i - 1][j] + acum[i][j - 1] - acum[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = i; k <= n; k++) {
                    for (int l = j; l <= n; l++) {
                        int sum = acum[k][l] - acum[i - 1][l] - acum[k][j - 1] + acum[i - 1][j - 1];
                        int area = (k - i + 1) * (l - j + 1);
                        ans[area] = Math.max(ans[area], sum);
                    }
                }
            }
        }
    }
}