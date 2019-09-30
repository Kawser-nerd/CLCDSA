import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class GCJ2011QualC{
	void solve(){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int testCase=1;testCase<=T;testCase++){
			int N = sc.nextInt();
			int sum = 0, xor = 0, m = 10000000;
			for(int i=0;i<N;i++){
				int C = sc.nextInt();
				sum += C;
				xor ^= C;
				m = Math.min(m, C);
			}
			System.out.print("Case #"+testCase+": ");
			if(xor != 0) System.out.println("NO");
			else         System.out.println(sum-m);
		}
	}
	public static void main(String args[]){
		new GCJ2011QualC().solve();
	}
}