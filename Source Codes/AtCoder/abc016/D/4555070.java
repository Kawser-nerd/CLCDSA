import java.util.Scanner;

class Main {
    static int ax;
    static int ay;
    static int bx;
    static int by;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        ax = sc.nextInt();
        ay = sc.nextInt();
        bx = sc.nextInt();
        by = sc.nextInt();
        int n = sc.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
            if (i == 0) {
                continue;
            }
            if (Check(x[i - 1], y[i - 1], x[i], y[i])) {
                ans++;
            }
        }
        if (Check(x[0], y[0], x[n - 1], y[n - 1])) {
            ans++;
        }
        System.out.println((ans / 2) + 1);

        sc.close();
    }

    public static boolean Check(int px, int py, int qx, int qy) {

        long t1 = ((py - ay) * (bx - ax) - (px - ax) * (by - ay));
        long t2 = ((qy - ay) * (bx - ax) - (qx - ax) * (by - ay));

        long t3 = ((ay - py) * (qx - px) - (ax - px) * (qy - py));
        long t4 = ((by - py) * (qx - px) - (bx - px) * (qy - py));
        return t1 * t2 < 0 && t3 * t4 < 0;
    }
}