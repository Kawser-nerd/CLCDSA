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
 * @author Mirio
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FReader in = new FReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int k2 = k * 2;

            TaskD.PrefixMatrix preB = new TaskD.PrefixMatrix(k2);
            TaskD.PrefixMatrix preW = new TaskD.PrefixMatrix(k2);

            for(int i = 0; i < n; ++i) {
                int x = (in.nextInt() % k2);
                int y = (in.nextInt() % k2);

                if(in.next().charAt(0) == 'B')
                    preB.update(x, y);
                else
                    preW.update(x, y);
            }
            preB.generatePrefix();
            preW.generatePrefix();

            int ans = 0;
            for(int offsetX = 0; offsetX <= k; ++offsetX) {
                for(int offsetY = 0; offsetY <= k; ++offsetY) {
                    int pAns = 0, bx, by, wx, wy;

                    bx = 0 + offsetX;
                    by = 0 + offsetY;
                    pAns += preB.get(bx, by, bx + k - 1, by + k - 1);

                    bx = k + offsetX;
                    by = k + offsetY;
                    pAns += preB.get(bx, by, k2 - 1, k2 - 1);
                    if(offsetY != 0 && offsetX == 0) {
                        pAns += preB.get(bx, 0, k2 - 1, offsetY - 1);
                    } else if(offsetY == 0 && offsetX != 0) {
                        pAns += preB.get(0, by, offsetX - 1, k2 - 1);
                    } else if(offsetY != 0 && offsetX != 0) {
                        pAns += preB.get(bx, 0, k2 - 1, offsetY - 1);
                        pAns += preB.get(0, by, offsetX - 1, k2 - 1);
                        pAns += preB.get(0, 0, offsetX - 1, offsetY - 1);
                    }

                    wx = 0 + offsetX;
                    wy = k + offsetY;
                    pAns += preW.get(wx, wy, wx + k - 1, k2 - 1);
                    if(offsetY != 0 && offsetX == 0) {
                        pAns += preW.get(0, 0, k - 1, offsetY - 1);
                    } else if(offsetY != 0 && offsetX != 0) {
                        pAns += preW.get(wx, 0, wx + k - 1, offsetY - 1);
                    }

                    wx = k + offsetX;
                    wy = 0 + offsetY;
                    pAns += preW.get(wx, wy, k2 - 1, wy + k - 1);
                    if(offsetY == 0 && offsetX != 0) {
                        pAns += preW.get(0, 0, offsetX - 1, k - 1);
                    } else if(offsetY != 0 && offsetX != 0) {
                        pAns += preW.get(0, wy, offsetX - 1, wy + k - 1);
                    }

                    ans = Math.max(ans, Math.max(n - pAns, pAns));
                }
            }

            out.println(ans);
        }

        private static class PrefixMatrix {
            private int[][] pre;
            private int     N;

            public PrefixMatrix() {}

            public PrefixMatrix(int n) {
                N = n + 5;
                pre = new int[N + 1][N + 1];
            }

            public void generatePrefix() {
                for(int i = 1; i <= N; ++i)
                    for(int j = 1; j <= N; ++j)
                        pre[i][j] += pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
            }

            public int get(int x, int y, int nx, int ny) {
                if(nx < x || ny < y)
                    return 0;

                ++x;
                ++y;
                ++nx;
                ++ny;

                return pre[nx][ny] - pre[nx][y - 1] - pre[x - 1][ny] + pre[x - 1][y - 1];
            }

            public void update(int x, int y) {
                ++pre[x + 1][y + 1];
            }

        }

    }

    static class FReader {
        private BufferedReader  r;
        private String          line;
        private StringTokenizer st;
        private String          token;

        public FReader() {
            this(System.in);
        }

        public FReader(InputStream i) {
            r = new BufferedReader(new InputStreamReader(i));
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public String next() {
            return nextToken();
        }

        private String peekToken() {
            if(token == null)
                try {
                    while(st == null || !st.hasMoreTokens()) {
                        line = r.readLine();
                        if(line == null) return null;
                        st = new StringTokenizer(line);
                    }
                    token = st.nextToken();
                } catch(IOException e) { }
            return token;
        }

        private String nextToken() {
            String ans = peekToken();
            token = null;
            return ans;
        }

    }
}