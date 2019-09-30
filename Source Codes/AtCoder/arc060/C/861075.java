import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA60E solver = new TaskA60E();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA60E {
        int MAX = 20;
        int N;
        int[] x;
        int L;
        int Q;
        int[][] right;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            N = in.nextInt();
            x = new int[N + 1];

            for (int i = 1; i <= N; i++) {
                x[i] = in.nextInt();
            }
            L = in.nextInt();
            Q = in.nextInt();
            right = new int[MAX][N + 1];


            for (int i = 1; i <= N; i++) {
                int idx = Arrays.binarySearch(x, x[i] + L);
                right[0][i] = (idx >= 0) ? idx : -idx - 1 - 1;
            }


            for (int i = 1; i < MAX; i++) {
                for (int j = 0; j <= N; j++) {
                    right[i][j] = right[i - 1][right[i - 1][j]];
                }
            }

            for (int q = 1; q <= Q; q++) {
                int _u = in.nextInt();
                int _v = in.nextInt();

                int u = Math.min(_u, _v);
                int v = Math.max(_u, _v);

                int r = 0;
                for (int i = MAX - 1; i >= 0; i--) {
                    if (right[i][u] < v) {
                        u = right[i][u];
                        r += (1 << i);
                    }
                }
                out.println(r + 1);
            }
        }

    }
}