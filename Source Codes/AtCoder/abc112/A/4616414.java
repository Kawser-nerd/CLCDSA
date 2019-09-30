import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		if(n==1) {
			System.out.println("Hello World");
		}
		else {
			int a,b;
			a=sc.nextInt();
			b=sc.nextInt();
			System.out.println(a+b);
		}
	}
}