import java.io.*;
import java.util.*;

/**
 * @author Ivan Romanov
 */
public class B {
    private static final String PROBLEM = "B";

    private static final String SIZE = "large";
    //private static final String SIZE = "small";
    //private static final String SIZE = "small-attempt0";

    private final Map<String, Integer> colors = new HashMap<String, Integer>();
    private static final int DOSOK = 10000;

    private int getColor() throws IOException {
        String c = nextToken();
        if (!colors.containsKey(c)) {
            colors.put(c, colors.size());
        }
        return colors.get(c);
    }

    int n;
    Range[] r;

    private String solve() throws IOException {
        n = nextInt();
        r = new Range[n];

        for (int i = 0; i < n; i++) {
            int tmp = getColor();
            r[i] = new Range(nextInt() - 1,  nextInt() - 1, tmp);
        }

        int ans = Integer.MAX_VALUE;

        Arrays.sort(r);
        for (int col0 = 0; col0 < colors.size(); col0++) {
            ans = Math.min(ans, solve(col0, -1, -1));
            for (int col1 = col0 + 1; col1 < colors.size(); col1++) {
                ans = Math.min(ans, solve(col0, col1, -1));
                for (int col2 = col1 + 1; col2 < colors.size(); col2++) {
                    ans = Math.min(ans, solve(col0, col1, col2));
                }
            }
        }

        return ans == Integer.MAX_VALUE ? "IMPOSSIBLE" : ("" + ans);
    }

    private static class Range implements Comparable<Range> {
        final int min;
        final int max;
        final int color;

        public Range(int min, int max, int color) {
            this.min = min;
            this.max = max;
            this.color = color;
        }

        public int compareTo(Range that) {
            if (this.min < that.min) return -1;
            if (this.min > that.min) return 1;
            return 0;
        }
    }

    private int solve(int col0, int col1, int col2) {
        int nextNeed = 0;
        Range last = null;
        int res = 0;
        for (Range a : r) {
            if (a.color == col0 || a.color == col1 || a.color == col2) {
                if (a.min > nextNeed) {
                    if (last == null) {
                        return Integer.MAX_VALUE;
                    }
                    res++;
                    nextNeed = last.max + 1;
                    if (nextNeed >= DOSOK) {
                        return res;
                    }
                }

                if (a.min <= nextNeed) {
                    if (last == null || last.max < a.max) {
                        last = a;
                    }
                } else {
                    return Integer.MAX_VALUE;
                }
            }
        }
        if (last != null) {
            res++;
            nextNeed = last.max + 1;
        }
        if (nextNeed >= DOSOK) {
            return res;
        }
        return Integer.MAX_VALUE;
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
        reader = new BufferedReader(new FileReader(PROBLEM + "-" + SIZE + ".in"));
        PrintWriter writer = new PrintWriter(new File(PROBLEM + "-" + SIZE + ".out"));
        try {
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                writer.print("Case #" + (i + 1) + ": ");
                writer.print(solve());
                writer.println();
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new B().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}