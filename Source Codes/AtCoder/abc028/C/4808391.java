import java.util.Comparator;
import java.util.stream.Stream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int a = scanner.nextInt(), b = scanner.nextInt(), c = scanner.nextInt(), d = scanner.nextInt(), e = scanner.nextInt();
        Stream.of(a + b + c, a + b + d, a + b + e, a + c + d, a + c + e, a + d + e, b + c + d, b + c + e, b + d + e, c + d + e)
                .distinct()
                .sorted(Comparator.reverseOrder())
                .skip(2)
                .findFirst()
                .ifPresent(System.out::println);
    }
}