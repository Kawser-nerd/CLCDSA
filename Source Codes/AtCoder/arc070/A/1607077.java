import java.io.*;
import java.util.*;

public class Main { // "Main" should be used for most online judges
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int nestValue = sc.nextInt();
		int result = 0;
		
		for (int i = 0; i <= nestValue; i++) {
			if(maxValue(i) >= nestValue) {
				result = i;
				 i = nestValue;
			}
		}
		
		System.out.println(result);
		sc.close();
	}
	
	public static int maxValue(int n) {
		int max = 0;
		for (int i = 1; i <= n; i++) {
			max += i;
		}
		return max;
	}
}