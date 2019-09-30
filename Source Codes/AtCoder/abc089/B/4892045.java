import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Set<Character> set = new HashSet<Character>();
    int N = sc.nextInt();
    for(int i = 0; i < N; i++) {
      String s = sc.next();
      char c = s.charAt(0);
      set.add(c);
    }
    System.out.println(set.size() == 3 ? "Three" : "Four");
  }
}