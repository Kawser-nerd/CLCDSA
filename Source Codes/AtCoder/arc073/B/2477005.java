import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    static Map<Integer, List<Integer>> map;
    static long ans = 0;
    static int[] keys;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt(), W = in.nextInt();
        map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            int w = in.nextInt(), v = in.nextInt();
            if(!map.containsKey(w)) {
                List<Integer> list = new ArrayList<>();
                list.add(v);
                map.put(w, list);
            } else {
                map.get(w).add(v);
            }
        }
        keys = new int[map.keySet().size()];
        int idx = 0;
        for (int key: map.keySet()) {
            keys[idx++] = key;
        }
        map.keySet().stream()
                .map(key -> map.get(key))
                .forEach(list -> Collections.sort(list, Collections.reverseOrder()));
        solve(W, 0, 0, 0L);
        System.out.println(ans);
    }
    public static void solve(int W, int idx, int wSum, long vSum) {
        if(idx == keys.length) {
            ans = Math.max(ans, vSum);
        } else {
            solve(W, idx+1, wSum, vSum);
          for(int v : map.get(keys[idx])) {
              if(W - wSum < keys[idx]) return;
              wSum += keys[idx];
              vSum += (long)v;
              solve(W, idx+1, wSum, vSum);
          }
        }
    }
}