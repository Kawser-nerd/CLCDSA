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

        int h = sc.nextInt();
        int w = sc.nextInt();
        boolean[][] field = new boolean[h][w];
        int black = 0;
        for(int i = 0; i < h; i++) {
            String str = sc.next();
            for(int j = 0; j < w; j++) {
                field[i][j] = str.charAt(j) == '.';
                if(!field[i][j]) black++;
            }
        }

        int[][] dist = new int[h][w];
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                dist[i][j] = INF;
            }
        }
        dist[0][0] = 0;
        Deque<Point> que = new ArrayDeque<>();
        que.add(new Point(0, 0));
        while(!que.isEmpty()) {
            Point p = que.poll();
            int x = p.x;
            int y = p.y;
            if(x == h - 1 && y == w - 1) break;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0 <= nx && nx < h && 0 <= ny && ny < w && field[nx][ny] && dist[nx][ny] == INF) {
                    dist[nx][ny] = dist[x][y] + 1;
                    que.add(new Point(nx, ny));
                }
            }
        }

        if(dist[h - 1][w - 1] == INF) System.out.println(-1);
        else System.out.println(h * w - black - dist[h - 1][w - 1] - 1);

        sc.close();
    }
}