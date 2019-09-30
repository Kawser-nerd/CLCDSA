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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();

            String[] map = new String[n];
            long[][] point = new long[n][11];

            for (int i = 0; i < n; i++) {
                String str = "";
                for (int j = 0; j < 10; j++) {
                    str += in.next();
                }
                map[i] = str;
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 11; j++) {
                    point[i][j] = in.nextLong();
                }
            }
            long ans = Long.MIN_VALUE;
            for (int i = 1; i < 1024; i++) {
                long p = 0;
                for (int j = 0; j < n; j++) {
                    String str = map[j];
                    int dec = Integer.parseInt(str, 2);
                    int cnt = Integer.bitCount(dec & i);
                    p += point[j][cnt];
                }
                ans = Math.max(ans, p);
            }

            out.print(ans);


        }

    }
}