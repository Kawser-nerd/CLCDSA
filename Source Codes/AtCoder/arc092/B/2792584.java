import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int a[][] = new int[29][n];
        int b[][] = new int[29][n];
        for (int i = 0; i < n; i++) {
            int ai = sc.nextInt();
            for (int j = 1; j <= 29; j++) {
                a[j - 1][i] = ai % (1 << j);
            }
        }
        for (int i = 0; i < n; i++) {
            int bi = sc.nextInt();
            for (int j = 1; j <= 29; j++) {
                b[j - 1][i] = bi % (1 << j);
            }
        }

        int ans = 0;
        int tmp = 1;
        for (int bit = 0; bit < 29; bit++) {
            Arrays.sort(b[bit]);

            int bi = 0;
            for (int i = 0; i < n; i++) {
                bi += check(a[bit][i], tmp, b[bit]);
                bi %= 2;
            }
            ans += (bi << bit);

            tmp *= 2;
        }

        System.out.println(ans);
    }

    private int check(int a, int t, int n[]) {
        int cnt1 = search(2 * t - a, n) - search(t - a, n);
        int cnt2 = search(4 * t - a, n) - search(3 * t - a, n);

        return (cnt1 + cnt2) % 2;
    }

    private int search(int t, int n[]) {
        int l = 0;
        int r = n.length - 1;
        if (t <= n[0]) {
            return 0;
        }
        if (n[r] < t) {
            return r + 1;
        }

        int c = 0;
        while (l < r) {
            c = (l + r) / 2;
            if (t < n[c]) {
                r = c;
            } else if (t > n[c]) {
                l = c + 1;
            } else {
                r = c;
            }
        }

        return l;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}