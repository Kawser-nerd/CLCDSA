import java.util.*;

public class Main {
    public static void main(String[]$) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt(), k = s.nextInt();
        System.out.println(java.util.stream.IntStream.range(0, n).mapToDouble(i -> s.nextDouble()).sorted().skip(n - k).reduce(0D, (a, b) -> (a + b) / 2));
    }
}