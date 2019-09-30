import java.awt.*;
import java.util.*;

import static java.lang.System.*;

// https://atcoder.jp/contests/abc088/submissions/4733059
public class Main {
    private static final int INF = 1000;
    private static final int[] dx = {0, 1, 0, -1};
    private static final int[] dy = {1, 0, -1, 0};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();

        boolean[][] field = new boolean[H][W];
        int black = 0;
        for (int i = 0; i < H; i++) {
            String s = sc.next();
            for (int j = 0; j < W; j++) {
                field[i][j] = s.charAt(j) == '.';
                if (!field[i][j]) black++;
            }
        }

        // ?????(wfs)
        ArrayDeque<Point> queue = new ArrayDeque<>();
        queue.add(new Point(0, 0));

        int[][] dist = new int[H][W];
        for (int i = 0; i < H; i++) {
            Arrays.fill(dist[i], INF);
        }
        dist[0][0] = 0;

        while (!queue.isEmpty()) {
            Point p = queue.poll();
            int x = p.x;
            int y = p.y;

            if (x == H - 1 && y == W - 1) {
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (0 <= nx && nx < H && 0 <= ny && ny < W && field[nx][ny] && dist[nx][ny] == INF) {
                    dist[nx][ny] = dist[x][y] + 1;
                    queue.add(new Point(nx, ny));
                }
            }

        }

        if (dist[H - 1][W - 1] == INF) {
            out.println(-1);
        } else {
            out.println(W * H - black - dist[H - 1][W - 1] - 1);
        }
    }
}