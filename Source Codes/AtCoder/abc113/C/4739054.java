import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int M = sc.nextInt();

		Map<Integer, ArrayList> map = new TreeMap<Integer, ArrayList>();

		for (int i = 0; i < M; i++) {
			int p = sc.nextInt();
			int y = sc.nextInt();
			map.put(y,new ArrayList<Integer>(Arrays.asList(p,i)));
		}

		int[] cnt = new int[N + 1];
		String[] ans = new String[M+1];

		Arrays.fill(cnt,0);

		int i = 0;
		for (List<Integer> ii : map.values()) {
			ans[ii.get(1)] = String.format("%06d%06d",ii.get(0),++cnt[ii.get(0)]);
			i++;
		}

		for(i = 0; i < M; i++){
			System.out.println(ans[i]);
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.