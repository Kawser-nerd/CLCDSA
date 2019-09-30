import java.util.Scanner;

/**
 * ARC004A_The_longest_distance
 */
public class Main {
    private static Scanner sc;

    public static void main(String[] args) {
        sc = new Scanner(System.in);

        // ???N??????????????
        int N = sc.nextInt();
        int[] x = new int[N];
        int[] y = new int[N];
        for (int i = 0; i < N; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }

        // 1???????????
        float answer = 0;
        float tmp = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                tmp = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                if (answer < tmp) {
                    answer = tmp;
                }
            }
        }

        System.out.println(Math.sqrt(answer));

        sc.close();
    }
}