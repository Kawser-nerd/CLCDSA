import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        try (Scanner in = new Scanner(System.in)) {
            int n = in.nextInt();
            int k = in.nextInt();
            int a[] = new int[n];
            long sum = 0;
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                sum += a[i];
            }
            if (sum < k) {
                System.out.println(n);
                return;
            }
            Arrays.sort(a);
            for (int i = 0; i < n; ++i) {
                if (a[i] >= k) {
                    a = Arrays.copyOf(a, i);
                    break;
                }
            }
            int min = -1, max = a.length;
            while (max - min > 1) {
                int mid = (max + min) / 2;
                if (ok(a, mid, k)) max = mid;
                else min = mid;
            }
            System.out.println(max);
        }
    }

    boolean ok(int a[], int b, int k) {
        boolean ok[] = new boolean[k];
        ok[0] = true;
        for (int i = 0; i < a.length; ++i) {
            if (i == b) continue;
            for (int j = k - 1 - a[i]; j >= 0; --j) {
                if (ok[j]) ok[j + a[i]] = true;
            }
        }
        for (int i = k - a[b]; i < k; ++i) {
            if (ok[i]) return true;
        }
        return false;
    }

    void tr(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}