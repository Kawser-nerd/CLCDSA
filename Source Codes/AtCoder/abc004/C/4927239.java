import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] cards = new int[6];
		for(int i = 0; i < 6; i++)
			cards[i] = i + 1;
		for(int i = 0; i < N % 30; i++) {
			int tmp = cards[i % 5];
			cards[i % 5] = cards[i % 5 + 1];
			cards[i % 5 + 1] = tmp;
		}
		for(int i = 0; i < 6; i++)
			System.out.print(cards[i]);
	}

}