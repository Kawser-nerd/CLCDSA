import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
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
        Word[] W = new Word[WLEN];
        int[] chars = new int[26];
        for (int i = 0; i < K; i++) {
            chars[S.charAt(i) - 'a']++;
        }
        W[0] = new Word(0, Arrays.copyOf(chars, 26));
        for (int i = 1; i < WLEN; i++) {
            chars[S.charAt(i+K-1) - 'a']++;
            chars[S.charAt(i-1) - 'a']--;
            W[i] = new Word(i, Arrays.copyOf(chars, 26));
        }

        Comparator<Word> cw = (w1, w2) -> {
            for (int i = 0; i < 26; i++) {
                if( w1.chars[i] != w2.chars[i] ) {
                    return Integer.compare(w1.chars[i], w2.chars[i]);
                }
            }
            return Integer.compare(w1.i, w2.i);
        };
        Arrays.sort(W, cw);

        BiPredicate<Word, Word> p = (w1, w2) -> {
            for (int i = 0; i < 26; i++) {
                if( w1.chars[i] != w2.chars[i] ) {
                    return false;
                }
            }
            return true;
        };

        int i = 0;
        while(i < WLEN) {
            Word first = W[i];
            int j = i+1;
            Word last = null;
            while( j < WLEN ) {
                Word w1 = W[j];
                if( p.test(first, w1) ) {
                    last = w1;
                    j++;
                } else {
                    break;
                }
            }

            if( last != null ) {
                if( last.i >= first.i + K ) {
                    return true;
                } else {
                    i = j;
                }

            } else {
                i++;
            }
        }
        return false;
    }

    static class Word {
        int i; // start
        int[] chars; // 26

        public Word(int i, int[] chars) {
            this.i = i;
            this.chars = chars;
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