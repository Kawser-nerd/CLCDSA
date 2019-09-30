import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        long a[] = new long[3 * n];
        for (int i = 0; i < 3 * n; i++) {
            a[i] = sc.nextLong();
        }

        long sumr[] = new long[n + 1];
        long sumb[] = new long[n + 1];
        Queue<Long> rq = new PriorityQueue<>((o1, o2) -> Long.compare(o1, o2));
        Queue<Long> bq = new PriorityQueue<>((o1, o2) -> Long.compare(o2, o1));
        for (int i = 0; i < n; i++) {
            rq.add(a[i]);
            sumr[0] += a[i];
            bq.add(a[2 * n + i]);
            sumb[n] += a[2 * n + i];
        }

        for (int i = n; i < 2 * n; i++) {
            sumr[i - n + 1] = sumr[i - n] + a[i];
            rq.add(a[i]);
            sumr[i - n + 1] -= rq.poll();
            sumb[2 * n - i - 1] = sumb[2 * n - i] + a[3 * n - i - 1];
            bq.add(a[3 * n - i - 1]);
            sumb[2 * n - i - 1] -= bq.poll();
        }

        long ans = sumr[n] - sumb[n];
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, sumr[i] - sumb[i]);
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}