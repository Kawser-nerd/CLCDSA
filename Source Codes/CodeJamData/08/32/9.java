import java.util.*;
import java.math.*;

public class B {
	BigInteger ten = BigInteger.valueOf(10);
	BigInteger n2 = BigInteger.valueOf(2);
	BigInteger n3 = BigInteger.valueOf(3);
	BigInteger n5 = BigInteger.valueOf(5);
	BigInteger n7 = BigInteger.valueOf(7);
	BigInteger memo[][][][][];
	String s;

	BigInteger rec(int idx, int r2, int r3, int r5, int r7){
		if (idx==s.length()) return BigInteger.valueOf((r2==0 || r3==0 || r5==0 || r7==0)? 1 : 0);
		if (memo[idx][r2][r3][r5][r7]!=null) return memo[idx][r2][r3][r5][r7];

		BigInteger ret = BigInteger.ZERO;
		BigInteger num = BigInteger.ZERO;
		for (int i=idx; i<s.length(); i++){
			num = num.multiply(ten);
			num = num.add(BigInteger.valueOf(s.charAt(i)-'0'));
			int nr2 = ((r2+num.mod(n2).intValue())+2)%2;
			int nr3 = ((r3+num.mod(n3).intValue())+3)%3;
			int nr5 = ((r5+num.mod(n5).intValue())+5)%5;
			int nr7 = ((r7+num.mod(n7).intValue())+7)%7;
			ret = ret.add(rec(i+1,nr2,nr3,nr5,nr7));
			if (idx>0){
				nr2 = ((r2-num.mod(n2).intValue())+2)%2;
				nr3 = ((r3-num.mod(n3).intValue())+3)%3;
				nr5 = ((r5-num.mod(n5).intValue())+5)%5;
				nr7 = ((r7-num.mod(n7).intValue())+7)%7;
				ret = ret.add(rec(i+1,nr2,nr3,nr5,nr7));
			}
		}
		return memo[idx][r2][r3][r5][r7] = ret;
	}

	void solve(){
		Scanner scan = new Scanner(System.in);
		int nTC = scan.nextInt();
		for (int TC=1; TC<=nTC; TC++){
			s = scan.next();
			memo = new BigInteger[s.length()][2][3][5][7];
			System.out.printf("Case #%d: %s\n",TC,rec(0,0,0,0,0).toString());
		}
	}

	public static void main(String[] args){
		new B().solve();
	}
}
