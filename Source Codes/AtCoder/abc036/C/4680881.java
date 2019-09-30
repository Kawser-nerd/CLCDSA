import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] a = new int[N];
        Map<Integer, Integer> map = new TreeMap();
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
            map.put(a[i], 1);
        }

        // a[i] -> x?????
        HashMap<Integer, Integer> order = new HashMap<>();
        int j = 0;
        for(Map.Entry e: map.entrySet()){
            order.put((Integer)e.getKey(), j++);
        }

        for(int i = 0; i < N; i++){
            out.println(order.get(a[i]));
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.