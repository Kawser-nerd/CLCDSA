import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int h = sc.nextInt();
    int w = sc.nextInt();
    boolean[][] a = new boolean[h+2][w+2];
    for(int i = 1; i <= h; i++){
      String str = sc.next();
      for(int j = 1; j <= w; j++){
        a[i][j] = (str.charAt(j-1) == '#');
      }
    }
    for(int i = 1; i <= h; i++){
      for(int j = 1; j <= w; j++){
        if(!a[i][j]){
          continue;
        }
        if(a[i-1][j] || a[i+1][j] || a[i][j-1] || a[i][j+1]){
          continue;
        }else{
          System.out.println("No");
          System.exit(0);
        }
      }
    }
    System.out.println("Yes");
  }
}