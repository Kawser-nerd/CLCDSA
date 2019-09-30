import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int score = scan.nextInt();
		if(score <= 59) {
			System.out.println("Bad");
		}else if(score >= 60 && score <=89) {
			System.out.println("Good");
		}else if(score >= 90 && score <= 99) {
			System.out.println("Great");
		}else {
			System.out.println("Perfect");
		}
	}

}