import java.util.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int k = sc.nextInt();

    long count = 0;

    for (int b=k+1; b <= n; b++) {
      count += (b-k) * (n/b);
      if (n%b >= k && k == 0) {
        count += n%b - k;
      } else if (n%b >= k) {
        count += n%b - k + 1;
      }
    }

    System.out.println(count);
  }
}