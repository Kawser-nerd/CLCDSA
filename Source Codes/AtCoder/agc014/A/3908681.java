import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    int ans = 0;
    while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
      if (A == B && B == C) {
        System.out.println(-1);
        return;
      }
      int tmpA = A;
      int tmpB = B;
      int tmpC = C;
      ans++;
      A = tmpB / 2 + tmpC / 2;
      B = tmpA / 2 + tmpC / 2;
      C = tmpA / 2 + tmpB / 2; 
    }
    System.out.println(ans);
  }
}