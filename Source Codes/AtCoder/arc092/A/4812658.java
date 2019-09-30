import java.util.*;

public class Main {
    private static class Point {
        int x, y, pair;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
            this.pair = -1;
        }
    }

    int map[][];
    Point r[], b[];

    public void main(Scanner sc) {
        int n = sc.nextInt();
        r = new Point[n];
        b = new Point[n];
        for (int i = 0; i < n; i++) {
            r[i] = new Point(sc.nextInt(), sc.nextInt());
        }
        for (int i = 0; i < n; i++) {
            b[i] = new Point(sc.nextInt(), sc.nextInt());
        }

        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((r[i].x < b[j].x) && (r[i].y < b[j].y)) {
                    map[i][j] = 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (foo(i, n, new BitSet()) ? 1 : 0);
        }
        System.out.println(ans);
    }

    private boolean foo(int v, int n, BitSet bs) {
        for (int i = 0; i < n; i++) {
            if ((map[v][i] != 1) || (bs.get(i))) {
                continue;
            }

            bs.set(i);
            if (b[i].pair == -1 || foo(b[i].pair, n, bs)) {
                b[i].pair = v;
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().main(sc);
        } catch (Exception e) {
            throw e;
        }
    }
}