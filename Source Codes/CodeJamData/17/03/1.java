import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCount = in.nextInt();
        for (int testNo = 1; testNo <= testCount; testNo++) {
            solve(testNo, in);
        }
    }

    private static void solve(int testNo, Scanner in) {
        long n = in.nextLong();
        long k = in.nextLong();
        System.out.println("Case #" + testNo + ": " + calc(n, k));

    }

    private static String calc(long n, long k) {
        TreeMap<Long, Long> treeMap = new TreeMap<>();
        treeMap.put(n, 1L);
        while (k > 0) {
            Map.Entry<Long, Long> entry = treeMap.lastEntry();
            treeMap.remove(entry.getKey());
            if (k <= entry.getValue()) {
                return entry.getKey() / 2 + " " + (entry.getKey() - 1) / 2;
            } else {
                k -= entry.getValue();
                if (entry.getKey() / 2 > 0) {
                    long key = entry.getKey() / 2;
                    treeMap.put(key, treeMap.getOrDefault(key, 0L) + entry.getValue());
                }
                if ((entry.getKey() - 1) / 2 > 0) {
                    long key = (entry.getKey() - 1) / 2;
                    treeMap.put(key, treeMap.getOrDefault(key, 0L) + entry.getValue());
                }
            }
        }
        throw new RuntimeException();
    }

}
