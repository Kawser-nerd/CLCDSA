import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int a=Math.abs(s.nextInt()),b=Math.abs(s.nextInt());
		System.out.println(a==b?"Draw":a<b?"Ant":"Bug");
	}
}