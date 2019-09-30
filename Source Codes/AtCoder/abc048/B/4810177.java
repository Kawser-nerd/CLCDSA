import java.util.Scanner;

class Main{
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long x = sc.nextLong();
		sc.close();
		
		System.out.println(calc(a,b,x));
	}
	
	public static long calc(long a, long b, long x){
		return (b + x)/ x - (a + x - 1) / x;
	}
}