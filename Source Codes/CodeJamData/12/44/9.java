import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class D {
    Scanner in;
    PrintWriter out;

    int r, c;
    char[][] map;

    private class TCan {
        public boolean[][] can;
        long HASH;

        private TCan(boolean[][] a) {
            can = new boolean[r][c];
            HASH = 0;
            for (int i = 1; i < r - 1; ++i) for (int j = 1; j < c - 1; ++j) {
                can[i][j] = a[i][j];
                HASH = HASH * 3 + (can[i][j] ? 1 : 0);
            }
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            TCan tCan = (TCan) o;

            if (HASH != tCan.HASH) return false;

            for (int i = 1; i < r - 1; ++i) for (int j = 1; j < c - 1; ++j) if (can[i][j] != tCan.can[i][j]) return false;

            return true;
        }

        @Override
        public int hashCode() {
            return (int) (HASH ^ (HASH >>> 32));
        }
    }

    void doit(int tnum) {
        r = in.nextInt();
        c = in.nextInt();
        map = new char[r][c];
        for (int i = 0; i < r; ++i) {
            String tmp = in.next();
            for (int j = 0; j < c; ++j) map[i][j] = tmp.charAt(j);
        }
        out.println("Case #" + tnum + ":");
        System.err.println("Case #" + tnum + ":");
        for (char cave_num = '0'; cave_num <= '9'; ++cave_num) {
            for (int cave_i = 0; cave_i < r; ++cave_i) for (int cave_j = 0; cave_j < c; ++cave_j) if (map[cave_i][cave_j] == cave_num) {
                //cave found. Processing

                //stupid stuff:
                boolean[][] can = new boolean[r][c];
                for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) can[i][j] = false;
                can[cave_i][cave_j] = true;
                boolean finish = false;
                while (!finish) {
                    finish = true;
                    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) if (map[i][j] != '#' && !can[i][j]) {
                        if (can[i + 1][j] || can[i][j + 1] || can[i][j - 1]) {
                            can[i][j] = true;
                            finish = false;
                        }
                    }
                }
                int nc = 0;
                for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) if (can[i][j]) ++nc;

                boolean lucky = false;
                ArrayList<TCan> bfs = new ArrayList<TCan>();
                HashSet<TCan> visited = new HashSet<TCan>();
                bfs.add(new TCan(can));
                visited.add(new TCan(can));
                for (int index = 0; index < bfs.size(); ++index) {
                    //l
                    TCan q = bfs.get(index);

                    boolean good = true;
                    for (int i = 1; i < r - 1; ++i) for (int j = 1; j < c - 1; ++j) {
                        if (q.can[i][j] != ((i == cave_i) && (j == cave_j))) good = false;
                    }
                    if (good) {
                        lucky = true;
                        break;
                    }

                    TCan next;
                    for (int i = 1; i < r - 1; ++i) for (int j = 1; j < c - 1; ++j) {
                        can[i][j] = map[i][j] != '#' && (q.can[i][j + 1] || (q.can[i][j] && map[i][j - 1] == '#'));
                    }
                    next = new TCan(can);
                    if (!visited.contains(next)) {
                        visited.add(next);
                        bfs.add(next);
                    }

                    for (int i = 1; i < r - 1; ++i) for (int j = 1; j < c - 1; ++j) {
                        can[i][j] = map[i][j] != '#' && (q.can[i][j - 1] || (q.can[i][j] && map[i][j + 1] == '#'));
                    }
                    next = new TCan(can);
                    if (!visited.contains(next)) {
                        visited.add(next);
                        bfs.add(next);
                    }

                    for (int i = 1; i < r - 1; ++i) for (int j = 1; j < c - 1; ++j) {
                        can[i][j] = map[i][j] != '#' && (q.can[i - 1][j] || (q.can[i][j] && map[i + 1][j] == '#'));
                    }
                    next = new TCan(can);
                    if (!visited.contains(next)) {
                        visited.add(next);
                        bfs.add(next);
                    }



                }
                out.println(cave_num + ": " + nc + " " + (lucky ? "Lucky" : "Unlucky"));

            }
        }
    }

    public void doit() throws IOException{
        out = new PrintWriter(new FileOutputStream("output.txt"));
        in = new Scanner(new FileInputStream("D-small-attempt0.in"));
        int T = in.nextInt();
        for (int i = 0; i < T; ++i) {
            doit(i + 1);
        }
        out.close();

    }
    public static void main(String[] args) throws IOException{
        new D().doit();
    }
}
