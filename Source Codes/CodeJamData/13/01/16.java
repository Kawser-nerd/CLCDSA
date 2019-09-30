import java.util.Scanner;

// Google Codejam
// Qualification Round 2013
// Problem A. Tic-Tac-Toe-Tomek

public class Main {

	private static char[] player = new char[] { 'X', 'O' };
	private static char[] opponent = new char[] { 'O', 'X' };

	private static String[] board;

	private static char checkRow(int i) {
		int dots = 0, xs = 0, os = 0;
		for (int j = 0; j < 4; j++)
			switch (board[i].charAt(j)) {
			case '.':
				dots++;
				break;
			case 'X':
				xs++;
				break;
			case 'O':
				os++;
				break;
			}
		if (dots > 0)
			return '.';
		if (os == 0)
			return 'X';
		else if (xs == 0)
			return 'O';
		return 'D';
	}

	private static char checkCol(int j) {
		int dots = 0, xs = 0, os = 0;
		for (int i = 0; i < 4; i++)
			switch (board[i].charAt(j)) {
			case '.':
				dots++;
				break;
			case 'X':
				xs++;
				break;
			case 'O':
				os++;
				break;
			}
		if (dots > 0)
			return '.';
		if (os == 0)
			return 'X';
		else if (xs == 0)
			return 'O';
		return 'D';
	}

	private static char checkDia1() {
		int dots = 0, xs = 0, os = 0;
		for (int i = 0; i < 4; i++)
			switch (board[i].charAt(i)) {
			case '.':
				dots++;
				break;
			case 'X':
				xs++;
				break;
			case 'O':
				os++;
				break;
			}
		if (dots > 0)
			return '.';
		if (os == 0)
			return 'X';
		else if (xs == 0)
			return 'O';
		return 'D';
	}

	private static char checkDia2() {
		int dots = 0, xs = 0, os = 0;
		for (int i = 0; i < 4; i++)
			switch (board[i].charAt(3 - i)) {
			case '.':
				dots++;
				break;
			case 'X':
				xs++;
				break;
			case 'O':
				os++;
				break;
			}
		if (dots > 0)
			return '.';
		if (os == 0)
			return 'X';
		else if (xs == 0)
			return 'O';
		return 'D';
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int tt = scanner.nextInt();
		for (int t = 1; t <= tt; t++) {
			scanner.nextLine();
			board = new String[4];
			for (int i = 0; i < 4; i++)
				board[i] = scanner.nextLine();
			boolean incomplete = false;
			char wins = 'D';

			// rows
			for (int i = 0; i < 4; i++) {
				char current = checkRow(i);
				if (current == 'X' || current == 'O')
					wins = current;
				incomplete = incomplete || (current == '.');
			}

			// columns
			for (int j = 0; j < 4; j++) {
				char current = checkCol(j);
				if (current == 'X' || current == 'O')
					wins = current;
			}

			// diagonals
			char current = checkDia1();
			if (current == 'X' || current == 'O')
				wins = current;
			current = checkDia2();
			if (current == 'X' || current == 'O')
				wins = current;

			// output
			if (wins == 'X' || wins == 'O')
				System.out.printf("Case #%d: %c won\n", t, wins);
			else if (incomplete)
				System.out.printf("Case #%d: Game has not completed\n", t);
			else
				System.out.printf("Case #%d: Draw\n", t);
		}
	}

}
