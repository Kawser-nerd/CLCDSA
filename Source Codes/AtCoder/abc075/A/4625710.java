import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int A = scn.nextInt();
		int B  =scn.nextInt();
		int C  =scn.nextInt();
		if(A==B) {
			System.out.println(C);
		}
		if(A==C) {
			System.out.println(B);
		}
		if(C==B) {
			System.out.println(A);
		}
	}

}