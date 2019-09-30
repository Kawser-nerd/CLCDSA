import java.io.*;
import java.util.*;

public class B {

    static void process(int c, BufferedReader in) throws IOException {
        String res = "IMPOSSIBLE";
        int n = readInt(in);
        int m = readInt(in);
        HashSet<Integer>[] u = new HashSet[n];
        for (int i = 0; i < u.length; i++)
            u[i] = new HashSet<Integer>();
        HashSet<Integer>[] melt = new HashSet[n];
        for (int i = 0; i < u.length; i++)
            melt[i] = new HashSet<Integer>();
        int[] mm = new int[m];
        for (int i = 0; i < m; i++) {
            String[] v = in.readLine().split(" ");
            int f = Integer.parseInt(v[0]);
            for (int j = 0; j < f; j++) {
                int k = Integer.parseInt(v[2*j + 1]) - 1;
                if (v[2*j + 2].equals("0"))
                    u[k].add(i);
                else {
                    melt[k].add(i);
                    mm[i] = k;
                }
            }
        }

        int[] ans = new int[n];

        boolean ok = false;
        while (true) {
            HashSet<Integer> all = new HashSet<Integer>();
            for (int i = 0; i < n; i++) {
                if (ans[i] == 0)
                    all.addAll(u[i]);
                else
                    all.addAll(melt[i]);
            }
            if (all.size() == m) {
                ok = true;
                break;
            }
            boolean finish =true;
            for (int i = 0; i < m; i++) {
                if (!all.contains(i)) {
                    if (ans[mm[i]] == 0) {
                        ans[mm[i]] = 1;
                        finish = false;
                    }
                }
            }
            if (finish)
                break;
        }

        if (ok) {
            res = "";
            for (int i = 0; i < ans.length; i++) {
                res += " " + ans[i];
            }
            res = res.substring(1);
        }

        out.println("Case #" + c + ": " + res);
    }

    static PrintStream out;

    public static void main(String[] args) throws Throwable {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(args[0])));
        out = new PrintStream(new FileOutputStream(args[1]));
        int n = readInt(in);
        for (int i = 0; i < n; i++) {
            process(i + 1, in);
        }
        out.flush();
        out.close();
    }

    private static int readInt(BufferedReader in) {
        try {
            return Integer.parseInt(in.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

}