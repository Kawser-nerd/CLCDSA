public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), k = scanner.nextInt();
        long[] s = new long[n];
        for (int i = 0; i < n; i++) {
            if ((s[i] = scanner.nextInt()) == 0) {
                System.out.println(n);
                return;
            }
        }

        if (k == 0 || java.util.Arrays.stream(s).min().getAsLong() > k) {
            System.out.println(0);
            return;
        }

        long ans = 0, p = 1;
        for (int l = 0, r = 0; r < n;) {
            if (p * s[r] <= k) {
                p *= s[r];
                ans = Math.max(ans, r++ - l + 1);
            } else {
                p /= s[l];
                r = Math.max(r, ++l);
            }
        }
        System.out.println(ans);
    }
}