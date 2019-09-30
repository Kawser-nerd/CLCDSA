import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        try (Scanner in = new Scanner(System.in)) {
            String[] split = in.nextLine().split(" ");
            int H = Integer.parseInt(split[0]);
            int W = Integer.parseInt(split[1]);
            int K = Integer.parseInt(split[2]);

            int startH = -1;
            int startW = -1;

            int[][] board = new int[H][W];
            for (int h = 0; h < H; h++) {
                String line = in.nextLine();
                Utils.debug(h, line);
                for (int w = 0; w < W; w++) {
                    char charAt = line.charAt(w);
                    board[h][w] = charAt == '#' ? 1 : 0;
                    if (charAt == 'S') {
                        startH = h;
                        startW = w;
                    }
                }
            }

            int min = (int) 1e9;

            int[] dr = new int[] { -1, 0, 0, 1, 0, };
            int[] dc = new int[] { 0, -1, 1, 0, 0, };

            int[][] used = new int[H][W];
            for (int i = 0; i < used.length; i++) {
                for (int j = 0; j < used[i].length; j++) {
                    used[i][j] = (int) 1e9;
                }
            }
            LinkedList<State> queue = new LinkedList<>();
            {
                State e = new State(startH, startW, 0, 0);
                queue.addLast(e);
            }
            LinkedList<State> queue2 = new LinkedList<>();
            for (; !queue.isEmpty();) {
                State current = queue.pollFirst();

                if (current.numMagics == 1) {
                    queue2.add(new State(current.h, current.w, current.numMagics + 1, K));
                }

                if (current.h == 0 || current.h == H - 1 || current.w == 0 || current.w == W - 1) {
                    min = Math.min(min, current.numMagics);
                }

                for (int d = 0; d < 5; d++) {
                    int nextH = current.h + dr[d];
                    int nextW = current.w + dc[d];

                    if (nextH < 0 || nextH >= H || nextW < 0 || nextW >= W) {
                        continue;
                    }
                    if (board[nextH][nextW] == 1) {
                        continue;
                    }

                    int nextNumMagics = current.numMagics;
                    int nextMoveK = current.moveK - 1;

                    if (nextMoveK < 0) {
                        nextNumMagics++;
                        nextMoveK += K;
                    }

                    if (nextNumMagics > 1) {
                        continue;
                    }

                    if (nextNumMagics >= used[nextH][nextW]) {
                        continue;
                    }

                    queue.addLast(new State(nextH, nextW, nextNumMagics, nextMoveK));
                    used[nextH][nextW] = nextNumMagics;
                }

            }
            Utils.debug("queue2.size()", queue2.size());
            for (; !queue2.isEmpty();) {
                State current = queue2.pollFirst();

                if (current.h == 0 || current.h == H - 1 || current.w == 0 || current.w == W - 1) {
                    min = Math.min(min, current.numMagics);
                }

                for (int d = 0; d < 4; d++) {
                    int nextH = current.h + dr[d];
                    int nextW = current.w + dc[d];

                    if (nextH < 0 || nextH >= H || nextW < 0 || nextW >= W) {
                        continue;
                    }

                    int nextNumMagics = current.numMagics;
                    int nextMoveK = current.moveK - 1;

                    if (nextMoveK < 0) {
                        nextNumMagics++;
                        nextMoveK += K;
                    }

                    if (nextNumMagics >= used[nextH][nextW]) {
                        continue;
                    }

                    queue2.addLast(new State(nextH, nextW, nextNumMagics, nextMoveK));
                    used[nextH][nextW] = nextNumMagics;
                }

            }

            for (int i = 0; i < used.length; i++) {
                Utils.debug(i, used[i]);
            }

            System.out.println(min);

        }
    }
}

class State {
    int h;
    int w;
    int numMagics;
    int moveK;

    public State(int h, int w, int numMagics, int moveK) {
        super();
        this.h = h;
        this.w = w;
        this.numMagics = numMagics;
        this.moveK = moveK;
    }
}

final class Utils {
    private Utils() {
    }

    public static final void debug(Object... o) {
        System.err.println(toString(o));
    }

    public static final String toString(Object... o) {
        return Arrays.deepToString(o);
    }

}