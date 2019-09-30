import java.util.*;

public class Main{

  public static void main(String args[]){

    Scanner sc = new Scanner(System.in);

    int len = 8;
    int[][] board = new int[len][len];
    int[][] settable = new int[len][len];
    int[] settableRow = new int[5];
    int count = 0;
    boolean flag = true;

    // ?????????????
    for(int i=0; i<len; i++){
      String l = sc.next();
      for(int j=0; j<len; j++){
        if(l.substring(j,j+1).equals(".")){
          board[i][j] = 0;
        }else if(l.substring(j,j+1).equals("Q")){
          if(settable[i][j]==0){
            board[i][j] = 1;
            settable = changeSettable(i,j,settable);
          }else{
            flag = false;
          }
        }
      }
    }

    // ???????
    if(!flag){
      pl("No Answer");
      System.exit(0);
    }

    for(int i=0;i<len; i++){
      flag = true;
      for(int j=0; j<len; j++){
        if(board[i][j]==1){
          flag = false;
        }
      }
      if(flag){
        settableRow[count] = i;
        count++;
      }
    }

    for(int j=0; j<len; j++){
      if(settable[settableRow[0]][j]==0){
        setQueen(settableRow[0],j,board,settable,settableRow,0);
      }
    }
    
    pl("No Answer");


  }



  private static boolean setQueen(int i, int j, int[][] board, int[][] settable, int[] settableRow, int count){
    int len = 8;
    int[][] board_tmp = new int[len][len];
    int[][] settable_tmp = new int[len][len];
    for(int k=0; k<len; k++){
      for(int l=0; l<len; l++){
        board_tmp[k][l] = board[k][l];
        settable_tmp[k][l] = settable[k][l];
      }
    }

    board_tmp[i][j]=1;
    settable_tmp = changeSettable(i,j,settable_tmp);

    count++;
    if(count==5){
      printBoard(board_tmp);
      System.exit(0);
    }else{
      // ??????????????
      boolean flag = true;
      for(int k=0; k<len; k++){
        if(settable_tmp[settableRow[count]][k]==0){
          flag = false;
        }
      }
      if(flag){
        return false;
      }else{
        for(int k=0; k<len; k++){
          if(settable_tmp[settableRow[count]][k]==0){
            setQueen(settableRow[count],k,board_tmp,settable_tmp,settableRow,count);
          }
        }
      }
    }
    return true;
  }

  private static void printBoard(int[][] board){
    int len = 8;
    for(int i=0; i<len; i++){
      for(int j=0; j<len; j++){
        if(board[i][j]==0){
          pr(".");
        }else if(board[i][j]==1){
          pr("Q");
        }
      }
      pl("");
    }
  }


  private static int[][] changeSettable(int i, int j, int[][] settable){
    int len = 8;

    for(int k=0;k<len; k++){
      settable[k][j] = 1;
    }
    for(int k=0;k<len; k++){
      settable[i][k] = 1;
    }
    for(int k=0; Math.max(i+k,j+k)<len; k++){
      settable[i+k][j+k]=1;
    }
    for(int k=0; Math.min(i-k,j-k)>=0; k++){
      settable[i-k][j-k]=1;
    }
    for(int k=0; i+k<len && j-k>=0; k++){
      settable[i+k][j-k]=1;
    }
    for(int k=0; i-k>=0 && j+k<len; k++){
      settable[i-k][j+k]=1;
    }

    return settable;
  }


  private static void pr(Object o){
    System.out.print(o);
  }
  private static void pl(Object o){
    System.out.println(o);
  }

}