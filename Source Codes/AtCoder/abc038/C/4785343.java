public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt(), c = 0;
        long[] count = new long[n];
        for (int i = 1, l = scanner.nextInt(); i < n; i++) {
            if (l < (l = scanner.nextInt())) {
                c++;
            } else {
                for (int j = 0; j < c; j++)
                    count[j] += c - j;
                c = 0;
            }
        }
        for (int j = 0; j < c; j++)
            count[j] += c - j;
        System.out.println(n + java.util.Arrays.stream(count).sum());
    }
}