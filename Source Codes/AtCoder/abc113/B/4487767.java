import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {

    int N = sc.nextInt();
    int T = sc.nextInt();
    int A = sc.nextInt();

    int index = 0;
    double min = Integer.MAX_VALUE;
    for (int i=0; i<N; i++) {
      int h = sc.nextInt();
      double t = T - h * 0.006d;
      if (Math.abs(A - t) < min) {
        index = i;
        min = Math.abs(A - t);
      }
    }

    System.out.println(index+1);

  }
}