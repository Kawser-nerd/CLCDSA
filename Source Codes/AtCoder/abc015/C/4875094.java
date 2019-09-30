import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    static int n, k, a[][];
    public static void main(String[]$) {
        n = scanner.nextInt();
        k = scanner.nextInt();
        a = IntStream.range(0, n).mapToObj(i -> IntStream.range(0, k).map(j -> scanner.nextInt()).toArray()).toArray(int[][]::new);
        System.out.println(dfs(0, 0) ? "Found" : "Nothing");
    }

    private static boolean dfs(int d, int x) {
        return d == n ? x == 0 : IntStream.range(0, k).anyMatch(i -> dfs(d + 1, x ^ a[d][i]));
    }
}