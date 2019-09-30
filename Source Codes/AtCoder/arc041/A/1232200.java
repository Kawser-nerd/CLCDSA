import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);
	public static void main(String[] args) {
		int x=s.nextInt(),y=s.nextInt(),k=s.nextInt();
		System.out.println(x+y-Math.abs(y-k));
	}
}