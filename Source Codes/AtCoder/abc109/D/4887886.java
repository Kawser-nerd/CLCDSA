import java.awt.*;
import java.util.*;
import java.util.List;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();

        int[][] a = new int[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        int cnt = 0;
        List<Point> from = new ArrayList<>();
        List<Point> to = new ArrayList<>();
        for (int i = 0; i < H - 1; i++) {
            for (int j = 0; j < W; j++) {
                if (a[i][j] % 2 != 0) {
                    a[i][j] -= 1;
                    a[i + 1][j] += 1;
                    cnt++;

                    from.add(new Point(i + 1, j + 1));
                    to.add(new Point(i + 2, j + 1));
                }
            }
        }

        for (int j = 0; j < W - 1; j++) {
            if (a[H - 1][j] % 2 != 0) {
                a[H - 1][j] -= 1;
                a[H - 1][j + 1] += 1;
                cnt++;

                from.add(new Point(H, j + 1));
                to.add(new Point(H, j + 2));
            }
        }

        out.println(cnt);
        for(int i = 0; i < from.size(); i++){
            Point f = from.get(i);
            Point t = to.get(i);
            out.println(f.x + " " + f.y + " " + t.x + " " + t.y);
        }
    }
}