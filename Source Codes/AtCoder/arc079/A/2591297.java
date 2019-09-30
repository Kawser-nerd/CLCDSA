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
		int[] a = new int[m];
		int[] b = new int[m];
		for(int i=0;i<m;i++){
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
		int[] center1 = new int[n+1];
		int[] centern = new int[n+1];

		for(int i=0;i<m;i++){
			if(a[i]==1){
				center1[b[i]]++;
			}
			if(a[i]==n){
				centern[b[i]]++;
			}
			if(b[i]==1){
				center1[a[i]]++;
			}
			if(b[i]==n){
				centern[a[i]]++;
			}
		}

		boolean flag = false;
		for(int i=0;i<=n;i++){
			if(center1[i]!=0 && centern[i]!=0){
				flag = true;
			}
		}

		if(flag){
			System.out.println("POSSIBLE");
		}
		else{
			System.out.println("IMPOSSIBLE");
		}
	}	
}