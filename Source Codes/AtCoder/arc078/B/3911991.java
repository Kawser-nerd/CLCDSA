import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] a=new int[n-1],b=new int[n-1];
		for(int i=0;i<n-1;i++){
			a[i]=sc.nextInt();
			b[i]=sc.nextInt();
		}
		
		int[][] ad=get(n,a,b);
		
		int[] dist1=new int[n+1],dist2=new int[n+1];
		int[] stack=new int[n*2];
		int size=0;
		stack[size++]=1;
		while(size>0){
			int cur=stack[--size];
			for(int ch:ad[cur]){
				if(ch==1 || dist1[ch]!=0) continue;
				dist1[ch]=dist1[cur]+1;
				stack[size++]=ch;
			}
		}
		
		stack[size++]=n;
		while(size>0){
			int cur=stack[--size];
			for(int ch:ad[cur]){
				if(ch==n || dist2[ch]!=0)continue;
				dist2[ch]=dist2[cur]+1;
				stack[size++]=ch;
			}
		}
		
		int count=0;
		for(int i=1;i<=n;i++){
			if(dist1[i]<=dist2[i]) count++;
			else count--;
		}
		if(count>0) System.out.println("Fennec");
		else System.out.println("Snuke");
	}
	static int[][] get(int n,int[] a,int[] b){
		int[][] res=new int[n+1][];
		int[] c=new int[n+1];
		for(int i=0;i<a.length;i++){
			c[a[i]]++;
			c[b[i]]++;
		}
		for(int i=0;i<=n;i++) res[i]=new int[c[i]];
		for(int i=0;i<a.length;i++){
			res[a[i]][--c[a[i]]]=b[i];
			res[b[i]][--c[b[i]]]=a[i];
		}
		return res;
	}
}