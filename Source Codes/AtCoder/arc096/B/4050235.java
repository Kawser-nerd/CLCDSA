import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long c = scanner.nextLong();
        long [] x = new long[n];
        long [] v = new long[n];
        for (int i = 0; i < n; ++i) {
            x[i] = scanner.nextLong();
            v[i] = scanner.nextLong();
        }
        long [][] dist1 = new long[n][2];
        long [][] f1 = new long[n][2];
        f1[0][0] = 0;
        f1[0][1] = v[0] - x[0];
        dist1[0][0] = 0;
        dist1[0][1] = x[0];
        for (int i = 1; i < n; ++i) {
            f1[i][0] = Math.max(f1[i - 1][0], f1[i - 1][1]);
            f1[i][1] = f1[i - 1][1] + v[i] - (x[i] - x[i - 1]);
            dist1[i][0] = f1[i - 1][0] >= f1[i - 1][1]
                    ? dist1[i - 1][0]
                    : x[i - 1];
            dist1[i][1] = x[i];

        }
        long [][] dist2 = new long[n][2];
        long [][] f2 = new long[n][2];
        f2[n - 1][0] = 0;
        f2[n - 1][1] = v[n - 1] - (c - x[n - 1]);
        dist2[n - 1][0] = 0;
        dist2[n - 1][1] = c - x[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            f2[i][0] = Math.max(f2[i + 1][0], f2[i + 1][1]);
            f2[i][1] = f2[i + 1][1] + v[i] - (x[i + 1] - x[i]);
            dist2[i][0] = f2[i + 1][0] >= f2[i + 1][1]
                    ? dist2[i + 1][0]
                    : c - x[i + 1];
            dist2[i][1] = c - x[i];
        }

        long result = 0;
        for (int i = 0; i < n; ++i) {
            long onlyLeft = Math.max(f1[i][0], f1[i][1]);
            long onlyRight = i + 1 < n
                    ? Math.max(f2[i + 1][0], f2[i + 1][1])
                    : 0;
            result = Math.max(result, Math.max(onlyLeft, onlyRight));
            long leftBack = Math.max(f1[i][0] - dist1[i][0], f1[i][1] - dist1[i][1]);
            long rightBack = i + 1 < n
                    ? Math.max(f2[i + 1][0] - dist2[i + 1][0], f2[i + 1][1] - dist2[i + 1][1])
                    : 0;
            long leftRight = leftBack + onlyRight;
            long rightLeft = rightBack + onlyLeft;
            result = Math.max(result, Math.max(leftRight, rightLeft));
        }
        // all counter clockwise
        result = Math.max(result, Math.max(f2[0][0], f2[0][1]));

        System.out.println(result);

    }
}