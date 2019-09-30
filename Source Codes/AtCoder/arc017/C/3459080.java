import java.util.*;
public class Main{
	static int power(int n, int x){
		int ans = 1;
		while(x!=0){
			if(x%2==1){
				ans *= n;
				x--;
			}
			else{
				n *= n;
				x /= 2;
			}
		}
		return ans;
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int[] w = new int[n];
		for(int i=0; i<n; i++){
			w[i] = sc.nextInt();
		}
		int a = n / 2;
		int b = n - a;
		int lena = power(2, a);
		int lenb = power(2, b);
		int[] paca = new int[lena];
		int[] pacb = new int[lenb+1];
		for(int i=0; i<Math.pow(2, a); i++){
			for(int j=0; j<a; j++){
				if((1&i>>j)==1){
					paca[i] += w[j];
				}
			}
		}
		for(int i=0; i<Math.pow(2, b); i++){
			for(int j=0; j<b; j++){
				if((1&i>>j)==1){
					pacb[i] += w[a+j];
				}
			}
		}
		pacb[lenb] = -1;
		Arrays.sort(paca);
		Arrays.sort(pacb);
		int ans = 0;
		int r = lenb;
		int l = r;
		for(int i=0; i<lena; i++){
			if(paca[i]>x){
				break;
			}
			else if(i>=1 && paca[i]==paca[i-1]){
				ans += r - l;
			}
			else{
				r = l;
				while(pacb[r]>x-paca[i]){
					r--;
				}
				l = r;
				while(pacb[l]==x-paca[i]){
					l--;
				}
				ans += r - l;
			}
		}
		System.out.println(ans);
	}
}