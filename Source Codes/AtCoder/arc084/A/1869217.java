import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

class Main{
	static Scanner s=new Scanner(System.in);
	static int gInt(){
		return Integer.parseInt(s.next());
	}
	public static void main(String[]$){
		int n=gInt();
		int[] a=in(n),
				b=in(n),
				c=in(n);
		long[] v1=new long[n],v2=new long[n];
		{
			int v=0;
			for(int i=0;i<n;++i){
				for(;v<n&&a[v]<b[i];++v){
				}
				v1[i]=v;
			}
		}
		Arrays.parallelPrefix(v1,Long::sum);
		{
			int v=0;
			for(int i=0;i<n;++i){
				for(;v<n&&b[v]<c[i];++v){
				}
				v2[i]=v==0?0:v1[v-1];
			}
		}
		System.out.println(Arrays.stream(v2).sum());
	}
	static int[] in(int n){
		return IntStream.range(0,n).map(i->gInt()).sorted().toArray();
	}
}