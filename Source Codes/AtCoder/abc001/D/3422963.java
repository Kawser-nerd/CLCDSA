import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] S;
    static int[] E;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        S = new int[N];
        E = new int[N];
        for (int i = 0; i < N; i++) {
            String se = fc.next();
            S[i] = Integer.parseInt(se.substring(0, 4));
            E[i] = Integer.parseInt(se.substring(5));
        }

        PrintWriter pw = new PrintWriter(System.out);
        for (Range range : solve()) {
            pw.println( String.format("%04d", range.start) + "-" + String.format("%04d", range.end));
        }
        pw.flush();
    }

    static List<Range> solve() {
        int[] imos = new int[2400+2];
        for (int i = 0; i < N; i++) {
            int s = S[i] / 5 * 5; // floor
            int e = (E[i] + 4) / 5 * 5; // ceil
            if( String.valueOf(e).endsWith("60") ) {
                e += 40;
            }
            imos[s]++;
            imos[e+1]--;
        }

        List<Range> ans = new ArrayList<>();
        int cur = 0;
        int start = -1;
        for (int i = 0; i < imos.length; i++) {
            cur += imos[i];
            if( start == -1 && cur > 0 ) {
                start = i;
            } else if( start != -1 && cur == 0 ) {
                ans.add( new Range(start, i-1) );
                start = -1;
            }
        }
        return ans;
    }

    static class Range {
        int start;
        int end;

        public Range(int start, int end) {
            this.start = start;
            this.end = end;
        }
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