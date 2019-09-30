import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.UncheckedIOException;
import java.util.Objects;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner in = new LightScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        private static final int MOD = (int) 1e9 + 7;

        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints();
            ModMath m = new ModMath();
            long ans = 1;
            int last = 0;
            int c = 0;
            for (int i = 0; i < n; i++) {
                int a = in.ints();
                if (a < 0) {
                    c++;
                } else if (c > 0) {
                    ans *= m.nhr(a - last + 1, c);
                    ans %= MOD;
                    last = a;
                    c = 0;
                } else {
                    last = a;
                }
            }
            out.println(ans);
        }

    }

    static class ModMath {
        private static final int DEFAULT_MOD = 1_000_000_007;
        private final long mod;

        public ModMath(long mod) {
            this.mod = mod;
        }

        public ModMath() {
            this(DEFAULT_MOD);
        }

        public long mod(long x) {
            x %= mod;
            return x < 0 ? x + mod : x;
        }

        public long inv(long x) {
            return mod(LongEuclidSolver.solve(x, -mod).getX());
        }

        public long npr(int n, int r) {
            if (n < r) {
                return 0;
            }
            long ans = 1;
            for (int i = 0; i < r; i++) {
                ans *= (n - i);
                ans %= mod;
            }
            return ans;
        }

        public long ncr(int n, int r) {
            long div = 1;
            for (int i = 2; i <= r; i++) {
                div *= i;
                div %= mod;
            }
            return mod(npr(n, r) * inv(div));
        }

        public long nhr(int n, int r) {
            if ((n | r) == 0) {
                return 1;
            }
            return ncr(n + r - 1, r);
        }

    }

    static class LongEuclidSolver {
        private LongEuclidSolver() {
        }

        public static Vec3l solve(long p, long q) {
            if (q == 0) {
                return new Vec3l(p, 1, 0);
            }
            Vec3l vals = solve(q, p % q);
            long a = vals.getY();
            long b = vals.getX() - (p / q) * a;
            return new Vec3l(a, b, vals.getZ());
        }

    }

    static class Vec3l {
        private final long x;
        private final long y;
        private final long z;

        public Vec3l(long x, long y, long z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public long getX() {
            return x;
        }

        public long getY() {
            return y;
        }

        public long getZ() {
            return z;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Vec3i vec3i = (Vec3i) o;
            return x == vec3i.x &&
                    y == vec3i.y &&
                    z == vec3i.z;
        }

        public int hashCode() {
            return Objects.hash(x, y, z);
        }

        public String toString() {
            return "(" + x + ", " + y + ", " + z + ")";
        }

    }

    static class Vec3i {
        public final int x;
        public final int y;
        public final int z;

        public Vec3i(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Vec3i vec3i = (Vec3i) o;
            return x == vec3i.x &&
                    y == vec3i.y &&
                    z == vec3i.z;
        }

        public int hashCode() {
            return Objects.hash(x, y, z);
        }

        public String toString() {
            return "(" + x + ", " + y + ", " + z + ")";
        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int ints() {
            return Integer.parseInt(string());
        }

    }
}