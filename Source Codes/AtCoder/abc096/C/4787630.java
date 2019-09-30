import java.util.*;

import static java.lang.System.*;

public class Main {
    static final int[] dx = new int[]{1, 0, -1, 0};
    static final int[] dy = new int[]{0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();

        boolean[][] s = new boolean[H][W];
        for (int i = 0; i < H; i++) {
            String str = sc.next();
            for (int j = 0; j < W; j++) {
                s[i][j] = str.charAt(j) == '#' ? true : false;
            }
        }

        boolean isOk = true;
        loop:
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (s[i][j]) {
                    boolean tmpIsOk = false;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if (ni >= 0 && ni < H && nj >= 0 && nj < W && s[ni][nj]) {
                            tmpIsOk = true;
                        }
                    }

                    if (!tmpIsOk) {
                        isOk = false;
                        break loop;
                    }
                }

            }
        }

        if (isOk) {
            out.println("Yes");
        } else {
            out.println("No");
        }
    }
}