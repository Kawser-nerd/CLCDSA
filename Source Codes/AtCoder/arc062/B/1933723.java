import java.util.Arrays;
import java.util.Scanner;

class Main{
	static Scanner s=new Scanner(System.in);
	static int gInt() {return Integer.parseInt(s.next());}
	static long gLong() {return Long.parseLong(s.next());}

	public static void main(String[]$){
		char[]c=s.next().toCharArray();
		int n=c.length;
		int[]rem=new int[n];
		int res=0,rem_=0;
		for(int i=0;i<n;++i) {
			if(c[i]=='g') {
				++rem_;
			} else {
				if(rem_>0) {
					--rem_;
				}else {
					++res;
				}
			}
			rem[i]=rem_;
		}
		System.out.println(res+rem[n-1]/2);
	}
}