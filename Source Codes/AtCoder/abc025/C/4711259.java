import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    static int board[][] = new int[3][3];
    static int b[][] = new int[2][3];
    static int a[][] = new int[3][2];

    public static void main(String[] args) {
        int sum = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                b[i][j] = sc.nextInt();
                sum += b[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                a[i][j] = sc.nextInt();
                sum += a[i][j];
            }
        }


        int chokudai = dfs(0);
        System.out.println(chokudai);
        System.out.println(sum - chokudai);
    }

    private static int dfs(int turn) {
        if (turn == 9) {
            return calc();
        }
        if (turn % 2 == 0) {
            // ?????????????????
            int max = Integer.MIN_VALUE;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] != 0) continue;
                    board[i][j] = 1;
                    max = Math.max(max, dfs(turn + 1));
                    board[i][j] = 0;
                }
            }
            return max;
        } else {
            // ?????????????????
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] != 0) continue;
                    board[i][j] = -1;
                    min = Math.min(min, dfs(turn + 1));
                    board[i][j] = 0;
                }
            }
            return min;
        }
    }

    private static int calc() {
        int sum = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == board[i+1][j]) {
                    sum += b[i][j];
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                if (board[i][j] == board[i][j+1]) {
                    sum += a[i][j];
                }
            }
        }
        return sum;
    }
}