package google.codejam2012.qualification;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class RecycledNumbers {
	
	static private int getDigitsCount(int number) {
		int sh = 10;
		int digits = 1;
		while (sh <= number) {
			sh *= 10;
			digits++;
		}
		return digits;
	}
	
	static private int getRecyclingPairsCount(int number, int limit) {
		int digits = getDigitsCount(number);
		int sh = 1;
		for (int i = 1; i < digits; i++) {
			sh *= 10;
		}
		int permutation = number;
		int result = 0;
		int[] usedNumbers = new int[digits];
		int usedNumbersCount = 0;
		for (int i = 1; i < digits; i++) {
			permutation = (permutation % 10) * sh + (permutation / 10);
			if (number < permutation & permutation <= limit) {
				boolean isNumberAlreadyUsed = false;
				for (int j = 0; j < usedNumbersCount; j++) {
					if (usedNumbers[j] == permutation) {
						isNumberAlreadyUsed = true;
						break;
					}
				}
				if (!isNumberAlreadyUsed) {
					usedNumbers[usedNumbersCount++] = permutation;
					result++;
				}
			}
		}
		return result;
	}
	
	static public void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 64 << 10);
			int testsNumber = Integer.parseInt(br.readLine().trim());
			for (int test = 1; test <= testsNumber; test++) {
				StringTokenizer tokenizer = new StringTokenizer(br.readLine());
				int startingNumber = Integer.parseInt(tokenizer.nextToken());
				int endingNumber = Integer.parseInt(tokenizer.nextToken());
				int result = 0;
				for (int number = startingNumber; number <= endingNumber; number++) {
					result += getRecyclingPairsCount(number, endingNumber);
				}
				System.out.println("Case #" + test + ": " + result);
			}
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}
}
