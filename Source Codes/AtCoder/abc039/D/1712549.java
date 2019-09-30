import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        boolean[][] isBlack = new boolean[H][W];
        for (int i = 0; i < H; i++) {
            String S = sc.next();
            for (int j = 0; j < W; j++) {
                isBlack[i][j] = S.charAt(j) == '#';
            }
        }
        boolean[][] inflated = new boolean[H][W];
        int[] xkinbou = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        int[] ykinbou = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                inflated[i][j] = true;
                for (int k = 0; k < 9; k++) {
                    if (i + ykinbou[k] >= 0 && i + ykinbou[k] < H && j + xkinbou[k] >= 0 && j + xkinbou[k] < W && !isBlack[i + ykinbou[k]][j + xkinbou[k]]) {
                        inflated[i][j] = false;
                        break;
                    }
                }
            }
        }
        boolean[][] shrinked = new boolean[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                shrinked[i][j] = false;
                for (int k = 0; k < 9; k++) {
                    if (i + ykinbou[k] >= 0 && i + ykinbou[k] < H && j + xkinbou[k] >= 0 && j + xkinbou[k] < W && inflated[i + ykinbou[k]][j + xkinbou[k]]) {
                        shrinked[i][j] = true;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (isBlack[i][j] != shrinked[i][j]) {
                    System.out.println("impossible");
                    return;
                }
            }
        }
        System.out.println("possible");
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                System.out.print(inflated[i][j] ? '#' : '.');
            }
            System.out.println();
        }
    }
}