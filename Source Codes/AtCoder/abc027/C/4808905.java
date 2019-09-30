public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        long n = scanner.nextLong(), x = 1;
        int depth = Long.numberOfTrailingZeros(Long.highestOneBit(n)) & 1;
        boolean turn = false;
        while (n >= x) x = x * 2 + ((turn = !turn) ? 1 - depth : depth);
        System.out.println(turn ? "Aoki" : "Takahashi");
    }
}