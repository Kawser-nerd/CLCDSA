import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String s = sc.next();
        String t = sc.next();
        long l = lcm(n, m);

        Map<Long, String> sMap = new HashMap<>();
        Map<Long, String> tMap = new HashMap<>();
        for (int i = 0 ; i < n ; i++) {
            sMap.put((long) i * l / n, s.substring(i, i + 1));
        }

        for (int i = 0 ; i < m ; i++) {
            tMap.put((long) i * l / m , t.substring(i, i + 1));
        }

        for (Entry<Long, String> entry : sMap.entrySet()) {
            long num = entry.getKey();
            String ch = entry.getValue();
            if (tMap.containsKey(num)) {
                if (!ch.equals(tMap.get(num))) {
                    l = -1l;
                }
            }

        }

        System.out.println(l);

    }
    static int gcd(int m , int n) {
        if(m < n) return gcd(n, m);
        if(n == 0) return m;
        return gcd(n, m % n);
    }
    static long lcm(int n , int m) {
        return  (long) n * m / gcd(n, m);
    }

}