import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Solution {
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }
    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    void solve() throws IOException {
        st = new StringTokenizer(in.readLine(), "/");
        long p = nextLong();
        long q = nextLong();
        long gcd = BigInteger.valueOf(p).gcd(BigInteger.valueOf(q)).longValue();
        long qq = q / gcd;
        if ((qq & (qq - 1)) == 0) {
            p /= gcd;
            int ans = 1;
            while (p < qq / 2) {
                ans++;
                qq /= 2;
            }
            out.println(ans);
        } else {
            out.println("impossible");
        }
    }

    void run() {
        try {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
            //in = new BufferedReader(new InputStreamReader(System.in));
            //out = new PrintWriter(System.out);
            Locale.setDefault(Locale.UK);
            int tt = nextInt();
            for (int t = 1; t <= tt; t++) {
                out.print("Case #" + t + ": ");
                solve();
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            out.close();
        }
    }

    public static void main(String Args[]) {
        new Solution().run();
    }
}