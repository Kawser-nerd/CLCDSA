import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long N = sc.nextLong();

    String ans = "";
    do {
      ans += (char)(Math.abs(N) % 2 + '0');
      if (N < 0) N = (N - 1) / (-2);
      else N = N / (-2);
    } while (N != 0);
    StringBuffer sb = new StringBuffer(ans);
    sb.reverse();
    ans = sb.toString();
    System.out.println(ans);
  }
}