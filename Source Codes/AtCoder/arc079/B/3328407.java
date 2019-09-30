import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long k = sc.nextLong();
        sc.close();

        int n = 50;
        long[] ans = new long[n];

        long quo = k / n;
        int rem = (int)(k % n);

        for(int i=0; i<n; i++){
            ans[i] = n-1+quo;
        }

        for(int i=0; i<rem; i++){
            ans[i] += n - (rem-1);
        }
        for(int i=rem; i<n; i++){
            ans[i] -= rem;
        }

        System.out.println(n);
        for(int i=0; i<n-1; i++){
            System.out.print(ans[i] + " ");
        }
        System.out.println(ans[n-1]);
    }
}