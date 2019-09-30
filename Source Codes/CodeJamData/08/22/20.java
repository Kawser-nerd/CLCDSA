import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;

public class R1B_B {
	public static void main(String[] args) {
		Scanner scin = new Scanner(System.in);
		int N = scin.nextInt();
		for (int z = 1; z <= N; ++z) {
			long A = scin.nextLong();
			long B = scin.nextLong();
			long P = scin.nextLong();
			
			// for small
			int[] equiv = new int[(int)(B+1)];
			for (int i = (int)A; i <= B; ++i) equiv[i] = i;
			for (int i = (int)A; i <= B; ++i) {
				for (int j = i+1; j <= B; ++j) {
					if (equiv[i] == equiv[j]) continue;
					int gcd = (int)gcd(i, j);
					boolean ok = false;
					for (int k = (int)P; k <= gcd; ++k) {
						if (new BigInteger("" + k).isProbablePrime(1024) && gcd % k == 0) {
							ok = true;
							break;
						}
					}
					if (ok) {
						for (int k = (int)A; k <= B; ++k) {
							if (equiv[k] == equiv[j]) equiv[k] = equiv[i];
						}
					}
				}
			}
			HashSet<Integer> set = new HashSet<Integer>();
			for (int i : equiv) set.add(i);
			System.out.println("Case #" + z + ": " + (set.size()-1));
		}
	}
	static long gcd(long a, long b) {
		return new BigInteger("" + a).gcd(new BigInteger("" + b)).longValue();
	}
}
