import java.util.*;
import java.util.stream.Collectors;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		
		List<Integer> list = new ArrayList<>(N);
		int[] map = new int[N];
		for (int i = 0; i < N; i++) {
			map[i] = sc.nextInt();
			list.add(map[i]);
		}

		list = list.stream().distinct().sorted().collect(Collectors.toList());
		
		Map<Integer, Integer> convertMap = new HashMap<>(N);
		for (int i = 0; i < list.size(); i++) {
			convertMap.put(list.get(i), i);
		}
		
		for (int a : map) {
			System.out.println(convertMap.get(a));
		}
	}

}