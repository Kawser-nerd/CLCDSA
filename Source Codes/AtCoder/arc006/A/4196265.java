import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		HashSet<Integer> eSet = new HashSet<>();
		for (int i = 0; i < 6; i++) {
			eSet.add(sc.nextInt());
		}
		int b = sc.nextInt();
		int count = 0;
		boolean bonus = false;
		for (int i = 0; i < 6; i++) {
			int x = sc.nextInt();
			if (eSet.contains(x)) {
				count++;
			} else if (x == b) {
				bonus = true;
			}
		}
		int ans = 0;
		switch (count) {
			case 6:
			ans = 1;
			break;
			case 5:
			if (bonus) {
				ans = 2;
			} else {
				ans = 3;
			}
			break;
			case 4:
			ans = 4;
			break;
			case 3:
			ans = 5;
			break;
		}
		System.out.println(ans);
	}
}