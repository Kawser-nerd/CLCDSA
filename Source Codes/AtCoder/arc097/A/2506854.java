import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		String S = sc.next();
		int K = sc.nextInt();
		SortedSet<String> strings = new TreeSet<>();
		for (int i = 0; i < S.length(); i++) {
			for (int j = 1; j <= K && i + j <= S.length(); j++) {
				strings.add(S.substring(i, i + j));
			}
		}
		String ans = null;
		while (K > 0) {
			K--;
			strings.remove(ans = strings.first());
		}
		System.out.println(ans);
	}
}