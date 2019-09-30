import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a[] = new int[m];
        int b[] = new int[m];
        int t[] = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            t[i] = sc.nextInt();
        }
        int[][] masu = new int[n + 1][n + 1];
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                masu[i][j] = n * 10000 + 10;
                if (i == j) {
                    masu[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            masu[a[i]][b[i]] = t[i];
            masu[b[i]][a[i]] = t[i];
        }
        masu[1][1] = 0;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                for (int k = 0; k < n + 1; k++) {

                    masu[j][k] = Math.min(masu[j][k], masu[j][i] + masu[i][k]);
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        int tmpans = 0;
        for (int i = 1; i < n + 1; i++) {
            tmpans = 0;
            for (int j = 1; j < n + 1; j++) {
                if (masu[i][j] > tmpans) {
                    tmpans = masu[i][j];
                }
            }
            if (ans > tmpans) {
                ans = tmpans;
            }
        }
        System.out.println(ans);
    }
}