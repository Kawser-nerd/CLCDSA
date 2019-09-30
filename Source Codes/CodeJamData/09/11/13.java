import java.util.*;
import java.math.*;

public class Main {
  public static void main (String[] args) {
    int i, j, k, Lim = 50000;
    int[][] Base = new int[11][Lim+1];
    for (i = 3; i <= 10; i++) {
      Base[i][1] = 1;
      for (j = 2; j <= Lim; j++) if (Base[i][j] == 0) {
        int x = j;
        HashSet<Integer> Save = new HashSet<Integer>();

        while (!Save.contains(x)) {
          Save.add(x);
          String a = BigInteger.valueOf(x).toString(i);
          x = 0;
          for (k = 0; k < a.length(); k++) x += (a.charAt(k) - '0') * (a.charAt(k) - '0');
        }

        if (j == x) Base[i][j] = -1;
        Base[i][j] = Base[i][x];
      }
    }

    int[] Ans = new int[1000];
    for (i = 0; i < (1<<8); i++) {
      ArrayList<Integer> A = new ArrayList<Integer>();
      for (j = 0; j < 8; j++) if (((1<<j)&i) != 0) {
        A.add(j+3);
      }

      if (!(1 <= A.size() && A.size() <= 3)) {
        continue;
      }

      for (k = 2; k <= Lim; k++) {
        for (j = 0; j < A.size(); j++) if (Base[A.get(j)][k] != 1) break;
        if (j == A.size()) break;
      }

      if (k > Lim) System.out.println(i + "Impossible");
      else {
        Ans[i] = k;
      }
    }

    Scanner cin = new Scanner(System.in);
    int T = cin.nextInt();
    String temp = cin.nextLine();

    for (int t = 1; t <= T; t++) {
      String next = cin.nextLine();
      Scanner sin = new Scanner(next);

      int num = 0;
      while (sin.hasNextInt()) {
        int x = sin.nextInt();
        if (3 <= x) num = num|(1<<(x-3));
      }

      System.out.println("Case #" + t + ": " + Ans[num]);
    }
  }
}
