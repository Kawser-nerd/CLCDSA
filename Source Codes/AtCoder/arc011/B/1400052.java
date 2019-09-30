import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    HashMap<String, Integer> map = new HashMap<String, Integer>();
    map.put("b", 1);
    map.put("c", 1);
    map.put("d", 2);
    map.put("w", 2);
    map.put("t", 3);
    map.put("j", 3);
    map.put("f", 4);
    map.put("q", 4);
    map.put("l", 5);
    map.put("v", 5);
    map.put("s", 6);
    map.put("x", 6);
    map.put("p", 7);
    map.put("m", 7);
    map.put("h", 8);
    map.put("k", 8);
    map.put("n", 9);
    map.put("g", 9);
    map.put("z", 0);
    map.put("r", 0);
    HashMap<String, Integer> map1 = (HashMap<String, Integer>)map.clone();
    for(String key : map1.keySet()) {
      char k = key.charAt(0);
      k += ('A' - 'a');
      String s = String.valueOf(k);
      map.put(s, map.get(key));
    }
    int N = sc.nextInt();
    ArrayList<String> list = new ArrayList<String>();
    for(int i = 0; i < N; i++) {
      String word = sc.next();
      String num = "";
      for(int j = 0; j < word.length(); j++) {
        String s = String.valueOf(word.charAt(j));
        if(map.containsKey(s)) num += map.get(s);
      }
      if(!num.equals("")) list.add(num);
    }
    for(int i = 0; i < list.size(); i++) {
      System.out.print(list.get(i));
      if(i < list.size() - 1) System.out.print(" ");
    }
    System.out.println();
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.