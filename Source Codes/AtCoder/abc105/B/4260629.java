public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        if (n % 4 == 0) {
            System.out.println("Yes");
        } else {
            for (int i = 1; i <= n / 7; i++) {
                if ((n - (i * 7)) % 4 == 0) {
                    System.out.println("Yes");
                    return;
                }
            }
            System.out.println("No");
        }
    }
}