import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    class BS {
        int x, y;
        boolean[] can;

        public BS(int x, int y) {
            this.x = x;
            this.y = y;
            can = new boolean[2];
        }
    }

    ArrayList<Integer>[] e;
    ArrayList<Integer>[] er;
    boolean[] u;
    int[] g;
    int pos;
    int[] comp;

    void dfs1(int x) {
        u[x] = true;
        for (int y : e[x]) {
            if (!u[y]) {
                dfs1(y);
            }
        }
        g[--pos] = x;
    }

    void dfs2(int x, int col) {
        comp[x] = col;
        u[x] = true;
        for (int y : er[x]) {
            if (!u[y]) {
                dfs2(y, col);
            }
        }
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();

        for (int test = 1; test <= testNo; test++) {
            int h = in.nextInt();
            int w = in.nextInt();

            int[][] f = new int[h + 2][w + 2];
            ArrayList<BS> bsal = new ArrayList<>();
            for (int i = 0; i < h; i++) {
                String s = in.next();
                for (int j = 0; j < w; j++) {
                    f[i + 1][j + 1] = "#./\\-|".indexOf(s.charAt(j));
                    if (f[i + 1][j + 1] == 4) {
                        bsal.add(new BS(i + 1, j + 1));
                    }
                    if (f[i + 1][j + 1] == 5) {
                        f[i + 1][j + 1] = 4;
                        bsal.add(new BS(i + 1, j + 1));
                    }
                }
            }
            h += 2;
            w += 2;


            int n = bsal.size();
            BS[] bs = bsal.toArray(new BS[n]);


            int[] dx = {1, 0, -1, 0};
            int[] dy = {0, 1, 0, -1};
            int[][] cnt = new int[h][w];
            int[][][] whi = new int[h][w][2];
            int[][][] dir = new int[h][w][2];
            for (int i = 0; i < n; i++) {
                for (int bsd = 0; bsd < 2; bsd++) {
                    bs[i].can[bsd] = true;
                    for (int sd = bsd; sd < 4; sd += 2) {
                        int x = bs[i].x;
                        int y = bs[i].y;
                        int d = sd;
                        while (true) {
                            x += dx[d];
                            y += dy[d];
                            if (f[x][y] == 0) {
                                break;
                            }
                            if (f[x][y] == 1) {
                                boolean hit = false;
                                for (int j = 0; j < cnt[x][y]; j++) {
                                    if (whi[x][y][j] == i && dir[x][y][j] == bsd) {
                                        hit = true;
                                    }
                                }
                                if (!hit) {
                                    cnt[x][y]++;
                                    whi[x][y][cnt[x][y] - 1] = i;
                                    dir[x][y][cnt[x][y] - 1] = bsd;
                                }
                            }
                            if (f[x][y] == 4) {
                                bs[i].can[bsd] = false;
                                break;
                            }
                            if (f[x][y] == 3) {
                                d ^= 1;
                            }
                            if (f[x][y] == 2) {
                                d = 3 - d;
                            }
                        }
                    }
                }
            }

            int nv = 2 * n;
            boolean possible = true;
            e = new ArrayList[2 * n];
            er = new ArrayList[2 * n];
            for (int i = 0; i < nv; i++) {
                e[i] = new ArrayList<>();
                er[i] = new ArrayList<>();
            }

            for (int i = 0; i < n; i++) {
                if (!bs[i].can[0]) {
                    e[2 * i].add(2 * i + 1);
                }
                if (!bs[i].can[1]) {
                    e[2 * i + 1].add(2 * i);
                }
            }
            for (int x = 0; x < h; x++) {
                for (int y = 0; y < w; y++) {
                    if (f[x][y] == 1) {
                        if (cnt[x][y] == 1) {
                            e[2 * whi[x][y][0] + 1 - dir[x][y][0]].add(2 * whi[x][y][0] + dir[x][y][0]);
                        } else if (cnt[x][y] == 2) {
                            e[2 * whi[x][y][0] + 1 - dir[x][y][0]].add(2 * whi[x][y][1] + dir[x][y][1]);
                            e[2 * whi[x][y][1] + 1 - dir[x][y][1]].add(2 * whi[x][y][0] + dir[x][y][0]);
                        } else {
                            possible = false;
                        }
                    }
                }
            }
            for (int i = 0; i < nv; i++) {
                for (int j : e[i]) {
                    er[j].add(i);
                }
            }

            u = new boolean[nv];
            g = new int[nv];
            pos = nv;
            for (int i = 0; i < nv; i++) {
                if (!u[i]) {
                    dfs1(i);
                }
            }
            Arrays.fill(u, false);
            int nc = 0;
            comp = new int[nv];
            for (int i = 0; i < nv; i++) {
                if (!u[g[i]]) {
                    dfs2(g[i], nc++);
                }
            }

            int[] ans = new int[n];
            for (int i = 0; i < n; i++) {
                if (comp[2 * i] == comp[2 * i + 1]) {
                    possible = false;
                    break;
                }
                if (comp[2 * i] < comp[2 * i + 1]) {
                    ans[i] = 1;
                    f[bs[i].x][bs[i].y] = 5;
                } else {
                    ans[i] = 0;
                }
            }

            System.out.println("Case #" + test + ": " + (possible ? "POSSIBLE" : "IMPOSSIBLE"));
            out.println("Case #" + test + ": " + (possible ? "POSSIBLE" : "IMPOSSIBLE"));
            if (possible) {
                for (int i = 1; i < h - 1; i++) {
                    for (int j = 1; j < w - 1; j++) {
                        switch (f[i][j]) {
                            case 0:
                                out.print("#");
                                System.out.print("#");
                                break;
                            case 1:
                                out.print(".");
                                System.out.print(".");
                                break;
                            case 2:
                                out.print("/");
                                System.out.print("/");
                                break;
                            case 3:
                                out.print("\\");
                                System.out.print("\\");
                                break;
                            case 4:
                                out.print("|");
                                System.out.print("|");
                                break;
                            case 5:
                                out.print("-");
                                System.out.print("-");
                                break;
                        }
                    }
                    System.out.println();
                    out.println();
                }
            }
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("C-small-attempt0.in"));
            out = new PrintWriter(new File("C-small-attempt0.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        Locale.setDefault(Locale.US);
        new C().run();
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}