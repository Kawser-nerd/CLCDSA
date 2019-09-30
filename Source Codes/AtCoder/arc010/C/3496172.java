import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N, M, Y, Z;
    static int[] CP, CI;
    static int[] CTOI;
    static char[] B;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        Y = sc.nextInt();
        Z = sc.nextInt();
        CP = new int[26];
        CI = new int[26];
        for (int i = 0; i < M; i++) {
            char c = sc.next().charAt(0);
            CP[c - 'A'] = sc.nextInt();
            CI[c - 'A'] = i;
        }
        B = sc.next().toCharArray();

        System.out.println(solve());
    }

    static final int INF = Integer.MIN_VALUE / 2;

    static int solve() {
        int[][] prev = new int[1<<M][M+1];
        int[][] curr = new int[1<<M][M+1];
        for (int[] arr : prev) Arrays.fill(arr, INF);
        for (int[] arr : curr) Arrays.fill(arr, INF);
        curr[0][M] = 0;

        for (char b : B) {
            int[][] t = prev;
            prev = curr;
            curr = t;
            for (int[] arr : curr) Arrays.fill(arr, INF);

            int cp = CP[b - 'A'];
            int ci = CI[b - 'A'];
            for (int s = 0; s < 1<<M; s++) {
                for (int prevCi = 0; prevCi <= M; prevCi++) {
                    if( prev[s][prevCi] == INF ) continue;

                    // ??
                    int point = prev[s][prevCi];
                    point += cp;
                    if( ci == prevCi ) point += Y;
                    curr[s | (1 << ci)][ci] = Math.max(curr[s | (1 << ci)][ci], point);

                    // ????
                    curr[s][prevCi] = Math.max(prev[s][prevCi], curr[s][prevCi]);
                }
            }

//            for (int s = 0; s < 1 << M; s++) {
//                for (int i = 0; i <= M; i++) {
//                    if( curr[s][ci] != INF ) {
//                        System.out.println(Integer.toBinaryString(s) + " " + i + " " + curr[s][ci]);
//                    }
//                }
//            }
        }
        int all = (1 << M) - 1;
        for (int ci = 0; ci <= M; ci++) {
            if( curr[all][ci] != INF ) {
                curr[all][ci] += Z;
            }
        }
        
        int ans = INF;
        for (int s = 0; s < 1 << M; s++) {
            for (int ci = 0; ci <= M; ci++) {
                ans = Math.max( curr[s][ci], ans );
            }
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