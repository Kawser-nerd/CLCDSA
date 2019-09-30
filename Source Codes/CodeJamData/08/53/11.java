package r3;

import java.util.Arrays;
import java.util.Scanner;

public class Csmall {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int C = sc.nextInt();
    for(int cn = 1 ; cn <= C ; cn++){
      int M = sc.nextInt();
      int N = sc.nextInt();
      sc.nextLine();
      char map[][] = new char[M][N];
      for(int i = 0 ; i < M ; i++){
        map[i] = sc.nextLine().toCharArray();
      }
      System.out.printf("Case #%d: %d\n" , cn , solve(map));
    }
  }
  static boolean check(int i , int W){
    for(int j = 0 ; j < W - 1; j++){
      if((i & (1 << j)) != 0){
        if((i & (1 << (j + 1))) != 0){
          return false;
        }         
      }
    }
    return true;
  }
  static boolean bit(int i , int index){
    return (i & (1 << index)) != 0;
  }
  static int solve(char map[][]){
    int H = map.length;
    int W = map[0].length;
    int dp[][] = new int[H][1 << W];
    int state[] = new int[H];
    for(int i = 0 ; i < H ; i++){
      int s = 0;
      for(int j = 0 ; j < W ; j++){
        if(map[i][j] == 'x'){
          s = s | (1 << j);
        }
      }
      state[i] = s;
    }
    for(int i = 0 ; i < (1 << W) ; i++){
      if((i & state[0]) != 0)continue;
      if(!check(i, W))continue;
      int ic = Integer.bitCount(i);
      dp[0][i] = ic;
    }
    for(int i = 1 ; i < H ; i++){
      int prev[] = dp[i - 1];
      for(int j = 0 ; j < (1 << W) ; j++){
        if((j & state[i]) != 0)continue;
        if(!check(j, W))continue;
        int max = 0;
        for(int k = 0 ; k < (1 << W) ; k++){
          boolean f = true;
          for(int l = 0 ; l < W ; l++){
            if(bit(j, l)){
              if(l >= 1){
                if(bit(k , l - 1)){
                  f = false;
                  break;
                }
              }
              if(l < W - 1){
                if(bit(k , l + 1)){
                  f = false;
                  break;
                }               
              }
            }
          }
          if(f){
            max = Math.max(max, prev[k]);
          }
        }
        dp[i][j] = max + Integer.bitCount(j);
      }
    }
    int last[] = dp[H - 1];
    int max = last[0];
    for(int l : last){
      max = Math.max(l, max);
    }
    return max;
  }
}
