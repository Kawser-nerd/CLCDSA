import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int A = sc.nextInt();
    int B = sc.nextInt();
    int ans = 0;
    for(int i = 0; i < M; i++) {
      if(N <= A) N += B;
      int c = sc.nextInt();
      if(N < c) {
        ans = i + 1;
        break;
      } else {
        N -= c;
      }
    }
    if(ans > 0) {
      System.out.println(ans);
    } else {
      System.out.println("complete");
    }
  }
}