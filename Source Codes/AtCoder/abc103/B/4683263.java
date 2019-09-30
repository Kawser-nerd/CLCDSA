import java.util.Scanner;
import java.util.Arrays;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String sArray [] = s.split("");
		String t = sc.next();
		String tArray [] = t.split("");
		String a = "";
		boolean judge = false;
		for(int k = 0; k < sArray.length; k++) {
			a = sArray[sArray.length - 1];
			for(int i = sArray.length - 1; i > 0; i--){
				sArray[i] = sArray[i - 1];
			}
			sArray[0] = a;
			if(Arrays.equals(sArray, tArray)) {
				judge = true;
				break;
			}
		}
		if(judge) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
		sc.close();
	}
}