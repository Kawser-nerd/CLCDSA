import java.math.BigInteger;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger a = new BigInteger(sc.next());
		BigInteger a2 = a.multiply(a);
		BigInteger b = a.add(BigInteger.ONE);
		BigInteger b2 = b.multiply(b);
		
		String a2s = a2.toString();
		if(a2s.length()%2!=0)
			a2s = "0"+a2s;
		String b2s = b2.toString();
		while(b2s.length() < a2s.length())
			b2s = "0"+b2s;
		
		BigInteger ans = BigInteger.ZERO;
		boolean carry = false;
		for(int i=0; i<a2s.length(); i+=2) {
			ans = ans.multiply(BigInteger.TEN);
			ans = ans.add(new BigInteger(String.valueOf((int)(a2s.charAt(i)-'0'))));
			ans = ans.multiply(BigInteger.TEN);
			ans = ans.add(new BigInteger(String.valueOf((int)(a2s.charAt(i+1)-'0'))));
			
			if(followingZero(a2s, i+2))
				break;
			if(a2s.charAt(i)!=b2s.charAt(i) || a2s.charAt(i+1)!=b2s.charAt(i+1)) {
				if((carry ? 100 : 0)+(b2s.charAt(i)-a2s.charAt(i))*10+(b2s.charAt(i+1)-a2s.charAt(i+1))>1 || !followingZero(b2s, i+2)) {
					ans = ans.add(BigInteger.ONE);
					break;
				} else {
					carry = true;
				}
			}
		}
		
		System.out.println(ans);
		
		sc.close();
	}

	static boolean followingZero(String s, int idx) {
		for(int i=idx; i<s.length(); i++)
			if(s.charAt(i)!='0')
				return false;
		return true;
	}
}