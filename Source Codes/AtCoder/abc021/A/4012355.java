import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int[] map = {8,4,2,1};
		List<Integer> list = new ArrayList<>();
		for (int i : map) {
			if (N >= i) {
				list.add(i);
				N -= i;
			}
		}
		
		System.out.println(list.size());
		for(int i : list) {
			System.out.println(i);
		}
	}
}