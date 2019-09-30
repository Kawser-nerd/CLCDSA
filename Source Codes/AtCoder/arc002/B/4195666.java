import java.util.*;
import java.text.*;

public class Main {
	public static void main (String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd");
		Calendar cal = Calendar.getInstance();
		cal.setTime(sdf.parse(sc.next()));
		while (!match(cal)) {
			cal.add(Calendar.DATE, 1);
		}
		System.out.println(sdf.format(cal.getTime()));
	}
	
	static boolean match(Calendar cal) {
		int y = cal.get(Calendar.YEAR);
		int m = cal.get(Calendar.MONTH) + 1;
		int d = cal.get(Calendar.DATE);
		return y % (m * d) == 0;
	}
}