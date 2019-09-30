import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ogiekako
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyScanner in = new MyScanner(inputStream);
        MyPrintWriter out = new MyPrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int[][][] P;
        int[][] R;
        int[][] S;
        int[] dx = {0, -1, 0, 1};
        int[] dy = {-1, 0, 1, 0};

        public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
            int N = in.nextInt(), M = in.nextInt(), Q = in.nextInt();
            S = new int[N][M];
            for (int i = 0; i < N; i++) {
                String s = in.next();
                for (int j = 0; j < M; j++) {
                    S[i][j] = s.charAt(j) == '0' ? -1 : -2;
                }
            }
            P = new int[4][N + 2][M + 2];
            R = new int[N + 1][M + 1];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    R[i + 1][j + 1] = R[i + 1][j] + R[i][j + 1] - R[i][j];
                    if (S[i][j] == -2) {
                        dfs(i, j);
                        R[i + 1][j + 1]++;
                    }
                }
            }
            for (int d = 0; d < 4; d++) {
                for (int i = 0; i <= N; i++) {
                    for (int j = 0; j <= M; j++) {
                        if (d % 2 == 0) { // x
                            P[d][i + 1][j] += P[d][i][j];
                        } else {
                            P[d][i][j + 1] += P[d][i][j];
                        }
                    }
                }
            }
            for (int i = 0; i < Q; i++) {
                int x1 = in.nextInt() - 1, y1 = in.nextInt() - 1, x2 = in.nextInt(), y2 = in.nextInt();
                int res = R[x2][y2] - R[x2][y1] - R[x1][y2] + R[x1][y1];
                res += P[0][x2][y1 + 1] - P[0][x1][y1 + 1];
                res += P[1][x1 + 1][y2] - P[1][x1 + 1][y1];
                res += P[2][x2][y2] - P[2][x1][y2];
                res += P[3][x2][y2] - P[3][x2][y1];
                out.println(res);
            }
        }

        private void dfs(int x, int y) {
            S[x][y] = 0;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (0 <= nx && nx < S.length && 0 <= ny && ny < S[0].length && S[nx][ny] == -2) {
                    P[d ^ 2][nx + 1][ny + 1]++;
                    dfs(nx, ny);
                }
            }
        }

    }

    static class MyScanner {
        private final InputStream in;
        private static final int BUFSIZE = 65536;
        int bufLen;
        int bufPtr;
        byte[] buf = new byte[BUFSIZE];
        private char[] strBuf = new char[BUFSIZE];

        public MyScanner(InputStream in) {
            this.in = in;
        }

        public int read() {
            if (bufLen == -1)
                throw new InputMismatchException();
            if (bufPtr >= bufLen) {
                bufPtr = 0;
                try {
                    bufLen = in.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (bufLen <= 0)
                    return -1;
            }
            return buf[bufPtr++];
        }

        public String next() {
            int strLen = 0;
            int c;
            do {
                c = read();
                if (c == -1) throw new NoSuchElementException();
            } while (Character.isWhitespace(c));
            do {
                if (strLen + 1 >= strBuf.length) {
                    char[] tmp = new char[strBuf.length * 2];
                    System.arraycopy(strBuf, 0, tmp, 0, strBuf.length);
                    strBuf = tmp;
                }
                strBuf[strLen++] = (char) c;
                c = read();
            } while (c != -1 && !Character.isWhitespace(c));
            return new String(strBuf, 0, strLen);
        }

        public int nextInt() {
            int c = read();
            if (c == -1) throw new NoSuchElementException();
            while (c != '-' && (c < '0' || '9' < c)) {
                c = read();
                if (c == -1) throw new NoSuchElementException();
            }
            if (c == '-') return -nextInt();
            int res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while ('0' <= c && c <= '9');
            return res;
        }

    }

    static class MyPrintWriter {
        PrintWriter out;

        public MyPrintWriter(OutputStream outputStream) {
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public MyPrintWriter(Writer writer) {
            out = new PrintWriter(writer);
        }

        public void println(int a) {
            out.println(a);
        }

        public void close() {
            out.close();
        }

    }
}