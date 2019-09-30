import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;




class Main{


	static	ArrayList<Integer> one ;
	static	ArrayList<Integer> two ;
	static	ArrayList<Integer> three ;
	static	ArrayList<Integer> four ;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);			//?????
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		long[] v =  new long[n];

		for(int i = 0;i < n;i++){
			v[i] = sc.nextLong();
		}
		Arrays.sort(v);
		int j = 0;
		for(int i = 0;i < n;i++){
			if(v[n-1-i] == v[n-1]){
				j++;
			}
		}
		

		long[][] pdp = new long[51][51];
		pdp[0][0] = 1;
		for (int x = 1; x <= 50; x++) {				//??????????
			for (int k = 0; k <= x; k++) {
				if (k - 1 >= 0) {
					pdp[x][k] = pdp[x-1][k-1] + pdp[x-1][k];
				} else {
					pdp[x][k] = pdp[x-1][k];
				}
			}
		}

		if(j <= a){
			long sum = 0;
			for(int i = 0;i < a;i++){
				sum += v[n-1-i];
			}

			double ans = (double)sum/a;

			int c = 0;

			for(int i = 0;i < n;i++){				//??????
				if(v[i] == v[n-a]){
					c++;
				}
			}
			int h = 0;
			for(int i = 0;i < n;i++){
				if(v[i] > v[n-a]){
					h++;
				}
			}
			
			
			long ansnum = pdp[c][c-(a-h)];
			


			System.out.println(ans);
			System.out.println(ansnum);
			
		}else{		
			long sum = 0;
			for(int i = 0;i < a;i++){
				sum += v[n-1-i];
			}
			double ans = (double)sum/a;
			
			
			int c = 0;
			for(int i = 0;i < n;i++){				//????????????????
				if(v[i] == v[n-1]){
					c++;
				}
			}


			long ansc = 0;
			
			
			for(int i = a;i <= Math.min(c, b);i++){
				ansc += pdp[c][i];
			//System.out.println(pdp[c][i]);

			}
			
			System.out.println(ans);
			System.out.println(ansc);
			
			
			
		}




	}
	
	static long sum(long ue,long sita){
		long counter = sita;
		long u = 1;
		for(long i = 0;i < counter;i++){
			u *= ue;
			ue--;
		}
		long s = 1;
		for(long i = 0;i < counter;i++){
			s *= sita;
			sita--;
		}
		
		return u/s;
		
	}
}

class Pair implements Comparable{
	Character from;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}