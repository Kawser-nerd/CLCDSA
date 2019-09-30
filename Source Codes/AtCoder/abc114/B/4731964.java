import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int min = 753;
		for(int i = 0; i < s.length()-2; i++) {
			String num = s.substring(i, i+3);
			int n = Integer.parseInt(num);
			min = Math.min(min, Math.abs(753-n));
		}
		System.out.println(min);
	}
}