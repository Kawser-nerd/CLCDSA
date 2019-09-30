import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    String[] ans = new String[N];
    for(int i = 0; i < N; i++) {
      String s = sc.next();
      StringBuffer sb = new StringBuffer(s);
      ans[i] = sb.reverse().toString();
    }
    Arrays.sort(ans);
    for(int i = 0; i < N; i++) {
      StringBuffer sb = new StringBuffer(ans[i]);
      System.out.println(sb.reverse().toString());
    }
  }
}