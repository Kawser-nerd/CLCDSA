import java.io.*;
import java.util.*;

class Main{
	int max = 0;
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];
		int[] d = new int[n];
		boolean[] judge = new boolean[n];
		Arrays.fill(judge, true);
		int count = 0;
		for(int i=0;i<n;i++){
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
		for(int i=0;i<n;i++){
			c[i] = sc.nextInt();
			d[i] = sc.nextInt();
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]>a[j]){
					int tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
					tmp = b[i];
					b[i] = b[j];
					b[j] = tmp;
				}
				else if(a[i]==a[j] && b[i]>b[j]){
					int tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
					tmp = b[i];
					b[i] = b[j];
					b[j] = tmp;	
				}
				if(c[i]>c[j]){
					int tmp = c[i];
					c[i] = c[j];
					c[j] = tmp;
					tmp = d[i];
					d[i] = d[j];
					d[j] = tmp;
				}
				else if(c[i]==c[j] && d[i]>d[j]){
					int tmp = c[i];
					c[i] = c[j];
					c[j] = tmp;
					tmp = d[i];
					d[i] = d[j];
					d[j] = tmp;
				}
			}
		}
		for(int i=0;i<n;i++){
			int now = -1;
			int y = -1;
			for(int j=0;j<n;j++){
				if(!judge[j]){
					continue;
				}
				if(a[j]<c[i] && b[j]<d[i]){
					if(y<b[j]){
						now = j;
						y = b[j];
					}
				}
			}
			if(now!=-1){
				count++;
				judge[now] = false;
			}
		}
		System.out.println(count);
	}
}