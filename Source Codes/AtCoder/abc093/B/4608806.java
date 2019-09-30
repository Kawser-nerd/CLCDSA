import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int k = scanner.nextInt();
        if (b - a + 1 <= 2 * k) {
            for (int i = a; i <= b; i++) {
                System.out.println(i);
            }
        } else {
            for (int i = a; i < k + a; i++) {
                System.out.println(i);
            }
            for (int j = b - k + 1; j <= b; j++) {
                System.out.println(j);
            }
        }
    }
}