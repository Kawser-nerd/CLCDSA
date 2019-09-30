import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n+2];
		for(int i=1;i<n+1;i++){
			a[i] = sc.nextInt();
		}
		int num = 0;
		for(int i=0;i<n+1;i++){
			num += (int)Math.abs(a[i] - a[i+1]);
		}
		for(int i=1;i<n+1;i++){
			System.out.println(num - (int)Math.abs(a[i-1] - a[i]) - (int)Math.abs(a[i] - a[i+1]) + (int)Math.abs(a[i-1] - a[i+1]));
		}
	}
}