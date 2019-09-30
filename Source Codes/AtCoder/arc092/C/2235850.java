import java.util.*;
 
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		boolean[] a = new boolean[N+1];
		long odd = 0;
		long even = 0;
		long max = Long.MIN_VALUE;
		int mp = -1;
		for(int i=1;i<=N;++i){
			long temp = sc.nextLong();
			if(temp>max){
				max = temp;
				mp = i;
			}
			if(temp>0){
				a[i] = true;
				if(i%2==1) odd += temp;
				else even += temp;
			}
		}
		
		if(odd==0 && even==0){
			System.out.println(max);
			System.out.println(N-1);
			for(int i=N;i>mp;--i){
				System.out.println(i);
			}
			for(int i=1;i<mp;++i){
				System.out.println(1);
			}
			return;
		}
		
		System.out.println(Math.max(odd, even));
		int offset = odd>even ? 1 : 0;
		int p = N;		
		ArrayList<Integer> al = new ArrayList<Integer>();
		
		while(!a[p]||(p+offset)%2!=0){
			al.add(p);
			p--;
		}
		
		int left = 0;
		while(!a[left]||(left+offset)%2!=0) left++;
		for(int i=p-2;i>=left;i-=2){
			if(a[i]) al.add(i+1);
			else al.add(i);
		}
		
		for(int i=1;i<left;++i) al.add(1);
		
		System.out.println(al.size());
		for(int i=0;i<al.size();i++){
			System.out.println(al.get(i));
		}
		return;
	}
}