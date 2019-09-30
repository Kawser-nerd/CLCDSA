import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		System.out.println(N%10==9 || N/10 == 9?"Yes":"No");
	}

}