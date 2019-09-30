import java.io.*;
import java.util.StringTokenizer;

public class B {
    FastScanner in;
    PrintWriter out;

    final static long MOD = 1_000_000_007L;

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            long ans = 1;

            int[] sameCnt = new int[26];
            int n = in.nextInt();
            String[] car = new String[n];
            boolean[] forget = new boolean[n];
            char[] first = new char[n];
            char[] last = new char[n];
            boolean[] allSame = new boolean[n];
            for (int i = 0; i < n; i++) {
                car[i] = in.next();
                boolean same = true;
                for (int j = 1; j < car[i].length(); j++) {
                    if (car[i].charAt(j) != car[i].charAt(0)) {
                        same = false;
                    }
                }
                if (same) {
                    allSame[i] = true;
                    int ch = car[i].charAt(0) - 'a';
                    sameCnt[ch]++;
                }
                first[i] = car[i].charAt(0);
                last[i] = car[i].charAt(car[i].length() - 1);
            }

            for (int i = 0; i < 26; i++) {
                for (int j = 1; j <= sameCnt[i]; j++) {
                    ans = (ans * j) % MOD;
                }
            }

            boolean[] u = new boolean[n];
            boolean[] main = new boolean[n];
            int cc = 0;
            for (int i = 0; i < n; i++) {
                if (!u[i]) {
                    u[i] = true;
                    cc++;
                    main[i] = true;
                    boolean found = true;
                    while (found) {
                        found = false;
                        for (int j = 0; j < n; j++) {
                            if (!u[j] && allSame[j] && first[j] == last[i]) {
                                u[j] = true;
                                found = true;
                                car[i] = car[i] + car[j];
                                last[i] = last[j];
                                break;
                            }
                            if (!u[j] && allSame[j] && first[i] == last[j]) {
                                u[j] = true;
                                found = true;
                                car[i] = car[j] + car[i];
                                first[i] = first[j];
                                break;
                            }
                        }
                        if (!found) {
                            for (int j = 0; j < n; j++) {
                                if (!u[j] && !allSame[j] && first[j] == last[i]) {
                                    u[j] = true;
                                    found = true;
                                    car[i] = car[i] + car[j];
                                    last[i] = last[j];
                                    break;
                                }
                                if (!u[j] && !allSame[j] && first[i] == last[j]) {
                                    u[j] = true;
                                    found = true;
                                    car[i] = car[j] + car[i];
                                    first[i] = first[j];
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            String res = "";
            for (int i = 0; i < n; i++) {
                if (main[i]) {
                    res += car[i];
                }
            }
            boolean good = true;
            for (int i = 0; i < res.length(); i++) {
                int j = i;
                while (j < res.length() && res.charAt(i) == res.charAt(j)) {
                    j++;
                }
                if (j == res.length()) {
                    break;
                }
                i = j - 1;
                while (j < res.length() && res.charAt(i) != res.charAt(j)) {
                    j++;
                }
                if (j != res.length()) {
                    good = false;
                    break;
                }
            }

            if (good) {
                for (int i = 1; i <= cc; i++) {
                    ans = (ans * i) % MOD;
                }
            } else {
                ans = 0;
            }

            out("Case #%d: %d\n", test, ans);
        }
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-large.in"));
            out = new PrintWriter(new File("B-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new B().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}