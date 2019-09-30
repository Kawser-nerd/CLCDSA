public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        String n = scanner.next();
        System.out.println(n.charAt(0) - 49 + (n.length() - 1) * 9 + (n.substring(1).matches("9*") ? 1 : 0));
    }
}