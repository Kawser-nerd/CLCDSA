import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        int t = 1;
        Solver s = new Solver();
        for (int i = 1; i <= t; i++) {
            s.solve(i, in, out);
        }
        out.close();
    }

}

class Solver {

    void solve(int test, InputReader in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[] a = new int[n];
        long ans = 0;
        long A = in.nextLong();
        long B = in.nextLong();
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 1; i < n; i++) {
            long d1 = a[i] - a[i - 1];
            d1 *= A;
            ans += Math.min(d1, B);
        }
        out.println(ans);
    }
}

class InputReader {
    BufferedReader br;
    StringTokenizer st;

    public InputReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = null;
    }

    public String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public String nextLine() throws IOException {
        return br.readLine();
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}