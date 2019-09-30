import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemB {

	static char[] numbers = "0123456789".toCharArray();

	static String coder = "";
	static String jammer = "";
	static String coderBest = "";
	static String jammerBest = "";

	static long bestScore = Long.MAX_VALUE;
	static String coderOrig = "";
	static String jammerOrig = "";

	public static void solve(Scanner sc) {
		coderOrig = sc.next();
		jammerOrig = sc.next();
		char[] coderScore = coderOrig.toCharArray();
		char[] jammerScore = jammerOrig.toCharArray();
		int firstQ = -1;
		int lastQ = -1;
		int diffPos = -1;
		int diff = -1;
		for (int i = 0; i < coderScore.length; i++) {
			if (coderScore[i] != '?' && jammerScore[i] != '?') {
				if (diffPos == -1 && coderScore[i] != jammerScore[i]) {
					diffPos = i;
					diff = coderScore[i] - jammerScore[i];
				}
			} else {
				if (diffPos == -1) {
					lastQ = i;
				} else if (firstQ == -1) {
					firstQ = i;
				}
			}
		}
		if (diffPos == -1) {
			// same scores for both
			equalAndOut(jammerScore, coderScore);
			System.out.println(coder + " " + jammer);
			return;
		}
		correctAfter(jammerScore, coderScore, diffPos, diff);
		coderBest = coder;
		jammerBest = jammer;
		bestScore = score(coder, jammer);
		for (int pos = diffPos - 1; pos >= 0; pos--) {
			coderScore = coderOrig.toCharArray();
			jammerScore = jammerOrig.toCharArray();
			correctBefore(jammerScore, coderScore, diffPos, diff, pos);
			long score = score(coder, jammer);
			if (valid(coder, coderOrig) && valid(jammer, jammerOrig)) {
				if (score < bestScore || score == bestScore
						&& coder.compareTo(coderBest) < 0 || score == bestScore
						&& coder.compareTo(coderBest) == 0
						&& jammer.compareTo(jammerBest) < 0) {
					coderBest = coder;
					jammerBest = jammer;
					bestScore = score;
				}
			}
		}
		for (int pos = diffPos - 1; pos >= 0; pos--) {
			coderScore = coderOrig.toCharArray();
			jammerScore = jammerOrig.toCharArray();
			correctBeforeAndAfter(jammerScore, coderScore, diffPos, diff, pos);
			long score = score(coder, jammer);
			if (valid(coder, coderOrig) && valid(jammer, jammerOrig)) {
				if (score < bestScore || score == bestScore
						&& coder.compareTo(coderBest) < 0 || score == bestScore
						&& coder.compareTo(coderBest) == 0
						&& jammer.compareTo(jammerBest) < 0) {
					coderBest = coder;
					jammerBest = jammer;
					bestScore = score;
				}
			}
		}
		System.out.println(coderBest + " " + jammerBest);
	}

	private static long score(String coder, String jammer) {
		long l1 = Long.parseLong(coder);
		long l2 = Long.parseLong(jammer);
		return Math.abs(l1 - l2);
	}

	private static boolean valid(String s, String orig) {
		char[] arrS = s.toCharArray();
		char[] arrOrig = orig.toCharArray();
		for (int i = 0; i < arrOrig.length; i++) {
			if (arrOrig[i] != '?' && arrOrig[i] != arrS[i]) {
				return false;
			}
		}
		return true;
	}

	private static void correctBeforeAndAfter(char[] jammerScore,
			char[] coderScore, int diffPos, int diff, int correctionPoint) {
		for (int i = diffPos; i < coderScore.length; i++) {
			if (coderScore[i] == '?') {
				coderScore[i] = (diff < 0 ? '0' : '9');
			}
			if (jammerScore[i] == '?') {
				jammerScore[i] = (diff > 0 ? '0' : '9');
			}
		}
		correctBefore(jammerScore, coderScore, diffPos, diff, correctionPoint);

	}

	private static void correctBefore(char[] jammerScore, char[] coderScore,
			int diffPos, int diff, int correctionPoint) {
		for (int i = diffPos; i >= 0; i--) {
			if (i == correctionPoint) {
				if (coderScore[i] == '?' && jammerScore[i] == '?') {
					coderScore[i] = (diff > 0 ? '0' : '1');
					jammerScore[i] = (diff < 0 ? '0' : '1');
				} else if (coderScore[i] == '?') {
					int blub = jammerScore[i] - '0' + (diff > 0 ? -1 : 1);
					if (blub < 0) {
						blub = 0;
					}
					if (blub > 9) {
						blub = 9;
					}
					coderScore[i] = numbers[blub];
				} else {
					int blub = coderScore[i] - '0' + (diff < 0 ? -1 : 1);
					if (blub < 0) {
						blub = 0;
					}
					if (blub > 9) {
						blub = 9;
					}
					jammerScore[i] = numbers[blub];
				}
				equalAndOut(jammerScore, coderScore);
			}
			if (coderScore[i] == '?') {
				coderScore[i] = (diff > 0 ? '9' : '0');
			}
			if (jammerScore[i] == '?') {
				jammerScore[i] = (diff < 0 ? '9' : '0');
			}
		}
	}

	private static void correctAfter(char[] jammerScore, char[] coderScore,
			int diffPos, int diff) {
		for (int i = diffPos; i < coderScore.length; i++) {
			if (coderScore[i] == '?') {
				coderScore[i] = (diff > 0 ? '0' : '9');
			}
			if (jammerScore[i] == '?') {
				jammerScore[i] = (diff < 0 ? '0' : '9');
			}
		}
		equalAndOut(jammerScore, coderScore);
	}

	private static void equalAndOut(char[] jammerScore, char[] coderScore) {
		for (int i = 0; i < coderScore.length; i++) {
			if (coderScore[i] == '?' && jammerScore[i] == '?') {
				coderScore[i] = jammerScore[i] = '0';
			} else if (jammerScore[i] == '?') {
				jammerScore[i] = coderScore[i];
			} else if (coderScore[i] == '?') {
				coderScore[i] = jammerScore[i];
			}
		}
		coder = new String(coderScore);
		jammer = new String(jammerScore);
	}

	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(new File("B-practice.in"));
//		 Scanner sc = new Scanner(new File("B-small-attempt1.in"));
		 Scanner sc = new Scanner(new File("B-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
