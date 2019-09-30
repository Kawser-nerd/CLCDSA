import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        Integer[] as = new Integer[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }
        Arrays.sort(as);

        Integer[] bs = new Integer[n];
        for (int i = 0; i < n; i++) {
            bs[i] = sc.nextInt();
        }

        Integer[] cs = new Integer[n];
        for (int i = 0; i < n; i++) {
            cs[i] = sc.nextInt();
        }
        Arrays.sort(cs);

        long ans = 0;
        for (Integer b : bs) {
            // lower bound
            long ai = Arrays.binarySearch(as, b, (x, y) -> (x.compareTo(y) >= 0) ? 1 : -1);
            ai = ~ai;

            // uppwer bound
            long ci = Arrays.binarySearch(cs, b, (x, y) -> (x.compareTo(y) > 0) ? 1 : -1);
            ci = ~ci;

            ans += ai * (cs.length - ci);
        }

        System.out.println(ans);
    }
}