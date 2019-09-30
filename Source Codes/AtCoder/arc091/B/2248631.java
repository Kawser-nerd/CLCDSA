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
		long count = 0;

		if(k==0){
			count = (long)n*(long)n;
		}
		else{
			for(int i=2;i<=n;i++){
				if(i>k){
					count += (long)Math.max(0, n/i*(i-k));
					count += (long)Math.max(0, (n%i)-k+1);
				}
			}
		}

		System.out.println(count);
	}
}