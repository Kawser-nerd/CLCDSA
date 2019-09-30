import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N, A, B;
        N = scanner.nextLong();
        A = scanner.nextLong();
        B = scanner.nextLong();
        /*if (N == 1) {
            if (A == B) {
                System.out.println("1");
            } else {
                System.out.println("0");
            }
        } else {
            if (A > B) {
                System.out.println("0");
            } else {
                System.out.println((long)(B - A) * (N - 2) + 1);
            }
        }*/
        if (A > B) {
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
        /*long min = 0, max = 0;
        for (int i = 0; i < N - 1; i++) {
            min += A;
            max += B;
        }
        min += B;
        max += A;*/
        System.out.println((B - A) * (N - 2) + 1);
    }
}