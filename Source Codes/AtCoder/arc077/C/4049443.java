import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int[] a=new int[n];
		for(int i=0;i<n;i++) a[i]=sc.nextInt();
		
		int[][] hai=new int[n][];
		int size=0;
		for(int i=0;i<n;i++){
			int j=i+1;
			while((j<n) && (a[j]>a[j-1])) j++;
			j--;
			hai[size]=new int[j-i+1];
			for(int k=i;k<=j;k++){
				hai[size][k-i]=a[k];
			}
			i=j;
			size++;
		}
		hai=Arrays.copyOf(hai,size);
		
		long[] pref=new long[m];
		Arrays.fill(pref,size);
		
		for(int i=0;i<a[0];i++)pref[i]--;
		for(int i=a[n-1]+1;i<m;i++)pref[i]--;
		
		for(int i=1;i<n;i++){
			long dist=(a[i]-a[i-1]+m)%m;
			if(a[i]==m)continue;
			pref[a[i]]-=dist;
		}
		
		long[] sum=new long[m];
		long t=0;
		long max=0;
		int ind=0;
		for(int i=0;i<m;i++){
			t+=pref[i];
			if(t>max){
				max=t;
				ind=i;
			}
		}
		
		long res=0;
		int cur=a[0];
		for(int i=1;i<n;i++){
			if(a[i]>cur){
				if((cur<(ind+1)) && ((ind+1)<=a[i])){
					res+=a[i]-cur-(ind-cur);
				}
				else res+=a[i]-cur;
			}else{
				int dist=(ind+1-cur+m)%m;
				int dist2=(a[i]-cur+m)%m;
				if((dist>0)&&(dist<=dist2)){
					res+=dist2-dist+1;
				}else res+=dist2;
			}
			cur=a[i];
		}
		pl(res);
	}
	static void pl(Object o){
		System.out.println(o);
	}
}