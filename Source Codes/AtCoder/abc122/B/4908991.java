import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		Pattern p = Pattern.compile("[ATCG]+");
		Matcher m = p.matcher(s);
		int length = 0;
		while(m.find()) {
			int l = m.group().length();
			if(length < l)
				length = l;
		}
		System.out.println(length);
	}
}