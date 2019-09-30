import java.util.*;

public class Main {
    public static void main(String[] args) {
        new Main().run();
    }
    void run() {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next()),
            M = Integer.parseInt(sc.next());
        String[] A = new String[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.next();
        }
        String[] B = new String[M];
        for (int i = 0; i < M; i++) {
            B[i] = sc.next();
        }

        for (int i = 0; i + M <= N; i++) {
            for (int j = 0; j + M <= N; j++) {
                boolean yes = true;
                for (int k = 0; k < M; k++) {
                    yes = yes && (A[i + k].substring(j, j + M).equals(B[k]));
                }
                if (yes) {
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
    }
}