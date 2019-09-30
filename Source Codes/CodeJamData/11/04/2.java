import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class GCJ2011QualD{
	void solve(){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int testCase=1;testCase<=T;testCase++){
			int N = sc.nextInt();
			int res = 0;
			for(int i=1;i<=N;i++)
				if(i!=sc.nextInt()) res++;
			System.out.println("Case #"+testCase+": "+res);
		}
	}
	public static void main(String args[]){
		new GCJ2011QualD().solve();
	}
}