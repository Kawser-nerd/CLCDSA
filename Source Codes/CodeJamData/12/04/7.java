public class Frac implements Comparable<Frac> {
	public static final Frac ZERO = new Frac(0);
	public static final Frac ONE = new Frac(1);
	public final int num, denom;

	public Frac(int num) {
		this(num, 1);
	}

	public Frac(int num, int denom) {
		if (denom == 0) {
			if (num < 0)
				this.num = -1;
			else if (num > 0)
				this.num = 1;
			else
				this.num = 0;
			this.denom = 0;
		} else {
			int gcd;
			if (denom < 0) {
				gcd = -Math.abs(gcd(num, denom));
			} else {
				gcd = Math.abs(gcd(num, denom));
			}
			this.num = num / gcd;
			this.denom = denom / gcd;
		}
	}

	public Frac add(Frac other) {
		return new Frac(num * other.denom + denom * other.num, denom
				* other.denom);
	}

	public Frac mult(Frac other) {
		return new Frac(num * other.num, denom * other.denom);
	}

	public Frac sub(Frac other) {
		return new Frac(num * other.denom - denom * other.num, denom
				* other.denom);
	}

	public Frac div(Frac other) {
		return new Frac(num * other.denom, denom * other.num);
	}

	public Frac neg() {
		return new Frac(-num, denom);
	}

	public Frac inv() {
		return new Frac(denom, num);
	}

	@Override
	public boolean equals(Object other) {
		return other instanceof Frac && equals((Frac) other);
	}

	@Override
	public int hashCode() {
		return (31 + num) * 31 + denom;
	}

	public boolean equals(Frac other) {
		return num == other.num && denom == other.denom;
	}

	public boolean equals(int o) {
		return denom == 1 && num == o;
	}

	@Override
	public String toString() {
		if (denom == 1)
			return Integer.toString(num);
		else
			return num + "/" + denom;
	}

	@Override
	public int compareTo(Frac o) {
		return num * o.denom - o.num * denom;
	}

	public static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}

	public Frac roundAddSig(Frac sgn) {
		if (sgn.num > 0)
			return roundAddUp();
		else if (sgn.num < 0)
			return roundAddDown();
		else
			return null;
	}

	public Frac roundAddUp() {
		if (num < 0)
			return new Frac((num + 1) / denom);
		else
			return new Frac(num / denom + 1);
	}

	public Frac roundAddDown() {
		if (num > 0)
			return new Frac((num - 1) / denom);
		else
			return new Frac(num / denom - 1);
	}

	public int roundDownAddSmallUp() {
		if (num < 0)
			return (num - denom + 1) / denom;
		else
			return num / denom;
	}

	public int roundDownAddSmallDown() {
		if (num < 0)
			return num / denom - 1;
		else
			return (num - 1) / denom;
	}

	public boolean isZero() {
		return num == 0;
	}

	public int sgn() {
		if (num < 0)
			return -1;
		else if (num > 0)
			return 1;
		else
			return 0;
	}
}
