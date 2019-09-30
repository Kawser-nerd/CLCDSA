import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// standard input
		String inputText = sc.next();

		// solve
		char[] p1 = {'m', 'a', 'e', 'r', 'd'};
		char[] p2 = {'r', 'e', 'm', 'a', 'e', 'r', 'd'};
		char[] p3 = {'e', 's', 'a', 'r', 'e'};
		char[] p4 = {'r', 'e', 's', 'a', 'r', 'e'};

		char[] inputArray = inputText.toCharArray();
		int wordIndex = 0;
		char[] targetArray = null;
		for (int i = inputArray.length - 1; i >= 0; i--) {
			if (wordIndex == 0) {
				if (inputArray[i] == 'm') {
					// p1
					targetArray = p1;
				} else if (inputArray[i] == 'e') {
					// p3
					targetArray = p3;
				} else if (inputArray[i] == 'r') {
					// p2 or p4
					if (i - 2 > 0) {
						if (inputArray[i - 2] == 'm') {
							targetArray = p2;
						} else if (inputArray[i - 2] == 's') {
							targetArray = p4;
						} else {
							System.out.println("NO");
							return;
						}
					} else {
						System.out.println("NO");
						return;
					}
				} else {
					System.out.println("NO");
					return;
				}
			} else {
				if (targetArray[wordIndex] != inputArray[i]) {
					System.out.println("NO");
					return;
				}
			}

			if (wordIndex < targetArray.length - 1) {
				wordIndex++;
			} else {
				wordIndex = 0;
				targetArray = null;
			}
		}

		// standard output
		System.out.println("YES");
	}

}