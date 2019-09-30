import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[100001];
		for(int i=0;i<n;i++){
			a[sc.nextInt()]++; 
		}
		int max = 0;
		for(int i=0;i<99999;i++){
			max = (int)Math.max(max, a[i] + a[i+1] + a[i+2]);
		}

		System.out.println(max);
	}
}