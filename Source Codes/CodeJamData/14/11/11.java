import java.io.File;
import java.io.FileInputStream;
import java.util.HashMap;
import java.util.Scanner;

public class ChargingChaos {

    // private static String file = "data/r1asample.txt";

    // private static String file = "data/r1a-A-small-attempt0.in";

    private static String file = "data/r1a-A-large.in";

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        FileInputStream is = new FileInputStream(new File(file));
        Scanner scanner = new Scanner(is);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int n = scanner.nextInt();
            int l = scanner.nextInt();
            long[] src = new long[n];
            long[] dst = new long[n];
            for (int i = 0; i < n; i++) {
                String st = scanner.next();
                src[i] = Long.parseLong(st, 2);
            }
            for (int i = 0; i < n; i++) {
                String st = scanner.next();
                dst[i] = Long.parseLong(st, 2);
            }

            // pick up candidates
            long[] candidates = new long[n];
            for (int i = 0; i < n; i++) {
                candidates[i] = dst[i] ^ src[0];
            }

            int minCount = Integer.MAX_VALUE;
            for (long cand : candidates) {
                if (check(cand, src, dst)) {
                    int bc = Long.bitCount(cand);
                    minCount = Math.min(minCount, bc);
                }
            }
            if (minCount == Integer.MAX_VALUE) {
                out(t, "NOT POSSIBLE");
            } else {
                out(t, minCount);
            }
        }
    }

    static boolean check(long cand, long[] src, long[] dst) {
        HashMap<Long, Integer> countMap = new HashMap<Long, Integer>();
        for (long s : src) {
            long news = s ^ cand;
            if (countMap.containsKey(news)) {
                countMap.put(news, countMap.get(news) + 1);
            } else {
                countMap.put(news, 1);
            }
        }
        for (long d : dst) {
            if (countMap.containsKey(d)) {
                int newval = countMap.get(d) - 1;
                if (newval < 0) {
                    return false;
                }
                countMap.put(d, newval);
            } else {
                return false;
            }
        }
        return true;
    }

    static void out(int t, Object ans) {
        System.out.println("Case #" + (t + 1) + ": " + ans);
    }
}
