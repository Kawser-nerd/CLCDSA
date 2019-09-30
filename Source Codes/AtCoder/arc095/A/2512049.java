import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		for(int i=0;i<n;i++){
			x[i] = sc.nextInt();
			y[i] = x[i];
		}
		Arrays.sort(y);
		int min = y[n/2-1];
		int max = y[n/2];
		for(int i=0;i<n;i++){
			if(x[i]<=min){
				System.out.println(max);
			}
			else{
				System.out.println(min);
			}
		}
	}
}