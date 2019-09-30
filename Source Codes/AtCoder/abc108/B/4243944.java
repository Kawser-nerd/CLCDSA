public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int x1 = scanner.nextInt();
        int y1 = scanner.nextInt();
        int x2 = scanner.nextInt();
        int y2 = scanner.nextInt();
        System.out.printf("%s %s %s %s", x2 - y2 + y1, y2 + x2 - x1, x1 - y2 + y1, y1 + x2 - x1);
    }
}