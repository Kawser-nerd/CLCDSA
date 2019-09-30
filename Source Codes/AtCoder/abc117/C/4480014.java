import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();
        int M = in.nextInt();
        int[] values = new int[M];
        if (N >= M) {
            System.out.println("0");
            return;
        }
        for (int i = 0; i < M; i++) {
            values[i] = in.nextInt();
        }
        Arrays.sort(values);

        int[] diffs = new int[M - 1];
        for (int i = 0; i < M - 1; i++) {
            diffs[i] = values[i + 1] - values[i];
        }
        Arrays.sort(diffs);

        int ans = 0;
        for (int i = 0; i < M - N; i++) {
            ans += diffs[i];
        }
        System.out.println(ans);
    }

}