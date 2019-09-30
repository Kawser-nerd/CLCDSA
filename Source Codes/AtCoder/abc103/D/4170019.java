import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		ArrayList<Bridge> list = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			list.add(new Bridge(sc.nextInt(), sc.nextInt()));
		}
		Collections.sort(list, new Comparator<Bridge>() {
		public int compare(Bridge b1, Bridge b2) {
			if (b1.end == b2.end) {
				return b1.start - b2.start;
			} else {
				return b1.end - b2.end;
			}
		}
		});
		int count = 0;
		while (list.size() > 0) {
			Bridge b = list.get(0);
			while (list.size() > 0) {
				Bridge out = list.get(0);
				if (out.start >= b.end) {
					break;
				}
				list.remove(0);
			}
			count++;
		}
		System.out.println(count);
	}
	
	static class Bridge {
		int start;
		int end;
		public Bridge(int start, int end) {
			this.start = start;
			this.end = end;
		}
		
		public int hashCode() {
			return start + end * 1000;
		}
		
		public boolean equals(Object o) {
			Bridge b = (Bridge) o;
			return b.start == start && b.end == end;
		}
	}
}