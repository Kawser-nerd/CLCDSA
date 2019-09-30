import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int H = sc.nextInt();
    int W = sc.nextInt();
    char[][] output = new char[H][W];
    for(int i = 0; i < H; i++) {
      String s = sc.next();
      for(int j = 0; j < W; j++) {
        output[i][j] = s.charAt(j); 
      }
    }
    char[][] input = new char[H][W];
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        int[] rowMove = {-1, 0, 1};
        int[] columnMove = {-1, 0, 1};
        int count = 0;
        for(int k = 0; k < 3; k++) {
          for(int l = 0; l < 3; l++) {
            int x = i + rowMove[k];
            int y = j + columnMove[l];
            if(0 <= x && x < H && 0 <= y && y < W && output[x][y] == '.') count++;
          }
        }
        if(count == 0) {
          input[i][j] = '#';
        } else {
          input[i][j] = '.';
        }
      }
    }
    char[][] output2 = new char[H][W];
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        int[] rowMove = {-1, 0, 1};
        int[] columnMove = {-1, 0, 1};
        int count = 0;
        for(int k = 0; k < 3; k++) {
          for(int l = 0; l < 3; l++) {
            int x = i + rowMove[k];
            int y = j + columnMove[l];
            if(0 <= x && x < H && 0 <= y && y < W && input[x][y] == '#') count++;
          }
        }
        if(count == 0) {
          output2[i][j] = '.';
        } else {
          output2[i][j] = '#';
        }
      }
    }
    boolean flg = true;
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        if(output[i][j] != output2[i][j]) flg = false;
      }
    }
    if(flg) {
      System.out.println("possible");
      for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
          System.out.print(String.valueOf(input[i][j]));
          if(j == W - 1) System.out.println();
        }
      } 
    } else {
      System.out.println("impossible");
    }
  }
}