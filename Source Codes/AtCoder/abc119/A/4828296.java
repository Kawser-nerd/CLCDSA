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
        TaskAtCoder119 solver = new TaskAtCoder119();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskAtCoder119 {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            if (in.next().compareTo("2019/04/30") <= 0)
                out.println("Heisei");
            else
                out.println("TBD");
        }

    }
}