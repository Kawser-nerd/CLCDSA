import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int h = in.nextInt();
            int w = in.nextInt();
            int[][] a = in.nextIntArrayArray(h, w);

            List<String> answers = new ArrayList<>();
            for (int i = 0; i < h * w - 1; i++) {
                int y = i / w;
                int x = i % w;

                if (y % 2 != 0) x = w - 1 - x;
                if (a[y][x] % 2 == 0) continue;

                if ((i + 1) % w == 0) {
                    answers.add((y + 1) + " " + (x + 1) + " " + (y + 2) + " " + (x + 1));
                    a[y + 1][x]++;
                } else if (y % 2 == 0) {
                    answers.add((y + 1) + " " + (x + 1) + " " + (y + 1) + " " + (x + 2));
                    a[y][x + 1]++;
                } else {
                    answers.add((y + 1) + " " + (x + 1) + " " + (y + 1) + " " + x);
                    a[y][x - 1]++;
                }
            }

            out.println(answers.size());
            for (String s : answers) {
                out.println(s);
            }
        }

    }

    static class InputReader {
        private BufferedReader br;
        private StringTokenizer st;

        public InputReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
            st = new StringTokenizer("");
        }

        public String nextString() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public int[] nextIntArray(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        public int[][] nextIntArrayArray(int n, int m) {
            int[][] res = new int[n][m];
            for (int i = 0; i < n; i++) {
                res[i] = nextIntArray(m);
            }
            return res;
        }

    }
}