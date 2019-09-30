import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int h = scanner.nextInt(), w = scanner.nextInt(), t = scanner.nextInt(), s = 0, g = 0, l = 0, r = t;
        char[][] c = new char[h][w];
        IntStream.range(0, h).forEach(i -> c[i] = scanner.next().toCharArray());
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (c[i][j] == 'S') s = i * w + j;
                if (c[i][j] == 'G') g = i * w + j;
            }
        }
        while (r - l > 1) {
            int mid = (l + r) / 2;
            long[][] gragh = IntStream.range(0, h * w).mapToObj(i -> IntStream.range(0, h * w).mapToLong(j -> i == j ? 0 : 0x7ffffffffffffffL).toArray()).toArray(long[][]::new);
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + (new int[] {1, -1, 0, 0})[k];
                        int ny = j + (new int[] {0, 0, 1, -1})[k];
                        if (0 <= nx && nx < h && 0 <= ny && ny < w)
                            gragh[i * w + j][nx * w + ny] = c[nx][ny] == '#' ? mid : 1;
                    }
                }
            }
            IntStream.range(0, h * w).forEach(i -> IntStream.range(0, h * w).forEach(j -> IntStream.range(0, h * w).forEach(k -> gragh[j][k] = Math.min(gragh[j][k], gragh[j][i] + gragh[i][k]))));
            if (gragh[s][g] <= t) l = mid;
            else r = mid;
        }
        System.out.println(l);
    }
}