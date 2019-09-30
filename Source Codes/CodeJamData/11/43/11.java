import java.io.*;
import java.util.*;

public class Bai3 {
	
	static int gcd(int a, int b) {
		while(a != 0 && b != 0)
			if(a > b) a %= b;
			else b %= a;
		return a + b;
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		// Scanner sc = new Scanner(new FileReader("C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("Clarge.out"));
		
		boolean[] isprime = new boolean[1000010];
		Arrays.fill(isprime, true);
		isprime[0] = isprime[1] = false;
		int nprime = 0;
		for(int i=2;i<isprime.length;++i) 
			if(isprime[i]) {
				++nprime;
				for(int j=i+i;j<isprime.length;j+=i)
					isprime[j] = false;
			}
		int[] primelist = new int[nprime];
		nprime = 0;
		for(int i=2;i<isprime.length;++i)
			if(isprime[i])
				primelist[nprime++] = i;
		
		int ntest = sc.nextInt();
		
		for(int test=1;test<=ntest;++test) {

			long n = sc.nextLong();
			long res = 0;
			
			if(n > 1) {
				res = 1;
				for(int i=0;i<nprime;++i) {
					long p = primelist[i];
					
					if(p * p > n) break;
					
					long t = p;
					while(t * p <= n) {
						t *= p;
						++res;
					}
				}
			}
			
			pw.print("Case #" + test + ": ");
			pw.print(res);
			pw.println();
		}
		pw.close();
		sc.close();
	}
}
