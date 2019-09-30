import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int N = sc.nextInt();
    String[] v = new String[N];
    String[] w = new String[N];
    int[][] d = new int[N][10];
    for(int i = 0; i < N; i++) {
      v[i] = sc.next();
      w[i] = sc.next();
      for(int j = 0; j < v[i].length(); j++) {
        d[i][j] = Integer.parseInt(String.valueOf(v[i].charAt(j)));
      }
    }
    String[] s = new String[K];
    for(int i = 0; i < (int)Math.pow(3, K); i++) {
      int[] num = new int[K];
      boolean flg = true;
      s = new String[K];
      int[] select = new int[K];
      for(int j = 0; j < K; j++) {
        num[j] = ((i / (int)Math.pow(3, j)) % 3) + 1;
      }
      for(int j = 0; j < N; j++) {
        int index = 0;
        int len = 0;
        for(int k = 0; k < v[j].length(); k++) {
          len += num[d[j][k] - 1];
          if((index + num[d[j][k] - 1]) <= w[j].length()) {
            if(select[d[j][k] - 1] == 0) {
              s[d[j][k] - 1] = w[j].substring(index, index + num[d[j][k] - 1]);
              index += num[d[j][k] - 1];
              select[d[j][k] - 1] = 1;
            } else {
              String str = w[j].substring(index, index + num[d[j][k] - 1]);
              index += num[d[j][k] - 1];
              if(!(str.equals(s[d[j][k] - 1]))) {
                flg = false;
                break;
              }
            }
          } else {
            flg = false;
            break;
          }
        }
        if(len != w[j].length()) {
          flg = false;
          break;
        }
      }
      if(flg) break; 
    }
    for(int i = 0; i < K; i++) {
      System.out.println(s[i]);
    }
  }
}