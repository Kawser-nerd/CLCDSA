import java.io.PrintWriter;
import java.util.Scanner;

class A {
    public static void main(String... args) {
        final Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        final int[] A = new int[N + 2];
        for (int i = 1; i <= N; i++)
            A[i] = sc.nextInt();
        int sum = 0;
        for(int i = 0; i <= N; i++)
            sum += Math.abs(A[i + 1] - A[i]);
        try (final PrintWriter pw = new PrintWriter(System.out, false)) {
            for (int i = 1; i <= N; i++)
                if ((A[i + 1] - A[i]) * (A[i] - A[i - 1]) < 0)
                    pw.println(sum - Math.abs(A[i + 1] - A[i]) - Math.abs(A[i] - A[i - 1]) + Math.abs(A[i + 1] - A[i - 1]));
                else
                    pw.println(sum);
        }
    }
}
public class Main {
    public static void main(String...args) {
        A.main();
    }
}