import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    String[][] s = new String[4][4];
    for(int i = 0; i < 4; i++){
	  s[i] = sc.nextLine().split(" ");
    }
    String[][] ans = new String[4][4];
    
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
        ans[i][j] = s[3-i][3-j];
      }
    }
    
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
        if(j == 3){
          System.out.println(ans[i][j]);
        }else{
          System.out.print(ans[i][j]);
          System.out.print(" ");
        }
      }
    }
  }
}