import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        long A = sc.nextLong();
        long B = sc.nextLong();

        int[] X = new int[N];
        for (int i = 0; i < N; i++) {
            X[i] = sc.nextInt();
        }

        long ret = 0;

        for (int i = 0; i < N - 1; i++) {
            int distance = X[i+1] - X[i];

            ret += Math.min(distance * A, B);
        }

        System.out.println(ret);
    }
}