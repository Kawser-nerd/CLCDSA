import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class C implements Runnable {

    private class TestCaseSolver {

        int n;
        char[][] a;

        class State {
            int i, j, sum;

            public State(int i, int j, int sum) {
                this.i = i;
                this.j = j;
                this.sum = sum;
            }

            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;

                State state = (State) o;

                if (i != state.i) return false;
                if (j != state.j) return false;
                if (sum != state.sum) return false;

                return true;
            }

            public int hashCode() {
                int result;
                result = i;
                result = 31 * result + j;
                result = 31 * result + sum;
                return result;
            }

        }

        private Map<State, String> all = new HashMap<State, String>();
        private LinkedList<State> queue = new LinkedList<State>();
        private Set<State> inQueue = new HashSet<State>();

        private void solve() {
            n = nextInt();
            int q = nextInt();

            a = new char[n][];
            for (int i = 0; i < n; i++) {
                a[i] = nextToken().toCharArray();
                if (a[i].length != n) {
                    throw new IllegalStateException();
                }
            }

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (a[i][j] >= '0' && a[i][j] <= '9') {
                        addState(i, j, a[i][j] - '0', Character.toString(a[i][j]));
                    }

            int[] dx = new int[] {0, 0, -1, 1};
            int[] dy = new int[] {-1, 1, 0, 0};

            while (!queue.isEmpty()) {
                State state = queue.removeFirst();
                inQueue.remove(state);

                String s = all.get(state);
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++) {
                        walk(state, dx[i], dy[i], dx[j], dy[j], s);
                    }
            }

            for (int i = 0; i < q; i++) {
                int sum = nextInt();

                String answer = null;
                for (Map.Entry<State, String> e : all.entrySet()) {
                    State state = e.getKey();
                    String result = e.getValue();

                    if (state.sum == sum) {
                        if (answer == null || less(result, answer)) {
                            answer = result;
                        }
                    }
                }

                if (answer == null) {
                    throw new IllegalStateException("no solution");
                }

                out.println(answer);
            }
        }

        private boolean inside(int x, int y) {
            return 0 <= x && x < n && 0 <= y & y < n;
        }

        private void walk(State state, int dx1, int dy1, int dx2, int dy2, String s) {
            int ni = state.i + dx1 + dx2;
            int nj = state.j + dy1 + dy2;
            if (!inside(ni, nj)) return;

            int signI = state.i + dx1;
            int signJ = state.j + dy1;
            if (!inside(signI, signJ)) return;

            int mul;

            char sign = a[signI][signJ];
            if (sign == '+') {
                mul = 1;
            } else if (sign == '-') {
                mul = -1;
            } else {
                throw new IllegalStateException();
            }

            int digit = a[ni][nj] - '0';
            if (digit < 0 || digit > 9) {
                throw new IllegalStateException();
            }

            int nSum = state.sum + mul * digit;
            addState(ni, nj, nSum, s + sign + digit);
        }

        int MIN_SUM = -300;
        int MAX_SUM = 300;

        private void addState(int i, int j, int sum, String s) {
            if (sum < MIN_SUM || sum > MAX_SUM) {
                return;
            }

            State state = new State(i, j, sum);
            String current = all.get(state);
            if (current == null || less(s, current)) {
                all.put(state, s);
                if (!inQueue.contains(state)) {
                    queue.add(state);
                    inQueue.add(state);
                }
            }
        }

        private boolean less(String a, String b) {
            if (a.length() < b.length()) return true;
            if (a.length() == b.length() && a.compareTo(b) < 0) return true;
            return false;
        }

    }

    private BufferedReader in;
    private PrintWriter out;

    private StringTokenizer tokenizer = new StringTokenizer("");

    private String nextToken() {
        while (!tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = in.readLine();
            } catch (IOException e) {
                throw new IllegalStateException(e);
            }
            if (line == null) {
                return null;
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    private String nextLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }
    }

    private int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private int estimatedTimeLeft(int tc, int tCount, long timeStart) {
        long time = System.currentTimeMillis();
        double timePerTest = (1.0 * (time - timeStart)) / tc;
        return (int) (timePerTest * (tCount - tc) / 1000.0);
    }

    private void solve(File inFile) {
        long timeStart = System.currentTimeMillis();

        try {
            in = new BufferedReader(new FileReader(inFile));
            out = new PrintWriter(new FileWriter(inFile.getName() + ".out"));
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }

        int tCount = nextInt();
        for (int tc = 0; tc < tCount; tc++) {
            System.out.print("Solving test case #" + (tc + 1) + "/" + tCount);
            if (tc > 0) {
                System.out.print(", estimated time left: " + estimatedTimeLeft(tc, tCount, timeStart) + " sec");
            }
            System.out.println();

            out.println("Case #" + (tc + 1) + ":");
            new TestCaseSolver().solve();
        }

        try {
            in.close();
            out.close();
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }
    }

    public void run() {
        final Pattern inPattern = Pattern.compile("^" + Pattern.quote(getClass().getSimpleName()) + "\\-.*\\.in$", Pattern.CASE_INSENSITIVE);
        final File[] inFiles = new File(".").listFiles(
            new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return inPattern.matcher(name).matches();
                }
            }
        );
        for (File inFile : inFiles) {
            System.out.println("Solving [" + inFile.getName() + ']');
            solve(inFile);
        }
    }

    public static void main(String[] args) {
        new Thread(new C()).start();
    }
}