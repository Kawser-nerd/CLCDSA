import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[][] x = new int[n][3];

        for (int i = 0; i < n; i++) {
            x[i][0] = sc.nextInt() % (2 * k);
            x[i][1] = sc.nextInt() % (2 * k);
            String s = sc.next();
            if (s.equals("B")) {
                x[i][2] = 0;
            } else {
                x[i][2] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (x[i][2] == 0 && x[i][0] >= k) {
                x[i][2] = 1;
                x[i][0] -= k;
            } else if (x[i][2] == 0 && x[i][0] < k) {
                x[i][2] = 1;
                x[i][0] += k;
            }
            if (x[i][1] >= k && x[i][0] < k) {
                x[i][1] -= k;
                x[i][0] += k;
            } else if (x[i][1] >= k && x[i][0] >= k) {
                x[i][1] -= k;
                x[i][0] -= k;
            }
        }

        int[][] b = new int[2 * k + 1][k + 1];

        for (int i = 0; i < n; i++) {
            b[x[i][0] + 1][x[i][1] + 1]++;
        }
        for (int i = 1; i < 2 * k; i++) {
            b[i + 1][1] = b[i][1] + b[i + 1][1];
        }
        for (int i = 1; i < k; i++) {
            b[1][i + 1] = b[1][i] + b[1][i + 1];
        }
        for (int i = 1; i < k; i++) {
            for (int j = 1; j < 2 * k; j++) {
                b[j + 1][i + 1] = b[j][i + 1] + b[j + 1][i] + b[j + 1][i + 1] - b[j][i];
            }
        }

        int ans = 0;

        for (int i = 1; i < k * 2 + 1; i++) {
            for (int j = 1; j < k + 1; j++) {
                int tmp = culc(b, i - 1 - 2 * k, j - 1, i - k - 1, j + k - 1, k);
                tmp += culc(b, i - 1 - k, j - k - 1, i - 1, j - 1, k);
                tmp += culc(b, i - 1, j - 1, i - 1 + k, j - 1 + k, k);
                tmp += culc(b, i - 1 + k, j - k - 1, i - 1 + 2 * k, j - 1, k);
                if (tmp > ans)
                    ans = tmp;
            }
        }

        System.out.println(ans);
    }

    public static int culc(int[][] b, int x1, int y1, int x2, int y2, int k) {
        if (x1 < 0)
            x1 = 0;
        if (y1 < 0)
            y1 = 0;
        if (x2 < 0)
            x2 = 0;
        if (y2 < 0)
            y2 = 0;
        if (x1 > 2 * k)
            x1 = 2 * k;
        if (y1 > k)
            y1 = k;
        if (x2 > 2 * k)
            x2 = 2 * k;
        if (y2 > k)
            y2 = k;
        return b[x1][y1] + b[x2][y2] - b[x1][y2] - b[x2][y1];
    }
}