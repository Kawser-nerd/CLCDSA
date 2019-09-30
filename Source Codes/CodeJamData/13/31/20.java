import java.io.*;
import java.util.StringTokenizer;

public class ProblemA {

    public static void main(String[] args) throws Exception {
        new ProblemA();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "A-large";

    public ProblemA() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    private void solve() throws Exception {
        int T = nextInt();
        for (int ii = 1; ii <= T; ++ii) {
            out.print("Case #" + ii + ": ");
            char[] a = nextToken().toCharArray();
            int n = nextInt();
            int ll = 0, lr = 0, r;
            long ans = 0;
            int cur = 0;
            boolean flag = false;
            for (r = 0; r < a.length; ++r) {
                if (isConsonant(a[r])) {
                    cur++;
                    if (cur < n) {
                    } else if (cur == n) {
                        flag = true;
                        lr = r - n + 1;
                    } else {
                        cur = n;
                        ll = lr = r - n + 1;
                    }
                } else {
                    cur = 0;
                }
                if (flag) {
                    ans += lr + 1;
                }
            }
            out.println(ans);
        }
    }

    boolean isConsonant(char c) {
        return !"aeiou".contains(c + "");
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
            