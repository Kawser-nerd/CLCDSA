import java.io.File;
import java.util.Arrays;
import java.util.Scanner;

public class C {
  public static void main(String[] args) throws Exception {
    int[] arr = new int[1 << 22];
    long[] cost = new long[1 << 20];
    for (int i = 1; i < (1 << 20); i++) {
      cost[i] = cost[i - 1] + i * i;
    }
    Scanner s = new Scanner(new File("C.in"));
    int T = s.nextInt();
    for (int tc = 1; tc <= T; tc++) {
      int C = s.nextInt();
      Arrays.fill(arr, 0);
      for (int i = 0; i < C; i++) arr[s.nextInt() + 2000000] = s.nextInt();
      long ans = 0;
      boolean ok = false;
      while (!ok) {
        ok = true;
        for (int i = 0; i < 4000000; i++) {
          if (arr[i] > 1) {
            ok = false;
            int j = i;
            while (arr[j] >= arr[i]) j++;
            j--;
            if ((j - i) % 2 == 1) j--;
            int v = arr[i];
            int val = v * (j - i + 1);
            int loc = (i + j) / 2;
            ans -= v * cost[(j - i + 1) / 2];
            ans += cost[val / 2];
            
            for (int k = i; k <= j; k++) arr[k] -= v;
            for (int shift = 0; shift <= val / 2; shift++) {
              if (shift == 0 && val % 2 == 1) arr[loc]++;
              if (shift > 0) {
                arr[loc + shift]++;
                arr[loc - shift]++;
              }
            }
          }
        }
      }
      System.out.println("Case #" + tc + ": " + ans);
    }
  }

}
