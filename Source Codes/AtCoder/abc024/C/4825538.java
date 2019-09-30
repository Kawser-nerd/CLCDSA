public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), d = scanner.nextInt(), k = scanner.nextInt();
        int[] l = new int[d], r = new int[d], s = new int[k], t = new int[k], a = new int[k];
        boolean[] b = new boolean[k];
        for (int i = 0; i < d; i++) {
            l[i] = scanner.nextInt();
            r[i] = scanner.nextInt();
        }
        for (int i = 0; i < k; i++)
            b[i] = (s[i] = scanner.nextInt()) < (t[i] = scanner.nextInt());
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < k; j++) {
                if (l[i] <= s[j] && s[j] <= r[i]) {
                    s[j] = b[j] ? Math.max(s[j], r[i]) : Math.min(s[j], l[i]);
                    if ((b[j] ? s[j] >= t[j] : s[j] <= t[j]) && a[j] == 0)
                        a[j] = i + 1;
                }
            }
        }
        java.util.Arrays.stream(a).forEach(System.out::println);
    }
}