import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int nextInt () {return Integer.parseInt(sc.next());}
	static int[] nextIntArray (int n) {return IntStream.range(0,n).map(i->nextInt()).toArray();}
	static int max (int... ar) {Arrays.sort(ar);return ar[ar.length-1];}
	static int min (int... ar) {Arrays.sort(ar);return ar[0];}
	static String yesno (boolean b) {return b?"Yes":"No";}
	public static void main(String[] args) {
		
		HashMap<Integer, Integer> map = new HashMap<>();
		int n = nextInt();
		for (int i=0; i<n; i++) {
			int temp = nextInt();
			map.put(temp, map.getOrDefault(temp,0)+1);
			map.put(temp+1, map.getOrDefault(temp+1,0)+1);
			map.put(temp-1, map.getOrDefault(temp-1,0)+1);
		}
		
		int max = Integer.MIN_VALUE;
		for (Map.Entry<Integer, Integer> e: map.entrySet()) {
			max = Math.max(max, e.getValue());
		}
		
		out.println(max);
		
	}
}