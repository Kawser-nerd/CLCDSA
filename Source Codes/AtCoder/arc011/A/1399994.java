import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int m = sc.nextInt();
    int n = sc.nextInt();
    int N = sc.nextInt();
    int ans = N;
    int r = N;
    while(r >= m) {
      int a = (r / m) * n;
      ans += a;
      r = (r % m) + a; 
    }
    System.out.println(ans);
  }
}