public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), m = scanner.nextInt();
        int x = scanner.nextInt(), y = scanner.nextInt();
        int[] a = java.util.stream.IntStream.range(0, n).map(i -> scanner.nextInt()).toArray();
        int[] b = java.util.stream.IntStream.range(0, m).map(i -> scanner.nextInt()).toArray();
        int i = 0, j = 0, t = 1, ans = 0;
        loop: while (i < n && j < m) {
            while (a[i] < t) if (++i == n) break loop;
            t = a[i] + x;
            while (b[j] < t) if (++j == m) break loop;
            t = b[j] + y;
            ans++;
        }
        System.out.println(ans);
    }
}