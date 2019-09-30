import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {

    int N = sc.nextInt();
    int sum = 0;
    int max = 0;
    for (int i=0; i<N; i++) {
      int a = sc.nextInt();
      max = Math.max(max, a);
      sum += a;
    }

    sum -= max / 2;

    System.out.println(sum);

  }
}