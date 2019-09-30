import java.awt.Point;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
    private static final int[] dy = {0, 1, 0, -1};
    private static final int[] dx = {1, 0, -1, 0};
    private static final int INF = 10000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int r = sc.nextInt();
        int c = sc.nextInt();
        int sy = sc.nextInt() - 1;
        int sx = sc.nextInt() - 1;
        int gy = sc.nextInt() - 1;
        int gx = sc.nextInt() - 1;
        boolean[][] maze = new boolean[r][c];
        for(int i = 0; i < r; i++) {
            String str = sc.next();
            for(int j = 0; j < c; j++) {
                char chr = str.charAt(j);
                maze[i][j] = chr == '.';
            }
        }

        int[][] dist = new int[r][c];
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                dist[i][j] = INF;
            }
        }
        Deque<Point> que = new ArrayDeque<>();
        que.add(new Point(sx, sy));
        dist[sy][sx] = 0;

        while(true) {
            Point p = que.poll();
            int y = p.y;
            int x = p.x;
            if(y == gy && x == gx) break;
            
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(maze[ny][nx] && dist[ny][nx] == INF) {
                    dist[ny][nx] = dist[y][x] + 1;
                    que.add(new Point(nx, ny));
                }
            }
        }

        System.out.println(dist[gy][gx]);

        sc.close();
    }
}