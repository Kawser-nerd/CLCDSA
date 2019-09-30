import java.awt.Point;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
    private static final int[] dy = {0, 1, 0, -1};
    private static final int[] dx = {1, 0, -1, 0};
    private static final int INF = 10;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int h = sc.nextInt();
        int w = sc.nextInt();
        boolean[][] field = new boolean[h][w];
        int sx = -1;
        int sy = -1;
        int gx = -1;
        int gy = -1;
        for(int i = 0; i < h; i++) {
            String str = sc.next();
            for(int j = 0; j < w; j++) {
                char c = str.charAt(j);
                field[i][j] = c != '#';
                if(c == 's') {
                    sx = i;
                    sy = j;
                }else if(c == 'g') {
                    gx = i;
                    gy = j;
                }
            }
        }

        int[][] cost = new int[h][w];
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cost[i][j] = INF;
            }
        }
        cost[sx][sy] = 0;
        Deque<Point> que = new ArrayDeque<>();
        que.add(new Point(sx, sy));
        while(!que.isEmpty()) {
            Point p = que.poll();
            int x = p.x;
            int y = p.y;
            if(x == gx && y == gy) break;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0 <= nx && nx < h && 0 <= ny && ny < w) {
                    if(field[nx][ny]) {
                        if(cost[x][y] < cost[nx][ny]) {
                            cost[nx][ny] = cost[x][y];
                            que.add(new Point(nx, ny));
                        }
                    }else {
                        if(cost[x][y] < 2 && cost[x][y] + 1 < cost[nx][ny]) {
                            cost[nx][ny] = cost[x][y] + 1;
                            que.add(new Point(nx, ny));
                        }
                    }
                }
            }
        }

        System.out.println(cost[gx][gy] <= 2? "YES" : "NO");

        sc.close();
    }
}