import java.util.*;

public class Main{           
      static int[][] b = new int[2][3];
  static int[][] c = new int[3][2];
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    // ??????????
    int sum = 0;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 3; j++) {
        b[i][j] = sc.nextInt();
        sum += b[i][j];
      }
    }
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 2; j++) {
        c[i][j] = sc.nextInt();
        sum += c[i][j];
      }
    }
    char[][] board = new char[3][3];
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        board[i][j] = '.';
      }
    }
    int score = dfs(1, board);
    System.out.println((sum + score) / 2);
    System.out.println((sum - score) / 2);
  }

  // n???????????????-??????
  public static int dfs(int n, char[][] board) {
    if(n == 10) {
      int sente = 0;
      int koute = 0;
      for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
          if(board[i][j] == board[i + 1][j]) {
            sente += b[i][j];
          } else {
            koute += b[i][j];
          }
        }
      }
      for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
          if(board[i][j] == board[i][j + 1]) {
            sente += c[i][j];
          } else {
            koute += c[i][j];
          }
        }
      }
      return sente - koute;
    } else {
      if(n % 2 == 0) {
        int score = Integer.MAX_VALUE;
        for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 3; j++) {
            if(board[i][j] == '.') {
              board[i][j] = 'x';
              score = Math.min(score, dfs(n + 1, board));
              board[i][j] = '.';
            }
          }
        }
        return score;
      } else {
        int score = -10000;
        for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 3; j++) {
            if(board[i][j] == '.') {
              board[i][j] = 'o';
              score = Math.max(score, dfs(n + 1, board));
              board[i][j] = '.';
            }
          }
        }
        return score;
      }
    }
  }     
}