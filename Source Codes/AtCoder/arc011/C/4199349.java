import java.util.*;
 
public class Main {
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String first = sc.next();
		String last = sc.next();
		if (first.equals(last)) {
			System.out.println(0);
			System.out.println(first);
			System.out.println(last);
			return;
		}
		int n = sc.nextInt();
		String[] arr = new String[n + 2];
		arr[0] = first;
		arr[1] = last;
		for (int i = 0; i < n; i++) {
			arr[i + 2] = sc.next();
		}
		ArrayList<Integer>[] lists = new ArrayList[n + 2];
		ArrayList<Integer>[] ans = new ArrayList[n + 2];
		for (int i = 0; i < n + 2; i++) {
			lists[i] = new ArrayList<Integer>();
			ans[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n + 2; i++) {
			for (int j = i + 1; j < n + 2; j++) {
				if (diff(arr[i], arr[j]) == 1) {
					lists[i].add(j);
					lists[j].add(i);
				}
			}
		}
		ans[0].add(0);
		ArrayList<Integer> result = null;
		for (int i = 1; i < n + 2; i++) {
			int count = 0;
			for (int j = 0; j < n + 2; j++) {
				if (ans[j].size() == i) {
					for (int x : lists[j]) {
						if (ans[x].size() == 0) {
							ans[x] = (ArrayList<Integer>)ans[j].clone();
							ans[x].add(x);
							count++;
							if (x == 1) {
								result = ans[x];
								break;
							}
						}
					}
				}
				if (result != null) {
					break;
				}
			}
			if (result != null) {
				break;
			}
			if (count == 0) {
				System.out.println(-1);
				return;
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append(result.size() - 2).append("\n");
		for (int x : result) {
			sb.append(arr[x]).append("\n");
		}
		System.out.print(sb);
	}
	
	static int diff(String a, String b) {
		int count = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a.charAt(i) != b.charAt(i)) {
				count++;
			}
		}
		return count;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.