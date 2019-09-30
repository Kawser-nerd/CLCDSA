import java.util.*;

public class Main {

    int H, W;
    boolean[][] rg, bg, pg;

    void run() {

        Scanner sc = new Scanner(System.in);

        H = sc.nextInt();
        W = sc.nextInt();

        rg = new boolean[H][W];
        bg = new boolean[H][W];
        pg = new boolean[H][W];


        for (int h = 0; h < H; h++) {
            if (h % 2 == 0) {
                for (int w = 0; w < W; w++) rg[h][w] = true;
            } else {
                for (int w = 0; w < W; w++) bg[h][w] = true;
            }
            bg[h][W - 1] = rg[h][0] = true;
            rg[h][W - 1] = bg[h][0] = false;
        }

        for (int h = 0; h < H; h++) {
            String l = sc.next();
            for (int w = 0; w < W; w++) {
                if (l.charAt(w) == '#') bg[h][w] = rg[h][w] = true;
                pg[h][w] = bg[h][w] & rg[h][w];
            }
        }
        printBoard(rg);

        System.out.println();

        printBoard(bg);
    }

    void printBoard(boolean[][] b) {
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) System.out.print(b[h][w] ? '#' : '.');
            System.out.println();
        }
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }
}