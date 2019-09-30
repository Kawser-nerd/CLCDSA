import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();

        if (a[0] != 0) {
            System.out.println(-1);
            return;
        }

        long cnt = 0;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] < a[i]) {
                if (a[i] - a[i - 1] != 1) {
                    System.out.println(-1);
                    return;
                }
                cnt++;
            } else {
                cnt += a[i];
            }
        }

        System.out.println(cnt);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
    }
}