import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] s = in.nextLine().toCharArray();
            int ans = s.length;
            for (int i = 0; i < s.length - 1; i++)
                if (s[i] != s[i + 1])
                    ans = Math.min(ans, Math.max(i + 1, s.length - i - 1));
            out.println(ans);
        }

    }

    static class InputReader {
        BufferedReader br;

        public InputReader(InputStream is) {
            BufferedReader br = new BufferedReader(new InputStreamReader(is));
            this.br = br;
        }

        public String nextLine() {
            String str = null;
            try {
                str = br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            return str;
        }

    }
}