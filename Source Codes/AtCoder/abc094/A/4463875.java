import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner  scan = new Scanner(System.in);
		int cats = scan.nextInt();
		int mix = scan.nextInt();
		int rslt = scan.nextInt();

		if(rslt >= cats && cats+mix >= rslt) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
	}
}