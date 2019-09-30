import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    boolean flag = true;
    for (int i = 0; i < s.length() / 2; i++) {
      if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
        flag = false;
      }
    }
    if (flag) {
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }
  }
}