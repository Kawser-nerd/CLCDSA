package qround;

import java.util.*;

public class A {
	static int[] next(int seq[] , int from , int S){
		int d[] = new int[S];
		Arrays.fill(d, -1);
		for(int i = from ; i < seq.length ; i++){
			int s = seq[i];
			if(d[s] < 0){
				d[s] = i;
			}
		}
		return d;
	}
	static int choice(int d[]){
		int max = d[0];
		int mp = 0;
		if(max < 0)return -1;
		for(int i = 1 ; i < d.length ; i++){
			int s = d[i];
			if(s < 0)return -1;
			if(max < s){
				max = s;
				mp = i;
			}
		}
		return mp;
	}
	static int solve(int seq[] , int S){
		int d[] = next(seq, 0 , S);
		int change = 0;
		int engine = choice(d);
		if(engine < 0)return change;
		for(int i = 0 ; i < seq.length ; i++){
			int s = seq[i];
			if(s != engine)continue;
			change++;
			d = next(seq , i  , S);
			engine = choice(d);
			if(engine < 0)return change;	
		}
		return change;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for(int i = 0 ; i < N ; i++){
			int S = sc.nextInt();
			sc.nextLine();
			Map<String , Integer> engines = new HashMap<String, Integer>();
			for(int j = 0 ; j < S ; j++){
				engines.put(sc.nextLine(), j);				
			}
			int Q = sc.nextInt();
			sc.nextLine();
			int seq[] = new int[Q];
			for(int j = 0 ; j < Q ; j++){
				seq[j] = engines.get(sc.nextLine());
			}
			System.out.printf("Case #%d: %d\n" , (i + 1) , solve(seq, S));
		}
	}
}
