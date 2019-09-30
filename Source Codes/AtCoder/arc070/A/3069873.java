import java.util.*;

public class Main {

	public Main() {
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int k = scanner.nextInt();
		int c = 0;
		for(int i = 1;;i++) {
			c = c + i;
			if(k <= c) {
				System.out.println(i);
				break;
			}
		}
	}

}