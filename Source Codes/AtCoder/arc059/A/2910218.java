import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] t = new int[n];
            int min = Integer.MAX_VALUE;
            int max = Integer.MIN_VALUE;
            for (int i = 0; i < n; i++) {
                t[i] = sc.nextInt();
                min = Math.min(min, t[i]);
                max = Math.max(max, t[i]);
            }

            int ans = Integer.MAX_VALUE;
            for (int i = min; i <= max; i++) {
                int sum = 0;
                for (int j = 0; j < n; j++) {
                    int diff = t[j] - i;
                    sum += diff * diff;
                }
                ans = Math.min(ans, sum);
            }
            System.out.println(ans);
        }
    }
}