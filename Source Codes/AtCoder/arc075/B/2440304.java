import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long a = in.nextLong(), b = in.nextLong();
        long[] h = new long[n];
        for(int i = 0; i < n;i ++) {
            h[i] = in.nextLong();
        }
        long left = 0L, right = (long)1e9;
        while (left < right) {
            // System.out.println(left + " " + right);
            long c = (left + right) / 2;
            if(isBeatUp(h, a, b, c)){
                right = c;
            } else {
                left = c + 1;
            }
        }
        System.out.println(right);
    }

    public static boolean isBeatUp(long[] health, long a, long b, long c) {
        long cnt = 0;
        for(long h : health) {
            long t = (long)Math.ceil((h - b*c) / (double)(a - b));
            cnt += Math.max(t, 0);
        }
        return cnt <= c;
    }
}