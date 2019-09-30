public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int r = scanner.nextInt(), c = scanner.nextInt(), k = scanner.nextInt(), n = scanner.nextInt();
        int[] ra = new int[n], ca = new int[n], rSum = new int[r], cSum = new int[c];
        for (int i = 0; i < n; i++) {
            rSum[ra[i] = scanner.nextInt() - 1]++;
            cSum[ca[i] = scanner.nextInt() - 1]++;
        }
        long[] rb = new long[n + 1], cb = new long[n + 1];
        for (int i : rSum) rb[i]++;
        for (int i : cSum) cb[i]++;
        System.out.println(java.util.stream.IntStream.rangeClosed(0, k).mapToLong(i -> rb[i] * cb[k - i]).sum() + java.util.stream.IntStream.range(0, n).map(i -> rSum[ra[i]] + cSum[ca[i]] - k).map(i -> (i == 0 ? -1 : i == 1 ? 1 : 0)).sum());
    }
}