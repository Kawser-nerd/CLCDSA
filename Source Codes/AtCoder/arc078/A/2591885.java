import java.io.*;
import java.util.*;
import java.lang.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        long count = 0;
        for(int i=0;i<n;i++){
        	a[i] = sc.nextLong();
        	count += a[i];
        }
        long min = Long.MAX_VALUE/2;

        long counter = 0;
        for(int i=0;i<n-1;i++){
        	counter += a[i];
        	min = Math.min(min, (long)Math.abs((count-counter) - counter));
        }

        System.out.println(min);
    }
}