import java.util.*;

public class Main {
    static int n, k;
    static int[] a;
    static int modP = 1000000007;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        k = in.nextInt();
        a = new int[n];
        for(int i = 0; i < n; i++) a[i] = in.nextInt();

        int ans = (int)Math.ceil((double)(n - 1) / (double)(k - 1));

        System.out.println(ans);
    }
}