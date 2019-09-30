public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        System.out.println((scanner.nextInt() - scanner.nextInt() & 1) == 1 ? "Borys" : "Alice");
    }
}