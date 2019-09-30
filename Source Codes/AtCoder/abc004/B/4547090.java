import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num =0;
		ArrayList<String> array = new ArrayList<String>();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				array.add(sc.next() + " ");
			}
		}
		Collections.reverse(array);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				System.out.print(array.get(num));
				num++;
				if(j==3) {
					System.out.println(" ");
				}
			}
		}
	}
}