import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String board[][] = new String[4][4];
		String dummy[][] = new String[4][4];

		for (int i = 0; i < 4; i++) {
			board[i] = sc.nextLine().split(" ");
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dummy[i][j] = board[i][j] ;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				board[i][j] = dummy[3-i][3-j] ;
			}
		}
		String s = "";
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				s += board[i][j];
				if (j!=3) {
					s += " ";
				}
			}
			System.out.println(s);
			s = "";
		}
	}
}