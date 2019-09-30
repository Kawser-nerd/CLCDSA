import java.util.Arrays;
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		long K = scn.nextLong();
		Pair[] P = new Pair[N];
		for (int i = 0; i < N; i++) {
			P[i] = new Pair(scn.nextLong(), scn.nextLong());
		}
		Arrays.sort(P);
		long ans = 0;
		for (int i = 0; i < N; i++) {
			K -= P[i].getB();
			if (K <= 0) {
				ans = P[i].getA();
				break;
			}
		}
		System.out.println(ans);
	}

}

class Pair implements Comparable<Pair> {
	long a;
	long b;

	Pair(long a, long b) {
		this.a = a;
		this.b = b;
	}

	@Override
	public int compareTo(Pair o) {
		if (this.getA() > o.getA())
			return 1;
		if (this.getA() < o.getA())
			return -1;
		return 0;
	}

	long getA() {
		return this.a;
	}

	long getB() {
		return this.b;
	}
}