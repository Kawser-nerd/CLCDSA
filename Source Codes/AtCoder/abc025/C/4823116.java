import java.util.Arrays;
import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    static int[] b, c;
    public static void main(String[]$) {
        b = new int[] {scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt()};
        c = new int[] {scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt()};
        int score = f(0, new Boolean[][] {new Boolean[] {null, null, null}, new Boolean[] {null, null, null}, new Boolean[] {null, null, null}});
        System.out.println(score);
        System.out.println(IntStream.concat(Arrays.stream(b), Arrays.stream(c)).sum() - score);
    }

    static int f(int n, Boolean[][] i) {
        boolean turn = n % 2 == 0;
        int score = turn ? 0 : 1200;

        if (n == 9) {
            score = 0;
            if (i[0][0] == i[1][0] ^ turn) score += b[0];
            if (i[0][1] == i[1][1] ^ turn) score += b[1];
            if (i[0][2] == i[1][2] ^ turn) score += b[2];
            if (i[1][0] == i[2][0] ^ turn) score += b[3];
            if (i[1][1] == i[2][1] ^ turn) score += b[4];
            if (i[1][2] == i[2][2] ^ turn) score += b[5];

            if (i[0][0] == i[0][1] ^ turn) score += c[0];
            if (i[0][1] == i[0][2] ^ turn) score += c[1];
            if (i[1][0] == i[1][1] ^ turn) score += c[2];
            if (i[1][1] == i[1][2] ^ turn) score += c[3];
            if (i[2][0] == i[2][1] ^ turn) score += c[4];
            if (i[2][1] == i[2][2] ^ turn) score += c[5];

            return score;
        }

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i[j][k] == null) {
                    i[j][k] = turn;
                    score = turn ? Math.max(score, f(n + 1, i)) : Math.min(score, f(n + 1, i));
                    i[j][k] = null;
                }
            }
        }

        return score;
    }
}