import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(), M = sc.nextInt(), D = sc.nextInt();
        int A[] = new int[M];
        for (int i = 0; i < M; i++) {
            A[i] = sc.nextInt() - 1;
        }

        int amida[] = new int[N];
        for (int i = 0; i < N; i++) {
            amida[i] = i;
        }

        for (int i = 0; i < M; i++) {
            int tmp = amida[A[i]];
            amida[A[i]] = amida[A[i] + 1];
            amida[A[i] + 1] = tmp;
        }

        int doubling[][] = new int[31][N];
        for (int i = 0; i < N; i++) {
            doubling[0][amida[i]] = i;
        }

        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < N; j++) {
                doubling[i + 1][j] = doubling[i][doubling[i][j]];
            }
        }

        for (int i = 0; i < N; i++) {
            int now = i, res = D;
            for (int j = 30; j >= 0; j--) {
                if ((res >> j & 1) == 1) {
                    now = doubling[j][now];
                    res -= 1 << j;
                }
            }
        System.out.println(now + 1);
        }
    }
}