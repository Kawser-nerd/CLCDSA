import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int W = sc.nextInt();
    int H = sc.nextInt();
    int N = sc.nextInt();
    boolean[][] s = new boolean[W][H];
    for(int i = 0; i < N; i++){
      int x = sc.nextInt();
      int y = sc.nextInt();
      int a = sc.nextInt();
      switch(a){
        case 1:
          for(int j = 0; j < H; j++){
            for(int k = 0; k < x; k++){
              s[k][j] = true;
            }
          }
          break;
        case 2:
          for(int j = 0; j < H; j++){
            for(int k = x; k < W; k++){
              s[k][j] = true;
            }
          }
          break;
        case 3:
          for(int j = 0; j < y; j++){
            for(int k = 0; k < W; k++){
              s[k][j] = true;
            }
          }
          break;
        case 4:
          for(int j = y; j < H; j++){
            for(int k = 0; k < W; k++){
              s[k][j] = true;
            }
          }
          break;
      }
    }
    int sum = 0;
    for(int i = 0; i < W; i++){
      for(int j = 0; j < H; j++){
        sum += (s[i][j] == false) ? 1:0;
      }
    }
    System.out.println(sum);
  }
}