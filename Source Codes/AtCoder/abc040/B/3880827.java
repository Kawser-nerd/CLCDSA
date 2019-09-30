import java.util.Scanner;

class Main{


	static int[][] data;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		int n  = sc.nextInt();

		long ans = 100000000;
		for(int i = 1;i <= n;i++){
			int j = n /i;
			int num = n - i*j;
			ans = Math.min(ans, num + Math.abs(i-j));
			
			
		}
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