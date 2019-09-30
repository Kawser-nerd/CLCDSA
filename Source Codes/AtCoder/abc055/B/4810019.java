import java.util.Scanner;

class Main{
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sc.close();
		
		System.out.println(mulPower(N));
	}
	
	public static long mulPower(int N){
		long power = 1;
		long c = (long) (Math.pow(10, 9)+7);
		for (long i = 1; i <= N; i++) {
			power *= i;
			power %= c;
		}
		return power;
	}
}