package round3;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class D {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caze = 1; caze <= cases; caze++) {
			int P = sc.nextInt();
			long[] vals = new long[P], freqs = new long[P];
			Map<Long, Integer> pos = new HashMap<Long, Integer>();
			for (int i = 0; i < vals.length; i++) {
				vals[i] = sc.nextLong();
				pos.put(vals[i], i);
			}
			long total = 0;
			for (int i = 0; i < vals.length; i++) {
				freqs[i] = sc.nextLong();
				total += freqs[i];
			}
			int cant = 0;
			long tmp = total;
			while (tmp > 1) {
				tmp /= 2;
				cant++;
			}
			long[] ans = new long[cant];
			int sumIdx = 0, setIdx = 0;
			for (setIdx = 0; setIdx < cant; setIdx++) {
				for (int m = 0; m < (1<<setIdx); m++) {
					if (setIdx != 0 && (m&(1<<(setIdx-1))) == 0) continue;
					long val = 0;
					for (int i = 0; i < setIdx; i++) if ((m&(1<<i)) != 0) val+=ans[i];
					freqs[pos.get(val)]--;
				}
				while (freqs[sumIdx] == 0) {
					sumIdx++;
				}
				ans[setIdx] = vals[sumIdx];
			}
			System.out.print("Case #" + caze + ":");
			for (int i = 0; i < ans.length; i++) {
				System.out.print(" " + ans[i]);
			}
			System.out.println();
		}
	}

}
