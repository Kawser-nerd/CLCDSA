import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int A = scn.nextInt(), B = scn.nextInt();
		System.out.println(Math.max(A+B, Math.max(A-B, A*B)));
	}

}