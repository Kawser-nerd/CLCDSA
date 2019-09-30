import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author kishore
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.nextLine();
            if (s.length() >= 2) {
                for (int i = 0; i < s.length() - 1; i++) {
                    if (s.charAt(i) == s.charAt(i + 1)) {
                        out.println((i + 1) + " " + (i + 2));
                        return;
                    }
                    if (i + 2 < s.length() && s.charAt(i) == s.charAt(i + 2)) {
                        out.println((i + 1) + " " + (i + 3));
                        return;
                    }
                }

            }
            out.println("-1 -1");
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }

    }
}