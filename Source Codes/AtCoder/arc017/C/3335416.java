import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	static int a;
	static int[] w;
	static HashMap<Integer,Integer> left = new HashMap<Integer,Integer>();
	static HashMap<Integer,Integer> right = new HashMap<Integer,Integer>();
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in) ;
		int N = sc.nextInt();
		int X = sc.nextInt();

		w = new int[N];
		for(int i=0;i<N;i++) {
			w[i] = sc.nextInt();
		}
		a = N/2;
		int ans =0;
		pack(0,a,left,0);
		pack(a,N,right,0);
		for(int c:left.keySet()) {
			if(right.containsKey(X-c)) {
				ans += left.get(c) * right.get(X-c);
			}
		}
		System.out.println(ans);
	}
	 static void pack(int s,int g,HashMap<Integer,Integer> map,int W) {
		 if(s == g) {
			 if(map.containsKey(W)) {
				 map.put(W, map.get(W)+1);
			 }else {
				 map.put(W,1);
			 }
		 }else {
			 pack(s+1,g,map,W);
			 pack(s+1,g,map,W+w[s]);
		 }
	 }
}