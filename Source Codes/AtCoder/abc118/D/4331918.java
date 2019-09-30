import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;

public class Main {
	static int[] honsuu = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	static int[][] bou = {
			{1, 2},
			{7, 3},
			{4, 4},
			{5, 5},
			{3, 5},
			{2, 5},
			{9, 6},
			{6, 6},
			{8, 7}
			};

	public static void main(String[] args) throws Exception {
		// 1?????????????????
		TreeMap<Integer, Integer> honsuuMap = new TreeMap<Integer, Integer>();

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		Set<Integer> aSet = new HashSet<Integer>();
		for (int i = 0; i < m; i++) {
			Integer ai = sc.nextInt();
			aSet.add(ai);
			honsuuMap.put(honsuu[ai], 0);
		}
		sc.close();

		// ??????????????????
		Integer[] array = honsuuMap.keySet().toArray(new Integer[0]);

		editHonsuuMap(n, array, 0, honsuuMap);
//		for (Entry<Integer, Integer> entry : honsuuMap.entrySet()) {
//			System.out.print(entry.getKey() + " " + entry.getValue());
//			System.out.println();
//		}

		int totalKetasuu = 0;
		for (int val : honsuuMap.values()) {
			totalKetasuu += val;
		}

		int[] ketasuuArray = new int[10];
		editKetasuuArray(n, totalKetasuu, aSet, 9, honsuuMap, ketasuuArray);
//		for (int val : ketasuuArray) {
//			System.out.print(val + " ");
//		}
//		System.out.println();

		for (int i = 9; i >= 1; i--) {
			for (int j = 0; j < ketasuuArray[i]; j++) {
				System.out.print(i);
			}
		}
		System.out.println();
	}

	/**
	 * ?????????????????????
	 */
	private static boolean editHonsuuMap(
			int n, Integer[] array, int startIdx, TreeMap<Integer, Integer> honsuuMap) {
		for (int i = startIdx; i < array.length; i++) {
			if (n % array[i] == 0) {
				honsuuMap.put(array[i], n / array[i]);
				return true;
			}

			for (int j = (n / array[i]) - 1; j >= 0; j--) {
				int tempN = n - (array[i] * j);
				boolean flg = editHonsuuMap(tempN, array, i + 1, honsuuMap);
				if (flg) {
					honsuuMap.put(array[i], j);
					return true;
				}
			}
		}
		return false;
	}

	/**
	 * ??????????????????????????????????????
	 */
	private static boolean editKetasuuArray(
			int n, int totalKetasuu, Set<Integer> aSet, int startVal, TreeMap<Integer, Integer> honsuuMap,
			int[] ketasuuArray) {
		for (int i = startVal; i >= 0; i--) {
			if (!aSet.contains(i)) {
				continue;
			}
			if (honsuu[i] * totalKetasuu == n) {
				ketasuuArray[i] += totalKetasuu;
				return true;
			}

			int zanHonsuu = n - honsuu[i];
			int zanKetasuu = totalKetasuu - 1;
			if (zanHonsuu < 0 || zanKetasuu < 0
					|| zanKetasuu * honsuuMap.lastKey() < zanHonsuu
					|| zanHonsuu < zanKetasuu * honsuuMap.firstKey()) {
				continue;
			}

			boolean flg = editKetasuuArray(zanHonsuu, zanKetasuu, aSet, i, honsuuMap, ketasuuArray);
			if (flg) {
				ketasuuArray[i]++;
				return true;
			}
		}
		return false;
	}
}