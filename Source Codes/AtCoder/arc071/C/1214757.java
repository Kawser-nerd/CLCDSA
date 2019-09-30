import java.util.Arrays;
import java.util.Scanner;
import java.util.concurrent.SynchronousQueue;

public class Main {
    MyScanner sc    = new MyScanner();
    Scanner   sc2   = new Scanner(System.in);
    long      start = System.currentTimeMillis();
    long      fin   = System.currentTimeMillis();
    final int MOD   = 1000000007;
    int[]     dx    = { 1, 0, 0, -1 };
    int[]     dy    = { 0, 1, -1, 0 };

    void run() {
        char[] S = sc.next().toCharArray();
        char[] T = sc.next().toCharArray();
        int[] scoreS = new int[S.length + 1];
        int[] scoreT = new int[T.length + 1];
        for (int i = 1; i <= S.length; i++)
            scoreS[i] += scoreS[i - 1] + (S[i - 1] == 'A' ? 1 : 2);
        for (int i = 1; i <= T.length; i++)
            scoreT[i] += scoreT[i - 1] + (T[i - 1] == 'A' ? 1 : 2);
        StringBuilder out = new StringBuilder();
        int q = sc.nextInt();
        while (q-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            int d = sc.nextInt();
            out.append((scoreS[b] - scoreS[a - 1]) % 3 == (scoreT[d] - scoreT[c - 1]) % 3 ? "YES\n": "NO\n");
        }
        System.out.print(out);
    }

    public static void main(String[] args) {
        new Main().run();
    }

    void debug(Object... o) {
        System.out.println(Arrays.deepToString(o));
    }

    void debug2(int[][] array) {
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array[i].length; j++) {
                System.out.print(array[i][j]);
            }
            System.out.println();
        }
    }

    boolean inner(int h, int w, int limH, int limW) {
        return 0 <= h && h < limH && 0 <= w && w < limW;
    }

    void swap(char[] x, int a, int b) {
        char tmp = x[a];
        x[a] = x[b];
        x[b] = tmp;
    }

    // find minimum i (k <= a[i])
    int lower_bound(int a[], int k) {
        int l = -1;
        int r = a.length;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (k <= a[mid])
                r = mid;
            else
                l = mid;
        }
        // r = l + 1
        return r;
    }

    // find minimum i (k < a[i])
    int upper_bound(int a[], int k) {
        int l = -1;
        int r = a.length;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (k < a[mid])
                r = mid;
            else
                l = mid;
        }
        // r = l + 1
        return r;
    }

    int gcd(int a, int b) {
        return a % b == 0 ? b : gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    boolean palindrome(String s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    class MyScanner {
        int nextInt() {
            try {
                int c = System.in.read();
                while (c != '-' && (c < '0' || '9' < c))
                    c = System.in.read();
                if (c == '-')
                    return -nextInt();
                int res = 0;
                do {
                    res *= 10;
                    res += c - '0';
                    c = System.in.read();
                } while ('0' <= c && c <= '9');
                return res;
            } catch (Exception e) {
                return -1;
            }
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        String next() {
            try {
                StringBuilder res = new StringBuilder("");
                int c = System.in.read();
                while (Character.isWhitespace(c))
                    c = System.in.read();
                do {
                    res.append((char) c);
                } while (!Character.isWhitespace(c = System.in.read()));
                return res.toString();
            } catch (Exception e) {
                return null;
            }
        }

        int[] nextIntArray(int n) {
            int[] in = new int[n];
            for (int i = 0; i < n; i++) {
                in[i] = nextInt();
            }
            return in;
        }

        int[][] nextInt2dArray(int n, int m) {
            int[][] in = new int[n][m];
            for (int i = 0; i < n; i++) {
                in[i] = nextIntArray(m);
            }
            return in;
        }

        double[] nextDoubleArray(int n) {
            double[] in = new double[n];
            for (int i = 0; i < n; i++) {
                in[i] = nextDouble();
            }
            return in;
        }

        long[] nextLongArray(int n) {
            long[] in = new long[n];
            for (int i = 0; i < n; i++) {
                in[i] = nextLong();
            }
            return in;
        }

        char[][] nextCharField(int n, int m) {
            char[][] in = new char[n][m];
            for (int i = 0; i < n; i++) {
                String s = sc.next();
                for (int j = 0; j < m; j++) {
                    in[i][j] = s.charAt(j);
                }
            }
            return in;
        }
    }
}