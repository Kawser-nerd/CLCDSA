import java.util.*;
import java.lang.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int x = sc.nextInt();
        int[] a = new int[N+1];
        a[0]=0;
        for(int n=0;n<N;n++)a[n]=sc.nextInt();
        
        long ans = 0;
        for(int n=1;n<=N;n++){
        	int eat = (a[n-1]+a[n]<=x) ? 0 : a[n-1]+a[n]-x;
        	ans += eat;
        	a[n] -= eat;
        }
        System.out.println(ans);
    }
}