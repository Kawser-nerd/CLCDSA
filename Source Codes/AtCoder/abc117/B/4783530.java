import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int maxLength = scan.nextInt();
		int otherLength = maxLength;
		for(int i = 1;i <= n-1;i++) {
			int currentLength = scan.nextInt();
			otherLength = otherLength + currentLength;
			if(maxLength <= currentLength) {
				maxLength = currentLength;
			}
		}
		otherLength = otherLength- maxLength;
		if(maxLength < otherLength) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}

	}
}