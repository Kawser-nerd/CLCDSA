import java.nio.Buffer;
import java.util.*;
import java.io.*;

public class Main {

    private static final char BLOCK = '#';
    private static final char LOAD = '.';
    private static final char START = 's';
    private static final char GOAL = 'g';

    public static void main(String[] args) {
        try {
            new Main().execute();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void execute() throws IOException {
//        Scanner sc = new Scanner(System.in);
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] hw = in.readLine().split(" ");
        final int H = Integer.parseInt(hw[0]);
        final int W = Integer.parseInt(hw[1]);

        char[][] town = new char[H][W];
        int sx, sy, gx, gy;
        sx = sy = gx = gy = -1;

        for (int i = 0; i < H; i++) {
            String s = in.readLine();
            for (int j = 0; j < W; j++) {
                town[i][j] = s.charAt(j);
                switch (town[i][j]) {
                    case START:
                        sx = i;
                        sy = j;
                        break;
                    case GOAL:
                        gx = i;
                        gy = j;
                        break;
                }
            }
        }

        assert (sx >= 0 && sy >= 0 && gx >= 0 && gy >= 0);
        final Point start = new Point(sx, sy);
        final Point goal = new Point(gx, gy);

        int[][] cost = new int[H][W];

        for (int i = 0; i < cost.length; i++) {
            Arrays.fill(cost[i], 100000);
        }

//        cost[sx][sy] = 0;


        System.out.println(bfs(start, goal, town, cost) ? "YES" : "NO");
        in.close();
    }

    private boolean bfs(Point start, Point goal, char[][] town, int[][] cost) {
        int h = town.length;
        int w = town[0].length;
        boolean reachable = false;

        Deque<Point> deque = new LinkedList<>();
        deque.push(start);
        cost[start.x][start.y] = 0;

        while (!deque.isEmpty()) {
            Point p = deque.poll();
            if (p.equals(goal)) {
                if (cost[goal.x][goal.y] <= 2) {
                    reachable = true;
                }
                break;
            }

            List<Point> moves = new ArrayList<>();
            moves.add(new Point(p.x + 1, p.y));
            moves.add(new Point(p.x - 1, p.y));
            moves.add(new Point(p.x, p.y + 1));
            moves.add(new Point(p.x, p.y - 1));

            for (Point mv : moves) {
                if (mv.x >= 0 && mv.y >= 0 && mv.x < h && mv.y < w) {
                    switch (town[mv.x][mv.y]) {
                        case BLOCK:
                            if (cost[mv.x][mv.y] > cost[p.x][p.y] + 1) {
                                cost[mv.x][mv.y] = cost[p.x][p.y] + 1;
                                if (cost[mv.x][mv.y] <= 2) {
                                    deque.addLast(mv);
                                }
                            }
                            break;
                        case LOAD:
                        case GOAL:
                            if (cost[mv.x][mv.y] > cost[p.x][p.y]) {
                                cost[mv.x][mv.y] = cost[p.x][p.y];
                                deque.addFirst(mv);
                            }
                            break;
                    }
                }
            }
        }
        return reachable;
    }

    class Point {
        public final int x;
        public final int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object obj) {
            if (!(obj instanceof Point)) {
                return false;
            }
            Point that = (Point) obj;
            return (this.x == that.x && this.y == that.y);
        }

        @Override
        public int hashCode() {
            return Objects.hash(this.x, this, y);
        }
    }
}