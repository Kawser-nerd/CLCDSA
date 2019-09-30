import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

//AtCoder Beginner Contest 118
//D	Match Matching
public class Main {

	//                                  1, 2 ,3 ,4 ,5, 6 ,7 ,8 ,9
	static int[] NEEDS = new int[] { 2, 5, 5, 4, 5, 6, 3, 7, 6 };
	// matchNum, MaxFigure
	static Map<Integer, Integer> cache = new HashMap<Integer, Integer>();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();

		List<Integer> inList = new ArrayList<>();
		for (int i = 0; i < M; i++) {
				inList.add(sc.nextInt());
		}
		sc.close();

		boolean[] isUsables = new boolean[] { false, false, false, false, false, false, false, false, false };
		for (Integer in : inList) {
			isUsables[in - 1] = true;
		}

		cache.put(0, 0);
		for (int i = 0; i < N; i++) {
			getMaxFigure(i, isUsables);
		}
		int maxFigure = getMaxFigure(N, isUsables);

		List<Integer> ret = new ArrayList<>();
		int restMatch = N;
		for (int i = maxFigure; i > 0; i--) {
			for (int j = NEEDS.length - 1; j >= 0; j--) {
				if (!isUsables[j]) {
					continue;
				}

				int need = NEEDS[j];
				if (!cache.containsKey(restMatch - need)) {
					continue;
				}

				if (cache.get(restMatch - need) == i - 1) {
					ret.add(j + 1);
					restMatch -= need;
					break;
				}
			}
		}

		for (Integer i : ret) {
			System.out.print(i);
		}
	}

	private static int getMaxFigure(int matchNum, boolean[] isUsables) {
		if (cache.containsKey(matchNum)) {
			return cache.get(matchNum);
		}
		if (matchNum < 0) {
			return Integer.MIN_VALUE;
		}
		if (matchNum == 0) {
			return 0;
		}
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < isUsables.length; i++) {
			if (!isUsables[i]) {
				continue;
			}

			int need = NEEDS[i];
			int maxFigure = getMaxFigure(matchNum - need, isUsables);
			if (max < maxFigure + 1) {
				max = maxFigure + 1;
			}
		}
		if (max < 0) {
			max = Integer.MIN_VALUE;
		}
		cache.put(matchNum, max);
		return max;
	}
}