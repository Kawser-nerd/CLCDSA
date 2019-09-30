public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt(), t;
        if (n == 0) {
            System.out.println(0);
        } else {
            StringBuilder builder = new StringBuilder();
            while (n != 0) {
                builder.insert(0, t = Math.abs(n % 2));
                n = (n - t) / -2;
            }
            System.out.println(builder);
        }
    }
}