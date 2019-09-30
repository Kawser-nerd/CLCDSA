import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();
        int K = in.nextInt();

        int[] values = new int[N];
        for (int i = 0; i < N; i++) {
            values[i] = in.nextInt();
        }
        Arrays.sort(values);

        int min = Integer.MAX_VALUE;
        for (int i = 0; i < N-K+1; i++) {
            min = Math.min(values[i+K-1] - values[i], min);
        }

        System.out.println(min);
    }

}