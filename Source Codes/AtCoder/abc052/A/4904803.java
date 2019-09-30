import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);

		int a = scan.nextInt();
		int b = scan.nextInt();
		int c = scan.nextInt();
		int d = scan.nextInt();

		if(a*b >= c*d){
			System.out.println(a*b);
		}
		else {
			System.out.println(c*d);
		}
	}
}