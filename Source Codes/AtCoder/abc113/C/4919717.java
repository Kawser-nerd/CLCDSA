import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        Map<Integer, ArrayList<Integer>> map = new TreeMap<>();
        for (int i = 0; i < M; i++) {
            int P = sc.nextInt();
            int Y = sc.nextInt();
            map.put(Y, new ArrayList<>(Arrays.asList(P, i)));
        }
        String[] ans = new String[M];
        int[] count = new int[N + 1];
        for (List<Integer> list : map.values()) {
            ans[list.get(1)] = String.format("%06d%06d", list.get(0), ++count[list.get(0)]);
        }
        for (int i = 0; i < M; i++) {
            System.out.println(ans[i]);
        }
    }
}