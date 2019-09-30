import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int A;
    static int B;
    static int C;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        A = fc.nextInt();
        B = fc.nextInt();
        C = fc.nextInt();
        System.out.println(solve());
    }

    static int MOD = 1_000_000_007;

    static String solve() {
        // A = comb(r+c, c) = (r+c)! / r!c!
        // B = comb(r+c+1, c+1) = (r+c+1)! / r!(c+1)! = A * (r+c+1)/(c+1)
        // C = comb(r+c+1, c) = (r+c+1)! / (r+1)!c! = A * (r+c+1)/(r+1)

        int AdB = div(A, B);
        int AdC = div(A, C);

        // r + c + 1 = rev(A/B + A/C - 1)
        int rc1 = rev(sub(sum(AdB, AdC), 1));

        // c+1 = A/B * (r+c+1)
        // r+1 = A/C * (r+c+1)
        int c1 = mul(AdB, rc1);
        int r1 = mul(AdC, rc1);

        // r c
        return sub(r1, 1) + " " + sub(c1, 1);
    }

    static int mul(int a, int b) {
        return (int)((long)a * b % MOD);
    }

    static int sum(int a, int b) {
        return (int)(((long)a + b) % MOD);
    }

    static int sub(int a, int b) {
        return (a + MOD - b) % MOD;
    }

    static int div(int a, int b) {
        return mul(a, rev(b));
    }

    static int rev(int a) {
        return pow(a, MOD-2);
    }

    static int pow(int base, int exp) {
        if( exp == 0 ) return 1;

        int ans = 1;
        base %= MOD;
        while( exp > 0 ) {
            if( (exp & 1) == 1 ) {
                ans = mul(ans, base);
            }

            base = mul(base, base);
            exp = exp >> 1;
        }
        return ans;
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}