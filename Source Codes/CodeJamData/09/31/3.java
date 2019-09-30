import java.util.*;


public class A {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		s.useDelimiter("\\s+");
		
		int testCases = s.nextInt();
		for ( int t = 0 ; t < testCases ; t++ ) {
			String in = s.next();
			System.out.printf("Case #%d: %d\n", t + 1, calc(in));
		}
	}
	
	private static final String DIGITS = "1023456789abcdefghijklmnopqrstuvwxyz";
	
	static long calc(String in) {
		if ( in.length() == 1 ) return 1;
		Map<Character, Character> map = new HashMap<Character, Character>();
		
		int base = 0;
		
		for ( char c : in.toCharArray() ) {
			if ( !map.containsKey(c) ) base++;
			map.put(c, null);
		}
		
		int idx = 0;
		
		StringBuilder s = new StringBuilder();
		
		for ( char c : in.toCharArray() ) {
			if ( map.get(c) == null ) {
				map.put(c, DIGITS.charAt(idx++));
			}
			s.append(map.get(c));
		}
		
		if ( base == 1 ) base = 2;
		
		return Long.parseLong(s.toString(), base);
	}
}
