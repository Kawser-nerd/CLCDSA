import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        long mod = 998244353;
        long[] p2;

        long gcd(long a, long b) {
            if (a < 0) a = -a;
            if (b < 0) b = -b;
            if (b == 0) return a;
            return gcd(b, a % b);
        }

        long f(int k) {
            if (k <= 2) {
                return 0;
            }
            return ((p2[k] - (k * (k - 1) / 2) - k - 1) % mod + mod) % mod;
        }

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] x = new int[n];
            int[] y = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }

            p2 = new long[n + 1];
            p2[0] = 1;
            for (int i = 0; i < n; i++) {
                p2[i + 1] = (p2[i] * 2) % mod;
            }

            long ans = f(n);
            Set<Line> lines = new HashSet<>();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    long a = y[i] - y[j];
                    long b = x[j] - x[i];
                    long c = a * x[i] + b * y[i];
                    long d = gcd(a, b);
                    d = gcd(d, c);
                    a /= d;
                    b /= d;
                    c /= d;
                    if (a < 0 || a == 0 && b < 0) {
                        a = -a;
                        b = -b;
                        c = -c;
                    }

                    Line l = new Line(a, b, c);
                    if (lines.contains(l)) {
                        continue;
                    }
                    lines.add(l);
                    int cnt = 0;
                    for (int k = 0; k < n; k++) {
                        if (a * x[k] + b * y[k] == c) {
                            cnt++;
                        }
                    }
                    ans = ((ans - f(cnt)) % mod + mod) % mod;
                }
            }

            out.println(ans);
        }

        class Line {
            long a;
            long b;
            long c;

            public Line(long a, long b, long c) {
                this.a = a;
                this.b = b;
                this.c = c;
            }


            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;

                Line line = (Line) o;

                if (a != line.a) return false;
                if (b != line.b) return false;
                return c == line.c;
            }


            public int hashCode() {
                int result = (int) (a ^ (a >>> 32));
                result = 31 * result + (int) (b ^ (b >>> 32));
                result = 31 * result + (int) (c ^ (c >>> 32));
                return result;
            }

        }

    }
}