import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        Map<Integer, int[]> map = new TreeMap<Integer, int[]>();

        for (int i = 0; i < M; i++) {
            int[] arr = new int[2];
            arr[0] = sc.nextInt();  //P
            arr[1] = i;             //????
            map.put(sc.nextInt(), arr);  // Y, [P, ????]
        }

        String[] ans = new String[M];
        int[] seq = new int[N+1];
        for(int[] arr: map.values()){
            seq[arr[0]]++;
            ans[arr[1]] = String.format("%06d%06d", arr[0], seq[arr[0]]);
        }

        for (int i = 0; i < M; i++) {
            out.println(ans[i]);
        }
    }
}