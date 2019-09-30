import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long a = sc.nextLong();
    long b = sc.nextLong();
    long ans = 0;
    long c = 0;
    if(a % 2 == 0) {
      if(b % 2 == 0) {
        c = b - a;
        c /= 2;
        if(c % 2 == 0) {
          ans = b;
        } else {
          ans = b ^ 1;
        }
      } else {
        c = b - a + 1;
        c /= 2;
        if(c % 2 == 0) {
          ans = 0;
        } else {
          ans = 1;
        }
      }
    } else {
      if(b % 2 == 0) {
        c = b - a - 1;
        c /= 2;
        if(c % 2 == 0) {
          ans = a ^ b;
        } else {
          ans = (a ^ b) ^ 1;
        }
      } else {
        c = b - a;
        c /= 2;
        if(c % 2 == 0) {
          ans = a;
        } else {
          ans = a ^ 1;
        }
      }
    }
    System.out.println(ans);
  }
}