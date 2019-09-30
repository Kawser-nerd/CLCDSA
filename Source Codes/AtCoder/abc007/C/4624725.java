import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * ABC007C_breadth_first
 */
public class Main {
    private static Scanner sc;
    private static int R;
    private static int C;
    private static char[][] maze;
    private static boolean[][] reached;

    // ???????static???????
    // ???????????
    static class Point {
        int r;
        int c;
        int cnt; // ??????????????????

        public Point(int r, int c, int cnt) {
            this.r = r;
            this.c = c;
            this.cnt = cnt;
        }
    }

    public static void main(String[] args) {
        sc = new Scanner(System.in);

        // 1???????????
        String[] RC = sc.nextLine().split(" ");
        R = Integer.parseInt(RC[0]);
        C = Integer.parseInt(RC[1]);
        maze = new char[R][C];
        reached = new boolean[R][C];

        // ???????
        String[] startRC = sc.nextLine().split(" ");
        int startR = Integer.parseInt(startRC[0]) - 1;
        int startC = Integer.parseInt(startRC[1]) - 1;

        // ??????
        String[] goalRC = sc.nextLine().split(" ");
        int goalR = Integer.parseInt(goalRC[0]) - 1;
        int goalC = Integer.parseInt(goalRC[1]) - 1;

        // ????????
        for (int i = 0; i < R; i++) {
            // 1????????
            maze[i] = sc.nextLine().toCharArray();
        }

        // ????????
        Queue<Point> q = new LinkedList<Point>();
        q.add(new Point(startR, startC, 0)); // ???????0???????
        reached[startR][startC] = true; // ??????????

        // ?????????????????????4????
        // (dr,dc) = ?(1,0),?(-1,0),?(0,1),?(0.-1)
        int[] dr = { 1, -1, 0, 0 };
        int[] dc = { 0, 0, 1, -1 };

        // BFS???
        int answer = 0;
        int tmpR = 0;
        int tmpC = 0;
        int tmpCnt = 0;
        while (!q.isEmpty()) {
            // ???????????
            Point now = q.poll();

            // ???????????
            if (now.r == goalR && now.c == goalC) {
                answer = now.cnt;
                break;
            }

            // ?????????????????
            tmpCnt = now.cnt + 1; // ????
            for (int i = 0; i < dc.length; i++) {// dr??dc??OK
                tmpR = now.r + dr[i];
                tmpC = now.c + dc[i];

                // ????????,???????????,??????
                if (!(tmpR < 0) && !(tmpR >= R) && !(tmpC < 0) && !(tmpC >= C) && !reached[tmpR][tmpC]
                        && !(maze[tmpR][tmpC] == '#')) {
                    q.add(new Point(tmpR, tmpC, tmpCnt));
                    reached[tmpR][tmpC] = true;
                }
            }

        }

        System.out.println(answer);

        sc.close();
    }
}