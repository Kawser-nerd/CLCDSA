import java.util.*;
import java.util.stream.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), m = scanner.nextInt();
        List<Integer> list = IntStream.range(0, m).map(i -> scanner.nextInt()).boxed().collect(Collectors.toList());
        Collections.reverse(list);
        Stream.concat(list.stream(), IntStream.rangeClosed(1, n).boxed()).distinct().forEach(System.out::println);
    }
}