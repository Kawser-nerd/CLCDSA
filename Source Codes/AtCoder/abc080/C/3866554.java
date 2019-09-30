import java.util.Scanner;

public class Main {
    static int open[] = new int[10];
    static int ans = Integer.MIN_VALUE;
    static int n;
    static int f[][];
    static Scanner sc;

    static int p[][];
    static boolean first = true;

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        n = sc.nextInt();
        f = new int[n][10];
        /*
         * for (int i = 0; i < n; i++) { f[i] = new int[10]; }
         */
        // ??? ?? ??
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                f[i][j] = sc.nextInt();
            }
        }
        p = new int[n][11];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 11; j++) {
                p[i][j] = sc.nextInt();
            }
        }
        // ????
        DFS(0);
        System.out.println(ans);
    }

    public static void DFS(int pos) {
        if (pos >= 10) {
            return;
        }
        open[pos] = 0;

        func();

        DFS(pos + 1);
        open[pos] = 1;
        func();
        DFS(pos + 1);

    }

    // ans?????
    public static void func() {
        int opencnt = 0;
        for (int i = 0; i < 10; i++) {
            if (open[i] == 0) {
                opencnt++;
            }
        }
        if (opencnt == 10) {
            return;
        }
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < 10; j++) {
                if (open[j] == 0) {
                    continue;
                } else {
                    if (f[i][j] == 1) {
                        cnt++;
                    }
                }
            }
            tmp += p[i][cnt];
        }
        ans = Math.max(ans, tmp);
    }
}