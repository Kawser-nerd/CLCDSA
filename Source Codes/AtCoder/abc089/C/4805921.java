import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		long[] arr = new long[5];
		String str = "MARCH";
		String remain = "MARCH";
		long ans = 0;
		for (int i = 0; i < N; i++) {
			char ch = reader.next().charAt(0);
			int index = str.indexOf(ch);
			if (index != -1) {
				arr[index]++;
				remain = remain.replace(Character.toString(ch), "");
			}
		}
		int size = str.length() - remain.length();
		if (size < 3) {
			System.out.print(ans);
			return;
		}
		long[] only = new long[size];
		long[] incre = new long[size];
		int count = 0;
		int current = 0;
		while (count < size) {
			if (arr[current] > 0) {
				only[count] = arr[current];
				count++;
			}
			current++;
		}

		incre[size-1] = only[size-1];
		for (int i = size-2; i > 0; i--) {
			incre[i] = incre[i+1] + only[i];
		}
		for (int i = 0; i < size - 2; i++) {
			for (int j = i + 1; j < size - 1; j++) {
				ans += only[i] * only[j] * incre[j+1];
			}
		}
		System.out.print(ans);
		reader.close();
	}
}