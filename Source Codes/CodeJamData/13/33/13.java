import java.io.*;
import java.util.StringTokenizer;

public class ProblemC {

    public static void main(String[] args) throws Exception {
        new ProblemC();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "C-small-attempt0";

    public ProblemC() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    int[] d, n, w, e, s, delta_d, delta_p, delta_s;
    int[] wall;
    int N, LEN = 10000;

    private void solve() throws Exception {
        int T = nextInt();
        for (int ii = 1; ii <= T; ++ii) {
            out.print("Case #" + ii + ": ");
            N = nextInt();
            d = new int[N];
            n = new int[N];
            w = new int[N];
            e = new int[N];
            s = new int[N];
            delta_d = new int[N];
            delta_p = new int[N];
            delta_s = new int[N];
            for (int i = 0; i < N; ++i) {
                d[i] = nextInt();
                n[i] = nextInt();
                w[i] = nextInt() + LEN / 2;
                e[i] = nextInt() + LEN / 2;
                s[i] = nextInt();
                delta_d[i] = nextInt();
                delta_p[i] = nextInt();
                delta_s[i] = nextInt();
            }
            wall = new int[LEN];
            int ans = 0;
            while (true) {
                int min = Integer.MAX_VALUE;
                for (int i = 0; i < N; ++i) {
                    if (n[i] > 0 && d[i] < min) {
                        min = d[i];
                    }
                }
                if (min == Integer.MAX_VALUE) {
                    break;
                }
                for (int i = 0; i < N; ++i) {
                    if (n[i] > 0 && d[i] == min) {
                        for (int j = w[i]; j < e[i]; ++j) {
                            if (wall[j] < s[i]) {
                                ans++;
                                break;
                            }
                        }
                    }
                }
                for (int i = 0; i < N; ++i) {
                    if (n[i] > 0 && d[i] == min) {
                        for (int j = w[i]; j < e[i]; ++j) {
                            wall[j] = Math.max(wall[j], s[i]);
                        }
                        d[i] += delta_d[i];
                        n[i]--;
                        w[i] += delta_p[i];
                        e[i] += delta_p[i];
                        s[i] += delta_s[i];
                        if (d[i] < 0) {
                            System.err.println("overflow");
                        }
                    }
                }
            }
            out.println(ans);

        }
    }


    private void init() throws FileNotFoundException {
        if (fileName.equals("#Console")) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else if (fileName.equals("#IOtxt")) {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } else {
            in = new BufferedReader(new FileReader(fileName + ".in"));
            out = new PrintWriter(fileName + ".out");
        }
    }


    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }


    private String nextToken() throws IOException {
        while (!tok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            tok = new StringTokenizer(s);
        }
        return tok.nextToken();
    }

}
            