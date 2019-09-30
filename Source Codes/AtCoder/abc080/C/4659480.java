import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        int[][] f = IntStream.range(0, n).mapToObj(i -> IntStream.range(0, 10).map(j -> scanner.nextInt()).toArray()).toArray(int[][]::new);
        int[][] p = IntStream.range(0, n).mapToObj(i -> IntStream.range(0, 11).map(j -> scanner.nextInt()).toArray()).toArray(int[][]::new);
        IntStream.range(1, 1024).map(i -> IntStream.range(0, n).map(j -> p[j][(int)IntStream.range(0, 10).filter(k -> (i >> k & 1) == 1 && f[j][k] == 1).count()]).sum()).max().ifPresent(System.out::println);
    }
}