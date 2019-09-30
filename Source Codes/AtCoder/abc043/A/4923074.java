import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		try (Scanner scTmp = new Scanner(System.in);) {

			int numN = scTmp.nextInt();
			int sum = 0;
			for (int i = 1; i <= numN; i++) {
				sum = sum + i;
			}
			System.out.println(sum);
		}
	}

}