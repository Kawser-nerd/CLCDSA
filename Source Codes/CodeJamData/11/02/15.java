import java.io.File;
import java.util.Arrays;
import java.util.Scanner;


public class Magicka {
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File(args[0]));
		int nCases = scanner.nextInt();

		for (int caseNo = 1; caseNo <= nCases; caseNo++) {

			Element[] elements = new Element[26];
			for (int k = 0; k < elements.length; k++) {
				elements[k] = new Element();
			}
			
			scanner.nextLine();
			int nCombos = scanner.nextInt();
			for (int i = 0; i < nCombos; i++) {
				String combo = scanner.next();
				if (combo.length() != 3) {
					throw new RuntimeException("Bad input" + nCombos);
				}
				char left = combo.charAt(0);
				char right = combo.charAt(1);
				char transform = combo.charAt(2);
				elements[left - 'A'].addTranform(right, transform);
				elements[right - 'A'].addTranform(left, transform);

			}
			int nOppositions = scanner.nextInt();
			for (int i = 0; i < nOppositions; i++) {
				String oppose = scanner.next();
				if (oppose.length() != 2) {
					throw new RuntimeException("Bad input");
				}
				char left = oppose.charAt(0);
				char right = oppose.charAt(1);
				elements[left - 'A'].addOpposition(right);
				elements[right - 'A'].addOpposition(left);
			}
			int nInvokes = scanner.nextInt();
			StringBuilder builder = new StringBuilder(nInvokes);

			String invokes = scanner.next();
			if (invokes.length() != nInvokes) {
				throw new RuntimeException("Bad Input");
			}
			Element lastElement = null;
			for (char c : invokes.toCharArray()) {

				if (lastElement != null) {
					char transform = lastElement.transformWith(c);
					if (transform != 0) {
						builder.setCharAt(builder.length() - 1, transform);
						lastElement = elements[transform - 'A'];
					} else {
						Element thisElement = elements[c - 'A'];
						String oppositions = thisElement.oppositions.toString();
						boolean clearList = false;
						for (char check : oppositions.toCharArray()) {
							if (builder.indexOf("" + check) >= 0) {
								clearList = true;
								break;
							}
						}
						if (clearList) {
							builder.setLength(0);
							lastElement = null;
						} else {
							builder.append(c);
							lastElement = thisElement;
						}
					}
				} else {
					builder.append(c);
					lastElement = elements[c - 'A'];
				}
			
			}
			

			
			char[] output = builder.toString().toCharArray();
			
			System.out.println("Case #" + caseNo + ": " + Arrays.toString(output));
			
		}

	}
	
	private static class Element {
		
		private char[] transforms = new char[26];
		private StringBuilder oppositions = new StringBuilder();
		
		public void addOpposition(char o) {
			oppositions.append(o);
		}
		
		public void addTranform(char other, char to) {
			transforms[other - 'A'] = to;
		}
		
		public char transformWith(char c) {
			return transforms[c - 'A'];
		}
		
	}

}
