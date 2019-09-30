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
		
		int[] ar = nextIntArray(5);
		ArrayList<Integer> list = new ArrayList<>();
		
		for (int i=0; i<(Math.pow(2,5)); i++) {
			
			if (Integer.bitCount(i) != 3) continue;
			
			int tempSum = 0;
			for (int j=0; j<5; j++) {
				if ((1&i>>j) == 1) {
					tempSum += ar[j];
				}
			}
			list.add(tempSum);
			
		}
		
		Collections.sort(list);
		
		out.println(list.get(list.size()-3));
		
	}
}