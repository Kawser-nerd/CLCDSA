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

    static final long MODULO = (long) (1e9 + 7);

    void solve(int test, InputReader in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[] p = new int[(int) (1e3 + 7)];
        for (int i = 2; i < p.length; i++) {
            if (p[i] == 0)
            for (int j = i; j < p.length; j += i) p[j] = i;
        }
        long ans = 1;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 2; i <= n; i++) {
            HashMap<Integer, Integer> m = getFactors(i, p);
            map = merge(m, map);
        }
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) ans = (ans * (entry.getValue() + 1)) % MODULO;
        out.println(ans);
    }

    private HashMap<Integer, Integer> merge(HashMap<Integer, Integer> m, HashMap<Integer, Integer> map) {
        for (Map.Entry<Integer, Integer> entry : m.entrySet()) {
            if (map.containsKey(entry.getKey())) map.put(entry.getKey(), map.get(entry.getKey()) + entry.getValue());
            else map.put(entry.getKey(), entry.getValue());
        }
        return map;
    }

    private HashMap<Integer, Integer> getFactors(int i, int[] p) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int x = i;
        while (x > 1) {
            int j = p[x];
            int exp = 0;
            while (x % j == 0) {
                x /= j;
                exp++;
            }
            map.put(j, exp);
        }
        return map;
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