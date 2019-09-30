import java.io.*;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    void solve() throws IOException {
        String s = in.next();
        int n = s.length();
        double[] prob = new double[1 << n];
        double[] cost = new double[1 << n];
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '.') {
                cur |= 1 << i;
            }
        }
        prob[cur] = 1;
        for (int st = (1 << n) - 1; st > 0; st--) {
            if (prob[st] != 0) {
                for (int i = 0; i < n; i++) {
                    int firstFree = i;
                    int wait = 0;
                    while ((st & (1 << firstFree)) == 0) {
                        firstFree = (1 + firstFree) % n;
                        wait++;
                    }
                    int pay = n - wait;
                    int nextSt = st ^ (1 << firstFree);
                    double nextCost = (prob[st] * (pay + cost[st])/ n + cost[nextSt] * prob[nextSt]);
                    prob[nextSt] += prob[st] / n;
                    cost[nextSt] = nextCost / prob[nextSt];
                }
            }
        }
        out.println(cost[0]);
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("D.in"));
            out = new PrintWriter(new File("D.out"));

            int testNumber = in.nextInt();
            for (int test = 1; test <= testNumber; test++) {
                out.print("Case #" + (test) + ": ");
                solve();
                System.out.println(test);
            }

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        try {
            solve();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) throws IOException {
        new D().run();
    }
}