public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        System.out.println(java.util.Arrays.stream(scanner.next().split("\\+")).filter(t -> !t.contains("0")).count());
    }
}