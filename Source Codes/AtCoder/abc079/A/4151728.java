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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String str = in.nextLine();

            if (str.contains("000")) {
                out.print("Yes");
                return;
            }
            for (int i = 111; i < 1000; i += 111) {
                if (str.contains(String.valueOf(i))) {
                    out.print("Yes");
                    return;
                }
            }

            out.print("No");
        }

    }
}