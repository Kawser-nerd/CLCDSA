import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] t = new int[M];
        for (int i = 0; i < N; i++) {
            int K = sc.nextInt();
            for (int j = 0; j < K; j++) {
                t[sc.nextInt()-1]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < M; i++) {
            if (t[i] == N) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}