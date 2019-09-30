import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int[][] A;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        M = fc.nextInt();
        A = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                A[i][j] = fc.nextInt() - 1;
            }
        }
        System.out.println(solve());
    }

    static int solve() {
        int ans = Integer.MAX_VALUE;
        boolean[] removed = new boolean[M];

        // (ppl, spo) -> ??
        int[][] favorites = new int[N][M+1];
        for (int ppl = 0; ppl < N; ppl++) {
            for (int i = 0; i < M; i++) {
                int spo = A[ppl][i];
                favorites[ppl][spo] = i;
            }
            favorites[ppl][M] = Integer.MAX_VALUE/2;
        }

        for (int time = 0; time < M; time++) {
            int[] mostFavorite = new int[N];
            Arrays.fill(mostFavorite, M);

            for (int spo = 0; spo < M; spo++) {
                if( removed[spo] ) continue;

                for (int ppl = 0; ppl < N; ppl++) {
                    if( favorites[ppl][spo] < favorites[ppl][mostFavorite[ppl]] ) {
                        mostFavorite[ppl] = spo;
                    }
                }
            }

            int[] cnt = new int[M];
            for (int ppl = 0; ppl < N; ppl++) {
                cnt[mostFavorite[ppl]]++;
            }
            int max = cnt[0];
            int maxSpo = 0;
            for (int spo = 1; spo < M; spo++) {
                if( cnt[spo] > max ) {
                    max = cnt[spo];
                    maxSpo = spo;
                }
            }

//            System.out.println(Arrays.toString(mostFavorite));
//            System.out.println("maxSpo=" + maxSpo + " cnt=" + max);
//            System.out.println();
            ans = Math.min(max, ans);
            removed[maxSpo] = true;
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