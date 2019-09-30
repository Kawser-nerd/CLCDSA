import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] a = new long[n];
        long[] b = new long[n];
        long[] c = new long[m];
        long[] d = new long[m];
        long[] result = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            result[0] = 0;
        }
        for (int i = 0; i < m; i++) {
            c[i] = sc.nextInt();
            d[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            long minDis = 0;
            for (int j = 0; j < m; j++) {
                long dis = Math.abs(a[i] - c[j]) + Math.abs(b[i] - d[j]);
                if (j == 0) {
                    minDis = dis;
                    result[i] = j + 1;
                    continue;
                }
                if (dis < minDis) {
                    minDis = dis;
                    result[i] = j + 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.println(result[i]);
        }
    }

}