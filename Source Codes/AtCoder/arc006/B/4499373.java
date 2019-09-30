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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int l = in.nextInt();

            in.nextLine();
            String[] amida = new String[l + 1];
            for (int i = 0; i < l + 1; i++) {
                amida[i] = in.nextLine();
            }

            int pos = amida[l].indexOf('o');
            for (int i = l - 1; i >= 0; i--) {
                String s = amida[i];
                if (pos > 0 && s.charAt(pos - 1) == '-')
                    pos -= 2;
                else if (pos < s.length() - 1 && s.charAt(pos + 1) == '-')
                    pos += 2;
            }

            out.println(pos / 2 + 1);
        }

    }
}