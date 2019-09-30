import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class GCJ2011QualA{
	void solve(){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int testCase=1;testCase<=T;testCase++){
			int N = sc.nextInt();
			int oT = 0, bT = 0;
			int oP = 1, bP = 1;
			for(int i=0;i<N;i++){
				char[] c = sc.next().toCharArray();
				int pos = sc.nextInt();
				if(c[0] == 'O'){
					oT = Math.max(oT+Math.abs(pos-oP), bT)+1;
					oP = pos;
				} else {
					bT = Math.max(bT+Math.abs(pos-bP), oT)+1;
					bP = pos;
				}
			}
			System.out.println("Case #"+testCase+": "+Math.max(bT, oT));
		}
	}
	public static void main(String args[]){
		new GCJ2011QualA().solve();
	}
}