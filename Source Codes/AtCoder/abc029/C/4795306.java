public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt();
        java.util.stream.IntStream.range(0, (int)Math.pow(3, n))
                .mapToObj(i -> String.format("%" + n + "s", Integer.toString(i, 3)).replace(' ', 'a').replace('0', 'a').replace('1', 'b').replace('2', 'c'))
                .forEach(System.out::println);
    }
}