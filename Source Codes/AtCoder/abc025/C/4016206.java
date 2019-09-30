import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static int[][] b = new int[2][3];
    static int[][] c = new int[3][2];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sum = 0;
        for (int y = 0 ; y < 2 ; y++) {
            for (int x = 0; x < 3 ; x++) {
                b[y][x] = sc.nextInt();
                sum += b[y][x];
            }
        }
        for (int y = 0 ; y < 3 ; y++ ) {
            for (int x = 0 ; x < 2 ; x++ ) {
                c[y][x] = sc.nextInt();
                sum += c[y][x];
            }
        }
        int[][] board = new int[3][3];
        for (int i = 0 ; i < 3 ; i++) {
            Arrays.fill(board[i], -1);
        }
        int score = eval(new int[3][3], 1);
        System.out.println(score);
        System.out.println(sum - score);

    }

    public static int eval(int[][] board, int turn) {
        if (turn == 10) {
            return calc(board);
        }
        int score = turn % 2 == 1 ? 0 : Integer.MAX_VALUE;
        for (int y = 0; y < 3 ; y++) {
            for (int x = 0 ; x < 3 ; x++) {
                if (board[y][x] == 0) {
                    board[y][x] = 1 + (turn % 2);
                    if (turn % 2 == 1) {
                        score = Math.max(score, eval(board, turn + 1));
                    } else {
                        score = Math.min(score, eval(board, turn + 1));
                    }
                    board[y][x] = 0;
                }
            }
        }
        return score;
    }

    public static int calc(int[][] board) {
        int score = 0;
        for (int y = 0 ; y < 2 ; y++) {
            for (int x = 0; x < 3 ; x++) {
                if (board[y][x] == board[y + 1][x]) {
                    score += b[y][x];
                }
            }
        }
        for (int y = 0 ; y < 3 ; y++) {
            for (int x = 0 ; x < 2 ; x++) {
                if (board[y][x] == board[y][x + 1]) {
                    score += c[y][x];
                }
            }
        }
        return score;
    }

}