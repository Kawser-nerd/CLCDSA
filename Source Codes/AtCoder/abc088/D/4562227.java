import java.util.*;

public class Main {

    private static final char BLACK = '#';
    private static final char WHITE = '.';

    public static void main(String[] args) {
        new Main().execute();
    }

    public void execute() {
        Scanner sc = new Scanner(System.in);
        final int H = sc.nextInt();
        final int W = sc.nextInt();
        sc.nextLine();

        char[][] board = new char[H][W];

        int whiteCells = 0;
        for (int i = 0; i < H; i++) {
            String s = sc.nextLine();
            for (int j = 0; j < W; j++) {
                board[i][j] = s.charAt(j);
                if (board[i][j] == WHITE) {
                    whiteCells += 1;
                }
            }
        }

        final Point start = new Point(0, 0);
        final Point goal = new Point(H - 1, W - 1);

        int minSteps = bfs(start, goal, board);

        System.out.println(minSteps > 0 ? whiteCells - minSteps : minSteps);
        sc.close();
    }

    private int bfs(Point start, Point goal, char[][] board) {
        int h = board.length;
        int w = board[0].length;
        boolean[][] visited = new boolean[h][w];

        Queue<Point> fifo = new LinkedList<>();
        start.turn = 1;
        fifo.add(start);
        visited[start.x][start.y] = true;
        while (!fifo.isEmpty()) {
            Point p = fifo.poll();

            if (p.equals(goal)) {
                return p.turn;
            }

            List<Point> moves = new ArrayList<>();
            moves.add(new Point(p.x + 1, p.y));
            moves.add(new Point(p.x - 1, p.y));
            moves.add(new Point(p.x, p.y + 1));
            moves.add(new Point(p.x, p.y - 1));

            for (Point moveTo : moves) {
                if (moveTo.x >= 0 && moveTo.y >= 0 && moveTo.x < h && moveTo.y < w && !visited[moveTo.x][moveTo.y] && board[moveTo.x][moveTo.y] == WHITE) {
                    visited[moveTo.x][moveTo.y] = true;
                    moveTo.turn = p.turn + 1;
                    fifo.add(moveTo);
                }
            }
        }

        return -1;
    }


    class Point {
        public final int x;
        public final int y;
        public int turn;

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