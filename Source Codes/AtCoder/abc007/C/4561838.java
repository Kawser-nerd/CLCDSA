import java.util.*;

public class Main {

    public static void main(String[] args) {
        new Main().execute();
    }

    public void execute() {
        Scanner sc = new Scanner(System.in);
        final int R = sc.nextInt();
        final int C = sc.nextInt();

        Point start = new Point(sc.nextInt() - 1, sc.nextInt() - 1);
        Point goal = new Point(sc.nextInt() - 1, sc.nextInt() - 1);

        char[][] field = new char[R][C];

        sc.nextLine();

        for (int i = 0; i < R; i++) {
            String s = sc.nextLine();
            for (int j = 0; j < C; j++) {
                field[i][j] = s.charAt(j);
            }
        }

        System.out.println(bfs(start, goal, field));
        sc.close();
    }

    private int bfs(Point start, Point goal, char[][] field) {
        Queue<Point> fifo = new LinkedList<>();
        start.turn = 0;
        fifo.add(start);

        while (!fifo.isEmpty()) {
            Point p = fifo.poll();
            field[p.x][p.y] = '-'; // visited
            if (p.equals(goal)) {
                return p.turn;
            }

            move(p.x + 1, p.y, field, p.turn + 1, fifo);
            move(p.x - 1, p.y, field, p.turn + 1, fifo);
            move(p.x, p.y + 1, field, p.turn + 1, fifo);
            move(p.x, p.y - 1, field, p.turn + 1, fifo);
        }
        return -1;
    }

    private void move(int x, int y, char[][] field, int turn, Queue<Point> queue) {
        if (x >= 0 && y >= 0 && x < field.length && y < field[x].length) {
            if (field[x][y] == '.') {
                Point p = new Point(x, y);
                field[x][y] = '-'; // visited
                p.turn = turn;
                queue.add(p);
            }
        }
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