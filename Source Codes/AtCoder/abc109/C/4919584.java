import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int X = sc.nextInt();

		//X?xi???????list????
		List<Integer> list = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			list.add(Math.abs(sc.nextInt() - X));
		}

		//list??????????????
		Set<Integer> set = new HashSet<Integer>(list);
		list = new ArrayList<>(set);
		Collections.sort(list);

		//list??????????????
		if (list.size() == 1) {
			System.out.println(list.get(0));
		} else {
			int D = list.get(0);
			for(int i=1;i<list.size();i++) {
				D = gcd(D,list.get(i));
			}
			System.out.println(D);
		}
	}

	public static int gcd(int a, int b) {
		if (b == 0)
			return a;
		else
			return gcd(b, a % b);
	}

}