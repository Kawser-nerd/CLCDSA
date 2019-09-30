import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int C = sc.nextInt();
        int sy = sc.nextInt() - 1;
        int sx = sc.nextInt() - 1;
        int gy = sc.nextInt() - 1;
        int gx = sc.nextInt() - 1;

        String[][] c = new String[R][C];
        for (int i = 0; i < R; i++) {
            c[i] = sc.next().split("");
        }

        Queue<Point> points = new ArrayDeque<Point>();
        points.add(new Point(sy, sx, 0));
        c[sy][sx] = "!";  //?????????

        out.println(bfs(c, points, new Point(gy, gx, -1)));
    }

    public static int bfs(String[][] cource, Queue<Point> points, Point goal) {
        Point point = points.poll();

        int count = point.count;
        if (point.x == goal.x && point.y == goal.y) {
            return count;
        }

        int[][] move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        count++;
        for (int i = 0; i < move.length; i++) {
            Point nextPoint = new Point(point.y + move[i][0], point.x + move[i][1], count);
            if (cource[nextPoint.y][nextPoint.x].equals(".")) {
                cource[nextPoint.y][nextPoint.x] = "!";  //?????????
                points.add(nextPoint);
            }
        }

        return bfs(cource, points, goal);
    }
}

class Point {
    int y;
    int x;
    int count;

    Point(int y, int x, int count) {
        this.y = y;
        this.x = x;
        this.count = count;
    }
}