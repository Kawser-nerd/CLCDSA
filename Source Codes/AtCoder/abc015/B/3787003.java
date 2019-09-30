import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int N = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) A[i] = scanner.nextInt();

        int sum = 0, size = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] != 0) {
                sum += A[i];
                ++size;
            }
        }

        System.out.println(sum / size + (sum % size != 0 ? 1 : 0));
    }

}