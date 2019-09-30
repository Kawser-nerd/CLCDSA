import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int buf=n/2;
		System.out.println(buf*(n-buf));
	}
}