import java.io.*;
import java.util.*;

public class Main {

    static int Q;
    static int[] T, X;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        Q = fc.nextInt();
        T = new int[Q];
        X = new int[Q];
        for (int i = 0; i < Q; i++) {
            T[i] = fc.nextInt();
            X[i] = fc.nextInt();
        }

        PrintWriter pw = new PrintWriter(System.out);
        for (int i : solve()) {
            pw.println(i);
        }
        pw.flush();
    }

    static List<Integer> solve() {
        BinaryIndexedTree bit = new BinaryIndexedTree((int)2e6+1);
        List<Integer> answer = new ArrayList<>();
        for (int i = 0; i < Q; i++) {
            if( T[i] == 1 ) {
                bit.add(X[i], 1);

            } else {
                int n = find(bit, X[i]);
                bit.add(n, -1);
                answer.add(n);
            }
        }
        return answer;
    }

    static int find(BinaryIndexedTree bit, int x) {
        int low = 0;
        int high = (int)2e6;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low;
            if( bit.sum(mid) < x ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    static class BinaryIndexedTree {

        int n;
        int[] bit;

        BinaryIndexedTree(int n) {
            this.n = n;
            this.bit = new int[n+1];
        }

        void add(int i, int v) {
            i++; // 0 index -> 1 index

            while( i <= n ) {
                bit[i] += v;
                i += i & -i;
            }
        }

        int sum(int i) {
            i++; // 0 index -> 1 index

            int ret = 0;
            while(i > 0) {
                ret += bit[i];
                i -= i & -i;
            }
            return ret;
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