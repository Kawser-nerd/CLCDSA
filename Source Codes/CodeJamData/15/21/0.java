
import java.io.*;
import java.util.StringTokenizer;

public class A2 {


    private long solveTest() throws IOException {
        long[] p10 = new long[20];
        p10[0] = 1;
        for (int i = 1; i < 20; i++) {
            p10[i] = p10[i - 1] * 10;
        }
        long n = Long.parseLong(next());
        long x = 1;
        long res = 1;
        int len = ("" + n).length();
        for (int t = 2; t < len; t++) {
            long c = p10[t - 1] + p10[t / 2] - 1;
            res += (c - x + 1);
            x = reverse(c);
//            System.out.println(c + " " + x);
        }
        long res1 = res + (n - x);
        long nn = n / p10[len / 2] * p10[len / 2] + 1;
//        System.out.println(nn + " " + n);
        while (nn > n) {
            nn -= p10[len / 2];
        }
        if (reverse(nn) < x){
            return res1;
        }
        long res2 = res + (reverse(nn) - x) + 1 + (n - nn);
        return Math.min(res1, res2);
    }

    private long reverse(long i) {
        return Long.parseLong(new StringBuffer().append(i).reverse().toString());
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            long res = solveTest();
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
        new A2().run();
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