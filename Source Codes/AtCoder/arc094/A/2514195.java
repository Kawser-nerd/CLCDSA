import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int[] a = new int[3];
		int max = 0;
		for(int i=0;i<3;i++){
			a[i] = sc.nextInt();
			max = (int)Math.max(max, a[i]);
		}
		int count = 0;
		for(int i=0;i<3;i++){
			int x = (max - a[i])/2;
			a[i] += x*2;
			count += x;
		}
		Arrays.sort(a);
		if(a[0]==a[1] && a[1]==a[2]){

		}
		else if(a[2]==a[1]){
			count += 2;
		}
		else{
			count += 1;
		}
		System.out.println(count);

	}
}