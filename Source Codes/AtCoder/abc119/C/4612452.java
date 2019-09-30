import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    private static int n, a, b, c, l[];
    public static void main(String[] args) {
        n = scanner.nextInt();
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        l = IntStream.range(0, n).map(i -> scanner.nextInt()).toArray();

        System.out.println(dfs(0, 0, 0, 0));
    }

    private static int dfs(int cur, int a0, int b0, int c0) {
        if (cur == n)
            return (Math.min(Math.min(a0, b0), c0) > 0 ? Math.abs(a0 - a) + Math.abs(b0 - b) + Math.abs(c0 - c) - 30 : 1000000000);

        int ret0 = dfs(cur + 1, a0, b0, c0);
        int ret1 = dfs(cur + 1, a0 + l[cur], b0, c0) + 10;
        int ret2 = dfs(cur + 1, a0, b0 + l[cur], c0) + 10;
        int ret3 = dfs(cur + 1, a0, b0, c0 + l[cur]) + 10;

        return Math.min(Math.min(Math.min(ret0, ret1), ret2), ret3);
    }
}