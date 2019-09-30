import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int nextInt () {return Integer.parseInt(sc.next());}
	static int[] nextIntArray (int n) {return IntStream.range(0,n).map(i->nextInt()).toArray();}
	static int max (int... ar) {Arrays.sort(ar);return ar[ar.length-1];}
	static int min (int... ar) {Arrays.sort(ar);return ar[0];}
	static int maxInt = Integer.MAX_VALUE;
	static int minInt = Integer.MIN_VALUE;
	public static void main(String[] args) {
		
		String s = sc.next();
		int n = nextInt();
		
		ArrayList<String> list = new ArrayList<>();
		
		for (int i=0; i<s.length(); i++) {
			for (int j=0; j<s.length(); j++) {
				StringBuilder temp = new StringBuilder();
				temp.append(s.charAt(i));
				temp.append(s.charAt(j));
				list.add(temp.toString());
			}
			
		}
		
		Collections.sort(list);
		
		out.println(list.get(n-1));
		
	}
}