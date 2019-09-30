import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int K;
    static char[] S;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        S = sc.next().toCharArray();

        System.out.println(solve());
    }

    static String solve() {
        char[] T = Arrays.copyOf(S, N);


        int[] last = new int[26];
        for (int i = 0; i < N; i++) {
            last[S[i]-'a']++;
        }

        int i = 0;
        lo: while(i < N) {
            ch: for (char c = 'a'; c <= 'z'; c++) {
                if( T[i] == c ) {
                    i++;
                    last[c - 'a']--;
                    continue lo;
                }

                if( last[c - 'a'] == 0 ) {
                    continue ch;
                }

                for (int j = i+1; j < N; j++) {
                    if( T[j] == c ) {
                        swap(T, i, j);
                        if( count(T, i) > K ) {
                            swap(T, i, j);
                        } else {
                            i++;
                            continue lo;
                        }
                    }
                }
            }
        }

        return new String(T);
    }

    // [0, fixed] ?????, [fixed+1, N)?????ok
    static int count(char[] T, int fixed) {
        int d1 = 0;
        // ??????
        for (int i = 0; i <= fixed; i++) {
            if( S[i] != T[i] ) d1++;
        }
        // ????????????
        int[] cnt_s = new int[26];
        int[] cnt_t = new int[26];

        for (int i = fixed+1; i < N; i++) {
            cnt_s[S[i]-'a']++;
            cnt_t[T[i]-'a']++;
        }

        int minsum = 0;
        for (int i = 0; i < 26; i++) {
            minsum += Math.min(cnt_s[i], cnt_t[i]);
        }
        int d2 = N - (fixed+1) - minsum;

        return d1 + d2;
    }

    static void swap(char[] chars, int i, int j) {
        char t = chars[i];
        chars[i] = chars[j];
        chars[j] = t;
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