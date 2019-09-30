public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int w = scanner.nextInt(), h = scanner.nextInt();
        System.out.println(facAndMod(h + w - 2) * powAndMod(facAndMod(w - 1) * facAndMod(h - 1) % 1000000007, 1000000005) % 1000000007);
    }

    private static long powAndMod(long a, long b) {
        if (b == 0)
            return 1;
        if ((b & 1) == 1)
            return a * powAndMod(a, b - 1) % 1000000007;
        return powAndMod(a * a % 1000000007, b / 2);
    }

    private static long facAndMod(long a) {
        return a == 0 ? 1 : a * facAndMod(a - 1) % 1000000007;
    }
}