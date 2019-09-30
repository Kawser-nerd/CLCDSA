import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class C {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %d\n", i, solve());
		}
	}

	static long solve() {
		int N = sc.nextInt();
		int[] D = new int[N];
		int[] H = new int[N];
		int[] M = new int[N];
		ArrayList<Hiker> hiker = new ArrayList<>();
		for (int i = 0; i < N; ++i) {
			D[i] = sc.nextInt();
			H[i] = sc.nextInt();
			M[i] = sc.nextInt();
			for (int j = 0; j < H[i]; ++j) {
				hiker.add(new Hiker(i, j, M[i] + j, D[i]));
			}
		}
		Collections.sort(hiker);
		long ans = hiker.size();
		for (int i = 0; i < hiker.size(); ++i) {
			if (i < hiker.size() - 1 && hiker.get(i).time == hiker.get(i + 1).time) continue;
			long sum = 0;
			for (int j = 0; j < i; ++j) {
				long cyc = (M[hiker.get(j).gi] + hiker.get(j).mi) * 360L;
				long rest = hiker.get(i).time - hiker.get(j).time;
				//				System.out.println(i + " " + j + " " + rest + " " + cyc);
				rest /= cyc;
				sum += rest;
			}
			ans = Math.min(ans, hiker.size() - (i + 1) + sum);
		}

		return ans;
	}

	static class Hiker implements Comparable<Hiker> {
		int gi, mi;
		long time;

		Hiker(int gi, int mi, int M, int pos) {
			this.gi = gi;
			this.mi = mi;
			this.time = (360L - pos) * M;
		}

		public int compareTo(Hiker o) {
			return Long.compare(this.time, o.time);
		}
	}

	static class Rational implements Comparable<Rational> {
		final BigInteger num;
		final BigInteger den;

		Rational(BigInteger n, BigInteger d) {
			if (n.equals(BigInteger.ZERO)) {
				num = BigInteger.ZERO;
				den = BigInteger.ONE;
			} else {
				BigInteger gcd = n.gcd(d);
				num = n.divide(gcd);
				den = d.divide(gcd);
			}
		}

		Rational(long n, long d) {
			this(BigInteger.valueOf(n), BigInteger.valueOf(d));
		}

		Rational mul(Rational v) {
			return new Rational(this.num.multiply(v.num), this.den.multiply(v.den));
		}

		Rational div(Rational v) {
			return new Rational(this.num.multiply(v.den), this.den.multiply(v.num));
		}

		Rational add(Rational v) {
			return new Rational(this.num.multiply(v.den).add(v.num.multiply(this.den)), this.den.multiply(v.den));
		}

		Rational sub(Rational v) {
			return this.add(v.mul(new Rational(-1, 1)));
		}

		public int compareTo(Rational r) {
			BigInteger n1 = this.num.multiply(r.den);
			BigInteger n2 = this.den.multiply(r.num);
			return n1.compareTo(n2);
		}

		public String toString() {
			return this.num + "/" + this.den;
		}

		public int hashCode() {
			return this.num.hashCode() ^ this.den.hashCode();
		}

		public boolean equals(Object obj) {
			Rational other = (Rational) obj;
			if (!den.equals(other.den)) return false;
			if (!num.equals(other.num)) return false;
			return true;
		}

	}

}
