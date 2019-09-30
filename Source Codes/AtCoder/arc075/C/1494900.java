import java.io.*;
import java.util.*;
import java.text.*;
public class Main {
	static class Node implements Comparable<Node>{
		int t,y,l,r;
		public Node(int t,int y,int l,int r){
			this.t=t;
			this.y=y;
			this.l=l;
			this.r=r;
		}
		@Override
		public int compareTo(Node arg0) {
			// TODO Auto-generated method stub
			if(this.y==arg0.y){
				if(this.t>arg0.t)return 1;
				else return -1;
			}
			else{
				if(this.y>arg0.y)return 1;
				else return -1;
			}
		}
		
	}
	static StreamTokenizer in=new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static PrintWriter out=new PrintWriter(new OutputStreamWriter(System.out));
	static int nextInt()throws IOException{
		in.nextToken();
		return (int)in.nval;
	}
	static int n,m=200000,s,time,x1,y1,x2,y2,temp,ed,aed;
	static long ans,k;
	static long[] f=new long[200002];
	static long[] a=new long[200002];
	static long[] b=new long[200002];
	static HashMap<Long,Integer> hm=new HashMap<Long,Integer>();
	static int lowb(int x){
		return x&(-x);
	}
	static long sum(int x){
		long ans=0;
		while(x>0){
			ans+=f[x];
			x-=lowb(x);
		}
		return ans;
	}
	static void add(int x,int p){
		while(x<=m){
			f[x]+=p;
			x+=lowb(x);
		}
	}
	public static void main(String args[])throws IOException{
		n=nextInt();
		k=nextInt();
		for(int i=1;i<=n;i++){
			a[i]=a[i-1]+nextInt()-k;
			b[i]=a[i];
		}	
		Arrays.sort(b,1,n+1);
		hm.clear();
		ed=0;
		for(int i=1;i<=n;i++){
			if(!hm.containsKey(b[i]))hm.put(b[i],++ed);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=0)ans++;
			ans+=sum(hm.get(a[i]));
			add(hm.get(a[i]),1);
		}
		out.println(ans);
		out.flush();	
	}
}