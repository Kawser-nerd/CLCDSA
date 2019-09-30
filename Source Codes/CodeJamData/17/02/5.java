import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Chiaki.Hoshinomori
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] s = in.next().toCharArray();
            long ret = 0;
            int n = s.length;
            for (int i = 1; i < n; i++) {
                ret = ret * 10 + 9;
            }
            int last = 0;
            long now = 0;
            boolean flag = true;
            for (int i = 0; i < n; i++) {
                for (int d = last; d < s[i] - '0'; ++d) {
                    long tmp = now * 10 + d;
                    for (int j = 0; j < n - i - 1; ++j) {
                        tmp = tmp * 10 + 9;
                    }
                    ret = Math.max(ret, tmp);
                }
                if (s[i] - '0' < last) {
                    flag = false;
                    break;
                }
                last = s[i] - '0';
                now = now * 10 + s[i] - '0';
            }
            if (flag) ret = now;
            out.printf("Case #%d: %d\n", testNumber, ret);
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

    }
}

