
import java.io.*;
import java.util.StringTokenizer;

public class A {

    private String solveTest() throws IOException {
        int n = nextInt();
        int m = nextInt();
        char[][] a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '?') {
                    a[i][j] = a[i - 1][j];
                }
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '?') {
                    a[i][j] = a[i + 1][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (a[i][j] == '?') {
                    a[i][j] = a[i][j - 1];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = m - 2; j >= 0; j--) {
                if (a[i][j] == '?') {
                    a[i][j] = a[i][j + 1];
                }
            }
        }
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; i++) {
            res.append("\n").append(new String(a[i]));
        }
        return res.toString();
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