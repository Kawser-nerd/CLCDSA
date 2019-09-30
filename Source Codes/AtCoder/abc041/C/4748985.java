import java.util.Collections;
import java.util.TreeMap;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        IntStream.rangeClosed(1, scanner.nextInt()).boxed().collect(Collectors.toMap(i -> scanner.nextInt(), i -> i, (a, b) -> null, () -> new TreeMap<>(Collections.reverseOrder()))).values().forEach(System.out::println);
    }
}