import java.util.*;
import java.awt.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] p_index = new int[n];
    for (int i = 0; i < n; i++) {
      p_index[sc.nextInt()-1] = i;
    }

    int ans = 0;
    int count = 0;
    int prev_index = -1;

    for (int i = 0; i < n; i++) {
      if (p_index[i] > prev_index) {
        count++;
      } else {
        ans = Math.max(ans, count);
        count = 1;
      }

      prev_index = p_index[i];
    }

    ans = Math.max(ans, count);
    System.out.println(n - ans);
  }
}