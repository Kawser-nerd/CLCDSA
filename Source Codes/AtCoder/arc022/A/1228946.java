import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.println(s.next().toLowerCase().matches("^.*i.*c.*t.*$")?"YES":"NO");
	}
}