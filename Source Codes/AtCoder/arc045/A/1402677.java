import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.nextLine().replaceAll("Left", "<").replaceAll("Right", ">").replaceAll("AtCoder", "A");
		System.out.println(S);
	}
}