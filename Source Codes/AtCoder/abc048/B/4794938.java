import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);

		long a = scan.nextLong();
		long b = scan.nextLong();
		long x = scan.nextLong();

		System.out.println(f(b,x) - f(a-1,x));
	}
	
	public static long f(long s, long x){
		if(s == -1){
			return 0;
		}
		return s / x + 1;
	}
}