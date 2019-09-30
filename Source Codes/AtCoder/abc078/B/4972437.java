import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int X = reader.nextInt();
		int Y = reader.nextInt();
		int Z = reader.nextInt();
		X -= Z;
		int ans = X / (Y + Z);



		System.out.print(ans);
		reader.close();
	}
}