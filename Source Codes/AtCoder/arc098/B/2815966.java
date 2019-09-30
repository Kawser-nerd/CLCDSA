import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = in.nextInt();

        int l = 0, sum = 0, xorSum = 0;
        long ans = 0;
        for(int r = 0; r < n; ++r) {
            sum += a[r];
            xorSum ^= a[r];
            while (xorSum != sum) {
                sum -= a[l];
                xorSum ^= a[l];
                ++l;
            }
            ans += r-l+1;
        }

        System.out.println(ans);
    }
}