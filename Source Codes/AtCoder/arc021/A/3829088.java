import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int[][] A = new int[4][4];
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
        A[i][j] = scanner.nextInt();
      }
    }
    boolean flag = false;
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 3; j++){
        if(A[i][j] == A[i][j+1]){
          flag = true;
        }
      }
    }
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 4; j++){
        if(A[i][j] == A[i+1][j]){
          flag = true;
        }
      }
    }
    if(flag){
      System.out.println("CONTINUE");
    }else{
      System.out.println("GAMEOVER");
    }
  }
}