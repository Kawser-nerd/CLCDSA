import java.util.Scanner;


public class B {
	private static Scanner sc;
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) System.out.printf("Case #%d: %s\n", i + 1, exec());
	}
	
	private static String exec() {
		int c = sc.nextInt();
		String[] combs = new String[c];
		for (int i = 0; i < c; i++) combs[i] = sc.next();
		int d = sc.nextInt();
		String[] opps = new String[d];
		for (int i = 0; i < d; i++) opps[i] = sc.next();
		int n = sc.nextInt();
		String cast = sc.next();
		if (cast.length() != n) throw new RuntimeException("input read misunderstanding");
		
		return calc(combs, opps, cast);
	}
	
	private static String calc(String[] combs, String[] opps, String cast) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < cast.length(); i++) {
			char x = cast.charAt(i);
			sb.append(x);
			combine(sb, combs);
			elim(sb, opps);
		}
		StringBuilder out = new StringBuilder();
		for (int i = 0; i < sb.length(); i++) {
			if (out.length() != 0) out.append(", ");
			out.append(sb.charAt(i));
		}
		
		return "[" + out + "]";
	}
	
	private static void elim(StringBuilder sb, String[] opps) {
		if (sb.length() < 2) return;
		
		for (String opp : opps) {
			String a = "" + opp.charAt(0);
			String b = "" + opp.charAt(1);
			if (sb.indexOf(a) > -1 && sb.indexOf(b) > -1) {
				sb.setLength(0);
				return;
			}
		}
	}
	
	private static void combine(StringBuilder sb, String[] combs) {
		if (sb.length() < 2) return;
		
		String a = sb.substring(sb.length() - 2);
		String b = "" + a.charAt(1) + a.charAt(0);
		for (String combo : combs) {
			String cmb = combo.substring(0, 2);
			if (a.equals(cmb) || b.equals(cmb)) {
				sb.setLength(sb.length() - 2);
				sb.append(combo.charAt(2));
				return;
			}
		}
	}
}
