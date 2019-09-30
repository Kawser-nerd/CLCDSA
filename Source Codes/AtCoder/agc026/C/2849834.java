import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.StringTokenizer;
import java.util.function.Consumer;

public class Main {

    static int N;
    static String S;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        S = sc.next();
        System.out.println( solve() );
    }

    static long solve() {
        String S1 = S.substring(0, N);
        String S2 = S.substring(N);
        S2 = reverse(S2);

        Map<Key, Integer> map1 = toMap(S1, false);
        Map<Key, Integer> map2 = toMap(S2, true);

        long answer = 0;
        for (Map.Entry<Key, Integer> entry : map1.entrySet()) {
            Key key = entry.getKey();
            Integer cnt = entry.getValue();

            if( map2.containsKey(key) ) {
                answer += (long)cnt * map2.get(key);
            }
        }
        return answer;
    }

    static Map<Key, Integer> toMap(String s, boolean rev) {
        Map<Key, Integer> map = new HashMap<>();

        dfs(s, 0, "", "", key -> {
            if(rev) key = new Key(key.b, key.r);

            if( map.containsKey(key) ) {
                int cnt = map.get(key);
                map.put(key, cnt+1);
            } else {
                map.put(key, 1);
            }
        });

        return map;
    }

    static void dfs(String s, int i, String r, String b, Consumer<Key> results) {
        if( i == N ) {
            results.accept(new Key(r, b));

        } else {
            char c = s.charAt(i);
            dfs(s, i+1, r + c, b, results);
            dfs(s, i+1, r, b + c, results);
        }
    }

    static class Key {
        String r;
        String b;

        public Key(String r, String b) {
            this.r = r;
            this.b = b;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Key key = (Key) o;
            return Objects.equals(r, key.r) &&
                    Objects.equals(b, key.b);
        }

        @Override
        public int hashCode() {
            return Objects.hash(r, b);
        }

        public String toString() {
            return "(" + r + "," + b +")";
        }
    }

    static String reverse(String s) {
        char[] chars = s.toCharArray();
        for (int i = 0; i < N / 2; i++) {
            char t = chars[i];
            chars[i] = chars[N-i-1];
            chars[N-i-1] = t;
        }

        return new String(chars);
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