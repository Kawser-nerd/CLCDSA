import static java.lang.System.*;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(in);
		
		int n = sc.nextInt();
		int[] num = new int[n];
		
		for(int i=0; i<n; i++) num[i] = sc.nextInt();
		Arrays.sort(num);
		
		int[] ans = new int [2];
		Arrays.fill(ans, -1);
		for(int i=n-1; i>0; i--) {
			int l = 0;
			int h = i-1;
			
			int mid = l;
			while(l < h) {
				mid = (l+h)/2;
				
				if(num[mid] < num[i] / 2) l = mid;
				else if(num[mid] > num[i] / 2) h = mid;
				else break;
				
				if(l == h-1) {
					if(Math.abs(num[l] - num[i] / 2) < Math.abs(num[h] - num[i] / 2)) mid = l;
					else mid = h;
					
					break;
				}
				
			}
			
			if(ans[0] == -1 && ans[1] == -1) {
				ans[0] = num[i];
				ans[1] = num[mid];
				//continue;
				break;
			}
			
			/*
			if(ans[0] > num[i] && ans[1] > num[mid]) continue;
			
			BigInteger b = new BigInteger("1");
			BigInteger a = new BigInteger("1");
			
			for(int j=ans[0]; j>num[i]; j--) b = b.multiply(new BigInteger("" + j));

			int bs = ans[0] - ans[1] + 1;
			int as = num[i] - num[mid] + 1;
			if(bs > as) for(int j=bs-1; j>=as; j--) a = a.multiply(new BigInteger("" + j));
			else if(bs < as) for(int j=as-1; j>=bs; j--) b = b.multiply(new BigInteger("" + j));
			
			if(ans[1] > num[mid]) for(int j=ans[1]; j>num[mid]; j--) a = a.multiply(new BigInteger("" + j));
			else if(ans[1] < num[mid]) for(int j=num[mid]; j>ans[1]; j--) b = b.multiply(new BigInteger("" + j));
			
			out.println(ans[0] + " " + ans[1] + " , " + num[i] + " " + num[mid] + " , " + b + " " + a);
			
			if(b.compareTo(a) < 0) {
				ans[0] = num[i];
				ans[1] = num[mid];
			}
			*/
		}
		
		out.println(ans[0] + " " + ans[1]);
		
		return;
	}

}