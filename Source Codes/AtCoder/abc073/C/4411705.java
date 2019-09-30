import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        System.out.println(IntStream.range(0, scanner.nextInt())
                .boxed()
                .collect(Collectors.groupingBy(i -> scanner.nextInt(), Collectors.reducing(false, i -> true, (a, b) -> a ^ b)))
                .values().stream()
                .filter(Boolean::booleanValue)
                .count());
    }
}