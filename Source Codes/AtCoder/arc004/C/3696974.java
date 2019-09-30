import java.util.*;
public class Main{
	public static void main(String... argv){
		Scanner in = new Scanner(System.in);
		String[] s = in.next().split("/");
		long x = Long.parseLong(s[0]);
		long y = Long.parseLong(s[1]);
		long g = gcd(x,y);
		x /= g;
		y /= g;
		// X/Y??????
        // [N/2-0.5, N/2+0.5)
		//long N = 2*x/y + 1;//(x/y)*2 + 1????
		boolean flag = true;
		for (int i = 0; i < 2; i++) {
			long n = 2*x/y+i;
			if (n % y == 0) {
				long m = n*(n+1)/2 - (n/y)*x;
				if(m<=n && m>0){
					System.out.println(n+" "+ m);
					flag = false;
				}
			}
		}
		if(flag)
			System.out.println("Impossible");
	}
	
	//?????????????????
	static long gcd(long a, long b){
		//??????
		if(a<b){
			long temp = a;
			a = b;
			b = temp;
		}
		while(b!=0){
			long c = a;
			a = b;
			b = c%b;
		}
		return a;
	}
}