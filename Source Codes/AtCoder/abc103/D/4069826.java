import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Main{
	static int G;
	static int D;
	static int[] p;
	static int[] c;
	static boolean[] used;
	static long ans = 1000000000;


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] a = new int[m];
		int[] b = new int[m];
		ArrayList<Pair> pairs = new ArrayList<Pair>();
		for(int i  = 0;i < m;i++){
			Pair pair = new Pair();
			a[i] = sc.nextInt()-1;
			b[i] = sc.nextInt()-1;
			pair.from = a[i];
			pair.end = b[i];
			pairs.add(pair);
		}
		Collections.sort(pairs);
		
		int minR = pairs.get(0).end;
		int ans = 0;
		for(int i = 1;i < m;i++){
//			System.out.println(minR);
			if(pairs.get(i).from >= minR){
				ans++;
				minR = pairs.get(i).end;
			}else{
				if(pairs.get(i).end < minR){
					minR = pairs.get(i).end;
				}
			}
			
		}
		ans++;
		System.out.println(ans);
		
		
		
		


		
	}
	

}

class Pair implements Comparable{
	int from;		//p
	int end;		//y
	int num;
	int bango;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return from - otherpair.from;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.