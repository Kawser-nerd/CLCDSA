import java.io.*;
import java.math.*;
import java.util.*;
 
public class Main {
    private static boolean debug = false;
    private static boolean elapsed = true;
 
    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);
 
    private static class Question {
        int x1;
        int y1;
        int x2;
        int y2;
    }
    private void solve(BufferedReader in) throws IOException {
        String[] tokens;
        tokens = in.readLine().split(" ");
        int N = Integer.parseInt(tokens[0]);
        int M = Integer.parseInt(tokens[1]);
        int Q = Integer.parseInt(tokens[2]);
        boolean[][] S = new boolean[N][M];
        for (int i = 0; i < N; ++i) {
            String s = in.readLine();
            for (int j = 0; j < M; ++j) {
                S[i][j] = (s.charAt(j) == '1');
            }
        }
        List<Question> list = new ArrayList<>();
        for (int i = 0; i < Q; ++i) {
            tokens = in.readLine().split(" ");
 
            Question q = new Question();
            q.x1 = Integer.parseInt(tokens[0]);
            q.y1 = Integer.parseInt(tokens[1]);
            q.x2 = Integer.parseInt(tokens[2]);
            q.y2 = Integer.parseInt(tokens[3]);
            list.add(q);
        }
 
        boolean[][] edgeX = new boolean[N][M];
        boolean[][] edgeY = new boolean[N][M];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                edgeX[i][j] = (S[i][j] && i > 0 && S[i - 1][j]);
                edgeY[i][j] = (S[i][j] && j > 0 && S[i][j - 1]);
            }
        }
 
        CumulativeSum cs1 = new CumulativeSum(S, N, M);
        CumulativeSum cs2 = new CumulativeSum(edgeX, N, M);
        CumulativeSum cs3 = new CumulativeSum(edgeY, N, M);
 
        for (Question q : list) {
            _out.println(
                cs1.getSum(q.x1 - 1, q.x2, q.y1 - 1, q.y2)
                - cs2.getSum(q.x1, q.x2, q.y1 - 1, q.y2)
                - cs3.getSum(q.x1 - 1, q.x2, q.y1, q.y2));
        }
    }
    private static class CumulativeSum {
        int[][] sum;
        public CumulativeSum(boolean[][] b, int n, int m) {
            sum = new int[n + 1][m + 1];
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (b[i - 1][j - 1] ? 1 : 0);
                }
            }
        }
        public int getSum(int t, int b, int l, int r) {
            return sum[b][r] - sum[b][l] - sum[t][r] + sum[t][l];
        }
    }
    private static BigInteger C(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        for (long i = r; i > 1; --i) {
            res = res.divide(BigInteger.valueOf(i));
        }
        return res;
    }
    private static BigInteger P(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }
    /*
     * 10^10 > Integer.MAX_VALUE = 2147483647 > 10^9
     * 10^19 > Long.MAX_VALUE = 9223372036854775807L > 10^18
     */
    public static void main(String[] args) throws IOException {
        long S = System.currentTimeMillis();
 
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        new Main().solve(in);
        _out.flush();
 
        long G = System.currentTimeMillis();
        if (elapsed) {
            _err.println((G - S) + "ms");
        }
        _err.flush();
    }
}