import java.io.File;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class ProperShuffle {

    // private static String file = "data/r1csample.txt";

    static Random random = new Random();

    private static String file = "data/r1c-C-small-attempt0.in";
    // private static String file = "data/C-large.in";

    // private static final int TRY_COUNT = 1000000;
    private static final int LEN = 1000;
    private static final int TRY_COUNT = 1000 * LEN;

    public static void main(String[] args) throws Exception {

        FileInputStream is = new FileInputStream(new File(file));
        Scanner scanner = new Scanner(is);

        int[][] count = new int[LEN][LEN];
        int[] arr = new int[LEN];
        for (int i = 0; i < LEN; i++) {
            arr[i] = i;
        }
        for (int i = 0; i < TRY_COUNT; i++) {
            // if (i % 10000 == 0) {
            // System.out.println(i);
            // }
            int[] copy = arr.clone();
            shuffle(copy);
            for (int j = 0; j < LEN; j++) {
                count[copy[j]][j]++;
            }
        }
        // for (int i = 0; i < LEN; i++) {
        // System.out.println(Arrays.toString(count[i]));
        // }

        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int n = scanner.nextInt();
            double prob = 1.0;
            for (int i = 0; i < n; i++) {
                int s = scanner.nextInt();
                prob *= (double) count[s][i] / (double) (TRY_COUNT / LEN);
            }
            // System.out.println(prob);
            if (prob > 1.0) {
                out(t, "BAD");
            } else {
                out(t, "GOOD");
            }
        }
    }

    static void shuffle(int arr[]) {
        int len = arr.length;
        for (int k = 0; k < len; k++) {
            int p = random.nextInt(len);
            int t = arr[p];
            arr[p] = arr[k];
            arr[k] = t;
        }
    }

    static void out(int t, Object ans) {
        System.out.println("Case #" + (t + 1) + ": " + ans);
    }

}
