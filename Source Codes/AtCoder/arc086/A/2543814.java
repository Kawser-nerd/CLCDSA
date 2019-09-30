import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] a = new int[200001];
		for(int i=0;i<n;i++){
			a[sc.nextInt()]++;
		}
		Arrays.sort(a);
		int count = 0;
		for(int i=200000;i>200000-k;i--){
			count += a[i];
		}
		System.out.println(n-count);
	}
}