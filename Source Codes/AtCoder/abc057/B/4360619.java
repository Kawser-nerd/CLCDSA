import java.util.*;

public class Main {
    public static void main(String[] args) {
        new Main().run();
    }
    void run() {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next()),
            M = Integer.parseInt(sc.next());
        int[] a = new int[N],
              b = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = Integer.parseInt(sc.next());
            b[i] = Integer.parseInt(sc.next());
        }

        int[] c = new int[M],
              d = new int[M];
        for (int i = 0; i < M; i++) {
            c[i] = Integer.parseInt(sc.next());
            d[i] = Integer.parseInt(sc.next());
        }

        for (int i = 0; i < N; i++) {
            int checkPoint = 0;
            for (int j = 0; j < M; j++) {
                if (Math.abs(a[i] - c[j]) + Math.abs(b[i] - d[j]) <
                        Math.abs(a[i] - c[checkPoint]) + Math.abs(b[i] - d[checkPoint])) {
                    checkPoint = j;
                }
            }
            System.out.println(checkPoint + 1);
        }
    }
}