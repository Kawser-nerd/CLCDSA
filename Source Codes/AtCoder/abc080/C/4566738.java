import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[][] fs = new int[N][10];
        int[][] ps = new int[N][11];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 10; j++) {
                fs[i][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 11; j++) {
                ps[i][j] = sc.nextInt();
            }
        }

        int ans = Integer.MIN_VALUE;
        for (int mask = 1; mask < 1 << 10; mask++) {
            int[] count = new int[N];
            for (int i = 0; i < 10; i++) {
                if (((mask >> i) & 1) == 1) {
                    for (int j = 0; j < N; j++) {
                        if (fs[j][i] == 1) {
                            count[j] = count[j] + 1;
                        }
                    }
                }
            }
            int total = 0;
            for (int i = 0; i < N; i++) {
                total += ps[i][count[i]];
            }
            ans = Math.max(total, ans);
        }
        System.out.println(ans);
    }
}