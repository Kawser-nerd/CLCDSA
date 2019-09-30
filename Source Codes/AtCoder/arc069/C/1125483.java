import java.io.PrintWriter;
import java.util.*;

public class Main {
	static final long MOD = 1000000007;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);

		int N = sc.nextInt();
		int[] a = new int[N];
		ArrayList<Integer> index = new ArrayList<>();
		ArrayList<Integer> value = new ArrayList<>();
		for(int i=0; i<N; i++) {
			a[i] = sc.nextInt();
			if(index.size()==0 || value.get(value.size()-1) < a[i]) {
				index.add(i);
				value.add(a[i]);
			}
		}
		index.add(N);
		value.add(Integer.MAX_VALUE);
		
		long[] sum = new long[index.size()+1];
		Arrays.sort(a);
		int p=0;
		for(int i=0; i<N; i++) {
			if(value.get(p)<=a[i]) {
				sum[p] += ((long)N-i)*(value.get(p)-(p>0 ? value.get(p-1) : 0));
				p++;
			}
			sum[p] += a[i]-(p>0 ? value.get(p-1) : 0);
		}
		
		long[] ans = new long[N];
		for(int i=0; i<index.size()-1; i++)
			ans[index.get(i)] = sum[i];
		for(int i=0; i<N; i++)
			pw.println(ans[i]);
		
		sc.close();
		pw.close();
	}
}