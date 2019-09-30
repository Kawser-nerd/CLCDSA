import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class B {
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(new File("B.in"));
    PrintWriter out = new PrintWriter(new File("B.out"));
    
    int T = s.nextInt();
    for (int tc = 1; tc <= T; tc++) {
      out.print("Case #" + tc + ": ");
      int C = s.nextInt();
      HashMap<String, Character> combine = new HashMap<String, Character>();
      for (int i = 0; i < C; i++) {
        String tmp = s.next();
        combine.put("" + tmp.charAt(0) + tmp.charAt(1), tmp.charAt(2));
        combine.put("" + tmp.charAt(1) + tmp.charAt(0), tmp.charAt(2));
      }
      int D = s.nextInt();
      HashMap<Character, HashSet<Character>> delete = new HashMap<Character, HashSet<Character>>();
      for (int i = 0; i < D; i++) {
        String tmp = s.next();
        if (!delete.containsKey(tmp.charAt(0))) delete.put(tmp.charAt(0), new HashSet<Character>());
        delete.get(tmp.charAt(0)).add(tmp.charAt(1));
        if (!delete.containsKey(tmp.charAt(1))) delete.put(tmp.charAt(1), new HashSet<Character>());
        delete.get(tmp.charAt(1)).add(tmp.charAt(0));
      }
      
      int N = s.nextInt();
      String seq = s.next();
      ArrayList<Character> list = new ArrayList<Character>();
      outer: for (int i = 0; i < N; i++) {
        char cur = seq.charAt(i);
        if (list.size() > 0) {
          Character comb = combine.get("" + list.get(list.size() - 1) + cur);
          if (comb != null) {
            list.set(list.size() - 1, comb);
            continue;
          }
          if (delete.containsKey(cur)) {
            for (Character c : delete.get(cur)) {
              if (list.contains(c)) {
                list.clear();
                continue outer;
              }
            }
          }
        }
        list.add(cur);
      }
      out.println(list);
    }
    out.close();
  }
}
