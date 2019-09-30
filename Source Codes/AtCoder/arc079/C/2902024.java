import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        long a[] = new long[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }

        long ans = 0;
        while (true) {
            long adivn[] = new long[n];
            for (int i = 0; i < n; i++) {
                adivn[i] = a[i] / n;
            }
            long sum = Arrays.stream(adivn).sum();
            ans += sum;
            if (sum == 0) {
                break;
            }

            for (int i = 0; i < n; i++) {
                a[i] = a[i] % n + sum - adivn[i];
            }
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}