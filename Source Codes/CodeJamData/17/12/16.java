import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * Created by jzj on 14/04/2017.
 */
public class ProblemB {

    private static class Interval implements Comparable<Interval> {
        long from;
        long to;

        public Interval(long from, long to) {
            if (from > to) {
                throw new RuntimeException();
            }
            this.from = from;
            this.to = to;
        }

        @Override
        public String toString() {
            return "Interval{" +
                    "from=" + from +
                    ", to=" + to +
                    '}';
        }


        @Override
        public int compareTo(Interval o) {
            if (from == o.from) {
                return Long.compare(to, o.to);
            }
            return Long.compare(from, o.from);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCount = in.nextInt();
        for (int testNo = 1; testNo <= testCount; testNo++) {
            solve(testNo, in);
        }
    }

    private static long upDiv(long a, long b) {
        if (a <= 0 || b <= 0) {
            throw new RuntimeException();
        }
        if (a % b == 0) {
            return a / b;
        } else {
            return a / b + 1;
        }
    }

    private static long calcUpperBound(int pack, int need) {
        return (pack * 10L) / (need * 9L);
    }

    private static long calcLowerBound(int pack, int need) {
        return upDiv(pack * 10L, need * 11L);
    }

    private static void solve(int testNo, Scanner in) {
        int n = in.nextInt();
        int p = in.nextInt();
        int[] need = new int[n];
        for (int i = 0; i < n; i++) {
            need[i] = in.nextInt();
        }
//        int[][] pack = new int[n][p];
        List<Interval>[] lists = new List[n];
        for (int i = 0; i < n; i++) {
            lists[i] = new ArrayList<>();
        }
        long max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                int pack = in.nextInt();
                long from = calcLowerBound(pack, need[i]);
                long to = calcUpperBound(pack, need[i]);
                if (from <= to) {
                    lists[i].add(new Interval(from, to));
                    max = Math.max(max, to);
                }
            }
        }
        for (List<Interval> list : lists) {
            Collections.sort(list);
        }
        int[] pts = new int[n];
        int answer = 0;
        tag:
        for (int serve = 1; serve <= max; serve++) {
            while (true) {
                for (int i = 0; i < n; i++) {
                    while (pts[i] < lists[i].size() && lists[i].get(pts[i]).to < serve) {
                        pts[i]++;
                    }
                    if (pts[i] >= lists[i].size()) {
                        break tag;
                    }
                    if (lists[i].get(pts[i]).from > serve) {
                        continue tag;
                    }
                }
                answer++;
                for (int i = 0; i < n; i++) {
                    if (lists[i].get(pts[i]).from > serve || lists[i].get(pts[i]).to < serve) {
                        throw new RuntimeException();
                    }
                    pts[i]++;
                }
            }
        }
        System.out.println("Case #" + testNo + ": " + answer);
    }

}
