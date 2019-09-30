import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] xy = new int[3][2];
        for (int i = 0; i < 3; i++) {
            xy[i][0] = sc.nextInt();
            xy[i][1] = sc.nextInt();
        }

        // xa, xy?(0, 0)??????????????
        int xMove = -xy[0][0];
        int yMove = -xy[0][1];
        for(int i = 0; i < 3; i++){
            xy[i][0] += xMove;
            xy[i][1] += yMove;
        }
        out.println(Math.abs(xy[1][0] * xy[2][1] - xy[1][1] * xy[2][0]) / 2.0);
    }
}