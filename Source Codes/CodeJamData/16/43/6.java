import java.io.*;
import java.util.*;

public class Gardener {

    public void solve() {
        r = in.nextInt();
        c = in.nextInt();
        pairs = new int[2 * (r + c)];
        for (int i = 0; i < pairs.length; i++) {
            pairs[i] = in.nextInt() - 1;
        }
        slow();
    }

    int r, c;
    int[] pairs;

    private void slow() {
        char[][] field = new char[r][c];
        for (int mask = 0; mask < 1 << (r * c); mask++) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    int bit = (mask >> (i * c + j)) & 1;
                    field[i][j] = bit == 0 ? '/' : '\\';

                }
            }
            if (check(field)) {
                for (int i = 0; i < r; i++) {
                    out.println(new String(field[i]));
                }
                return;
            }
        }
        out.println("IMPOSSIBLE");
    }

    boolean check(char[][] field) {
        int[][][] comp = new int[r][c][4];
        for (int[][] i : comp) {
            for (int[] j : i) {
                Arrays.fill(j, -1);
            }
        }
        int comps = 0;
        int[] queue = new int[r * c * 12];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                for (int t = 0; t < 4; t++) {
                    if (comp[i][j][t] == -1) {
                        int head = 0, tail = 0;
                        queue[tail++] = i;
                        queue[tail++] = j;
                        queue[tail++] = t;
                        comp[i][j][t] = comps;
                        while (head < tail) {
                            int curI = queue[head++], curJ = queue[head++], curT = queue[head++];
                            if (curT == 0) {
                                int newI = curI - 1, newJ = curJ, newT = (curT + 2) % 4;
                                if (newI >= 0 && comp[newI][newJ][newT] == -1) {
                                    comp[newI][newJ][newT] = comps;
                                    queue[tail++] = newI;
                                    queue[tail++] = newJ;
                                    queue[tail++] = newT;
                                }
                            } else if (curT == 1) {
                                int newI = curI, newJ = curJ + 1, newT = (curT + 2) % 4;
                                if (newJ < c && comp[newI][newJ][newT] == -1) {
                                    comp[newI][newJ][newT] = comps;
                                    queue[tail++] = newI;
                                    queue[tail++] = newJ;
                                    queue[tail++] = newT;
                                }

                            } else if (curT == 2) {
                                int newI = curI + 1, newJ = curJ, newT = (curT + 2) % 4;
                                if (newI < r && comp[newI][newJ][newT] == -1) {
                                    comp[newI][newJ][newT] = comps;
                                    queue[tail++] = newI;
                                    queue[tail++] = newJ;
                                    queue[tail++] = newT;
                                }
                            } else if (curT == 3) {
                                int newI = curI, newJ = curJ - 1, newT = (curT + 2) % 4;
                                if (newJ >= 0 && comp[newI][newJ][newT] == -1) {
                                    comp[newI][newJ][newT] = comps;
                                    queue[tail++] = newI;
                                    queue[tail++] = newJ;
                                    queue[tail++] = newT;
                                }
                            }

                            for (int d = -1; d <= 1; d += 2) {
                                int newT = (curT + d + 4) % 4;
                                if (field[curI][curJ] == '\\') {
                                    if (Math.min(curT, newT) == 1 && Math.max(curT, newT) == 2) {
                                        continue;
                                    }
                                    if (Math.min(curT, newT) == 0 && Math.max(curT, newT) == 3) {
                                        continue;
                                    }
                                } else {
                                    if (Math.min(curT, newT) == 0 && Math.max(curT, newT) == 1) {
                                        continue;
                                    }
                                    if (Math.min(curT, newT) == 2 && Math.max(curT, newT) == 3) {
                                        continue;
                                    }
                                }
                                if (comp[curI][curJ][newT] == -1) {
                                    comp[curI][curJ][newT] = comps;
                                    queue[tail++] = curI;
                                    queue[tail++] = curJ;
                                    queue[tail++] = newT;
                                }
                            }
                        }

                        comps++;
                    }
                }
            }
        }


        for (int i = 0; i < pairs.length; i++) {
            for (int j = 0; j < pairs.length; j++) {
                State s1 = getState(pairs[i]), s2 = getState(pairs[j]);
//                System.err.println(s1 + " " + s2);
                if (i / 2 == j / 2) {
                    if (comp[s1.i][s1.j][s1.t] != comp[s2.i][s2.j][s2.t]) {
                        return false;
                    }
                } else {
                    if (comp[s1.i][s1.j][s1.t] == comp[s2.i][s2.j][s2.t]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    State getState(int i) {
        if (i < c) {
            return new State(0, i, 0);
        } else if (i - c < r) {
            return new State(i - c, c - 1, 1);
        } else if (i - c - r < c) {
            return new State(r - 1, c - 1 - (i - c - r), 2);
        } else {
            return new State(r - 1 - (i - c - r - c), 0, 3);
        }
    }

    class State {
        int i, j, t;

        public State(int i, int j, int t) {
            this.i = i;
            this.j = j;
            this.t = t;
        }

        @Override
        public String toString() {
            return "State{" +
                    "i=" + i +
                    ", j=" + j +
                    ", t=" + t +
                    '}';
        }
    }

    public void run() {
        try {
            in = new FastScanner("input.txt");
            out = new PrintWriter("output.txt");
            int tests = in.nextInt();
            for (int i = 1; i <= tests; i++) {
                long time = System.currentTimeMillis();
                out.printf("Case #%d: ", i);
                out.println();
                solve();
                System.err.printf("Solved case #%d in %d ms\n", i, System.currentTimeMillis() - time);
            }
            out.close();
        } catch (FileNotFoundException e) {
        }
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
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
    }

    public static void main(String[] args) {
        new Gardener().run();
    }
}
