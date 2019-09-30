import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    String name = sc.next();
    String kit = sc.next();
    HashMap<String, Integer> namemap = new HashMap<String, Integer>();
    HashMap<String, Integer> kitmap = new HashMap<String, Integer>();
    for(int i = 0; i < N; i++) {
      String s = String.valueOf(name.charAt(i));
      if(namemap.containsKey(s)) {
        namemap.put(s, namemap.get(s) + 1);
      } else {
        namemap.put(s, 1);
      }
    }
    for(int i = 0; i < M; i++) {
      String s = String.valueOf(kit.charAt(i));
      if(kitmap.containsKey(s)) {
        kitmap.put(s, kitmap.get(s) + 1);
      } else {
        kitmap.put(s, 1);
      }
    }
    int ans = 0;
    for(String s : namemap.keySet()) {
      int num1 = namemap.get(s);
      int num2 = 0;
      if(kitmap.containsKey(s)) num2 = kitmap.get(s);
      if(num2 == 0) {
        ans = -1;
        break;
      } else {
        ans = Math.max(ans, (num1 + num2 - 1) / num2);
      }
    }
    System.out.println(ans);
  }
}