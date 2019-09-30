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
            int[] c = new int[n - 1];
            int[] s = new int[n - 1];
            int[] f = new int[n - 1];


            for (int i = 0; i < n - 1; i++) {
                c[i] = in.nextInt();
                s[i] = in.nextInt();
                f[i] = in.nextInt();
            }

            for (int i = 0; i < n - 1; i++) {
                int time = 0;
                for (int j = i; j < n - 1; j++) {
                    if (time < s[j]) {
                        time = s[j] + c[j];
                    } else {
                        if (time % f[j] != 0) {
                            time += f[j] - (time % f[j]);
                        }
                        time += c[j];
                    }
                }
                out.println(time);
            }

            out.print(0);
        }

    }
}