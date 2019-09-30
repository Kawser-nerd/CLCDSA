import java.util.Comparator;
import java.util.OptionalInt;
import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), m = scanner.nextInt(), d[][] = IntStream.range(0, n).mapToObj(i -> IntStream.range(0, n).map(j -> i == j ? 0 : 0x1fffffff).toArray()).toArray(int[][]::new);
        for (int i = 0, u1, u2; i < m; i++) d[u1 = scanner.nextInt() - 1][u2 = scanner.nextInt() - 1] = d[u2][u1] = Math.min(d[u1][u2], scanner.nextInt());
        IntStream.range(1, n).forEach(i -> IntStream.range(1, n).forEach(j -> IntStream.range(1, n).forEach(k -> d[j][k] = Math.min(d[j][k], d[j][i] + d[i][k]))));
        System.out.println(IntStream.range(1, n).mapToObj(i -> IntStream.range(i + 1, n).map(j -> d[0][i] + d[i][j] + d[j][0]).min()).filter(OptionalInt::isPresent).min(Comparator.comparing(OptionalInt::getAsInt)).filter(o -> o.getAsInt() < 0x1fffffff).orElse(OptionalInt.of(-1)).getAsInt());
    }
}