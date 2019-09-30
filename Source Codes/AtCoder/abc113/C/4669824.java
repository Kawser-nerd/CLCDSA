import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.next());
    int M = Integer.parseInt(sc.next());
    Map<Integer, ArrayList<Integer>> map = new TreeMap<Integer, ArrayList<Integer>>();
    for (int i = 0; i < M; i++) {
      int P = Integer.parseInt(sc.next());
      int Y = Integer.parseInt(sc.next());
      map.put(Y, new ArrayList<Integer>(Arrays.asList(P, i)));
    }
    String[] ans = new String[M];
    int[] cnt = new int[N + 1];
    for (List<Integer> i : map.values()) {
      ans[i.get(1)] = String.format("%06d%06d", i.get(0), ++cnt[i.get(0)]);
    }
    for (int i = 0; i < M; i++) {
      System.out.println(ans[i]);
    }
  }

}