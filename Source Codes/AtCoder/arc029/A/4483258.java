import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int t[] = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = sc.nextInt();
        }

        int ans = 201;
        for (int b = 0; b < (1 << n); b++) {
            int t1 = 0;
            int t2 = 0;
            for (int p = 0; p < n; p++) {
                if (((b & (1 << p)) >> p) == 1) {
                    t1 += t[p];
                } else {
                    t2 += t[p];
                }
            }
            ans = Math.min(ans, Math.max(t1, t2));
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().main(sc);
        } catch (Exception e) {
            throw e;
        }
    }
}