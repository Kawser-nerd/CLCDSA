import java.io.*;
import java.util.*;

public class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];
		for(int i=0;i<n;i++){
			a[i] = sc.nextInt();
		}
		for(int i=0;i<n;i++){
			b[i] = sc.nextInt();
		}
		for(int i=0;i<n;i++){
			c[i] = sc.nextInt();
		}
		Arrays.sort(a);
		Arrays.sort(b);
		Arrays.sort(c);
		long count = 0;
		for(int i=0;i<n;i++){
			int l = -1;
			int r = n;
			int min = 0;
			int max = 0;
			while(r-l>1){
				int center = (r + l) / 2;
				if(a[center]>=b[i]){
					r = center;
				}
				else{
					l = center;
				}
			}
			min = r;
			l = -1;
			r = n;
			while(r-l>1){
				int center = (r + l) / 2;
				if(c[center]<=b[i]){
					l = center;
				}
				else{
					r = center;
				}
			}
			max = n - r;
			count += (long)max * (long)min;
		}
		System.out.println(count);
	}
}