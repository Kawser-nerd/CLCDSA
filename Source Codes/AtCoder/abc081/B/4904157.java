import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int times = Integer.parseInt(sc.nextLine());
		int bit = 0;

		for(int i = 0; i< times; i++) {
			bit |= sc.nextInt();
		}
		System.out.println(Integer.numberOfTrailingZeros(bit));
	}
}