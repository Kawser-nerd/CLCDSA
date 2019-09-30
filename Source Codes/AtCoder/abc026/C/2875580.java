import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int []B = new int[N];
		for(int i = 0; i < N - 1; i++) {
			B[i] = scan.nextInt();
		}
		Map<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
		for(int i = 1; i <= N - 1; i++) {
			if(map.containsKey(B[i - 1])) {
				ArrayList<Integer> list = map.get(B[i - 1]);
				list.add(i + 1);
				map.put(B[i - 1], list);
			}else {
				ArrayList<Integer> list = new ArrayList<Integer>();
				list.add(i + 1);
				map.put(B[i - 1], list);
			}
		}
		int []m = new int[N + 1];
		for(int i = 1; i <= N; i++) {
			if(!map.containsKey(i)) {
				m[i] = 1;
			}
		}

//		disp(m);
//		for(int i = 1; i <= N; i++) {
//			if(map.containsKey(i)) {
//				ArrayList<Integer> list = map.get(i);
//				System.out.print(i + " ");
//				for(int j = 0; j < list.size(); j++) {
//					System.out.print(list.get(j) + " ");
//				}
//				System.out.println();
//			}else {
//				System.out.println(i + " 0");
//			}
//		}
		for(int i = N; i >= 1; i--) {
			if(map.containsKey(i)) {
				ArrayList<Integer> list = map.get(i);
				if(list.size() == 1) {
					m[i] = 2 * m[list.get(0)] + 1;
				}else {
					int t1 = list.get(0);
					int t2 = list.get(1);
					int min = Math.min(m[t1], m[t2]);
					int max = Math.max(m[t1], m[t2]);
					for(int j = 2; j < list.size(); j++) {
						int t = list.get(j);
						min = Math.min(min, m[t]);
						max = Math.max(max, m[t]);
					}
					m[i] = min + max + 1;
				}
			}
		}
		System.out.println(m[1]);

	}
	static void disp(int []m) {
		for(int i = 0; i < m.length - 1; i++) {
			System.out.println(m[i + 1]);
		}
	}
}