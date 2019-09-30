import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    int k, n;
    int[] numDigits;
    Goro[] goros;
    String[] ss;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        k = sc.nextInt();
        n = sc.nextInt();
        goros = new Goro[n];
        for (int i = 0; i < n; i++) {
            int v = sc.nextInt();
            char[] cs = sc.next().toCharArray();
            goros[i] = new Goro(v, cs);
        }
        solve();
    }

    void solve() {
        numDigits = new int[k + 1];
        dfs(1);
        for (int i = 1; i <= k; i++) {
            System.out.println(ss[i]);
        }
    }

    boolean dfs (int i) {
        if (i == k) {
            for (int j = 1; j <= 3; j++) {
                numDigits[i] = j;
                if (check()) {
                    return true;
                }
            }
            numDigits[i] = 0;
            return false;
        }
        for (int j = 1; j <= 3; j++) {
            numDigits[i] = j;
            boolean rec = dfs(i + 1);
            if (rec) {
                return true;
            }
        }
        numDigits[i] = 0;
        return false;
    }

    boolean check() {
        ss = new String[k + 1];
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = 0; j < goros[i].digits.length; j++) {
                num += numDigits[goros[i].digits[j]];
            }
            if (num != goros[i].cs.length) {
                return false;
            }
            int l = 0;
            for (int j = 0; j < goros[i].digits.length; j++) {
                int n = goros[i].digits[j];
                StringBuilder sb = new StringBuilder();
                for (int m = l; m < l + numDigits[n]; m++) {
                    sb.append(goros[i].cs[m]);
                }
                l += numDigits[n];
                String temp = sb.toString();
                if (ss[n] != null && !ss[n].equals(temp)) {
                    return false;
                } else if (ss[n] == null) {
                    ss[n] = temp;
                }
            }
        }
        return true;
    }

    class Goro {
        int num;
        int[] digits;
        char[] cs;

        Goro(int num, char[] cs) {
            this.num = num;
            this.digits = digits(num);
            this.cs = cs;
        }
    }

    static int[] digits(int n) {
        List<Integer> list = new ArrayList<>();
        while (n > 0) {
            list.add(n % 10);
            n /= 10;
        }
        int[] ret = new int[list.size()];
        int j = 0;
        for (int i = list.size() - 1; i >= 0; i--) {
            ret[j++] = list.get(i);
        }
        return ret;
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}