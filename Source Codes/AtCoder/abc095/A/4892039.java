import java.util.*;
public class Main {
  static String S;
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    S = sc.next();
    char[] s = S.toCharArray();
    int o = 0;
    for(int i = 0; i < s.length; i++)
      if(s[i] == 'o')
        o++;
    System.out.println(700 + o * 100);
  }
}