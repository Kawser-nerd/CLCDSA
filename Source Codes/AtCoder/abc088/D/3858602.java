// ABC088D Grid Repainting
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        String[] masu = new String[h];
        for (int i = 0; i < h; i++) {
            masu[i] = sc.next();
        }
        // ?????????????????????
        int[][] cnt = new int[h + 2][w + 2];
        int siro = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (masu[i].charAt(j) == '#') {
                    cnt[i + 1][j + 1] = -1;
                } else {
                    cnt[i + 1][j + 1] = 0;
                    siro++;
                }
            }
        }
        // ????
        for (int i = 0; i < w + 2; i++) {
            cnt[0][i] = -1;
            cnt[h + 1][i] = -1;
        }
        for (int i = 0; i < h + 2; i++) {
            cnt[i][0] = -1;
            cnt[i][w + 1] = -1;
        }
        cnt[1][1] = 1;

        int dx[] = { 0, 1, 0, -1 };
        int dy[] = { 1, 0, -1, 0 };
        point pos = new point(1, 1);
        LinkedList<point> queue = new LinkedList<point>();
        queue.add(pos);
        /*
         * for (int i = 0; i < h + 2; i++) { for (int j = 0; j < w + 2; j++) {
         * System.out.print(cnt[i][j]); System.out.print("  "); } System.out.println();
         * }
         */
        while (!queue.isEmpty()) {
            point nowpos = queue.removeFirst();
            for (int i = 0; i < 4; i++) {
                int nx = nowpos.x + dx[i];
                int ny = nowpos.y + dy[i];
                if (cnt[ny][nx] == 0) {
                    cnt[ny][nx] = cnt[nowpos.y][nowpos.x] + 1;
                    point npos = new point(nx, ny);
                    queue.add(npos);
                }
            }
        }
        if (cnt[h][w] != 0 && cnt[h][w] != -1) {
            System.out.println(siro - cnt[h][w]);
        } else {
            System.out.println(-1);
        }
    }
}

class point {
    public int x;
    public int y;

    point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}