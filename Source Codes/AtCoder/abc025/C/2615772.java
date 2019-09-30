import java.util.*;

public class Main {
    static int[][] B, C;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int sum = 0;
        B = new int[2][3];
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                B[i][j] = in.nextInt();
                sum += B[i][j];
            }
        }
        C = new int[3][2];
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 2; j++) {
                C[i][j] = in.nextInt();
                sum += C[i][j];
            }
        }
        
        int ans = rec(new int[3][3], 1);
        System.out.println(ans);
        System.out.println(sum - ans);
    }
    
    static int rec(int[][] board, int turn) {
        if(turn == 9) {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(board[i][j] == 0) {
                        board[i][j] = 1;
                        int ret = calc(board);
                        board[i][j] = 0;
                        return ret;
                    }
                }
            }
        }
        int max = 0;
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == 0) {
                    board[i][j] = turn % 2 == 1 ? 1 : 2;
                    int score = rec(board, turn + 1);
                    max = Math.max(max, score);
                    min = Math.min(min, score);
                    board[i][j] = 0;
                }
            }
        }
        return turn % 2 == 1 ? max : min;
    }
    
    static int calc(int[][] board) {
        int score = 0;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == board[i+1][j]) {
                    score += B[i][j];
                }
            }
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 2; j++) {
                if(board[i][j] == board[i][j+1]) {
                    score += C[i][j];
                }
            }
        }
        return score;
    }
}