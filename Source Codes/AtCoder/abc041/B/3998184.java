import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		long a=(scan.nextInt());
		long b=(scan.nextInt());
		long c=(scan.nextInt());
		long d=a*b%1000000007;
		long ans=(d*c)%1000000007;
		System.out.println(ans);
}
	}