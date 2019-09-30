import java.io.*;
import java.util.*;
import java.math.*;

// 5/5/12 8:25 PM
// by Abrackadabra

public class B {
    public static void main(String[] args) throws IOException {
        if (args.length > 0 && args[0].equals("Abra")) debugMode = true;
        new B().run();
        /*new Thread(null, new Runnable() {
            public void run() {
                try {
                    new B().run();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }, "1", 1 << 24).start();*/
    }

    int IOMode = 0; //0 - consoleIO, 1 - <taskName>.in/out, 2 - input.txt/output.txt, 3 - test case generator
    String taskName = "";
    boolean testBasedProblem = true;

    class State {
        int i, j;
        double timePassed = 0.0;

        State(int i, int j, double timePassed) {
            this.i = i;
            this.j = j;
            this.timePassed = timePassed;
        }
    }

    void solve() throws IOException {
        int h = nextInt(), n = nextInt(), m = nextInt();
        int[][] ceiling = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ceiling[i][j] = nextInt();
            }
        }
        int[][] floor = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                floor[i][j] = nextInt();
            }
        }
        double[][] minTime = new double[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                minTime[i][j] = Double.MAX_VALUE;
            }
        }
        Queue<State> queue = new LinkedList<State>();
        minTime[0][0] = 0.0;
        queue.add(new State(0, 0, 0.0));
        while (!queue.isEmpty()) {
            State state = queue.poll();
            int x = state.i;
            int y = state.j;
            double t = state.timePassed;
            for (int[] d : dirs) {
                int xx = x + d[0];
                int yy = y + d[1];
                if (xx >= n || xx < 0 || yy >= m || yy < 0) continue;
                double w = maxWaterLevelToPass(floor[x][y], ceiling[x][y], floor[xx][yy], ceiling[xx][yy]);
                if (w < 0) continue;
                double cw = h - t * 10.0;
                double tt = t;
                if (w < cw) tt += (cw - w) / 10.0;
                cw = h - tt * 10.0;
                if (cw - floor[x][y] >= 20.0) {
                    tt += 1.0;
                } else {
                    tt += 10.0;
                }
                if (w >= h && t == 0.0) tt = 0.0;
                State newState = new State(xx, yy, tt);
                if (minTime[xx][yy] > tt) {
                    queue.add(newState);
                    minTime[xx][yy] = tt;
                }
            }
        }
        out.print("Case #" + testIndex + ": ");
        out.println(minTime[n - 1][m - 1]);
    }

    double maxWaterLevelToPass(int f0, int c0, int f1, int c1) {
        if (Math.min(c0, c1) - Math.max(f0, f1) < 50) return -1.0;
        return Math.min(c0, c1) - 50;
    }

    int[][] dirs = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
    };

    long startTime = System.nanoTime(), tempTime = startTime, finishTime = startTime;
    long startMem = Runtime.getRuntime().totalMemory(), finishMem = startMem;
    int testIndex;

    void run() throws IOException {
        init();
        if (debugMode) {
            con.println("Start");
            con.println("Console:");
        }

        int tests = testBasedProblem ? nextInt() : 1;
        for (testIndex = 1; testIndex <= tests; testIndex++)
            solve();

        finishTime = System.nanoTime();
        finishMem = Runtime.getRuntime().totalMemory();
        out.flush();
        if (debugMode) {
            int maxSymbols = 1000;
            BufferedReader tbr = new BufferedReader(new FileReader("input.txt"));
            char[] a = new char[maxSymbols];
            tbr.read(a);
            if (a[0] != 0) {
                con.println("File input:");
                con.println(a);
                if (a[maxSymbols - 1] != 0) con.println("...");
            }
            tbr = new BufferedReader(new FileReader("output.txt"));
            a = new char[maxSymbols];
            tbr.read(a);
            if (a[0] != 0) {
                con.println("File output:");
                con.println(a);
                if (a[maxSymbols - 1] != 0) con.println("...");
            }
            con.println("Execution time: " + (finishTime - startTime) / 1000000000.0 + " sec");
            con.println("Used memory:    " + (finishMem - startMem) + " bytes");
            con.println("Total memory:   " + Runtime.getRuntime().totalMemory() + " bytes");
        }
    }

    boolean tick(double x) {
        if (System.nanoTime() - tempTime > x * 1e9) {
            tempTime = System.nanoTime();
            con.println("Tick at " + (tempTime - startTime) / 1000000000 + " sec");
            con.print("   ");
            return true;
        }
        return false;
    }

    static boolean debugMode = false;
    PrintStream con = System.out;

    void init() throws IOException {
        if (debugMode && IOMode != 3) {
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter(new FileWriter("output.txt"));
        } else
            switch (IOMode) {
                case 0:
                    br = new BufferedReader(new InputStreamReader(System.in));
                    out = new PrintWriter(System.out);
                    break;
                case 1:
                    br = new BufferedReader(new FileReader(taskName + ".in"));
                    out = new PrintWriter(new FileWriter(taskName + ".out"));
                    break;
                case 2:
                    br = new BufferedReader(new FileReader("input.txt"));
                    out = new PrintWriter(new FileWriter("output.txt"));
                    break;
                case 3:
                    out = new PrintWriter(new FileWriter("input.txt"));
                    break;
            }
        if (!debugMode)
            con = new PrintStream(new OutputStream() {
                public void write(int b) throws IOException {
                } // to /dev/null
            });
        if ((IOMode == 1 && taskName.length() == 0) || (IOMode != 1 && taskName.length() != 0)) {
            System.err.println("Leha, check IO settings");
            System.err.flush();
            System.exit(0);
        }
    }

    BufferedReader br;
    PrintWriter out;
    StringTokenizer in;

    boolean hasMoreTokens() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return false;
            in = new StringTokenizer(line);
        }
        return true;
    }

    String nextString() throws IOException {
        return hasMoreTokens() ? in.nextToken() : null;
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextString());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextString());
    }
}