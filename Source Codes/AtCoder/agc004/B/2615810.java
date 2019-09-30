import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        long x = sc.nextInt();
        long a[] = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        long b[] = new long[n];
        Arrays.fill(b, Long.MAX_VALUE);

        long ans = n * 1000000000L;
        for (int magic = 0; magic < n; magic++) {
            for (int i = 0; i < n; i++) {
                b[i] = Math.min(b[i], a[(i + n - magic) % n]);
            }
            ans = Math.min(ans, magic * x + Arrays.stream(b).sum());
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}