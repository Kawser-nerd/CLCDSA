public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int q = scanner.nextInt();
        int h = scanner.nextInt();
        int s = scanner.nextInt();
        int d = scanner.nextInt();
        int n = scanner.nextInt();

        long min1 = Math.min(q * 4L, Math.min(h * 2L, s));
        long min2 = Math.min(min1 * 2L, d);
        System.out.println(n / 2 * min2 + (n & 1) * min1);
    }
}