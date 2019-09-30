import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt(), A = scn.nextInt(),B = scn.nextInt();
		System.out.println(Math.min(N*A,B));
	}

}