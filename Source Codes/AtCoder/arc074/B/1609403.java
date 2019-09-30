import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    int n;
    long[] as;
    PriorityQueue<Long> maxQueue;
    PriorityQueue<Long> minQueue;

    public static void main(String[] args) {
        Main m = new Main();
        m.read();
        m.solve();
    }

    private void read() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        as = new long[3 * n];
        for (int i = 0; i < as.length; i++) {
            as[i] = sc.nextLong();
        }
    }

    private void solve() {
        maxQueue = new PriorityQueue<>();
        minQueue = new PriorityQueue<>(Comparator.reverseOrder());
        long[] maxs = new long[n+1];
        long[] mins = new long[n+1];
        for (int i = 0; i < n; i++) {
            maxQueue.add(as[i]);
            maxs[0] += as[i];
            minQueue.add(as[3*n-1 - i]);
            mins[mins.length-1] += as[3 * n - 1 -i];
        }
        for (int i = n; i < 2 * n; i++) {
            maxQueue.add(as[i]);
            long e = maxQueue.poll();
            maxs[i-n+1] = maxs[i-n] + as[i] - e;
        }
        for (int i = 2 * n - 1; i >= n; i--) {
            minQueue.add(as[i]);
            long e = minQueue.poll();
            mins[i-n] = mins[i-n+1] + as[i] - e;
        }
        long ans = maxs[0] - mins[0];
        for (int i = 0; i <= n; i++) {
            ans = Math.max(ans, maxs[i] - mins[i]);
        }
        System.out.println(ans);
    }
}