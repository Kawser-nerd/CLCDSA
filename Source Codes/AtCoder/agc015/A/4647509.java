import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N, A, B;
        N = scanner.nextInt();
        A = scanner.nextInt();
        B = scanner.nextInt();
        if ( B - A < 0) { // 2 4 10 ? 1 7 10 ??????????1?????????????????1??????
            System.out.println("0");
            return;
        }
        if (N == 1) {
            if (A == B) {
                System.out.println("1");
            } else {
                System.out.println("0");
            }
            return;
        }
        long min = 0, max = 0;
        for (int i = 0; i < N - 1; i++) {
            min += A;
            max += B;
        }
        min += B;
        max += A;
        System.out.println(max - min + 1);
    }
}