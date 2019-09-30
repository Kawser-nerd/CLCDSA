import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    String s = sc.next();
    String t = sc.next();
    String ans = "";
    for (int i = 0; i <= N; i++) {
      String tmp = s + t.substring(i);
      if (s.compareTo(tmp.substring(0, N)) == 0 && t.compareTo(tmp.substring(tmp.length() - N, tmp.length())) == 0) {
        ans = tmp;
      }
    }
    System.out.println(ans.length());
  }
}