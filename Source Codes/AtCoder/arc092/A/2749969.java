import java.util.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int[] a = new int[2 * N];
    int[] b = new int[2 * N];

    for (int i=0; i < N; i++) {
      int input = sc.nextInt();
      a[input] = sc.nextInt() + 1;
    }

    for (int i=0; i < N; i++) {
      int input = sc.nextInt();
      b[input] = sc.nextInt() + 1;
    }

    int count = 0;

    for (int i=0; i < 2*N; i++) {
      if (b[i] == 0) continue;

      int tmp_min = Integer.MAX_VALUE;
      int tmp_j = 2*N;
      boolean f = false;

      for (int j=i-1; j >= 0; j--){
        if (a[j] != 0) {
          if (b[i] - a[j] > 0 && b[i] - a[j] < tmp_min) {
            tmp_min = b[i] - a[j];
            tmp_j = j;
            f = true;
          }
        }
      }

      if (f) {
        a[tmp_j] = 0;
        count++;
        f = false;
      }
    }

    System.out.println(count);
  }
}