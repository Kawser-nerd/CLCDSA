import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

/**
 *
 */
public class Main {

    public static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        long a[] = new long[n];
        for (int i = 0 ; i < n ; i++)
            a[i]=sc.nextLong();
        long ans = 0, last =0;

        for (int i = 1; i < n ; i ++) {
            if ( last + t < a[i]) {
                ans += t;
                last = a[i];
            } else {
                ans += a[i]-a[i-1];
                last = a[i];
            }
        }
        ans+=t;
        System.out.println(ans);

    }

    public static void main(String[] argc) {
        solve();
    }
}