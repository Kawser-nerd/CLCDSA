public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int r = scanner.nextInt();
        System.out.println(r < 1200 ? "ABC" : r < 2800 ? "ARC" : "AGC");
    }
}