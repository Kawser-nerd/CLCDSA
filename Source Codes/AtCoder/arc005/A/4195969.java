import java.util.*;

public class Main {
	public static void main (String[] args) {
		String[] TAKAHASHI = new String[]{"TAKAHASHIKUN", "Takahashikun", "takahashikun"};
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int count = 0;
		for (int i = 0; i < n; i++) {
			String s = sc.next();
			s = s.replaceAll("\\.", "");
			for (String taka : TAKAHASHI) {
				if (s.equals(taka)) {
					count++;
				}
			}
		}
		System.out.println(count);
	}
}