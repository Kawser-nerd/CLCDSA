import java.util.Arrays;
import java.util.Scanner;
import java.io.*;
import java.math.BigInteger;

public class Main {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static BigInteger gcd(BigInteger aa, BigInteger bb) {
		BigInteger a = aa, b = bb, c;
		while(true) {
			c = a.mod(b);
			if(c == BigInteger.ZERO) break;
			a = b;
			b = c;
		}
		return b;
	}
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		cin = new Scanner(new File("E:\\Program Files\\WinZip\\Source\\´óÈýÏÂ\\JAVA\\src\\B-large.in"));
		BigInteger[] s;
		int n, t = cin.nextInt();
		for(int tt = 1; tt <= t; ++tt) {
			n = cin.nextInt();
			s = new BigInteger[n];
			for(int i = 0; i < n; ++i) {
				s[i] = cin.nextBigInteger();
			}
			Arrays.sort(s);
			for(int i = 1; i < n; ++i) {
				s[i] = s[i].subtract(s[0]);
			}
			BigInteger tmp = s[1], ans;
			for(int i = 2; i < n; ++i) {
				if(s[i] == BigInteger.ZERO) continue;
				tmp = gcd(tmp, s[i]);
			}
			ans = s[0].mod(tmp);
			System.out.println("Case #" + tt + ": " + tmp.subtract(ans).mod(tmp));
		}
	}

}
