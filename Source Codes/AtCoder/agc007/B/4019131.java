import java.util.*;
import java.util.stream.*;

class Main{
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);
		
		int n=s.nextInt();
		int[]v=new int[n];
		int[]a=new int[n];
		int[]b=new int[n];
		Arrays.setAll(v,i->s.nextInt()-1);
		Arrays.setAll(a,i->i+1);
		Arrays.setAll(b,i->n-i);
		
		for(int i=1;i<n;++i) {
			for(int j=v[i];j<n;++j)
				a[j]+=i;
			for(int j=v[i];j>=0;--j)
				b[j]+=i;
		}
		
		System.out.println(Arrays.stream(a).mapToObj(String::valueOf).collect(Collectors.joining(" ")));
		System.out.println(Arrays.stream(b).mapToObj(String::valueOf).collect(Collectors.joining(" ")));
	}
}