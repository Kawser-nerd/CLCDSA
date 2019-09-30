import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int p[] = new int[n];
        int q[] = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
            q[p[i] - 1] = i + 1;
        }

        int max = 0;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            cnt++;
            if (q[i] > q[i + 1]) {
                max = Math.max(max, cnt);
                cnt = 0;
            }
        }
        max = Math.max(max, cnt + 1);

        System.out.println(n - max);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}