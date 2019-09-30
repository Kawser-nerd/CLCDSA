import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int B[] = new int[N];
		LinkedList list[] = new LinkedList[N + 1];
		for(int i = 0; i < N + 1; i++) {
			list[i] = new LinkedList();
		}
		for(int i = 1; i < N; i++) {
			B[i] = sc.nextInt();
			list[B[i] - 1].add(i);
		}
		System.out.println(get_money(0, list));
	}

	public static int get_money(int num, LinkedList list[]) {
		if(list[num].size() == 0) {
			return 1;
		} else {
			int min = Integer.MAX_VALUE;
			int max = 0;
			for(int i = 0; i < list[num].size(); i++) {
				int n = get_money(list[num].get(i), list);
				min = Math.min(min, n);
				max = Math.max(max, n);
			}
			return min + max + 1;
		}
	}
}

class LinkedList {
	ArrayList<Integer> link = new ArrayList<Integer>();
	public void add(int vertex) {
		link.add(vertex);
	}

	public int get(int i){
		return link.get(i);
	}

	public void remove(int vertex) {
	}

	public void view() {
		for(int i = 0; i < link.size(); i++) {
			System.out.println(link.get(i));
		}
	}

	public boolean linked(int vertex) {
		if(Arrays.asList(link).contains(vertex)){
			return true;
		} else {
			return false;
		}
	}

	public int size() {
		return link.size();
	}
}