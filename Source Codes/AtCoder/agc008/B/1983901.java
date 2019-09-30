import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long[] a = new long[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextLong();
        }

        long ans1 = 0;
        long ans2 = 0;

        long max = -1000000000000000L;
        long max2 = -1000000000000000L;
        long min = 1000000000000000L;
        int posmax = 0;
        int posmin = 0;
        long l1 = 0;
        long s1 = 0;
        for(int j=0; j<k; j++){
            if(a[j] > 0) l1 += a[j];
            if(a[j] < 0)  s1 += a[j];
        }
        if(s1 > max){
            max = s1;
            posmax = 0;
        }
        if( l1 < min){
            min = l1;
            posmin = 0;
        }
        for(int i=1; i<n+1-k; i++){
            long l = l1;
            if(a[i-1] > 0) l -= a[i-1];
            if(a[i-1+k] > 0) l += a[i-1+k];
            long s = s1;
            if(a[i-1]< 0) s -= a[i-1];
            if(a[i-1+k] < 0) s += a[i-1+k];
            if(s > max){
                max = s;
                posmax = i;
            }
            if( l < min){
                min = l;
                posmin = i;
            }
            l1 = l;
            s1 = s;
        }

        for(int i=0; i<n; i++){
            if((i < posmin || i > posmin + k-1) && a[i] > 0){
                ans1 += a[i];
            }
        }

        ans2 += max;
        for(int i=0; i<n; i++){
            if(a[i] > 0){
                ans2 += a[i];
            }
        }

        System.out.println(Long.max(ans1, ans2));
    }
}