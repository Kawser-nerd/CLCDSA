import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int y = Integer.parseInt(s.substring(0, 4));
		int m = Integer.parseInt(s.substring(5, 7));
		int d = Integer.parseInt(s.substring(8, 10));
		Calendar calendar = Calendar.getInstance();
		calendar.set(y, m - 1, d);
		while (true) {
			if (calendar.get(Calendar.YEAR) % ((calendar.get(Calendar.MONTH) + 1) * calendar.get(Calendar.DATE)) == 0) {
				break;
			} else {
				calendar.add(Calendar.DAY_OF_MONTH, 1);
			}
		}
		System.out.println(String.format("%04d", calendar.get(Calendar.YEAR)) + "/" + String.format("%02d", calendar.get(Calendar.MONTH) + 1) + "/" + String.format("%02d", calendar.get(Calendar.DATE)));
	}
}