import java.util.*;
import java.lang.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        TreeMap<Long, Integer> tm = new TreeMap<Long, Integer>();
        for (int i = 0; i < n; i++) {
            long tmp = sc.nextLong();
            if (tm.containsKey(tmp)) {
                tm.put(tmp, tm.get(tmp) + 1);
            } else {
                tm.put(tmp, 1);
            }
        }

        int count = 0;
        while (!tm.isEmpty()) {
            long req = 0;
            for (int j = 0; j < 33; j++) {
                if (Math.pow(2, j) > tm.lastKey()) {
                    req = (long)Math.pow(2, j) - tm.lastKey();
                    break;
                }
            }
            if (tm.get(tm.lastKey()) == 1) {
                tm.remove(tm.lastKey());
            } else {
                tm.put(tm.lastKey(), tm.get(tm.lastKey()) - 1);
            }
            if (tm.containsKey(req)) {
                if (tm.get(req) == 1) {
                    tm.remove(req);
                } else {
                    tm.put(req, tm.get(req) - 1);
                }
                count++;
            }
        }
        System.out.println(count);
    }
}