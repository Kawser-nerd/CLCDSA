import java.util.*;

public class Main{
  public static void main (String[]args){
    Scanner sc = new Scanner(System.in);
    String[] s = sc.nextLine().split(" ");
    int H = Integer.parseInt(s[0]);
    int W = Integer.parseInt(s[1]);
    int[] sx = {-1, -1, -1, 0, +1, +1, +1, 0};
    int[] sy = {-1, 0, +1, +1, +1, 0, -1, -1};
    
    char[][] field = new char[H][W];
    for(int i = 0; i < H; i++){
      field[i] = sc.nextLine().toCharArray();
    }
    
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        int count = 0;
        if(field[i][j] == '.'){
          for(int k = 0; k < 8; k++){
            if(i + sx[k] >= 0 && i + sx[k] < H && j + sy[k] >= 0 && j + sy[k] < W){
              if(field[i + sx[k]][j + sy[k]] == '#'){
                count++;
              }
            }
          }
          field[i][j] = (char)(count + '0');
        }
            System.out.print(field[i][j]);
      }
      System.out.println("");
    }
  }
}