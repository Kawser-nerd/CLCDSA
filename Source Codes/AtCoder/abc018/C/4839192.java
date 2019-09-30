public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int r = scanner.nextInt(), c = scanner.nextInt(), k = scanner.nextInt(), s[][] = java.util.stream.IntStream.range(0, r).mapToObj(i -> scanner.next().chars().toArray()).toArray(int[][]::new), a[][] = new int[r][c];
        java.util.stream.IntStream.range(0, c).map(i -> java.util.stream.IntStream.range(0, r).reduce(0, (t, j) -> a[j][i] = s[j][i] == 'x' ? 0 : t + 1) + java.util.stream.IntStream.range(0, r).reduce(0, (t, j) -> a[r - j - 1][i] = Math.min(a[r - j - 1][i], s[r - j - 1][i] == 'x' ? 0 : t + 1))).count();
        System.out.println(java.util.stream.IntStream.rangeClosed(k - 1, r - k).mapToLong(i -> java.util.stream.IntStream.range(0, c - k * 2 + 2).filter(j -> java.util.stream.IntStream.range(0, k * 2 - 1).allMatch(l -> a[i][j + l] >= Math.min(l + 1, k * 2 - l - 1))).count()).sum());
    }
}