import java.awt.*;
import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        int T = sc.nextInt();

        int[][] s = new int[H][W];
        int sx = 0;
        int sy = 0;
        for (int i = 0; i < H; i++) {
            String str = sc.next();
            for (int w = 0; w < W; w++) {
                s[i][w] = str.charAt(w);
                if (s[i][w] == 'S') {
                    sx = i;
                    sy = w;
                }
            }
        }

        // 2????(0?Integer.MAX_VALUE), log2(N) = 30??
        long min = 1;
        long max = 1_000_000_000;
        long x = (min + max) / 2;

        long lastOk = 0;

        while (min <= max) {
            if (canGoal(s, H, W, T, sx, sy, x)) {
                min = x + 1;
                lastOk = x;
            } else {
                max = x - 1;
            }
            x = (min + max) / 2;
        }

        out.println(lastOk);
    }

    public static boolean canGoal(int[][] s, int H, int W, int T, int sx, int sy, long x) {

        long[][] moveCosts = new long[H][W];
        for (int h = 0; h < H; h++) {
            Arrays.fill(moveCosts[h], -1);
        }


        Queue<Point> que = new ArrayDeque<>();
        que.add(new Point(sx, sy));
        moveCosts[sx][sy] = 0;

        int[][] move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!que.isEmpty()) {

            Point p = que.poll();
            int px = p.x;
            int py = p.y;

            for (int i = 0; i < 4; i++) {
                int nx = px + move[i][0];
                int ny = py + move[i][1];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                    long cost = 0;

                    if (s[nx][ny] == '#') {
                        cost += x;
                    } else if (s[nx][ny] == '.') {
                        cost += 1;
                    } else if (s[nx][ny] == 'S') {
                        continue;
                    } else { // s[nx][ny] == 'G'
                        if (moveCosts[px][py] < T) {
                            return true;
                        }
                    }

                    if (moveCosts[nx][ny] == -1 || moveCosts[nx][ny] > moveCosts[px][py] + cost) {
                        moveCosts[nx][ny] = moveCosts[px][py] + cost;
                        que.add(new Point(nx, ny));
                    }
                }
            }
        }

        return false;
    }
}