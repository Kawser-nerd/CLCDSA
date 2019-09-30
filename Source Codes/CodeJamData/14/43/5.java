import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class C {

    class Building {
        int xFrom, xTo, yFrom, yTo;

        Building(int xFrom, int xTo, int yFrom, int yTo) {
            this.xFrom = xFrom;
            this.xTo = xTo;
            this.yFrom = yFrom;
            this.yTo = yTo;
        }

        public int distTo(Building other) {
            int distX = Math.max(other.xFrom - xTo, xFrom - other.xTo) - 1;
            int distY = Math.max(other.yFrom - yTo, yFrom - other.yTo) - 1;
            return Math.max(distX, distY);
        }
    }

    private void solve() throws Exception {
        int w = nextInt(), h = nextInt(), n = nextInt();
        Building[] b = new Building[n];
        for (int i = 0; i < n; ++i) {
            int xFrom = nextInt(), yFrom = nextInt(), xTo = nextInt(), yTo = nextInt();
            b[i] = new Building(xFrom, xTo, yFrom, yTo);
        }
        boolean[] used = new boolean[n];
        int[] d = new int[n];
        Building leftSide = new Building(-1, -1, 0, h - 1);
        for (int i = 0; i < n; ++i) {
            d[i] = leftSide.distTo(b[i]);
            if (d[i] != b[i].xFrom) {
                throw new RuntimeException("Not equal at " + i + ": " + d[i] + " " + b[i].xFrom);
            }
        }
        for (int i = 0; i < n; ++i) {
            int minVal = Integer.MAX_VALUE, minValInd = -1;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && d[j] < minVal) {
                    minVal = d[j];
                    minValInd = j;
                }
            }
            used[minValInd] = true;
            for (int j = 0; j < n; ++j) {
                if (!used[j]) {
                    d[j] = Math.min(d[j], d[minValInd] + b[minValInd].distTo(b[j]));
                }
            }
        }
        Building rightSide = new Building(w, w, 0, h - 1);
        int ans = rightSide.distTo(leftSide);
        for (int i = 0; i < n; ++i) {
            ans = Math.min(ans, d[i] + b[i].distTo(rightSide));
        }
        out.println(ans);
    }

    public void run() {
        try {
            int tc = nextInt();
            for (int it = 1; it <= tc; ++it) {
                System.err.println(it);
                out.print("Case #" + it + ": ");
                solve();
            }
        } catch (Exception e) {
            NOO(e);
        } finally {
            out.close();
        }
    }

    PrintWriter out;
    BufferedReader in;
    StringTokenizer St;

    void NOO(Exception e) {
        e.printStackTrace();
        System.exit(42);
    }

    int nextInt() {
        return Integer.parseInt(nextToken());
    }

    long nextLong() {
        return Long.parseLong(nextToken());
    }

    double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    String nextToken() {
        while (!St.hasMoreTokens()) {
            try {
                String line = in.readLine();
                if (line == null)
                    return null;
                St = new StringTokenizer(line);
            } catch (Exception e) {
                NOO(e);
            }
        }
        return St.nextToken();
    }

    private C(String name) {
        try {
            in = new BufferedReader(new FileReader("input.txt"));
            St = new StringTokenizer("");
            out = new PrintWriter(new FileWriter("output.txt"));
        } catch (Exception e) {
            NOO(e);
        }
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new C("a").run();
    }
}
