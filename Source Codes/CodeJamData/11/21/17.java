import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class R1 {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;

    public void solveOne(String prefix) throws IOException {
        int size = nextInt();
        int[][] g = new int[size][size];
        for (int i = 0; i < size; ++i) {
            String line = next();
            for (int j = 0; j < size; ++j) {
                char c = line.charAt(j);
                if (c == '0') {
                    g[i][j] = -1;
                    g[j][i] = 1;
                } else if (c == '1') {
                    g[i][j] = 1;
                    g[j][i] = -1;
                }
            }
        }
        double[] wp = new double[size];
        double[] owp = new double[size];
        double[] oowp = new double[size];
        double[][] wpx = new double[size][size];

        for (int i = 0; i < size; ++i) {
            int count = 0;
            int sum = 0;
            for (int j = 0; j < size; ++j) {
                if (g[i][j] != 0) {
                    ++count;
                    if (g[i][j] == 1) {
                        ++sum;
                    }
                }
            }
            wp[i] = (double) (sum) / count;
            for (int j = 0; j < size; ++j) {
                if (g[i][j] == 0) {
                    wpx[i][j] = wp[i];
                } else {
                    wpx[i][j] = (double) (sum - (g[i][j] == 1 ? 1 : 0)) / (count - 1);
                }
            }
        }
        for (int i = 0; i < size; ++i) {
            double sum = 0;
            int count = 0;
            for (int j = 0; j < size; ++j) {
                if (g[i][j] != 0) {
                    ++count;
                    sum += wpx[j][i];
                }
            }
            owp[i] = sum / count;
        }
        for (int i = 0; i < size; ++i) {
            double sum = 0;
            int count = 0;
            for (int j = 0; j < size; ++j) {
                if (g[i][j] != 0) {
                    ++count;
                    sum += owp[j];
                }
            }
            oowp[i] = sum / count;
        }
        out.println(prefix);
        for (int i = 0; i < size; ++i) {
            out.println(0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]);
        }
    }

    public void run() throws IOException {
        in = new BufferedReader(new FileReader("A.in"));
        out = new PrintWriter("A.out");

        int nTests = nextInt();

        for (int i = 1; i <= nTests; ++i) {
            solveOne(String.format("Case #%d:", i));
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
        new R1().run();
    }
}
