import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), t = in.nextInt();
        int[] a = new int[n], b = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int min = Integer.MAX_VALUE, max = 0;
        for(int i = 0; i < n; i++) {
            min = Math.min(min, a[i]);
            b[i] = a[i] - min;
            max = Math.max(max, b[i]);
        }
        final int ans = max;
        System.out.println(Arrays.stream(b).filter(num -> num == ans).count());

    }
}