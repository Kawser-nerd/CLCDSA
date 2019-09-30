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
            int h = in.nextInt();
            int w = in.nextInt();

            int[][] map = new int[10][10];
            int[][] a = new int[h][w];

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    map[i][j] = in.nextInt();
                }
            }

            //??????????
            for (int k = 0; k < 10; k++) {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        map[i][j] = Math.min(map[i][j], map[i][k] + map[k][j]);
                    }
                }
            }

            int ans = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    int next = in.nextInt();
                    if (next != -1) {
                        ans += map[next][1];
                    }
                }
            }

            out.print(ans);


        }

    }
}