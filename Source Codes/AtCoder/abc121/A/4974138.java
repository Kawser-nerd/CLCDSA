import java.util.Scanner;

public class Main {

    public static void main(final String[] args) {

        try (final Scanner sc = new Scanner(System.in)) {
            final int H = sc.nextInt();
            final int W = sc.nextInt();
            final int h = sc.nextInt();
            final int w = sc.nextInt();
            final int total = H * W;
            System.out.println(total - (h * W + (H - h) * w));
        }
    }
}