import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n,a,b;
		n=sc.nextInt();
		a=sc.nextInt();
		b=sc.nextInt();
		int x=Math.min(a*n, b);
		System.out.println(x);
	}
}