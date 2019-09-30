import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int N = sc.nextInt();
            int[] t = new int[N];
            int max = Integer.MIN_VALUE;
            int maxIdx = -1;

            for (int i = 0; i < N; i++) {
                t[i] = sc.nextInt();
                int abs = Math.abs(t[i]);
                if (max < abs) {
                    max = abs;
                    maxIdx = i;
                }
            }

            System.out.println(N * 2 - 1);

            for (int i = 0; i < N; i++) {
                System.out.println((maxIdx + 1) + " " + (i + 1));
            }

            for (int i = 0; i < N - 1; i++) {
                if (t[maxIdx] > 0) {
                    System.out.println((i + 1) + " " + (i + 2));
                } else {
                    System.out.println((N - i) + " " + (N - i - 1));
                }
            }
        }
    }
}