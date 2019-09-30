import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class Main {
	public static void main(String args[]){
		    Scanner sc = new Scanner(System.in);	
			
			int n = sc.nextInt();
			int[] ar = new int[n];
			int count = 0;
			for (int i = 0; i < n; i++) {
				ar[i] = sc.nextInt();
			}
			for (int i = 0; i < n; i++) {
				if(isOdd(ar[i]) == true){
					count++;
				}
			}

			if (isOdd(count) == true) {
				System.out.println("NO");
			} else {
				System.out.println("YES");
			}

			sc.close();
		}
	private static boolean isOdd(int n) {
		if (n % 2 != 0) {
			return true;
		}else{
			return false;
		}
	}
}