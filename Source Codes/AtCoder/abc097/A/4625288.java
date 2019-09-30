import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int A = scn.nextInt(), B = scn.nextInt(),C = scn.nextInt(), D = scn.nextInt();
		boolean ans = Math.abs(A-C) <= D ||((Math.abs(A-B)<=D)&&(Math.abs(C-B)<=D));

		System.out.println(ans?"Yes":"No");
	}

}