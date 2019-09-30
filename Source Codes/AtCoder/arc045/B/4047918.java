import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		int[] a=new int[m],b=new int[m];
		SegSumMin ssm=new SegSumMin(n);
		for(int i=0;i<m;i++){
			a[i]=sc.nextInt()-1;
			b[i]=sc.nextInt()-1;
			ssm.add(a[i],b[i],1);
		}
		int[] stack=new int[m];
		int size=0;
		for(int i=0;i<m;i++){
			long min=ssm.min(a[i],b[i]);
			if(min>1) stack[size++]=i;
		}
		System.out.println(size);
		for(int i=0;i<size;i++) System.out.println(stack[i]+1);
	}
}
class SegSumMin{
	int size,n;//size=n*2
	long[] arr;
	long[] lazy;
	public SegSumMin(int n){
		this.n=(n==1)?1:Integer.highestOneBit(n-1)*2;
		size=this.n*2;
		arr=new long[size];
		lazy=new long[size];
		for(int i=this.n+n;i<size;i++) arr[i]=Long.MAX_VALUE/10;
	}
	void add(int left,int right,long v){//right included 0 index
		left+=n;
		right+=n;
		int lc=left,rc=right;
		propagate(left);
		propagate(right);
		
		for(;left<=right;left=(left+1) >> 1 , right=(right-1) >> 1){
			if((left & 1) == 1) lazy[left]+=v;
			if((right & 1) == 0) lazy[right]+=v;
		}
		popUp(lc);
		popUp(rc);
	}
	void popUp(int i){
		for(;i>1;i=(i>>1)) arr[i>>1]=Math.min(arr[i]+lazy[i],arr[i^1]+lazy[i^1]);
	}
	long min(int left,int right){
		left+=n;
		right+=n;
		propagate(left);
		propagate(right);
		
		long res=Long.MAX_VALUE/10;
		for(;left<=right;left=(left+1) >> 1, right=(right-1) >> 1){
			if((left & 1) == 1) res=Math.min(res,arr[left]+lazy[left]);
			if((right & 1 ) == 0) res=Math.min(res,arr[right]+lazy[right]);
		}
		return res;
	}
	void propagate(int i){
		int k=0;
		while((i>>k)>0) k++;
		k--;
		for(;k>=0;k--){
			long v=lazy[(i>>k)];
			lazy[(i>>k)]=0;
			arr[(i>>k)]+=v;
			if(k==0) break;
			lazy[(i>>k)*2]+=v;
			lazy[(i>>k)*2+1]+=v;
		}
	}
}