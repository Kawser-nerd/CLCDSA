import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    double va = sc.nextDouble();
    double vb = sc.nextDouble();
    double L = sc.nextDouble();
    double ans = L;
    for(int i = 0; i < N; i++) {
      ans = (vb * ans) / va;
    }
    System.out.println(ans);
  }
}