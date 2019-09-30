public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    static long l = 0, n = scanner.nextInt(), last = scanner.nextInt();
    public static void main(String[] args) {
        System.out.println(java.util.stream.LongStream.range(1, n).reduce(n, (ans, i) -> ans + ((last < (last = scanner.nextInt())) ? i - l : (l = i) * 0)));
    }
}