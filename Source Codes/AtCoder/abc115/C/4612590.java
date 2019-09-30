import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt(), k = scanner.nextInt();
        int[] h = IntStream.range(0, n).map(i -> scanner.nextInt()).sorted().toArray();
        System.out.println(IntStream.range(k - 1, n).map(i -> h[i] - h[i - k + 1]).min().getAsInt());
    }
}