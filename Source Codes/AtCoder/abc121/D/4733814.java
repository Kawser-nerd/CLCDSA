import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            long A = scanner.nextLong();
            long B = scanner.nextLong();
            long xor = A;

            if (B - A < 0) {
                for (long i = A + 1; i <= B; i++) {
                    xor = xor ^ i;
                }
                System.out.println(xor);
            } else {
                long skipL = ((A / 4) + 1) * 4;
                long skipR = (B / 4) * 4 - 1;
                for (long i = A + 1; i < skipL; i++) {
                    xor = xor ^ i;
                }
                for (long i = skipR + 1; i <= B; i++) {
                    xor = xor ^ i;
                }
                System.out.println(xor);
            }
        }
    }
}