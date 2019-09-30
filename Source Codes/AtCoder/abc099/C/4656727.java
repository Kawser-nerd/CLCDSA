import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        IntStream.rangeClosed(0, n).map(i -> {
            int cc = 0, t = i;
            while (t > 0) {
                cc += t % 6;
                t /= 6;
            }
            t = n - i;
            while (t > 0) {
                cc += t % 9;
                t /= 9;
            }
            return cc;
        }).min().ifPresent(System.out::println);
    }
}