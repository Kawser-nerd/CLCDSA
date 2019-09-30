import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);

		String A = scan.next();
		String B = scan.next();
		String C = scan.next();

		char[] x = B.toCharArray();

		System.out.println("A" + x[0] + "C");
	}
}