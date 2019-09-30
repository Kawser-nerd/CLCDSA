import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), k = scanner.nextInt();
        System.out.println(java.util.stream.IntStream.range(0, n).mapToDouble(i -> scanner.nextDouble()).sorted().skip(n - k).reduce(0D, (a, b) -> (a + b) / 2));
    }
}