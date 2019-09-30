import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long[] a=new long[n];
		boolean all=true;
		for(int i=0;i<n;i++){
			a[i]=sc.nextLong();
			if(a[i]>=0) all=false;
		}
		if(all){
			int ind=0;
			for(int i=0;i<n;i++){
				if(a[i]>a[ind]) ind=i;
			}
			System.out.println(a[ind]);
			System.out.println(n-1);
			for(int i=0;i<ind;i++) System.out.println(1);
			for(int i=ind+1;i<n;i++) System.out.println(n-i+1);
			return;
		}
		
		long os=0,es=0;
		int[] stack=new int[n];
		int size=0;
		for(int i=0;i<n;i++){
			if(a[i]<0) continue;
			if(i%2==0) es+=a[i];
			else os+=a[i];
		}
		
		System.out.println(Math.max(os,es));
		int[] ta=new int[n];
		int p=os>es?1:0;
		
		int count=0;
		for(int i=0;i<n;i++){
			if(i%2!=p || a[i]>=0) continue;
			stack[size++]=(i-count);
			ta[i]++;
			if((i-count)==0 || i==(n-1)) count+=1;
			else{
				count+=2;
				ta[i]*=2;
			}
		}
		count=0;
		for(int i=0;i<n;i++){
			count+=ta[i];
			if(i%2==p) continue;
			if((i>0) && (ta[i-1]>1)) continue;
			stack[size++]=i-count;
			if((i-count)==0 || i==(n-1)) count+=1;
			else count+=2;
		}
		System.out.println(size);
		for(int i=0;i<size;i++) System.out.println(stack[i]+1);
	}
}