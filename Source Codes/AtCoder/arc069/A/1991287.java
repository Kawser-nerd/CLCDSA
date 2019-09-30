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
        long n = in.nextLong();
        long m = in.nextLong();
        long low = 0, high = (long) 1e15;
        long ans = 0;
        while (low <= high) {
            long mid = (low + high) / 2;
            if (can(mid, n, m)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        out.println(ans);
    }

    private boolean can(long groups, long s, long c) {
        long rc = groups * 2;
        if (s >= groups && c >= rc) return true;
        if (c < rc) return false;
        long mr = groups - s;
        c -= 2 * mr;
        s += mr;
        return s >= groups && c >= rc;
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