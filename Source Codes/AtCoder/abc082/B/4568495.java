import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		char s[] = sc.next().toCharArray();
		char t[] = sc.next().toCharArray();
		Arrays.sort(s);
		Arrays.sort(t);
		String s2 = String.valueOf(s);
		String t2 = new StringBuilder(String.valueOf(t)).reverse().toString();
		if(s2.compareTo(t2) < 0)
			System.out.println("Yes");
		else
			System.out.println("No");
	}

}