import java.io.*;
import java.util.*;

public class Main {

    static int K, N;
    static String[] V, W;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        K = sc.nextInt();
        N = sc.nextInt();
        V = new String[N];
        W = new String[N];
        for (int i = 0; i < N; i++) {
            V[i] = sc.next();
            W[i] = sc.next();
        }

        PrintWriter pw = new PrintWriter(System.out);
        for (String s : solve()) {
            pw.println(s);
        }
        pw.flush();
    }

    static List<String> solve() {
        int[] lens = new int[K];
        return dfs(0, lens);
    }

    static List<String> dfs(int i, int[] lens) {
        if( i == K ) return calc(lens);

        lens[i] = 1;
        List<String> r1 = dfs(i+1, lens);
        if( r1 != null ) return r1;

        lens[i] = 2;
        List<String> r2 = dfs(i+1, lens);
        if( r2 != null ) return r2;

        lens[i] = 3;
        return dfs(i+1, lens);
    }

    static List<String> calc(int[] lens) {
        Map<Integer, String> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            String v = V[i];
            String w = W[i];

            if( w.length() != calcLen(v, lens) ) {
                return null;
            }

            int curr = 0;
            for (int j = 0; j < v.length(); j++) {
                char c = v.charAt(j);
                int n = (c - '0');
                int nlen = lens[n-1];
                String ns = w.substring(curr, curr+nlen);
                if( map.containsKey(n) ) {
                    if( !map.get(n).equals(ns) ) {
                        return null;
                    }
                } else {
                    map.put(n, ns);
                }

                curr += nlen;
            }
        }

        List<String> ret = new ArrayList<>();
        for (int i = 0; i < K; i++) {
            if( !map.containsKey(i+1) ) {
                throw new IllegalArgumentException("why : " + map);
            }
            ret.add(map.get(i+1));
        }
        return ret;
    }

    static int calcLen(String v, int[] lens) {
        int sum = 0;
        for (int i = 0; i < v.length(); i++) {
            char c = v.charAt(i);
            int n = (c - '0');
            sum += lens[n-1];
        }
        return sum;
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