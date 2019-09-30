import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int S = reader.nextInt();
		reader.close();
		ArrayList<Integer> list = new  ArrayList<Integer>();
		int count = 1;
		while (!list.contains(S)) {
			list.add(S);
			if (S % 2 == 0) {
				S /= 2;
			} else {
				S = 3 * S + 1;
			}
			count++;
		}
		System.out.print(count);
	}
}