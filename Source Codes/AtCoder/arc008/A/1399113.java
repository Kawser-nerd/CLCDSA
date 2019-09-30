import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int r = N % 10;
    int ans = 0;
    if(r < 7) ans = 100 * (N / 10) + 15 * r;
    if(r > 6) ans = 100 * ((N + 9) / 10); 
    System.out.println(ans);
  }
}