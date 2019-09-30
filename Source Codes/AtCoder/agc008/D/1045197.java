import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    void solve() throws IOException {
        int n = ni();
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = ni() - 1;
        }

        PriorityQueue<Pair> Q = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            if (i > 0) Q.add(new Pair(i + 1, x[i] - 1, i));
        }

        int[] ans = new int[n * n];
        for (int i = 0; i < n; i++) {
            ans[x[i]] = i + 1;
        }

        for (int i = 0; i < n * n; i++) {
            if (ans[i] != 0) continue;

            Pair p = Q.poll();
            if (p.y < i) {
                out.println("No");
                return;
            }

            ans[i] = p.x;
            if (p.z > 1) {
                Q.add(new Pair(p.x, p.y, p.z - 1));
            }

            if (Q.isEmpty()) break;
        }

        if (!Q.isEmpty()) {
            out.println("No");
            return;
        }

        Q = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < n; i++) {
            if (i < n - 1) Q.add(new Pair(i + 1, x[i] + 1, n - 1 - i));
        }

        for (int i = n * n - 1; i >= 0; i--) {
            if (ans[i] != 0) continue;

            Pair p = Q.poll();
            if (p.y > i) {
                out.println("No");
                return;
            }

            ans[i] = p.x;
            if (p.z > 1) {
                Q.add(new Pair(p.x, p.y, p.z - 1));
            }

            if (Q.isEmpty()) break;
        }

        if (!Q.isEmpty()) {
            out.println("No");
            return;
        }

        out.println("Yes");
        for (int i = 0; i < n * n; i++) {
            if (i > 0) out.print(" ");
            out.print(ans[i]);
        }
        out.println();
    }

    public class Pair implements Comparable<Pair> {
    	int x, y, z;

    	Pair(int x, int y, int z) {
    		this.x = x;
    		this.y = y;
    		this.z = z;
    	}

    	public int compareTo(Pair p) {
    		return y - p.y;
    	}
    }

    String ns() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine(), " ");
        }
        return tok.nextToken();
    }

    int ni() throws IOException {
        return Integer.parseInt(ns());
    }

    long nl() throws IOException {
        return Long.parseLong(ns());
    }

    double nd() throws IOException {
        return Double.parseDouble(ns());
    }

    String[] nsa(int n) throws IOException {
        String[] res = new String[n];
        for (int i = 0; i < n; i++) {
            res[i] = ns();
        }
        return res;
    }

    int[] nia(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = ni();
        }
        return res;
    }

    long[] nla(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nl();
        }
        return res;
    }

    class INA {
        int[][] a;

        INA(int n, int m) throws IOException {
            this(n, m, -1);
        }

        INA(int n, int m, int t) throws IOException {
            a = new int[m][n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[j][i] = ni() + t;
                }
            }
        }

        int[] get(int i) {
            return a[i - 1];
        }
    }

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        tok = new StringTokenizer("");
        Main main = new Main();
        main.solve();
        out.close();
    }
}