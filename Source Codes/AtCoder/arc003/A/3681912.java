import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    String r = sc.next();
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int f = 0;
    for (int i = 0; i < N; i++) {
      char tmp = r.charAt(i);
      switch (tmp) {
      case 'A':
        a++;
        break;
      case 'B':
        b++;
        break;
      case 'C':
        c++;
        break;
      case 'D':
        d++;
        break;
      case 'F':
        f++;
        break;
      default:
        break;
      }
    }
    if (f == N) {
      System.out.println(0);
      return;
    }
    System.out.println((double)(4 * a + 3 * b + 2 * c + d) / (a + b + c + d + f));
  }
}