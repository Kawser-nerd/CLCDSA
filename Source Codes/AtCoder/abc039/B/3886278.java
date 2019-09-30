import java.util.Scanner;

class Main{
	static int n;
	static long ans = 1000000000;
	static int[] memo;
	static int[] dp;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		int a = sc.nextInt();
		long ans = (long)Math.sqrt(a);
		ans = (long)Math.sqrt(ans);
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