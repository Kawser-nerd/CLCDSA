import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Scanner;

public class Main {
    public static class Interval implements Comparable<Interval> {
        public int start;
        public int end;

        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Interval interval = (Interval) o;
            return start == interval.start &&
                    end == interval.end;
        }

        @Override
        public int hashCode() {
            return Objects.hash(start, end);
        }

        @Override
        public int compareTo(Interval o) {
            if (this.start < o.start) {
                return -1;
            } else if (this.start == o.start) {
                if (this.end < o.end) {
                    return -1;
                } else if (this.end == o.end) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                return 1;
            }
        }
    }
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long mod = 1000000007L;

        int [] colors = new int[n];
        for (int i = 0; i < n; ++i) {
            colors[i] = scanner.nextInt();
        }
        ArrayList<Integer> dedupeColors = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && colors[i] == colors[i - 1]) {
                continue;
            }
            dedupeColors.add(colors[i]);
        }
//        for (int i = 0; i < dedupeColors.size(); ++i) {
//            System.out.print(dedupeColors.get(i) + " ");
//        }
      //  System.out.println();
        Map<Integer, List<Integer>> colorPos = new HashMap<>();
        for (int i = 0; i < dedupeColors.size(); ++i) {
            int color = dedupeColors.get(i);
            List<Integer> pos = colorPos.getOrDefault(color, new ArrayList<>());
            pos.add(i);
            colorPos.put(color, pos);
        }
        long [][] dp = new long[dedupeColors.size()][2];
        dp[0][0] = 1;
        dp[0][1] = 0;
        for (int i = 1; i < dedupeColors.size(); ++i) {
            int currentColor = dedupeColors.get(i);
         //   System.out.println("i: " + i + " color: " + currentColor);
            List<Integer> poses = colorPos.get(currentColor);
          //  System.out.println("positions: ");
//            for (int j = 0; j < poses.size(); ++j) {
//                System.out.print(poses.get(j) + " ");
//            }
         //   System.out.println();
            int binaryIndex = Collections.binarySearch(poses, i);
            int lastPos = binaryIndex >= 1 ? poses.get(binaryIndex - 1) : -1;
        //    System.out.println("lastPos: " + lastPos);
            if (lastPos >= 0) {
                dp[i][1] = dp[lastPos][0] + dp[lastPos][1];
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
                dp[i][1] %= mod;
                dp[i][0] %= mod;
            } else {
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
                dp[i][0] %= mod;
                dp[i][1] = 0;
                dp[i][1] %= mod;
            }
      //      System.out.println("dp[" + i + "][0]: " + dp[i][0]);
      //      System.out.println("dp[" + i + "][1]: " + dp[i][1]);


        }
        long res = (dp[dedupeColors.size() - 1][0] + dp[dedupeColors.size() - 1][1]) % mod;
        System.out.println(res);

    }
}