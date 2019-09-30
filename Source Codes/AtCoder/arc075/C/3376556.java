import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        long k = sc.nextInt();
        long a[] = new long[n + 1];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();

        long b[] = new long[n + 1];
        TreeMap<Long, Integer> map = new TreeMap<>();
        long sum = 0;
        for (int i = 0; i <= n; i++) {
            b[i] = sum - k * i;
            map.putIfAbsent(b[i], null);
            sum += a[i];
        }
        int value = 0;
        for (Map.Entry<Long, Integer> entry : map.entrySet()) {
            entry.setValue(value++);
        }

        int bn = Integer.highestOneBit((n + 1) * 2 - 1);
        long bit[] = new long[2 * bn];
        long ans = 0;
        for (int i = 0; i <= n; i++) {
            int c = map.get(b[i]);
            ans += query(c, bn, bit) + bit[c + bn];
            add(c, bn, bit);
        }

        System.out.println(ans);
    }

    private void add(int n, int off, long bit[]) {
        if (off == 0) {
            return;
        }

        bit[n + off]++;
        add(n / 2, off / 2, bit);
    }

    private long query(int n, int off, long bit[]) {
        if (off == 0) {
            return 0;
        }

        return (n % 2) * bit[n + off - 1] + query(n / 2, off / 2, bit);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
    }
}