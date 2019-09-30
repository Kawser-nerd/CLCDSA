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
        BATCoder solver = new BATCoder();
        solver.solve(1, in, out);
        out.close();
    }

    static class BATCoder {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String s = in.next();
            int longest = 0;
            int current = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == 'A' || s.charAt(i) == 'C' || s.charAt(i) == 'G' || s.charAt(i) == 'T') {
                    current++;
                    if (current > longest) {
                        longest = current;
                    }
                } else {
                    current = 0;
                }
            }
            out.println(longest);
        }

    }
}