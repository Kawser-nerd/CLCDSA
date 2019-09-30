import java.util.Scanner;

public class Main {

    public static void main(final String[] args) {

        try (final Scanner sc = new Scanner(System.in)) {
            final int A = sc.nextInt();
            final int B = sc.nextInt();
            final int C = sc.nextInt();
            System.out.println(Math.min(B / A, C));
        }
    }
}