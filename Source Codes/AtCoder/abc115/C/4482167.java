import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {

    int N = sc.nextInt();
    int K = sc.nextInt();

    int[] h = new int[N];
    for (int i=0; i<N; i++) {
      h[i] = sc.nextInt();
    }

    Arrays.sort(h);

    int dif = Integer.MAX_VALUE;
    for (int i=K-1; i<N; i++) {
      dif = Math.min(dif, h[i] - h[i-K+1]);
    }

    System.out.println(dif);

  }
}