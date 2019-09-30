import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static final int INF = 1000000;
    /* IO */
    InputReader in;
    BufferedWriter out;
    StringTokenizer tok;
    StringBuilder ans;

    /* FIELDS */
    int activityWho[];
    int totalMinutes = 24 * 60;
    int offset = totalMinutes;
    private int[][][][] dp;

    public static void main(String[] args) throws IOException {
        Main sol = new Main();
        sol.begin();
    }

    private void begin() throws IOException {
        // io
        boolean file = true;
        if (file)
            in = new InputReader(new FileInputStream("B-large (2).in"));
        else
            in = new InputReader(System.in);
        ans = new StringBuilder();

        activityWho = new int[totalMinutes];
        dp = new int[2][2][totalMinutes][2 * offset + 2];

        int nCases = in.nextInt();
        for (int cas = 1; cas <= nCases; cas++) {
            System.out.println(cas);
            Arrays.fill(activityWho, -1);
            int[] n = {in.nextInt(), in.nextInt()};
            for (int who = 0; who <= 1; who++) {
                for (int k = 0; k < n[who]; k++) {
                    int from = in.nextInt();
                    int to = in.nextInt();
                    for (int i = from; i < to; i++)
                        activityWho[i] = who;
                }
            }
            int min = solve();
            ans.append(String.format("Case #%d: %d\n", cas, min));
        }
        System.out.println(ans.toString());

        // output to file
        out = new BufferedWriter(new FileWriter("output.txt"));
        out.write(ans.toString());
        out.flush();
        out.close();
    }

    private int solve() {
        for (int a = 0; a < 2; a++)
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < totalMinutes; j++)
                for (int k = 0; k < 2 * offset + 2; k++) {
                    dp[a][i][j][k] = -1;
                }
        return Math.min(
                f(0, 0, 0, offset),
                f(1, 1, 0, offset));
    }

    private int f(int start, int prevWho, int minute, int diff) {
        if (minute == totalMinutes)
            return diff == offset ? (start == prevWho ? 0 : 1) : INF;
        if (dp[start][prevWho][minute][diff] != -1)
            return dp[start][prevWho][minute][diff];

        // continue
        int min = INF;
        if (activityWho[minute] != prevWho)
            min = Math.min(min, f(start, prevWho, minute + 1, diff + (prevWho == 0 ? 1 : -1)));
        if (activityWho[minute] != (1 - prevWho))
            min = Math.min(min, 1 + f(start,1 - prevWho, minute + 1, diff + ((1 - prevWho) == 0 ? 1 : -1)));

        return dp[start][prevWho][minute][diff] = min;
    }


}

class InputReader {
    BufferedReader reader;
    StringTokenizer tok;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tok = new StringTokenizer("");
    }

    public String next() {
        while (!tok.hasMoreTokens())
            try {
                tok = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        return tok.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
}