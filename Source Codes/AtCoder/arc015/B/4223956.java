import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		double n = sc.nextInt();
		int mou = 0;
		int mana = 0;
		int na = 0;
		int ne = 0;
		int fu = 0;
		int maf = 0;
		for (int i = 0; i < n; i++) {
			double max = sc.nextDouble();
			double min = sc.nextDouble();
			if (max >= 35) {
				mou++;
			} else if (max >= 30) {
				mana++;
			} else if (max >= 25) {
				na++;
			}
			if (min >= 25) {
				ne++;
			}
			if (min < 0 && max >= 0) {
				fu++;
			}
			if (max < 0) {
				maf++;
			}
		}
		System.out.println(mou + " " + mana + " " + na + " " + ne + " " + fu + " " + maf);
	}
}