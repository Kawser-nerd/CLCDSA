import java.io.File;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

// 'e' = 1, 'E' = -1, 'I' = -i, 'J' = -j, 'K' = -k
public class C {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "C";
	static final String INPUT = "large";
	static final String ID = "0";
	static final String PATH = "/Users/wangkai/Documents/codejam-commandline-1.2-beta1/source/";

	static Map<Operands, Character> multiplicationTable = new HashMap<Operands, Character>();
	static {
		multiplicationTable.put(new Operands('e', 'e'), 'e');
		multiplicationTable.put(new Operands('e', 'i'), 'i');
		multiplicationTable.put(new Operands('e', 'j'), 'j');
		multiplicationTable.put(new Operands('e', 'k'), 'k');

		multiplicationTable.put(new Operands('i', 'e'), 'i');
		multiplicationTable.put(new Operands('i', 'i'), 'E');
		multiplicationTable.put(new Operands('i', 'j'), 'k');
		multiplicationTable.put(new Operands('i', 'k'), 'J');

		multiplicationTable.put(new Operands('j', 'e'), 'j');
		multiplicationTable.put(new Operands('j', 'i'), 'K');
		multiplicationTable.put(new Operands('j', 'j'), 'E');
		multiplicationTable.put(new Operands('j', 'k'), 'i');

		multiplicationTable.put(new Operands('k', 'e'), 'k');
		multiplicationTable.put(new Operands('k', 'i'), 'j');
		multiplicationTable.put(new Operands('k', 'j'), 'I');
		multiplicationTable.put(new Operands('k', 'k'), 'E');
	}

	public static void main(String[] args) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int partLength = in.nextInt();
			long repeat = in.nextLong();
			String part = in.next();

			String reduced = reduce(part, repeat);

			boolean result;
			if (compute(reduced) != 'E') {
				result = false;
			} else {
				int startIndex = findGroup(reduced, 0, 'i');
				if (startIndex < 0) {
					result = false;
				} else {
					startIndex = findGroup(reduced, startIndex, 'j');
					if (startIndex < 0) {
						result = false;
					} else {
						result = true;
					}
				}
			}
			out.println(result ? "YES" : "NO");
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	static String reduce(String part, long repeat) {
		char partResult = compute(part);
		if (partResult == 'e') {
			return "e";
		} else if (partResult == 'E') {
			if (repeat % 2 == 0) {
				return "e";
			} else {
				return join(part, (int) Math.min(repeat, 5));
			}
		} else {
			if (repeat % 4 == 0) {
				return "e";
			} else {
				String rest;
				if (repeat % 2 != 0) {
					rest = part;
					repeat--;
				} else {
					rest = "";
				}
				return rest + join(part, (int) Math.min(repeat, 10));
			}
		}
	}

	static String join(String part, int repeat) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < repeat; i++) {
			sb.append(part);
		}
		return sb.toString();
	}

	static char compute(String sequence) {
		char result = 'e';
		for (int i = 0; i < sequence.length(); i++) {
			result = multiply(result, sequence.charAt(i));
		}
		return result;
	}

	static char multiply(char left, char right) {
		boolean positive = true;
		if (Character.isUpperCase(left)) {
			positive = !positive;
			left = Character.toLowerCase(left);
		}
		if (Character.isUpperCase(right)) {
			positive = !positive;
			right = Character.toLowerCase(right);
		}

		char result = multiplicationTable.get(new Operands(left, right));

		if (!positive) {
			if (Character.isLowerCase(result)) {
				result = Character.toUpperCase(result);
			} else {
				result = Character.toLowerCase(result);
			}
		}
		return result;
	}

	static int findGroup(String sequence, int startIndex, char target) {
		char result = 'e';
		for (int i = startIndex; i < sequence.length(); i++) {
			result = multiply(result, sequence.charAt(i));
			if (result == target) {
				return i + 1;
			}
		}
		return -1;
	}
}

class Operands {
	char left;
	char right;

	Operands(char left, char right) {
		this.left = left;
		this.right = right;
	}

	@Override
	public int hashCode() {
		return left * right;
	}

	@Override
	public boolean equals(Object obj) {
		Operands other = (Operands) obj;
		return left == other.left && right == other.right;
	}
}