
import java.io.*;
import java.util.StringTokenizer;

public class A {

    private String solveTest() throws IOException {
        char[] s = next().toCharArray();
        int k = nextInt();
        int res = 0;
        for (int i = 0; i <= s.length - k; i++) {
            if (s[i] == '-') {
                res++;
                for (int j = 0; j < k; j++) {
                    s[i + j] = s[i + j] == '+' ? '-' : '+';
                }
            }
        }
        for (int i = 0; i < s.length; i++) {
            if (s[i] == '-') {
                return "IMPOSSIBLE";
            }
        }
        return "" + res;
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            String res = solveTest();
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