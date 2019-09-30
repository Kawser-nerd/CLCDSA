import java.io.*;
import java.util.*;

public class D {
    private final Scanner in;
    private final PrintWriter out;

    public D(Scanner in, PrintWriter out) {
        this.in = in;
        this.out = out;
    }

    public static void main(String[] args) {
        final String filename = "D-small-attempt0";
        try (Scanner in = new Scanner(new FileReader(new File(filename + ".in")));
             PrintWriter out = new PrintWriter(filename + ".out")) {
            new D(in, out).solve();
        } catch (Throwable t) {
            t.printStackTrace();
            System.exit(-1);
        }
    }

    private void solve() {
        int tests = in.nextInt();
        for (int test = 1; test <= tests; ++test) {
            System.out.println(test);

            max = 0;
            cnt = 1;

            int m = in.nextInt();
            n = in.nextInt();

            s = new String[m];

            for (int i = 0; i < m; ++i) {
                s[i] = in.next();
            }

            cl = new int[m];

            bt(0);

            out.print("Case #" + test + ": ");
            out.println(max + " " + cnt);
            System.out.println(max + " " + cnt);
        }
    }

    int max = 0;
    int cnt = 1;

    String[] s;
    int[] cl;
    int n;

    void bt(int i) {
        if (i == s.length) {
            int tans = 0;
            for (int j = 0; j < n; ++j) {
                tans += count(j);
            }
            if (max < tans) {
                max = tans;
                cnt = 0;
            }
            if (max == tans) {
                ++cnt;
            }
            return;
        }

        for (int j = 0; j < n; ++j) {
            cl[i] = j;
            bt(i + 1);
        }
    }

    int count(int c) {
        Set<String> pref = new HashSet<>();
        for (int i = 0; i < s.length; ++i) {
            if (cl[i] != c) continue;
            for (int j = 0; j <= s[i].length(); ++j) {
                pref.add(s[i].substring(0, j));
            }
        }
        return pref.size();
    }
}
