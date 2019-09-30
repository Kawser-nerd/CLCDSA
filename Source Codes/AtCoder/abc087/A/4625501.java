import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int X = scn.nextInt(), A = scn.nextInt(),B = scn.nextInt();
		X -= A;
		X%=B;
		System.out.println(X);
	}

}