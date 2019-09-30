import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int a = sc.nextInt();
    int b = sc.nextInt();
    int k = n / (a + b);
    int r = n - k * (a + b);
    String ans = "Bug";
    if((r > 0) && (r <= a)) ans = "Ant";
    System.out.println(ans);
  }
}