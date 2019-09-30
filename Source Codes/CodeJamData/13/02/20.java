package qual;

import java.util.Scanner;

public class B {
  static boolean check(int[][] pattern , int r , int c){
    int h = pattern[r][c];
    boolean f = true;
    for(int i = 0 ; i < pattern.length ; ++i){
      if(pattern[i][c] > h){
        f = false;
      }
    }
    if(f){
      return true;
    }
    f = true;
    for(int i = 0 ; i < pattern[0].length ; ++i){
      if(pattern[r][i] > h){
        f = false;
      }
    }
    return f;
  }
  
  static boolean check(int[][] pattern){
    for(int r = 0 ; r < pattern.length ; ++r){
      for(int c = 0 ;  c < pattern[0].length ; ++c){
        if(!check(pattern , r , c)){
          return false;
        }
      }
    }
    return true;
  }
  
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      int N = sc.nextInt();
      int M = sc.nextInt();
      int arr[][] = new int[N][M];
      for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < M ; ++j){
          arr[i][j] = sc.nextInt();
        }
      }
      System.out.printf("Case #%d: %s\n", cn , check(arr) ? "YES" : "NO");
    }
  }
}
