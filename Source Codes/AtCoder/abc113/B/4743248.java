import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int T = sc.nextInt();
        int A = sc.nextInt();

        int ans = 0;
        double minDiff = Double.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            int h = sc.nextInt();
            double temp = (double) T - (((double) h) * 0.006);
            double diff = Math.abs((double) A - temp);
            if (minDiff > diff) {
                minDiff = diff;
                ans = i + 1;
            }
        }
        System.out.println(ans);
    }
}