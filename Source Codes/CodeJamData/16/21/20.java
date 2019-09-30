import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class ProbA {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("A-large.in"));
		PrintStream out = new PrintStream(new File("A-large.out"));
		
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			String s = in.next();
			int[] counts = new int[256];
			for (char c : s.toCharArray()) {
				counts[c]++;
			}
			int[] digits = new int[10];
			{
				int zeroes = counts['Z'];
				digits[0] = zeroes;
				subtract(counts, "ZERO", zeroes);
			}
			{
				int twos = counts['W'];
				digits[2] = twos;
				subtract(counts, "TWO", twos);
			}
			{
				int fours = counts['U'];
				digits[4] = fours;
				subtract(counts, "FOUR", fours);
			}
			{
				int fives = counts['F'];
				digits[5] = fives;
				subtract(counts, "FIVE", fives);
			}
			{
				int sixes = counts['X'];
				digits[6] = sixes;
				subtract(counts, "SIX", sixes);
			}
			{
				int sevens = counts['V'];
				digits[7] = sevens;
				subtract(counts, "SEVEN", sevens);
			}
			{
				int eights = counts['G'];
				digits[8] = eights;
				subtract(counts, "EIGHT", eights);
			}
			{
				int ones = counts['O'];
				digits[1] = ones;
				subtract(counts, "ONE", ones);
			}
			{
				int threes = counts['R'];
				digits[3] = threes;
				subtract(counts, "THREE", threes);
			}
			digits[9] = counts['I'];
			out.printf("Case #%d: ", caseNum);
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < digits[i]; j++) {
					out.printf("%d", i);
				}
			}
			out.println();
		}
	}
	
	private static void subtract(int[] counts, String str, int count) {
		for (char c : str.toCharArray()) {
			counts[c] -= count;
		}
	}
}
