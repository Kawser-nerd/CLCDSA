import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int K = sc.nextInt();
        int x[] = new int[n];
        int y[] = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }
        long ans = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            long left = x[i];
            for (int j = 0; j < n; j++) {
                long right = x[j];
                if (left > right)
                    continue;
                for (int k = 0; k < n; k++) {
                    long down = y[k];
                    for (int l = 0; l < n; l++) {
                        long up = y[l];
                        if (down > up)
                            continue;
                        int cnt = 0;
                        for (int m = 0; m < n; m++) {
                            if (left <= x[m] && x[m] <= right) {
                                if (down <= y[m] && y[m] <= up) {
                                    cnt++;
                                }
                            }
                        }
                        long tmp = (right - left) * (up - down);
                        if (cnt >= K) {
                            ans = Math.min(ans, tmp);

                        }
                    }
                }
            }
        }
        System.out.println(ans);
    }
}