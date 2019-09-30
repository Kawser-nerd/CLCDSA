import java.util.TreeMap;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        long k = scanner.nextLong();
        IntStream.range(0, n)
                .boxed()
                .collect(Collectors.toMap(i -> scanner.nextInt(), i -> scanner.nextLong(), Long::sum, TreeMap::new))
                .entrySet().stream()
                .reduce(k, (rem, entry) -> {
                    if (rem != null && (rem -= entry.getValue()) <= 0) {
                        System.out.println(entry.getKey());
                        return null;
                    }
                    return rem;
                }, Long::sum);
    }
}