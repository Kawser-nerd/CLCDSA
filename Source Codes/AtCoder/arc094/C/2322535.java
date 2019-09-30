import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int Q = scanner.nextInt();

        long count = 0;
        long minb = Integer.MAX_VALUE;

        int[] A = new int[Q];
        int[] B = new int[Q];

        for (int i = 0; i < Q; i++) {
            A[i] = scanner.nextInt();
            B[i] = scanner.nextInt();
            count += A[i];
            if (A[i] > B[i]) {
                minb = Math.min(minb, B[i]);
            }
        }
        scanner.close();

        if (Arrays.equals(A, B)) {
            System.out.println(0);
            return;
        }

        System.out.println((count - minb));
    }
}