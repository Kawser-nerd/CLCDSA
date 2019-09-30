package google.codejam2012.qualification;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class DancingWithTheGooglers {
	
	static public void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 64 << 10);
			int testsNumber = Integer.parseInt(br.readLine().trim());
			for (int test = 1; test <= testsNumber; test++) {
				StringTokenizer tokenizer = new StringTokenizer(br.readLine());
				int contestantsCount = Integer.parseInt(tokenizer.nextToken());
				int surprisesCount = Integer.parseInt(tokenizer.nextToken());
				int threshold = Integer.parseInt(tokenizer.nextToken());
				int result = 0;
				for (int i = 0; i < contestantsCount; i++) {
					int score = Integer.parseInt(tokenizer.nextToken());
					// - (score + 2) / 3
					// - (score + 4) / 3
					if (2 <= score & score <= 28) {
						int best = (score + 2) / 3;
						int bestSurprise = (score + 4) / 3;
						if (best >= threshold) {
							result++;
						}
						else if (bestSurprise >= threshold & surprisesCount > 0) {
							result++;
							surprisesCount--;
						}
					}
					else if ((score + 2) / 3 >= threshold) {
						result++;
					}
				}
				System.out.println("Case #" + test + ": " + result);
			}
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}
}
