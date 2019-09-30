import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author kessido
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ESequenceGrowingHard solver = new ESequenceGrowingHard();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESequenceGrowingHard {
        long MOD;
        int k;
        int n;
        long[][] hm = new long[301][301];
        long[][] sumValue = new long[301][301];
        long[][] nChK = new long[301][301];
        BigInteger[] factor = new BigInteger[400];

        long calcValue(int size, int withElementLargerThen) {
            if (size == 0) return 1;
            if (k <= withElementLargerThen) return 0;
            if (size == 1) {
                return (k - withElementLargerThen);
            }
            long res = 0;
            for (int sizeToTheLeft = 0; sizeToTheLeft < size; sizeToTheLeft++) {
                long optionLeft = getSumValue(sizeToTheLeft, withElementLargerThen + 1);
                long optionRight = getValue(size - 1 - sizeToTheLeft, withElementLargerThen);
                long optionToAddToEachSide = nChK[size - 1][sizeToTheLeft];
                res = (res + ((((optionLeft * optionRight) % MOD) * optionToAddToEachSide) % MOD)) % MOD;
            }
            return res;
        }

        long getValue(int size, int withElementLargerThen) {
            if (hm[size][withElementLargerThen] == -1) {
                hm[size][withElementLargerThen] = calcValue(size, withElementLargerThen) % MOD;
            }
            return hm[size][withElementLargerThen];
        }

        long getSumValue(int size, int fromValue) {
            if (sumValue[size][fromValue] == -1) {
                long res = 0;
                for (int i = fromValue; i <= k; i++) {
                    res += getValue(size, i);
                    res %= MOD;
                }
                sumValue[size][fromValue] = res % MOD;
            }
            return sumValue[size][fromValue];
        }

        void fillWith_1(long[][] m) {
            for (long[] mm : m) {
                Arrays.fill(mm, -1);
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.NextInt();
            k = in.NextInt();
            MOD = in.NextLong();
            fillWith_1(hm);
            fillWith_1(sumValue);
            fillWith_1(nChK);
            factor[0] = BigInteger.ONE;
            for (int i = 1; i < 400; i++) {
                factor[i] = factor[i - 1].multiply(BigInteger.valueOf(i));
            }
            for (int i = 0; i < 301; i++) {
                for (int j = 0; j <= i; j++) {
                    nChK[i][j] = factor[i].divide(factor[j]).divide(factor[i - j]).mod(BigInteger.valueOf(MOD)).longValue();
                }
            }
            out.println(getValue(n, 0));
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine(), " \t\n\r\f,");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int NextInt() {
            return Integer.parseInt(next());
        }

        public long NextLong() {
            return Long.parseLong(next());
        }

    }
}