import java.io.*;
import java.math.*;
import java.util.*;

class b {
/*	  static BigInteger func(int n, int k) {//BigInteger n, BigInteger k) {
	  		 
		 n = (n-k)/2+k;
		 int i;
		 BigInteger result = new BigInteger("1");
		 
		 //System.out.printf("%d %d\n", n, k);
		 
		 for(i=1; i<=k; i++)
		 {
		  		 result = result.multiply(new BigInteger(""+(n-i+1)));
 		  //System.out.println(result.toString());
		   		  		 result = result.divide(new BigInteger(""+i));
 		  //System.out.println(result.toString());
  		}
		 return result;
	  }*/
	public static void main(String[] args) {
		Scanner fin = new Scanner(System.in);
		int nt = fin.nextInt(), it;
		boolean debug = false;
		
		for (it = 1; it <= nt; it++) {
			String s = fin.next();
			BigInteger d[][][][][] = new BigInteger[41][2][3][5][7], r = BigInteger.ZERO;
			int n = s.length(), i, j, k, m2, m3, m5, m7, i2, i3, i5, i7;
			
			for (i = 0; i <= n; i++) for (i2 = 0; i2 < 2; i2++) for (i3 = 0; i3 < 3; i3++) for (i5 = 0; i5 < 5; i5++) for (i7 = 0; i7 < 7; i7++) d[i][i2][i3][i5][i7] = BigInteger.ZERO;
			d[0][0][0][0][0] = BigInteger.ONE;
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= i; j++) {
					BigInteger t = new BigInteger(s.substring(n - i, n - i + j));
					//System.out.println(t);
					for (k = 1; k >= (i < n ? -1 : 1); k -= 2) { // n. var būt tikai pluszīmīte
						if (debug) System.out.println(t);
						m2 = (t.mod(new BigInteger("2"))).intValue();
						m3 = (t.mod(new BigInteger("3"))).intValue();
						m5 = (t.mod(new BigInteger("5"))).intValue();
						m7 = (t.mod(new BigInteger("7"))).intValue();
						for (i2 = 0; i2 < 2; i2++) for (i3 = 0; i3 < 3; i3++) for (i5 = 0; i5 < 5; i5++) for (i7 = 0; i7 < 7; i7++) {
							d[i][(i2 + m2 + 2) % 2][(i3 + m3 + 3) % 3][(i5 + m5 + 5) % 5][(i7 + m7 + 7) % 7] = d[i][(i2 + m2 + 2) % 2][(i3 + m3 + 3) % 3][(i5 + m5 + 5) % 5][(i7 + m7 + 7) % 7].add(d[i - j][i2][i3][i5][i7]);
						}
						t = t.negate();
					}
				}
			}
			for (i2 = 0; i2 < 2; i2++) for (i3 = 0; i3 < 3; i3++) for (i5 = 0; i5 < 5; i5++) for (i7 = 0; i7 < 7; i7++) if (i2 == 0 || i3 == 0 || i5 == 0 || i7 == 0) {
				r = r.add(d[n][i2][i3][i5][i7]);
			}
			
			System.out.println("Case #" + it + ": "/* + s + ": "*/ + r);
		}
	}
}
