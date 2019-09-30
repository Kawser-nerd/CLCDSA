import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    void solve() throws IOException {
        int n = in.nextInt();
        boolean[] enter = new boolean[n];
        int[] id = new int[n];
        for (int i = 0; i < n; i++) {
            enter[i] = in.next().equals("E");
            id[i] = in.nextInt();
        }
        int[] dp = new int[1 << n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int st = 0; st < 1 << n; st++)
            for (int sub = st; sub > 0; sub = (sub - 1) & st) {
                int ii = 0;
                if (dp[st ^ sub] == Integer.MAX_VALUE)
                    continue;
                for (int i = 0; i < n; i++)
                    if (((1 << i) & sub) != 0) {
                        if (id[i] != 0) {
                            if (ii != 0 && id[i] != ii) {
                                ii = -2;
                                break;
                            } else {
                                ii = id[i];
                            }
                        }
                    }
                if (ii != -2) {
                    if (ii != 0) {
                        for (int i = 0; i < n; i++)
                            if (((1<<i)&sub)==0)
                                if (id[i] == ii) 
                                    ii = -2;
                        if (ii == -2)
                            continue;
                    }
                    int lastAction = -1;
                    for (int i = 0; i < n; i++) {
                        if (((1 << i) & sub) != 0) {
                            if (enter[i]) {
                                if (lastAction == 1) {
                                    lastAction = -2;
                                    break;
                                }
                                lastAction = 1;
                            } else {
                                if (lastAction == 2) {
                                    lastAction = -2;
                                    break;
                                }
                                lastAction = 2;
                            }
                        }
                    }
                    if (lastAction != -2) {
                        dp[st] = Math.min(dp[st],
                                dp[st ^ sub] + (lastAction == 1 ? 1 : 0));
                    }
                }
            }
        if (dp[dp.length - 1] == Integer.MAX_VALUE) {
            out.println("CRIME TIME");
            return;
        }
        out.println(dp[dp.length - 1]);
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("C.in"));
            out = new PrintWriter(new File("C.out"));

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
        new C().run();
    }
}