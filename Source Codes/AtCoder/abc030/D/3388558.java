import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int N, A;
    static String K;
    static int[] B;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        A = fc.nextInt()-1;
        K = fc.next();
        B = new int[N];
        for (int i = 0; i < N; i++) {
            B[i] = fc.nextInt()-1;
        }
        System.out.println(solve()+1);
    }

    static int solve() {
        int[] cnt = new int[N];
        int curr = A;
        cnt[curr]++;
        while(true) {
            int next = B[curr];
            if( cnt[next] < 2 ) {
                cnt[next]++;

                curr = next;
            } else {
                break;
            }
        }
        int loopSize = (int)Arrays.stream(cnt).filter(i -> i == 2 ).count();
        int nonLoopSize = (int)Arrays.stream(cnt).filter(i -> i == 1 ).count();

        BigInteger k = new BigInteger(K);

        if( k.compareTo(BigInteger.valueOf(loopSize + nonLoopSize)) < 0 ) {
            return step(k.intValue());

        } else {
            BigInteger mod = k.subtract(BigInteger.valueOf(nonLoopSize))
                    .mod(BigInteger.valueOf(loopSize));
            return step(nonLoopSize + mod.intValue());
        }
    }

    static int step(int k) {
        int curr = A;
        for (int i = 0; i < k; i++) {
            curr = B[curr];
        }
        return curr;
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