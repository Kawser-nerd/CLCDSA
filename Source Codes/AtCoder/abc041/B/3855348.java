import java.util.Scanner;

class Main{



	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		long pow = 1000000007;
		long ans = a*b%pow;
		ans *= c;
		ans %= pow;
		System.out.println(ans);
	}


}

class Pair implements Comparable{
	int from;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}