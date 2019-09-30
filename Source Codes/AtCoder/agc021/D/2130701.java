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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyScan in = new MyScan(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, MyScan in, PrintWriter out) {
            String s = in.next();
            int k = in.nextInt();
            int[][][] pos = new int[k + 1][s.length() + 1][s.length()];

            for (int i = 0; i < s.length(); i++) {
                pos[0][1][i] = 1;
            }
            for (int r = 2; r <= s.length(); r++) {
                for (int l = 0; l <= s.length() - r; l++) {
                    int e = l + r - 1;
                    boolean match = s.charAt(l) == s.charAt(e);
                    if (match) {
                        for (int i = 0; i <= k; i++) {
                            pos[i][r][l] = Math.max(2 + pos[i][r - 2][l + 1], pos[i][r][l]);
                        }
                    } else {
                        for (int i = 0; i <= k; i++) {
                            pos[i][r][l] = Math.max(pos[i][r][l], pos[i][r - 1][l]);
                            pos[i][r][l] = Math.max(pos[i][r - 1][l + 1], pos[i][r][l]);
                        }
                        for (int i = 0; i < k; i++) {
                            pos[i + 1][r][l] = Math.max(pos[i + 1][r][l], 2 + pos[i][r - 2][l + 1]);
                        }
                    }
                }
            }
            int max = 0;
            for (int l = 0; l <= k; l++) {
                max = Math.max(max, pos[l][s.length()][0]);
            }
            out.println(max);


        }

    }

    static class MyScan {
        BufferedReader br;
        StringTokenizer st;

        MyScan(BufferedReader br) {
            this.br = br;
        }

        public MyScan(InputStream in) {
            this(new BufferedReader(new InputStreamReader(in)));
        }

        public void findToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }

        public String next() {
            findToken();
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}