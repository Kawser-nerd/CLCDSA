public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), m = scanner.nextInt(), sum = 0;
        int[] a = new int[m + 1];
        for (int i = 0; i < n; i++) {
            int l = scanner.nextInt() - 1, r = scanner.nextInt(), s = scanner.nextInt();
            a[l] += s;
            a[r] -= s;
            sum += s;
        }
        java.util.Arrays.parallelPrefix(a, Integer::sum);
        System.out.println(sum - java.util.Arrays.stream(a).limit(m).min().getAsInt());
    }
}