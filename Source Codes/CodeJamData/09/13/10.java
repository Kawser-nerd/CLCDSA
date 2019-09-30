import java.io.*;
import java.util.*;
import java.math.*;


public class AAA {
	
	class fraction{
		BigInteger n, m;
		fraction(){
			n = BigInteger.ZERO;
			m = BigInteger.ONE;
		}
		fraction(int n, int m){
			this.n = BigInteger.valueOf(n);
			this.m = BigInteger.valueOf(m);
		}
		fraction(BigInteger n){
			this.n = n;
			this.m = BigInteger.ONE;
		}
		fraction add(fraction b){
			fraction res = new fraction();
			res.n = n.multiply(b.m).add(m.multiply(b.n));
			res.m = m.multiply(b.m);
			BigInteger tmp = res.n.gcd(res.m);
			res.n = res.n.divide(tmp);
			res.m = res.m.divide(tmp);
			return res;
		}
		fraction subtract(fraction b){
			fraction res = new fraction();
			res.n = n.multiply(b.m).subtract(m.multiply(b.n));
			res.m = m.multiply(b.m);
			BigInteger tmp = res.n.gcd(res.m);
			res.n = res.n.divide(tmp);
			res.m = res.m.divide(tmp);
			return res;
		}
		fraction multiply(fraction b){
			fraction res = new fraction();
			res.n = n.multiply(b.n);
			res.m = m.multiply(b.m);
			BigInteger tmp = res.n.gcd(res.m);
			res.n = res.n.divide(tmp);
			res.m = res.m.divide(tmp);
			return res;
		}
		fraction divide(fraction b){
			fraction res = new fraction();
			res.n = n.multiply(b.m);
			res.m = m.multiply(b.n);
			BigInteger tmp = res.n.gcd(res.m);
			res.n = res.n.divide(tmp);
			res.m = res.m.divide(tmp);
			return res;
		}
		public String toString(){
			return n.toString() + " / " + m.toString();
		}
	}
	
	BigInteger F(int n){
		BigInteger res = BigInteger.ONE;
		for (int i = 1; i <= n; ++i)
			res = res.multiply(BigInteger.valueOf(i));
		return res;
	}
	BigInteger C(int n, int k){
		if ((n < k) || (k < 0)) return BigInteger.ZERO;
		return F(n).divide(F(k)).divide(F(n - k));
	}
	
	
	void solve() throws IOException {
		Scanner in = new Scanner(new FileInputStream("input.txt"));
		PrintWriter out = new PrintWriter(new FileOutputStream("output.txt"));
		int tt = in.nextInt();
		fraction p[];
		for (int t = 1; t <= tt; ++t){
			out.print("Case #" + t + ": ");
			int c = in.nextInt();
			int n = in.nextInt();
			p = new fraction[c + 1];
			p[0] = new fraction(0, 1);
			for (int i = 1; i <= c; ++i){
				fraction sum = new fraction(1, 1);
				for (int d = 1; d <= i; ++d){
					fraction f1 = new fraction(C(i, d));
					fraction f2 = new fraction(C(c - i, n - d));
					fraction f3 = new fraction(C(c, n));
					fraction f4 = p[i - d];
					sum = sum.add(f1.multiply(f2).divide(f3).multiply(f4));
//					out.println("i = " + i);
	//				out.println("d = " + d);
		//			out.println("f1 = " + f1);
			//		out.println("f2 = " + f2);
				//	out.println("f3 = " + f3);
					//out.println("f4 = " + f4);
//					out.println("addiction = " + f1.multiply(f2).divide(f3).multiply(f4));
				}
				fraction f1 = new fraction(C(i, 0));
				fraction f2 = new fraction(C(c - i, n - 0));
				fraction f3 = new fraction(C(c, n));
				fraction ko = f1.multiply(f2.divide(f3));
				ko = new fraction(1, 1).subtract(ko);
//				out.println("i = " + i);
	//			out.println("sum = " + sum);
		//		out.println("ko = " + ko);
				p[i] = sum.divide(ko);
			}
			BigInteger a = p[c].n;
			BigInteger b = p[c].m;
			out.print(a.divide(b) + ".");
			a = a.mod(b);
			for (int i = 0; i < 10; ++i){
				a = a.multiply(BigInteger.TEN);
				out.print(a.divide(b));
				a = a.mod(b);
			}
			out.println();
		}
		out.close();
	}
	public static void main(String[] args) throws IOException {
		AAA a = new AAA();
		a.solve();
	}

}
