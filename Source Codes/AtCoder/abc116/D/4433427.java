import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();

		Sushi[] array = new Sushi[n];
		for (int i = 0; i < n; i++) {
			array[i] = new Sushi(sc.nextInt(), sc.nextInt());
		}
		sc.close();

		// ??????????
		Arrays.sort(array, new Comparator<Sushi>() {
			public int compare(Sushi s1, Sushi s2) {
				return s2.d - s1.d;
			}
		});

		// ??????????
		Map<Integer, Integer> typeMap = new HashMap<Integer, Integer>();
		// ?????????K?????????????????
		int typeCnt = 0;
		long manzoku = 0L;
		for (int i = 0; i < k; i++) {
			Sushi sushi = array[i];
			int bonusDiff = 0;
			if (typeMap.containsKey(sushi.t)) {
				typeMap.put(sushi.t, typeMap.get(sushi.t) + 1);
			} else {
				bonusDiff -= typeCnt * typeCnt;
				typeMap.put(sushi.t, 1);
				typeCnt++;
				bonusDiff += typeCnt * typeCnt;
			}
			manzoku += sushi.d + bonusDiff;
		}

		long ans = manzoku;
		int rmIdx = k - 1;
		for (int i = k; i < n; i++) {
			Sushi sushi = array[i];
			// ????????
			if (!typeMap.containsKey(sushi.t)) {
				Sushi rmSushi = null;
				for (; rmIdx >= 0; rmIdx--) {
					rmSushi = array[rmIdx];
					int rmCnt = typeMap.get(rmSushi.t);
					if (rmCnt >= 2) {
						typeMap.put(rmSushi.t, rmCnt - 1);
						rmIdx--;
						break;
					}
					rmSushi = null;
				}
				if (rmSushi != null) {
					typeMap.put(sushi.t, 1);
					int bonusDiff = 0;
					bonusDiff -= typeCnt * typeCnt;
					typeCnt++;
					bonusDiff += typeCnt * typeCnt;
					manzoku += sushi.d - rmSushi.d + bonusDiff;
					ans = Math.max(ans, manzoku);
				}
			}
		}
		System.out.println(ans);
	}

	static class Sushi {
		int t;
		int d;
		public Sushi(int t, int d) {
			this.t = t;
			this.d = d;
		}
	}
}