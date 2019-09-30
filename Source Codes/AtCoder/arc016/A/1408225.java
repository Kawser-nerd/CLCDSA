import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      if(i != m) {
        ans = i;
        break;
      }
    }
    System.out.println(ans);
  }
}