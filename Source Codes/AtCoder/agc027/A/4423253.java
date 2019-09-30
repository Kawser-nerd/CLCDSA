import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt(), x = scanner.nextInt(), ans = 0;
        int[] a = IntStream.range(0, n)
                .map(i -> scanner.nextInt())
                .sorted()
                .toArray();

        for (int i = 0; i < n; i++, ans++) {
            if (x >= a[i]) {
                x -= a[i];
            } else {
                break;
            }
        } if (ans == n && x != 0) {
            ans--;
        }
        System.out.println(ans);
    }
}