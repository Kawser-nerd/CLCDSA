import java.util.*;
 
class Sushi{
	long v;
	long x;
	public Sushi(long a,long b){
		x = a;
		v = b;
	}
}

public class Main{	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long C = sc.nextLong();
		long ans = 0;
		if(N==1){
			long position = sc.nextLong();
			long value = sc.nextLong();
			long distance = Math.min(position, C-position);
			if(value > distance) System.out.println(value-distance);
			else System.out.println(0);
			return;
		}
		
		ArrayList<Sushi> al = new ArrayList<Sushi>();
		for(int i=0;i<N;++i) al.add( new Sushi(sc.nextLong(),sc.nextLong()) );
		Collections.sort( al, new Comparator<Sushi>(){
	        public int compare(Sushi a, Sushi b){
	          if(a.x >= b.x) return 1;
	          else return -1;
	        }
	    });
		
		long[] calL = new long[N];
		calL[0] = al.get(0).v;
		for(int i=1;i<N;++i) calL[i] = calL[i-1] + al.get(i).v;
		for(int i=0;i<N;++i) calL[i] -= al.get(i).x;
		long[] calR = new long[N];
		calR[N-1] = al.get(N-1).v;
		for(int i=N-2;i>=0;--i) calR[i] = calR[i+1] + al.get(i).v;
		for(int i=N-1;i>=0;--i) calR[i] -= (C-al.get(i).x);
		
		long[] maxL = new long[N];
		maxL[0] = Math.max(0, calL[0]);
		for(int i=1;i<N;++i) maxL[i] = Math.max(calL[i], maxL[i-1]);	
		ans = Math.max(ans, maxL[N-1]);
		long[] maxR = new long[N];
		maxR[N-1] = Math.max(0, calR[N-1]);
		for(int i=N-2;i>=0;--i) maxR[i] = Math.max(calR[i], maxR[i+1]);
		ans = Math.max(ans, maxR[0]);
		
		long now = 0;
		for(int i=0;i<N-1;++i){
			now += al.get(i).v;
			ans = Math.max(ans, maxR[i+1]+now-2*al.get(i).x);
		}
		now = 0;
		for(int i=N-1;i>0;--i){
			now += al.get(i).v;
			ans = Math.max(ans, maxL[i-1]+now-2*(C-al.get(i).x));
		}
		
		System.out.println(ans);
		return;
	}
}