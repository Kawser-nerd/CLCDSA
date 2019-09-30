package qual;

import java.util.Arrays;
import java.util.Scanner;

public class A {
  public static boolean win(char[][] board , 
      int sx , int sy , int dx , int dy, char c){
    int tn = 0;
    int cn = 0;
    for(int i = 0 ; i < 4 ; ++i){
      int nx = sx + dx * i;
      int ny = sy + dy * i;
      char b = board[ny][nx];
      if(b == 'T'){
        ++tn;
      }
      if(b == c){
        ++cn;
      }
    }
    if(cn == 4)return true;
    if(cn == 3 && tn == 1)return true;
    return false;
  }
  
  public static boolean win(char[][] board , char c){
    for(int row = 0 ; row < board.length ; ++row){
      if(win(board, 0 , row , 1 , 0 , c)){
        return true;
      }
    }
    for(int col = 0 ; col < board.length ; ++col){
      if(win(board, col , 0 , 0 , 1 , c)){
        return true;
      }      
    }
    if(win(board , 0 , 0 , 1 , 1 , c)){
      return true;
    }
    if(win(board , 0 , 3 , 1 , -1 , c)){
      return true;
    }
    return false;
  }
  
  public static String getStatus(char[][] board){
    if(win(board , 'X')){
      return "X won";
    }
    if(win(board , 'O')){
      return "O won";      
    }
    for(char[] arr : board){
      for(char c : arr){
        if(c == '.'){
          return "Game has not completed";
        }
      }
    }
    return "Draw";
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int tn = sc.nextInt();
    for(int i = 1 ; i <= tn ; ++i){
      char[][] board = new char[4][];
      for(int r = 0 ; r < 4 ; ++r){
        board[r] = sc.next().toCharArray();
      }
//      System.out.println(Arrays.deepToString(board));
      System.out.printf("Case #%d: %s\n", i , getStatus(board));
    }
  }
}
