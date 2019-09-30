import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int x = sc.nextInt() - 1;
    int y = sc.nextInt() - 1;
    String W = sc.next();
    int[] vec = new int[2];
    if(W.equals("R")) {
      vec[0] = 1;
      vec[1] = 0;
    }
    if(W.equals("L")) {
      vec[0] = -1;
      vec[1] = 0;
    }
    if(W.equals("U")) {
      vec[0] = 0;
      vec[1] = -1;
    }
    if(W.equals("D")) {
      vec[0] = 0;
      vec[1] = 1;
    }
    if(W.equals("RU")) {
      vec[0] = 1;
      vec[1] = -1;
    }
    if(W.equals("RD")) {
      vec[0] = 1;
      vec[1] = 1;
    }
    if(W.equals("LU")) {
      vec[0] = -1;
      vec[1] = -1;
    }
    if(W.equals("LD")) {
      vec[0] = -1;
      vec[1] = 1;
    }
    String[][] c = new String[9][9];
    for(int i = 0; i < 9; i++) {
      String s = sc.next();
      for(int j = 0; j < 9; j++) {
        String d = String.valueOf(s.charAt(j));
        c[j][i] = d;
      }
    }
    String ans = "";
    ans += c[x][y];
    for(int i = 1; i < 4; i++) {
      if(x + vec[0] < 0) {
        vec[0] = 1;
      } else if(x + vec[0] >= 9) {
        vec[0] = -1;
      }
      if(y + vec[1] < 0) {
        vec[1] = 1;
      } else if(y + vec[1] >= 9) {
        vec[1] = -1;
      }
      x += vec[0];
      y += vec[1];
      ans += c[x][y];
    }
    System.out.println(ans);
  }
}