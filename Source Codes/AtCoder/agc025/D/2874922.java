import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
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
        DChoosingPoints solver = new DChoosingPoints();
        solver.solve(1, in, out);
        out.close();
    }

    static class DChoosingPoints {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int d1 = in.nextInt();
            int d2 = in.nextInt();

            int cnt = 0;
            for (int i = 0; i < 2 * n; i++) {
                for (int j = 0; j < 2 * n; j++) {
                    int tmpI = i;
                    int tmpJ = j;
                    int tmpD1 = d1;
                    while (tmpD1 % 4 == 0) {
                        tmpI /= 2;
                        tmpJ /= 2;
                        tmpD1 /= 4;
                    }

                    boolean flg1;
                    if (tmpD1 % 2 == 1) {
                        flg1 = (tmpI + tmpJ) % 2 == 0;
                    } else {
                        flg1 = tmpI % 2 == 0;
                    }

                    tmpI = i;
                    tmpJ = j;
                    int tmpD2 = d2;
                    while (tmpD2 % 4 == 0) {
                        tmpI /= 2;
                        tmpJ /= 2;
                        tmpD2 /= 4;
                    }

                    boolean flg2;
                    if (tmpD2 % 2 == 1) {
                        flg2 = (tmpI + tmpJ) % 2 == 0;
                    } else {
                        flg2 = tmpI % 2 == 0;
                    }

                    if (flg1 && flg2) {
                        out.println(i + " " + j);
                        cnt++;
                        if (cnt == n * n) return;
                    }
                }
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

    }
}