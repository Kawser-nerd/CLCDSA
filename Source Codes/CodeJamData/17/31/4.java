import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    /* IO */
    InputReader in;
    BufferedWriter out;
    StringTokenizer tok;
    StringBuilder ans;

    /* FIELDS */
    Item[] items;
    int n, k;
    private long[][] dp;

    public static void main(String[] args) throws IOException {
        Main sol = new Main();
        sol.begin();
    }

    private void begin() throws IOException {
        // io
        boolean file = true;
        if (file)
            in = new InputReader(new FileInputStream("A-large (2).in"));
        else
            in = new InputReader(System.in);
        ans = new StringBuilder();

        int nCases = in.nextInt();
        for (int cas = 1; cas <= nCases; cas++) {
            n = in.nextInt();
            k = in.nextInt();
            items = new Item[n];
            for (int i = 0; i < n; i++) {
                int r = in.nextInt();
                int h = in.nextInt();
                items[i] = new Item(r, h);
            }
            double max = solve();
            ans.append(String.format("Case #%d: %.12f\n", cas, max));
        }
        System.out.print(ans.toString());

        // output to file
        out = new BufferedWriter(new FileWriter("output.txt"));
        out.write(ans.toString());
        out.flush();
        out.close();
    }

    private double solve() {
        Arrays.sort(items, (o1, o2) -> Integer.compare(o2.r, o1.r));
        dp = new long[n][n];
        for (int i = 0; i < n; i++)
            Arrays.fill(dp[i], -1);

        double max = 0;
        for (int i = 0; i < n; i++) {
            long initial = 1l * items[i].r * items[i].r;
            initial += 2l * items[i].r * items[i].h;
            initial += 2l * f(i + 1, k - 1);
            max = Math.max(max, initial);
        }
        return max * Math.PI;
    }

    private long f(int idx, int rem) {
        if (rem == 0 || idx == n)
            return 0;
        if (dp[idx][rem] != -1)
            return dp[idx][rem];

        return dp[idx][rem] = Math.max(
                f(idx + 1, rem),
                1l * items[idx].r * items[idx].h + f(idx + 1, rem - 1));
    }

}

class Item {
    int r, h;

    public Item(int r, int h) {
        this.r = r;
        this.h = h;
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