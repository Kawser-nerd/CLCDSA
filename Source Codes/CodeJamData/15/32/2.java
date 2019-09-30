import java.io.*;
import java.util.StringTokenizer;

public class Main {

    int[][] go;

    void init(String s) {
        int n = s.length();
        go = new int[n + 1][26];
        int[] p = new int[n];
        for (int i = 1, k = 0; i < n; i++) {
            while (k > 0 && s.charAt(i) != s.charAt(k))
                k = p[k - 1];
            if (s.charAt(i) == s.charAt(k))
                k++;
            p[i] = k;
        }
        for (int len = 0; len <= n; len++)
            for (char c = 'A'; c <= 'Z'; c++) {
                int k = len;
                if (k == n)
                    k = p[k - 1];
                while (k > 0 && s.charAt(k) != c)
                    k = p[k - 1];
                if (s.charAt(k) == c)
                    k++;
                go[len][c - 'A'] = k;
            }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        out.printf("Case #%d: ", testNumber);
        int k = in.nextInt();
        int len = in.nextInt();
        int tot = in.nextInt();
        String keys = in.next();
        int[] cnt = new int[26];
        for (int i = 0; i < keys.length(); i++)
            cnt[keys.charAt(i) - 'A']++;
        String target = in.next();
        init(target);
        int maxCnt = tot + 1;
        double[][][] dp = new double[tot + 1][len + 1][maxCnt + 2];
        boolean[][][] can = new boolean[tot + 1][len + 1][maxCnt + 2];
        dp[0][0][0] = 1.0;
        can[0][0][0] = true;
        for (int pos = 0; pos < tot; pos++)
            for (int pref = 0; pref <= len; pref++)
                for (int have = 0; have <= maxCnt; have++)
                    for (int c = 0; c < 26; c++) {
                        int newPref = go[pref][c];
                        int newHave = have;
                        if (newPref == len)
                            newHave++;
                        int newPos = pos + 1;
                        if (cnt[c] > 0)
                            can[newPos][newPref][newHave] |= can[pos][pref][have];
                        dp[newPos][newPref][newHave] += cnt[c] * 1.0 / k * dp[pos][pref][have];
                    }
        int max = 0;
        for (int pref = 0; pref <= len; pref++)
            for (int have = 0; have <= maxCnt; have++)
                if (can[tot][pref][have])
                    max = Math.max(max, have);
        double exp = 0;
        for (int pref = 0; pref <= len; pref++)
            for (int have = 0; have <= maxCnt; have++)
                exp += have * dp[tot][pref][have];
        out.printf("%.10f%n", max - exp);
    }

    public static void main(String[] args)throws IOException {
        FastScanner in = new FastScanner(new FileInputStream("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int t = in.nextInt();
        for (int test = 1; test <= t; test++)
            new Main().solve(test, in, out);
        in.close();
        out.close();
    }

}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String nextLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        tokenizer = null;
        return line;
    }

    public void close() {
        try {
            reader.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
