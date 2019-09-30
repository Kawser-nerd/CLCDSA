import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();
		String[] ss = s.split("");
		List<String> list = new ArrayList<String>();

		for(int i=0; i<s.length(); i++) {
			if(!ss[i].equals("a") && !ss[i].equals("i") && !ss[i].equals("u") &&
			   !ss[i].equals("e") && !ss[i].equals("o")) {
				list.add(ss[i]);
			}
		}
		String ans = "";
		for(int j=0; j<list.size(); j++) {
			ans += list.get(j);
		}

		System.out.println(ans);
	}
}