import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int k = s.nextInt();
    int a = 1;
    int b = 1;
    for (int i = 0; i < k; i++) {
      int nextA = a + b;
      int nextB = a;
      a = nextA;
      b = nextB;
    }
    System.out.printf("%d %d\n", a, b);
  }
}