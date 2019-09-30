import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;

    public void solveOne(String prefix) throws IOException {
        int r = nextInt();
        int c = nextInt();
        int d = nextInt();
        int[][] mass = new int[r][c];
        for (int i = 0; i < r; ++i) {
            String s = next();
            for (int j = 0; j < c; ++j) {
                mass[i][j] = d + s.charAt(j) - '0';
            }
        }
        long[][] s1 = new long[r + 1][c + 1];
        long[][] sr = new long[r + 1][c + 1];
        long[][] sc = new long[r + 1][c + 1];
        for (int i = 0; i < r; ++i) {
            long r1 = 0;
            long rr = 0;
            long rc = 0;
            for (int j = 0; j < c; ++j) {
                r1 += mass[i][j];
                rr += mass[i][j] * i;
                rc += mass[i][j] * j;
                s1[i + 1][j + 1] = s1[i][j + 1];
                sr[i + 1][j + 1] = sr[i][j + 1];
                sc[i + 1][j + 1] = sc[i][j + 1];
                s1[i + 1][j + 1] += r1;
                sr[i + 1][j + 1] += rr;
                sc[i + 1][j + 1] += rc;
            }
        }
        for (int k = Math.min(r, c); k >= 3; --k) {
            for (int minR = 0, maxR = k, maxR1 = k - 1; maxR <= r; ++minR, ++maxR, ++maxR1) {
                for (int minC = 0, maxC = k, maxC1 = k - 1; maxC <= c; ++minC, ++maxC, ++maxC1) {
                    long v1 = s1[maxR][maxC] - s1[maxR][minC] - s1[minR][maxC] + s1[minR][minC];
                    long vr = sr[maxR][maxC] - sr[maxR][minC] - sr[minR][maxC] + sr[minR][minC];
                    long vc = sc[maxR][maxC] - sc[maxR][minC] - sc[minR][maxC] + sc[minR][minC];
                    v1 -= mass[minR][minC] + mass[minR][maxC1] + mass[maxR1][minC] + mass[maxR1][maxC1];
                    vr -= mass[minR][minC] * minR + mass[minR][maxC1] * minR + mass[maxR1][minC] * maxR1 +
                            mass[maxR1][maxC1] * maxR1;
                    vc -= mass[minR][minC] * minC + mass[minR][maxC1] * maxC1 + mass[maxR1][minC] * minC +
                            mass[maxR1][maxC1] * maxC1;
                    int midR2 = minR + maxR1;
                    int midC2 = minC + maxC1;
                    if (v1 * midR2 == 2 * vr && v1 * midC2 == 2 * vc) {
                        out.println(prefix + k);
                        return;
                    }
                }
            }
        }
        out.println(prefix + "IMPOSSIBLE");
    }

    public void run() throws IOException {
        in = new BufferedReader(new FileReader(B.class.getSimpleName() + ".in"));
        out = new PrintWriter(B.class.getSimpleName() + ".out");

        int nTests = nextInt();

        for (int i = 1; i <= nTests; ++i) {
            solveOne(String.format("Case #%d: ", i));
        }

        out.close();
        in.close();
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }
}
