import java.util.*;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int N = scanner.nextInt();
            int[] As = new int[N];
            for (int i = 0; i < N; i++) {
                As[i] = scanner.nextInt();
            }
            int sum = 0;
            int current = 0;
            for (int i = 0; i < N; i++) {
                if (As[i] > current) {
                    sum += As[i] - current;
                }
                current = As[i];
            }
            System.out.println(sum);
        }
    }
}