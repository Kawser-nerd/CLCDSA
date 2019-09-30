import java.util.Scanner;
import java.lang.Math;

public class Main {
    private static final int maxn = 111;
    private static int[][] a = new int[3][maxn], f = new int[3][maxn];
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 1; i <= 2; ++i) for (int j = 1; j <= n; ++j) a[i][j] = in.nextInt();
        for (int i = 1; i <= 2; ++i) for (int j = 1; j <= n; ++j)
            f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]) + a[i][j];
        System.out.println(f[2][n]);
    }
}