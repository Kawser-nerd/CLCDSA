import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {

    int N = sc.nextInt();
    int[] h = new int[N];

    int max = 0;
    for (int i=0; i<N; i++) {
      h[i] = sc.nextInt();
      if (h[i] > max) max = h[i];
    }

    int count = 0;
    for (int t=0; t<max; t++) {
      if (h[0] > 0) count++;
      for (int i = 1; i < N; i++) {
        if (h[i-1] <= 0 && h[i] > 0) {
          count++;
        }
      }
      for (int i=0; i<N; i++) {
        h[i]--;
      }
    }

    System.out.println(count);

  }
}