import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt(), A = scn.nextInt();
		System.out.println(A>=(N%500)?"Yes":"No");
	}

}