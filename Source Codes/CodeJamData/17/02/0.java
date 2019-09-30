
import java.io.*;
import java.util.StringTokenizer;

public class B {

    private String solveTest() throws IOException {
        String s = next();

        int i = 0;
        while (i < s.length() - 1 && s.charAt(i + 1) >= s.charAt(i)) {
            i++;
        }
        if (i == s.length() - 1) return s;

        while (i > 0 && s.charAt(i - 1) == s.charAt(i)) i--;

        String res = "";
        for (int j = 0; j < s.length(); j++) {
            res += j < i ? s.charAt(j) : j == i ? (char)(s.charAt(j) - 1) : '9';
        }
        if (res.charAt(0) == '0') res = res.substring(1);
        return res;
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
        new B().run();
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