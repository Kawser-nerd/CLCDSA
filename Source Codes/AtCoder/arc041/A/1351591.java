import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int x = sc.nextInt();
    int y = sc.nextInt();
    int k = sc.nextInt();
    int ans = 0;
    if (y < k) {
      ans = x + y - (k - y);
    } else {
      ans = x + k;
    }
    System.out.println(ans);
  }
}