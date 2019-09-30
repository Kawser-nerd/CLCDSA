import java.util.HashMap;
import java.util.Scanner;

public class Main{
	
	static int[] UF1par;
	static int[] UF2par;
	static int[] UF1rank;
	static int[] UF2rank;
	
	
	public static void main(String args[])throws Exception{
		
		Scanner sc= new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int L = sc.nextInt();
		long n = N;
		UF1par = new int[N];
		UF2par = new int[N];
		UF1rank = new int[N];
		UF2rank = new int[N];
		
		for(int i=0;i<N;i++){
			UF1par[i] = i;
			UF2par[i] = i;
		}
		for(int i=0;i<K;i++){
			int p = sc.nextInt();
			int q = sc.nextInt();
			p--;
			q--;
			unite1(p,q);
		}
		for(int i=0;i<L;i++){
			int r = sc.nextInt();
			int s = sc.nextInt();
			r--;
			s--;
			unite2(r,s);

		}
		
		HashMap<Long,Integer> num = new HashMap<Long,Integer>();
		long[] l = new long[N];
		for(int i=1;i<=N;i++){
			long j = find1(i-1);
			long k = find2(i-1);
			l[i-1] = j * n + k;
			
			if(num.containsKey(l[i-1])){
				num.put(l[i-1], num.get(l[i-1])+1);
			}else{
				num.put(l[i-1], 1);
			}
			
			
		}
		for(int i=1;i<=N;i++){
			System.out.print(num.get(l[i-1]) + " ");
		}
		
	}


	private static void unite1(int p, int q) {
		p = find1(p);
		q = find1(q);
		if(p==q){
			return;
			
		}else{
			if(UF1rank[p]<UF1rank[q]){
				
				UF1par[p] = q;
			}else{
				UF1par[q] = p;
				if(UF1rank[p]==UF1rank[q]){
					
					UF1rank[p]++;
				}
			}
		}
	}


	private static int find1(int p) {
		if(UF1par[p]==p){
			return p;
		}else{
			
			return UF1par[p] =find1(UF1par[p]);
		}
	}
	
	private static void unite2(int p, int q) {
		p = find2(p);
		q = find2(q);
		if(p==q){
			return;
			
		}else{
			if(UF2rank[p]<UF2rank[q]){
				
				UF2par[p] = q;
			}else{
				UF2par[q] = p;
				if(UF2rank[p]==UF2rank[q]){
					
					UF2rank[p]++;
				}
			}
		}
	}


	private static int find2(int p) {
		if(UF2par[p]==p){
			return p;
		}else{
			return UF2par[p] = find2(UF2par[p]);
			
		}
	}
	
}