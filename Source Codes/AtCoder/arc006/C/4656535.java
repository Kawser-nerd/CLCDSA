import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int N;
		N = Integer.parseInt(reader.readLine());
		List<Integer> result = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			int value = Integer.parseInt(reader.readLine());
			int minIndex = -1, min = Integer.MAX_VALUE; //???????????
			for (int j = 0; j < result.size(); j++) {
				if (value <= result.get(j)) {
					if (result.get(j) - value < min) {
						min = result.get(j) - value;
						minIndex = j;
						//break;
					}
				}
			}
			if (minIndex == -1) {
				result.add(value);
			} else {
				result.set(minIndex, value);
			}
		}
		System.out.println(result.size());
	}

}