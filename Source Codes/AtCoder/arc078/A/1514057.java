import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] v = new int[n];
        long sum = 0;
        for (int i = 0; i < n; ++i) {
            v[i] = in.nextInt();
            sum += v[i];
        }
        long res = Long.MAX_VALUE, x = 0;
        for (int i = 0; i < n - 1; ++i) {
            x += v[i];
            long y = sum - x;
            res = Math.min(Math.abs(x - y), res);
        }
        System.out.println(res);
    }

}