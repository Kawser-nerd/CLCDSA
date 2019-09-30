import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int liked[] = new int[31];
        for (int i = 0; i < N; ++i) {
            int K = sc.nextInt();
            for (int j = 0; j < K; ++j) {
                int A = sc.nextInt();
                ++liked[A];
            }
        }
        int res = 0;
        for (int i = 0; i < 31; ++i) {
            if (liked[i] == N) ++res;
        }
        System.out.println(res);
    }
}