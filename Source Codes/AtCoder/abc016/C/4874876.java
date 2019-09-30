import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), m = scanner.nextInt();
        Map<Integer, List<Integer>> friendMap = IntStream.rangeClosed(1, n).boxed().collect(Collectors.toMap(Function.identity(), i -> new ArrayList<>()));
        for (int i = 0, l, r; i < m; i++) {
            friendMap.get(l = scanner.nextInt()).add(r = scanner.nextInt());
            friendMap.get(r).add(l);
        }
        IntStream.rangeClosed(1, n).mapToLong(i -> friendMap.get(i).stream().flatMap(friend -> friendMap.get(friend).stream().filter(f -> !friendMap.get(i).contains(f) && f != i)).distinct().count()).forEach(System.out::println);
    }
}