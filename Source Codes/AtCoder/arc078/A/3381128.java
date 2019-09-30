import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        long sum = 0;
        for(int i=0; i<n; i++){
            a[i] = sc.nextLong();
            sum += a[i];
        }
        sc.close();

        long ans = Long.MAX_VALUE;

        long x = 0;
        for(int i=0; i<n-1; i++){
            x += a[i];
            long dif = Math.abs((sum-x) - x);
            if(dif < ans) ans = dif;
        }

        System.out.println(ans);
    }
}