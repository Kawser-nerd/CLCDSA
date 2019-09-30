import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long[] a=new long[n];
		for(int i=0;i<n;i++)a[i]=sc.nextLong();
		
		int left=1,right=n+1;
		while(left<right){
			int mid=(left+right)/2+(int)(Math.random()*2);
			if(check(a,mid)) right=mid;
			else left=mid+1;
		}
		System.out.println(left);
	}
	static long[][] stack=new long[1000000][2];
	static boolean check(long[] a,int v){
		int n=a.length;
		int size=0;
		long plength=0;
		try{
			for(int i=0;i<n;i++){
				if(a[i]>plength){
					stack[size][0]=0;
					stack[size++][1]=a[i]-plength;
				}else{
					long kezu=plength-a[i];
					while(kezu>0){
						long kou=Math.min(kezu,stack[size-1][1]);
						kezu-=kou;
						stack[size-1][1]-=kou;
						if(stack[size-1][1]==0) size--;
					}
					int ind=size-1;
					long clength=a[i];
					while(stack[ind][0]==(v-1)){
						clength-=stack[ind][1];
						ind--;
					}
					long ch=stack[ind][0]+1;
					stack[ind][1]--;
					clength--;
					if(stack[ind][1]==0)ind--;
					size=ind+1;
					stack[size][0]=ch;
					stack[size++][1]=1;
					clength++;
					if(clength<a[i]){
						stack[size][0]=0;
						stack[size++][1]=a[i]-clength;
					}
				}
				plength=a[i];
			}
		}catch(Exception e){return false;}
		return true;
	}
}