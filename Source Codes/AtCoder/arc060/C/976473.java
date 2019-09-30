import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int[] x = new int[n];
    for (int i = 0; i < n; i++) {
      x[i] = s.nextInt();
    }
    int limit = s.nextInt();

    int[][] dptable = new int[18][n];

    int begin = 0;
    int end = 0;
    long sum = x[0];
    while (begin < n) {
      while (true) {
        if (end+1 < n && x[end+1] - x[begin] <= limit) {
          end++;
        } else {
          break;
        }
      }
      dptable[0][begin] = end;
      begin++;
    }
    for (int i = 1; i < 18; i++) {
      for (int j = 0; j < n; j++) {
        dptable[i][j] = dptable[i-1][dptable[i-1][j]];
      }
    }
/*
      System.out.println();
    for (int i = 0; i < 18; i++) {
      for (int j = 0; j < n; j++) {
        System.out.print(dptable[i][j]);
      }
      System.out.println();
    }
      System.out.println();
*/
    int q = s.nextInt();
    for (int i = 0; i < q; i++) {
      int ta = s.nextInt() - 1;
      int tb = s.nextInt() - 1;
      int a = Math.min(ta, tb);
      int b = Math.max(ta, tb);
/*
      if (dptable[0][a] >= b) {
        System.out.println(1);
        continue;
      }
*/
      int current = a;
      int days = 0;
      int depth = 0;
      for (depth = 0; depth < 17; depth++) {
        if (dptable[depth+1][current] >= b) {
          current = dptable[depth][current];
          days = 1 << depth;
          break;
        }
      }
      while (depth >= 0) {
//        System.out.printf("%d %d\n", depth, current);
        if (dptable[depth][current] < b) {
          current = dptable[depth][current];
          days += (1 << depth);
        }
        depth--;
      }
//        System.out.printf("%d %d\n", depth, current);
      System.out.println(days + (current < b ? 1 : 0));
    }
  }
}