import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String[] str = s.split("[+]", 0);
		int count = 0;
		for (int i = 0; i < str.length; i++) {
			if (!str[i].contains("0")) {
				count++;
			}
		}
		System.out.println(count);
	}
}