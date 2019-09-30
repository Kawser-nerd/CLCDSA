public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt(), q = scanner.nextInt();
        int[] a = new int[n + 1];
        for (int i = 0; i < q; i++) {
            a[scanner.nextInt() - 1]++;
            a[scanner.nextInt()]--;
        }
        for (int i = 1; i <= n; i++)
            a[i] += a[i - 1];
        for (int i = 0; i < n; i++)
            System.out.print(a[i] % 2);
        System.out.println();
    }
}