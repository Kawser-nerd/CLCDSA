import java.util.*;

public class Main{
  public static void main (String[]args){
    Scanner sc = new Scanner(System.in);
    String[] s = sc.nextLine().split(" ");
    int H = Integer.parseInt(s[0]);
    int W = Integer.parseInt(s[1]);
    int[] sx = {-1, 0, +1, 0};
    int[] sy = {0, +1, 0, -1};
    
    char[][] c = new char[H][W];
    for(int i = 0; i < H; i++){
      c[i] = sc.nextLine().toCharArray();
    }
    
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        boolean check = true;
        if(c[i][j] == '#'){
          for(int k = 0; k < 4; k++){
            if(i + sx[k] >= 0 && i + sx[k] < H && j + sy[k] >= 0 && j + sy[k] < W){
              if(c[i + sx[k]][j + sy[k]] == '#'){
                check = false;
              }
            }
          }
          if(check){
            System.out.println("No");
            System.exit(0);
          }
        }
      }
    }
    System.out.println("Yes");
  }
}