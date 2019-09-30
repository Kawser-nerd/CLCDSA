import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    TreeMap<Character, Integer> map = new TreeMap<>();
    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      if (map.containsKey(c)) {
        map.put(c, map.get(c) + 1);
      } else {
        map.put(c, 1);
      }
    }
    int ans = 0;
    if (map.size() > 1) {
      int min = Integer.MAX_VALUE;
      for (Character c : map.keySet()) {
        String tmp = s;
        int count = 0;
        while (!check(tmp, c)) {
          String after = tmp.substring(0, tmp.length() - 1);
          for (int i = 1; i < tmp.length(); i++) {
            if (tmp.charAt(i) == c) {
              char[] afterAry = after.toCharArray();
              afterAry[i - 1] = c;
              after = new String(afterAry);
            }
          }
          tmp = after;
          count++;
        }
        if (count < min) {
          min = count;
        }
      }
      ans = min;
    }
    System.out.println(ans);
  }

  public static boolean check(String s, char c) {
    boolean allSame = true;
    for (int i = 0; i < s.length(); i++) {
      if (s.charAt(i) != c) {
        allSame = false;
      }
    }
    return allSame;
  }
}