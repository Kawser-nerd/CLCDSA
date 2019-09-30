import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N, A, B;
        N = scanner.nextInt();
        A = scanner.nextInt();
        B = scanner.nextInt();
        if (N == 1) {
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
        }
    }
}