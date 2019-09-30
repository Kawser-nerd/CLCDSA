
import java.io.*;
import java.util.StringTokenizer;

public class C {

    private int solveTest() throws IOException {
        int n = nextInt();
        double f = Double.parseDouble(next());
        int[] a = new int[n];
        String s = next();
        for (int i = 0; i < n; i++) {
            a[i] = s.charAt(i) - '0';
        }
        double best = 1e100;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int k = 0;
            for (int j = i; j < n; j++) {
                int l = j - i + 1;
                k += a[j];
                double x = 1.0 * k / l;
                double dif = Math.abs(x - f);
                if (dif < best - 1e-9) {
                    best = dif;
                    res = i;
                }
            }
        }
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
        new C().run();
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