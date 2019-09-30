import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int limit=18*60;
		System.out.println(limit-s.nextInt()*60-s.nextInt());
	}
}