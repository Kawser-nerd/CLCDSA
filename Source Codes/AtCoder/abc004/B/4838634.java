import java.util.*;
public class Main {
  public static void main(String[] args){
    
    Boolean flg = true;
    int c = 0;
    Scanner sc = new Scanner(System.in);
    String[][] arr = new String[4][4]; 
    
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        arr[i][j] = sc.next();
      }
    }
    
    for (int i = 3; 0 <= i; i--) {
      for (int j = 3; 0 <= j; j--){
      	System.out.print(arr[i][j]);
        if(j == 0){
          System.out.println("");
        } else {
          System.out.print(" ");
        }
      }
    }
    
  }
}