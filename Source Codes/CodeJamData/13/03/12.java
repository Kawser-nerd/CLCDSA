import java.io.*;
import java.math.*;
import java.util.*;


public class Solution {
	
	public static Scanner in;
	public static PrintWriter out;
	
	public static void init() {
		try {
			in = new Scanner(new FileInputStream("input.txt"));
			out = new PrintWriter(new FileOutputStream("output.txt"));
		}
		catch (Exception e) {
			System.out.println(e);
		}
	}
	
	static int c = 0;
	
	static BigInteger[] xx = new BigInteger[2000000]; 
	
	static void check(BigInteger x, int f) {
		String s1 = x.toString();
		String s2 = "";
		for (int i = f; i < s1.length(); i++) {
			s2 = s2.concat((new Character(s1.charAt(s1.length() - i - 1))).toString());
		}
		BigInteger tmp = new BigInteger(s1.concat(s2));
		xx[c++] = tmp.multiply(tmp);
	}
	
	static void go(int s, int last, BigInteger val) {
		//out.println(s + " " + last + " " + val);		
		if (val.compareTo(new BigInteger("10000000000000000000000000")) >= 0)
			return;
		
		if (val.compareTo(BigInteger.ZERO) > 0) {
			if (s * 2 <= 9)
				check(val, 0);
			if (s * 2 - last * last <= 9)
				check(val, 1);
		}
				
		for (int i = 0; i <= 3; i++) {
			if (s * 2 + i * i > 9)
				break;
			BigInteger tval = val.multiply(BigInteger.TEN);
			tval = tval.add(BigInteger.valueOf(i));
			go(s + i * i, i, tval);
		}
	}
	
	public static void main(String[] args) {
		init();
		
		go(1, 1, BigInteger.ONE);
		go(4, 2, BigInteger.valueOf(2));
		go(9, 3, BigInteger.valueOf(3));
		
		Arrays.sort(xx, 0, c);
	
		/*out.println(c);
		for (int i = 0; i < 100; i++)
			out.println(xx[c - i - 1]);*/
		
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			BigInteger l = in.nextBigInteger();
			BigInteger r = in.nextBigInteger();
			int ans = 0;
			for (int j = 0; j < c; j++) {
				BigInteger t = xx[j];
				if (t.compareTo(r) > 0)
					break;
				if (t.compareTo(l) >= 0 && t.compareTo(r) <= 0)
					ans++;
			}
			out.println("Case #" + (i + 1) + ": " + ans);
		}
		
		out.flush();
	}

}
