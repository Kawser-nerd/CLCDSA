import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main m = new Main();
		m.run();
	}

	Scanner sc = new Scanner(System.in);

		
	int dk(long k){
		int count =0;
		while(k>0){
			k /= 10;
			count++;
		}
		return count;
	}
	
	long[] magic(int d){
		long[] res= new long[d+1];
		
		long x = 9;
		long y = 10;
		for(int i = 0; i < d; i++){
			y*=10;
		}
		
		long r = y;
		for(int i =0 ;i<d+1;i++){
			r += x;
			res[i] = r;
			x *= 10;
		}
		return res;
	}
	
	int s(long i){
		return  (int)((i/1000000000000000L)%10+				
				(i/100000000000000L)%10+
				(i/10000000000000L)%10+
				(i/1000000000000L)%10+
				(i/100000000000L)%10+
				(i/10000000000L)%10+
				(i/1000000000L)%10+
				(i/100000000L)%10+
				(i/10000000L)%10+
				(i/1000000L)%10+
				(i/100000L)%10+
				(i/10000L)%10+
				(i/1000L)%10+
				(i/100L)%10+
				(i/10L)%10+
				(i/1L)%10);
	}

	
	boolean comp(long x, long y){
		return (s(x)*y < s(y)*x);
	}
	
	void run() {
		
		
		long k = sc.nextLong();
		LinkedList<String> c = new LinkedList<String>();
		
		for(int i = 1; i < 10 ;i++){
			c.addFirst(i+"");
		}
		for(int i = 1; i < 10 ;i++){
			c.addFirst(i+"9");
		}
		for(int d = 1; d<14; d++){
			long[] cand = magic(d);
			int x = d;
			for(; x > 0 ;x--){
				if(!comp(cand[x], cand[x-1])){
					break;
				}
			}
			
			int d9 = x+1;
			long m9 = 9;
			long p = 0;
			for(int i = 0 ; i < d9;i++){
				p+=m9;
				m9*=10;
			}
			int rem = d-x;
			int xx = 1;
			for(int i = 0 ; i < rem; i++){
				xx *= 10;
			}
			
			for(int y = xx ; y < xx*10;y++){
				c.addFirst((y + ""+p));
			}
		}
		
		
		long minX = Long.valueOf(c.get(0));
		long minS = s(minX);
		
		LinkedList<Long> ans = new LinkedList<Long>();
		
		for(String ss: c){
			long xx = Long.valueOf(ss);
			long sss = s(xx);
			
			
			if(xx*minS <= minX*sss){
				minX = xx;
				minS = sss;
				ans.addFirst(xx);
			}
		}
		
		for(Long v: ans){
			System.out.println(v);
			k--;
			if(k==0){
				break;
			}
		}
		
	}
}