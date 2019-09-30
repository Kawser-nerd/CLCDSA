import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n=sc.nextLong();
		long m=sc.nextLong();
		if(n==1&&m==1) System.out.println(1);
		else if(n==1||m==1) System.out.println(Math.max(n, m)-2);
		else System.out.println((n-2)*(m-2));
	}
}