import java.util.*;

public class Main{
  public static int area = 1;
  public static int count = 0;
  public static char[][] map = new char[10][10];
  public static boolean[][] check;
  public static boolean flag = false;
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    for(int i = 0; i < 10; i++){
      String str = sc.nextLine();
      for(int j = 0; j < 10; j++){
        map[i][j] = str.charAt(j);
        if(map[i][j] == 'o'){
          area++;
        }
      }
    }
    c : for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        if(map[i][j] == 'x'){
          count = 0;
	      check = new boolean[10][10];
          map[i][j] = 'o';
          meth(i, j);
          map[i][j] = 'x';
          if(flag){
            break c;
          }
        }
      }
    }
        
    if(flag){
	  System.out.println("YES");
    }
    else{
      System.out.println("NO");
    }
  }
  
  public static void meth(int h, int w){
    if(h < 0 || w < 0 || h >= 10 || w >= 10 || map[h][w] == 'x'){
      return;
    }
    if(check[h][w]){
      return;
    }
    check[h][w] = true;
    count++;
    if(count == area){
      flag = true;
    }
    
    meth(h+1, w);
    meth(h-1, w);
    meth(h, w+1);
    meth(h, w-1);
  }
}