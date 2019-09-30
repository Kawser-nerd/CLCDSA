//package googleCodeJam.season2013.quali;
import java.util.*;
import java.io.*;
import java.math.*;

public class C{
	static Scanner scan;
	static BigInteger upper = BigInteger.TEN.pow(25);
	static TreeSet<BigInteger> set;
	static String zeros = "";
	static int counter = 1000000;
	public static void main(String[] args) throws Exception{
		scan = new Scanner(System.in);
		for(int i = 0 ; i < 1000; i++)zeros += "0";
		set = new TreeSet<BigInteger>();
		for(int i = 0; i < 10; i++)check(BigInteger.valueOf(i));
		for(int i = 1; i < 10; i++)bruteForce(BigInteger.valueOf(i), BigInteger.valueOf(i), BigInteger.TEN, 1, i);
		//System.out.println(set.size());
		//for(int i = 0; i < 10000000; i++)check(BigInteger.valueOf(i));
		//System.out.println(set.size());
		BigInteger tmp = set.last();
		System.err.println(set.size());
		System.err.println(tmp);
		int tc = scan.nextInt();
		for(int tcc = 1; tcc <= tc; tcc++){
			System.out.print("Case #" + tcc +": ");
			BigInteger A = scan.nextBigInteger(), B = scan.nextBigInteger();
			int res = 0;
			for(BigInteger i: set)if(i.compareTo(A) >= 0 && i.compareTo(B) <= 0)++res;
			System.out.println(res);
		}
	}
	static void check(BigInteger b){
		BigInteger tmp = b.multiply(b);
		String s = b.toString();
		for(int i = 0; i < s.length(); i++)if(s.charAt(i) != s.charAt(s.length() - 1 - i))return;
		s = tmp.toString();
		for(int i = 0; i < s.length(); i++)if(s.charAt(i) != s.charAt(s.length() - 1 - i))return;
		set.add(tmp);
		if(set.size()%500 == 0){
				System.err.println(set.size());
				System.err.println(b);
		}
	}
	private static void bruteForce(BigInteger front, BigInteger back,
			BigInteger mul, int digits, int sum) {
		if(sum >= 5)return;
		if(counter--==0){
			counter = 1000000;
			System.err.println("fron: " + front);
		}
		if(mul.compareTo(upper) > 0)return;
		BigInteger lo = front.multiply(front);
		BigInteger hi = lo.add(front).add(front);
		BigInteger bsq = back.multiply(back).mod(mul);
		String bs = bsq.toString();
		bs = zeros.substring(0, digits - bs.length()) + bs;
		String los = lo.toString();
		String his = hi.toString();
		boolean slen = (los.length() == his.length());
		los = los.substring(0, bs.length());
		his = his.substring(0, bs.length());
		bs = new StringBuffer(bs).reverse().toString();
		if(slen){
			if(bs.compareTo(los) < 0)return;
			if(bs.compareTo(his) > 0)return;
		} else {
			if(bs.compareTo(los) < 0 && bs.compareTo(his) > 0)return;
		}
		check(front.multiply(mul).add(back));
		for(int i = 0; i < 10; i++)check(front.multiply(BigInteger.TEN).add(BigInteger.valueOf(i)).multiply(mul).add(back));
		for(int i = 0; i < 4; i++){
				bruteForce(front.multiply(BigInteger.TEN).add(BigInteger.valueOf(i)), 
							back.add(mul.multiply(BigInteger.valueOf(i))), 
							mul.multiply(BigInteger.TEN), digits + 1, sum + i);
		}
	}
}
