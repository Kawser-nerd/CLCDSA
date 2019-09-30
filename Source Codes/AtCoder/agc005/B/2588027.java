import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        long a[] = new long[n];

        for (int i = 0; i < n; i++) {
            a[sc.nextInt() - 1] = i;
        }

        TreeSet<Long> set = new TreeSet<>();

        long ans = 0;
        for (int i = 0; i < n; i++) {
            long num = a[i];
            Long l = set.lower(num);
            Long r = set.higher(num);

            l = (l == null ? -1 : l);
            r = (r == null ? n : r);

            ans += (i + 1) * (num - l) * (r - num);

            set.add(num);
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}