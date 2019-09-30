import java.util.Arrays;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String [][] nArray = new String [n][];
		for(int i = 0; i < n; i++) {
			String num = sc.next();
			nArray[i] = num.split("");
		}
		boolean judge = true;
		out: for(int i = 1; i < n; i++) {
			for(int k = 0; k < i; k++) {
				if(Arrays.equals(nArray[i], nArray[k])) {
					judge = false;
					break out;
				}
			}
		}
		for(int i = 0; i < n-1; i++) {
			if(nArray[i][nArray[i].length-1].equals(nArray[i+1][0])) {
			}else {
				judge = false;
				break;
			}
		}

		if(judge) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}

}