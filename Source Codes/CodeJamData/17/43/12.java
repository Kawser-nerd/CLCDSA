import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("beams.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("beams.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Beams solver = new Beams();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class Beams {
        static int[] dx = {0, -1, 0, 1};
        static int[] dy = {1, 0, -1, 0};

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int r = in.nextInt();
            int c = in.nextInt();
            char[][] grid = new char[r][];
            for (int i = 0; i < r; i++) {
                grid[i] = in.nextToken().toCharArray();
            }
            List<Integer> beamPositions = new ArrayList<>();
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] == '|' || grid[i][j] == '-') {
                        beamPositions.add(i * c + j);
                    }
                }
            }
            List<Beams.Beam> beams = new ArrayList<>();
            for (int beamPos : beamPositions) {
                int x = beamPos / c, y = beamPos % c;
                boolean[][] ok = new boolean[2][];
                for (int direction = 0; direction < 2; direction++) {
                    boolean[] covers = new boolean[r * c];
                    boolean good1 = traceBeam(grid, covers, direction, x, y);
                    boolean good2 = traceBeam(grid, covers, direction ^ 2, x, y);
                    if (good1 && good2) {
                        ok[direction] = covers;
                    }
                }
                beams.add(new Beams.Beam(beamPos, ok));
            }
            grid = solveTwoSat(beams, grid);
            if (grid == null) {
                out.println("Case #" + testNumber + ": " + "IMPOSSIBLE");
            } else {
                out.println("Case #" + testNumber + ": " + "POSSIBLE");
                for (int i = 0; i < r; i++) {
                    out.println(grid[i]);
                }
            }
        }

        char[][] solveTwoSat(List<Beams.Beam> beams, char[][] grid) {
            int r = grid.length;
            int c = grid[0].length;
            Beams.TwoSat graph = new Beams.TwoSat(2 * beams.size());
            for (int i = 0; i < beams.size(); i++) {
                Beams.Beam beam = beams.get(i);
                if (beam.covers[0] == null && beam.covers[1] == null) {
                    return null;
                }
//            System.err.println(i + " " + (beam.covers[0] == null) + " " + (beam.covers[1] == null));
                if (beam.covers[0] == null) {
                    graph.addEdge(2 * i, 2 * i + 1);
                }
                if (beam.covers[1] == null) {
                    graph.addEdge(2 * i + 1, 2 * i);
                }
            }
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] != '.') {
                        continue;
                    }
                    List<Integer> goodBeams = new ArrayList<>();
                    for (int it = 0; it < beams.size(); it++) {
                        for (int dir = 0; dir < 2; dir++) {
                            if (beams.get(it).covers[dir] != null && beams.get(it).covers[dir][i * c + j]) {
                                goodBeams.add(it * 2 + dir);
                            }
                        }
                    }
                    if (goodBeams.size() > 2) {
                        throw new AssertionError();
                    }
                    if (goodBeams.size() == 0) {
                        return null;
                    }
                    if (goodBeams.size() == 2) {
                        int u = goodBeams.get(0);
                        int v = goodBeams.get(1);
                        if ((u ^ v) != 1) {
                            graph.addEdge(u ^ 1, v);
                            graph.addEdge(v ^ 1, u);
                        }
//                    System.err.println(u + " OR " + v);
                    }
                    if (goodBeams.size() == 1) {
                        int u = goodBeams.get(0);
                        graph.addEdge(u ^ 1, u);
//                    System.err.println("TRUE: " + u);
                    }
                }
            }
            int[] component = graph.findComponents();
//        System.err.println("AFDFDS");
//        System.err.println(Arrays.toString(component));
            for (int i = 0; i < beams.size(); i++) {
                if (component[2 * i] == component[2 * i + 1]) {
                    return null;
                }
                int x = beams.get(i).pos / c;
                int y = beams.get(i).pos % c;
//            System.err.println(x + " " + y + " " + component[2 * i] + " " + component[2 * i + 1]);
                if (component[2 * i] > component[2 * i + 1]) {
                    grid[x][y] = '-';
                } else {
                    grid[x][y] = '|';
                }
            }
            return grid;
        }

        private boolean traceBeam(char[][] grid, boolean[] covers, int direction, int x, int y) {
            int r = grid.length;
            int c = grid[0].length;
            while (true) {
                int newX = x + dx[direction];
                int newY = y + dy[direction];
                if (newX < 0 || newY < 0 || newX >= r || newY >= c || grid[newX][newY] == '#') {
                    break;
                }
                if (grid[newX][newY] == '|' || grid[newX][newY] == '-') {
                    return false;
                }
                int newDir = direction;
                if (grid[newX][newY] == '/') {
                    newDir = direction ^ 1;
                }
                if (grid[newX][newY] == '\\') {
                    newDir = direction ^ 3;
                }
                covers[newX * c + newY] = true;
                direction = newDir;
                x = newX;
                y = newY;
            }
            return true;
        }

        static class Beam {
            int pos;
            boolean[][] covers;

            public Beam(int pos, boolean[][] covers) {
                this.pos = pos;
                this.covers = covers;
            }

        }

        static class TwoSat {
            List<Integer>[] edges;
            List<Integer>[] edgesRev;
            int[] component;
            int[] order;
            int time;

            TwoSat(int n) {
                edges = new List[n];
                edgesRev = new List[n];
                for (int i = 0; i < n; i++) {
                    edges[i] = new ArrayList<>();
                    edgesRev[i] = new ArrayList<>();
                }
            }

            void addEdge(int u, int v) {
                edges[u].add(v);
                edgesRev[v].add(u);
            }

            void dfs1(int u) {
                component[u] = 1;
                for (int v : edges[u]) {
                    if (component[v] >= 0) {
                        continue;
                    }
                    dfs1(v);
                }
                order[time++] = u;
            }

            void dfs2(int u) {
                for (int v : edgesRev[u]) {
                    if (component[v] >= 0) {
                        continue;
                    }
                    component[v] = component[u];
                    dfs2(v);
                }
            }

            int[] findComponents() {
                int n = edges.length;
                component = new int[n];
                order = new int[n];
                time = 0;
                Arrays.fill(component, -1);
                for (int i = 0; i < n; i++) {
                    if (component[i] >= 0) {
                        continue;
                    }
                    dfs1(i);
                }
                Arrays.fill(component, -1);
                int components = 0;
                for (int i = 0; i < n; i++) {
                    int u = order[n - 1 - i];
                    if (component[u] >= 0) {
                        continue;
                    }
                    component[u] = components++;
                    dfs2(u);
                }
                return component;
            }

        }

    }

    static class InputReader {
        public BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            return nextToken();
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (line == null) {
                    return null;
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

    }
}

