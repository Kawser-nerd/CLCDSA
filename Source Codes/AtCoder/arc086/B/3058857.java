import java.util.*;

class Main{
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[]a=new int[n];
		Arrays.setAll(a,i->s.nextInt());
		
		ArrayList<String>r=new ArrayList<>();
		
		int m=0;
		for(int i=1;i<n;++i)
			if(Math.abs(a[m])<Math.abs(a[i]))
				m=i;
		
		for(int i=0;i<n;++i)
			if(a[m]>=0^a[i]>=0)
				r.add(m+1+" "+(i+1));
		if(a[m]>=0) {
			for(int i=1;i<n;++i)
				r.add(i+" "+(i+1));
		}else {
			for(int i=n;i>1;--i)
				r.add(i+" "+(i-1));
		}
		
		System.out.println(r.size());
		r.forEach(System.out::println);
	}
}