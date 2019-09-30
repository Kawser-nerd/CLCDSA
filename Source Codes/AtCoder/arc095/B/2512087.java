import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for(int i=0;i<n;i++){
			a[i] = sc.nextInt();
		}
		Arrays.sort(a);
		int max = a[n-1];
		int min = (max+1)/2;
		int now = 0;
		for(int i=1;i<n-1;i++){
			if((int)Math.abs(min-a[i])<(int)Math.abs(min-a[now])){
				now = i;
			}
		}
		System.out.println(max+" "+a[now]);
	}
}