
import java.io.*;
import java.util.StringTokenizer;

public class A {

    private int solveTest() throws IOException {
        String s = next();
        int n = s.length();
        char[] ss = new char[n];
        int m = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            ss[m++] = s.charAt(i);
            if (m >= 2 && ss[m - 1] == ss[m - 2]) {
                m -= 2;
                res += 10;
            }
        }
        res += m / 2 * 5;
        return res;
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            int res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new A().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName().substring(0, 1) + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName().substring(0, 1) + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

}