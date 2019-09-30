import java.util.*;
 
public class Main {
		public static void main(String[] args) {
			 
			Scanner sc = new Scanner(System.in);
	 
			long N = sc.nextInt();
			long M = sc.nextInt();
			char[] S = sc.next().toCharArray();
			char[] T = sc.next().toCharArray();
			long g = gcd(N,M);
			long L = (N * M) / g;
			boolean flag = true;
	 
			for(long i = 0;i<g;i++) {
				if(S[(int)(N/g * i)] != T[(int)(M/g *i)]) {
					flag = false;
				}
			}
	 
			if(flag) {
				System.out.println(L);
			}else {
				System.out.println("-1");
			}
		    sc.close();
		}
	 
	 
	    private static long gcd(long m, long n) {
	        if(m < n) return gcd(n, m);
	        if(n == 0) return m;
	        return gcd(n, m % n);
	    }
}