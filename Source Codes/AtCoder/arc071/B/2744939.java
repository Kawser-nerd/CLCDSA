import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] x = new int[n];
        int[] y = new int[m];
        int etc = (int)Math.pow(10, 9) + 7;
        for(int i=0;i<n;i++){
        	x[i] = sc.nextInt();
        }
        for(int i=0;i<m;i++){
        	y[i] = sc.nextInt();
        }
        Arrays.sort(x);
        Arrays.sort(y);
        long xcount = 0;
        long ycount = 0;
        long ans = 0;
        for(int i=0;i<n;i++){
        	xcount += (long)i * (long)x[i] - ((long)n - (long)i - 1) * (long)x[i];
        }

        for(int i=0;i<m;i++){
        	ycount += (long)i * (long)y[i] - ((long)m - (long)i - 1) * (long)y[i];
        }
        xcount = xcount%etc;
        ycount = ycount%etc;
        ans = xcount*ycount%etc;

        System.out.println(ans%etc);
    }
}