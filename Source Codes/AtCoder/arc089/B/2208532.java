import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            final int n = in.nextInt();
            final int k = in.nextInt();
            int[][] field = new int[k * 4 + 1][k * 4 + 1];
            for (int i = 0; i < n; i++) {
                int cx = in.nextInt();
                int cy = in.nextInt();
                char cc = in.next().charAt(0);
                if (cc == 'B') {
                    cy += k;
                }
                cx %= (k * 2);
                cy %= (k * 2);

                field[cx][cy]++;
                field[cx + k][cy]--;
                field[cx][cy + k]--;
                field[cx + k][cy + k]++;

                cx += k;
                cy += k;
                field[cx][cy]++;
                field[cx + k][cy]--;
                field[cx][cy + k]--;
                field[cx + k][cy + k]++;
            }
            for (int i = 0; i < 4 * k; i++) {
                for (int j = 0; j < 4 * k - 1; j++) {
                    field[i][j + 1] += field[i][j];
                }
            }
            for (int i = 0; i < 4 * k - 1; i++) {
                for (int j = 0; j < 4 * k; j++) {
                    field[i + 1][j] += field[i][j];
                }
            }

            int[][] sum = new int[2 * k][2 * k];
            for (int i = 0; i < 2 * k; i++) {
                for (int j = 0; j < 2 * k; j++) {
                    sum[i][j] += field[i][j] + field[i + (2 * k)][j] + field[i][j + (2 * k)] + field[i + (2 * k)][j + (2 * k)];
                }
            }

            int max = 0;
            for (int x = 0; x < k * 2; x++) for (int y = 0; y < k * 2; y++) if (sum[x][y] > max) max = sum[x][y];
            out.println(max);
        }

    }
}