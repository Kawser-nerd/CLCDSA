import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int month = scn.nextInt();
		int next = 0;
		if(month == 12) {
			next = 1;
		}else {
			next = month+1;
		}
		System.out.println(next);
	}

}