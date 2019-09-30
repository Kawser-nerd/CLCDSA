import java.util.*;

public class Main {
	int N;
	List<Set<Integer>> groups = new ArrayList<>();

	Main() {
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		in.close();
	}

	void makeGroups() {
		if (N % 2 == 0) {
			for (int i = 0; i < N / 2; ++i) {
				Set<Integer> set = new HashSet<>();
				set.add(i + 1);
				set.add(N - i);
				this.groups.add(set);
			}
		} else {
			for (int i = 0; i < N / 2; ++i) {
				Set<Integer> set = new HashSet<>();
				set.add(i + 1);
				set.add(N - i - 1);
				this.groups.add(set);
			}
			Set<Integer> s = new HashSet<>();
			s.add(N);
			this.groups.add(s);
		}
	}

	void show() {
		List<String> results = new ArrayList<>();
		for (int i = 0; i < this.groups.size(); ++i) {
			Set<Integer> grA = this.groups.get(i);
			for (int j = i + 1; j < this.groups.size(); ++j) {
				Set<Integer> grB = this.groups.get(j);
				for (Integer a : grA) {
					for (Integer b : grB) {
						results.add(a + " " + b);
					}
				}
			}
		}
		System.out.println(results.size());
		for (String line : results) {
			System.out.println(line);
		}
	}

	public static void main(String[] args) {
		Main ins = new Main();
		ins.makeGroups();
		ins.show();
	}

}