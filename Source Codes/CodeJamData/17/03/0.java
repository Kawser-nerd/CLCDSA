
import java.io.*;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class C {

    private String solveTest() throws IOException {
        long n = Long.parseLong(next());
        long k = Long.parseLong(next()) - 1;
        TreeMap<Long, Long> q = new TreeMap<>();
        q.put(n, 1L);
        while (k > 0) {
            long max = q.lastKey();
            long num = q.remove(max);
            long cnt = Math.min(num, k);
            if (num - cnt > 0) {
                q.put(max, num - cnt);
            }
            add(q, max / 2, cnt);
            add(q, (max - 1) / 2, cnt);
            k -= cnt;
        }
        long max = q.lastKey();
        return "" + (max / 2) + " " + ((max - 1) / 2);
    }

    private void add(TreeMap<Long, Long> q, long k, long v) {
        if (k == 0) return;
        Long vv = q.get(k);
        if (vv == null) {
            q.put(k, v);
        } else {
            q.put(k, vv + v);
        }
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