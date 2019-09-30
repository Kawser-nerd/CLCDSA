import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

public class C implements Runnable {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;
    String filename = C.class.getName().substring(0, 1);

    void preSolve() {

    }

    BigInteger[] sign = new BigInteger[255];
    {
        for (int i = 0; i < 10; ++i) {
            sign['0' + i] = BigInteger.valueOf(i);
        }
        sign['+'] = BigInteger.valueOf(0);
        sign['-'] = BigInteger.valueOf(1);
    }

    String conv(BigInteger x) {
        StringBuilder sb = new StringBuilder();
        BigInteger curr = x;
        while (true) {
            BigInteger[] rem = curr.divideAndRemainder(BigInteger.TEN);
            curr = rem[0];
            sb.append(rem[1]);
            if (curr.compareTo(BigInteger.TEN) <= 0) {
                break;
            }
            if (curr.getLowestSetBit() == 0) {
                sb.append('-');
            } else {
                sb.append('+');
            }
            curr = curr.shiftRight(1);
        }
        return sb.reverse().toString();
    }

    BigInteger min(BigInteger a, BigInteger b) {
        BigInteger rv = a == null ? b : b == null ? a : b.min(a);
//        if (a != null && conv(a).compareTo(conv(rv)) < 0) {
//            throw new AssertionError(a + " " + rv + " " + conv(a) + " " + conv(rv));
//        }
//        if (b != null && conv(b).compareTo(conv(rv)) < 0) {
//            throw new AssertionError(b + " " + rv + " " + conv(b) + " " + conv(rv));
//        }
        return rv;
    }

    BigInteger xadd(BigInteger v, char a, char b) {
        return v.shiftLeft(1).add(sign[a]).multiply(BigInteger.TEN).add(sign[b]);
    }

    int vadd(char a, char b) {
        if (a != '+' && a != '-') {
            throw new AssertionError();
        }
        return a == '+' ? (b - '0') : ('0' - b);
    }

    void solve(int testNumber) throws IOException {
        int w = nextInt();
        int q = nextInt();

        char[][] field = new char[w][];
        for (int i = 0; i < w; ++i) {
            field[i] = nextLine().toCharArray();
        }

        int[] queries = new int[q];
        BigInteger[] answers = new BigInteger[q];
        for (int i = 0; i < q; ++i) {
            queries[i] = nextInt();
        }

        int W = 1024, hW = W / 2;

        BigInteger[] trace = new BigInteger[w * w * W];

        int[] x = new int[w * w];
        int[] y = new int[w * w];
        int[][] xy = new int[w][w];
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < w; ++j) {
                int id = i * w + j;
                x[id] = i;
                y[id] = j;
                xy[i][j] = id;
            }
        }

        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < w; ++j) {
                if (field[i][j] >= '0' && field[i][j] <= '9') {
                    int cell = (xy[i][j] << 10) + (field[i][j] - '0' + hW);
                    trace[cell] = BigInteger.valueOf(field[i][j] - '0').add(BigInteger.TEN);
                }
            }
        }

        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};

        int qCount = 0;

        while (qCount < q) {
            for (int i = 0; i < w; ++i) {
                for (int j = 0; j < w; ++j) {
                    int code0 = (xy[i][j] << 10) + hW;

                    for (int val = 0; val < q; ++val) {
                        if (trace[code0 + queries[val]] != null) {
                            if (answers[val] == null) {
                                ++qCount;
                            }
                            answers[val] = min(answers[val], trace[code0 + queries[val]]);
                        }
                    }
                }
            }
            for (int i = 0; i < w; ++i) {
                for (int j = 0; j < w; ++j) {
                    for (int val = 0; val < W; ++val) {
                        if (field[i][j] != '+' && field[i][j] != '-' && trace[(xy[i][j] << 10) + val] != null) {
                            for (int d = 0; d < dx.length; ++d) {
                                int ni = i + dx[d];
                                int nj = j + dy[d];
                                if (ni >= 0 && nj >= 0 && ni < w && nj < w) {
                                    trace[(xy[ni][nj] << 10) + val] = min(
                                            trace[(xy[ni][nj] << 10) + val],
                                            trace[(xy[i][j]   << 10) + val]
                                    );
                                }
                            }
                            trace[(xy[i][j] << 10) + val] = null;
                        }
                    }
                }
            }
            for (int i = 0; i < w; ++i) {
                for (int j = 0; j < w; ++j) {
                    for (int val = 0; val < W; ++val) {
                        if ((field[i][j] == '+' || field[i][j] == '-') && trace[(xy[i][j] << 10) + val] != null) {
                            for (int d = 0; d < dx.length; ++d) {
                                int ni = i + dx[d];
                                int nj = j + dy[d];
                                if (ni >= 0 && nj >= 0 && ni < w && nj < w) {
                                    int nv = val + vadd(field[i][j], field[ni][nj]);
                                    if (nv >= 0 && nv < W) {
                                        trace[(xy[ni][nj] << 10) + nv] = min(
                                                trace[(xy[ni][nj] << 10) + nv],
                                                xadd(trace[(xy[i][j] << 10) + val], field[i][j], field[ni][nj])
                                        );
                                    }
                                }
                            }
                            trace[(xy[i][j] << 10) + val] = null;
                        }
                    }
                }
            }
        }
        out.println("Case #" + testNumber + ":");
        for (int i = 0; i < q; ++i) {
            out.println(conv(answers[i]));
        }
    }

    public void run() {
        try {
            in = new BufferedReader(new FileReader(filename + ".in"));
            out = new PrintWriter(filename + ".out");
            eat(null);

            preSolve();
            int nt = nextInt();
            for (int i = 1; i <= nt; ++i) {
                long t0 = System.currentTimeMillis();
                solve(i);
                t0 = System.currentTimeMillis() - t0;
                System.out.println(i + "/" + nt + " done in " + t0 + " ms.");
            }

            out.close();
            in.close();
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
    }

    void eat(String s) {
        st = s == null ? null : new StringTokenizer(s);
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    int[] nextIntArray() throws IOException {
        int n = nextInt();
        int[] rv = new int[n];
        for (int i = 0; i < n; ++i) {
            rv[i] = nextInt();
        }
        return rv;
    }

    int[] nextIntArrayFromLine() throws IOException {
        StringTokenizer st = new StringTokenizer(nextLine());
        int[] rv = new int[st.countTokens()];
        for (int i = 0; i < rv.length; ++i) {
            rv[i] = Integer.parseInt(st.nextToken());
        }
        return rv;
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    String nextLine() throws IOException {
        eat(null);
        return in.readLine();
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new Thread(new C()).start();
    }
}