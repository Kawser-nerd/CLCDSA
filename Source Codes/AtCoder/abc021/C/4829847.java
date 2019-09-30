import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);
    private static int mod = 1000000007;

    public static void main(String[]$) {
        int n = scanner.nextInt(), a = scanner.nextInt() - 1, b = scanner.nextInt() - 1, m = scanner.nextInt(), aa[][] = new int[n][n], ba[][] = new int[n][n], ca[][] = new int[n][n];
        for (int i = 0, l, r; i < m; i++) aa[l = scanner.nextInt() - 1][r = scanner.nextInt() - 1] = aa[r][l] = ba[l][r] = ba[r][l] = 1;
        System.out.println(IntStream.range(0, n).reduce(0, (a1, b1) -> {
            if (ba[a][b] != 0) return ba[a][b];
            IntStream.range(0, n).forEach(i -> IntStream.range(0, n).forEach(j -> ca[i][j] = IntStream.range(0, n).map(k -> ba[i][k] * aa[k][j]).sum() % mod));
            IntStream.range(0, n).forEach(i -> IntStream.range(0, n).forEach(j -> ba[i][j] = ca[i][j]));
            return ba[a][b];
        }));
    }
}