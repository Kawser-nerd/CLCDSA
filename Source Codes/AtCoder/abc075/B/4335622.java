import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int h = sc.nextInt();
    int w = sc.nextInt();
    char[][] a = new char[h+2][w+2];
    for(int i = 0; i < a.length; i++){
      Arrays.fill(a[i], '.');
    }
    for(int i = 1; i < h + 1; i++){
      String tmp = sc.next();
      for(int j = 0; j < w; j++){
        if(tmp.charAt(j) == '#'){
          a[i][j+1] = '#';
        }
      }
    }
    for(int i = 1; i < a.length-1; i++){
      for(int j = 1; j < a[i].length-1; j++){
        if(a[i][j] == '#'){
          System.out.print('#');
        }else{
          int count = 0;
          for(int k = -1; k < 2; k++){
            for(int l = -1; l < 2; l++){
              if(k == 0 && l == 0) continue;
              if(a[i+k][j+l] == '#'){
                count++;
              }
            }
          }
          System.out.print(count);
        }
      }
      System.out.println();
    }
  }
}