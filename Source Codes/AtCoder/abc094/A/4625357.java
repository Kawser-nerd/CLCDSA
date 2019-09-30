import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int A = scn.nextInt();
		int B = scn.nextInt();
		int X = scn.nextInt();
		System.out.println(A<=X && X <= A+B?"YES":"NO");
	}

}