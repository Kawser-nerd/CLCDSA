import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;
import java.util.function.BiPredicate;
import java.util.function.Predicate;

public class Main {

    static int N, K;
    static String S;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        K = fc.nextInt();
        S = fc.next();
        System.out.println(solve() ? "YES" : "NO");
    }

    static boolean solve() {
        int WLEN = N-K+1;
        int[] chars = new int[26];
        for (int i = 0; i < K; i++) {
            chars[S.charAt(i) - 'a']++;
        }
        Map<Word, MinMax> map = new HashMap<>();
        map.put( new Word(Arrays.copyOf(chars, 26)), new MinMax(0) );
        for (int i = 1; i < WLEN; i++) {
            chars[S.charAt(i+K-1) - 'a']++;
            chars[S.charAt(i-1) - 'a']--;
            Word w = new Word(Arrays.copyOf(chars, 26));

            MinMax mm = map.get(w);
            if( mm != null ) {
                mm.add(i);
            } else {
                map.put(w, new MinMax(i));
            }
        }

        for (MinMax mm : map.values()) {
            if( mm.max >= mm.min + K ) return true;
        }
        return false;
    }

    static class MinMax {
        int min, max;
        public MinMax(int i) {
            min = i;
            max = i;
        }

        public void add(int i) {
            min = Math.min(i, min);
            max = Math.max(i, max);
        }
    }

    static class Word {
        int[] chars; // 26

        public Word(int[] chars) {
            this.chars = chars;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Word word = (Word) o;
            return Arrays.equals(chars, word.chars);
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(chars);
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