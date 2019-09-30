import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a=sc.nextInt()-1,b=sc.nextInt()-1;
		long[] x=new long[n+1],y=new long[n+1];
		for(int i=0;i<n;i++){
			long xx=sc.nextLong();
			long yy=sc.nextLong();
			x[i]=xx+yy;
			y[i]=xx-yy;
		}
		long d=Math.max(Math.abs(x[a]-x[b]),Math.abs(y[a]-y[b]));
		
		Comparator<Integer> comp1=(z,w)->{
			if(x[z]!=x[w]) return Long.signum(x[z]-x[w]);
			return Long.signum(y[z]-y[w]);
		};
		Comparator<Integer> comp2=(z,w)->{
			if(y[z]!=y[w]) return Long.signum(y[z]-y[w]);
			return Long.signum(x[z]-x[w]);
		};
		TreeSet<Integer> ts1=new TreeSet<>(comp1);
		TreeSet<Integer> ts2=new TreeSet<>(comp2);
		for(int i=0;i<n;i++){
			ts1.add(i);
			ts2.add(i);
		}
		ts1.remove(a);
		ts2.remove(a);
		int[] stack=new int[n*2];
		int size=0;
		stack[size++]=a;
		int[] stack2=new int[n];
		int size2=0;
		while(size>0){
			int cur=stack[--size];
			long tx=x[cur],ty=y[cur];
			//tx-d,ty-d...ty+d
			x[n]=tx-d;
			y[n]=ty-d-1;
			int count=0;
			Integer ind=ts1.higher(n);
			while((ind!=null) && (x[ind]==(tx-d)) && (y[ind]<=(ty+d))){
				count++;
				ts1.remove(ind);
				ts2.remove(ind);
				stack[size++]=ind;
				ind=ts1.higher(ind);
			}
			
			x[n]=tx+d;
			y[n]=ty-d-1;
			ind=ts1.higher(n);
			while((ind!=null) && (x[ind]==(tx+d)) && (y[ind]<=(ty+d))){
				count++;
				ts1.remove(ind);
				ts2.remove(ind);
				stack[size++]=ind;
				ind=ts1.higher(ind);
			}
			
			x[n]=tx-d-1;
			y[n]=ty-d;
			ind=ts2.higher(n);
			while((ind!=null) && (y[ind]==(ty-d)) && (x[ind]<=(tx+d))){
				count++;
				ts1.remove(ind);
				ts2.remove(ind);
				stack[size++]=ind;
				ind=ts2.higher(ind);
			}
			
			x[n]=tx-d-1;
			y[n]=ty+d;
			ind=ts2.higher(n);
			while((ind!=null) && (y[ind]==(ty+d)) && (x[ind]<=(tx+d))){
				count++;
				ts1.remove(ind);
				ts2.remove(ind);
				stack[size++]=ind;
				ind=ts2.higher(ind);
			}
			stack2[size2++]=cur;
		};
		Integer[] hai1=new Integer[size2],hai2=new Integer[size2];
		for(int i=0;i<size2;i++){
			hai1[i]=stack2[i];
			hai2[i]=stack2[i];
		}
		Arrays.sort(hai1,comp1);
		Arrays.sort(hai2,comp2);
		
		long res=0;
		for(int i=0;i<size2;i++){
			int ind=stack2[i];
			
			long tx=x[ind],ty=y[ind];
			
			x[n]=tx-d;
			y[n]=ty-d;
			int higher =Arrays.binarySearch(hai1,n,comp1);
			if(higher>=0) higher++;
			else higher=-1-higher;
			
			y[n]=ty+d;
			int lower=Arrays.binarySearch(hai1,n,comp1);
			if(lower>=0) lower--;
			else lower=-2-lower;
			res+=lower-higher+1;
			
			x[n]=tx+d;
			y[n]=ty-d;
			higher =Arrays.binarySearch(hai1,n,comp1);
			if(higher>=0) higher++;
			else higher=-1-higher;
			
			y[n]=ty+d;
			lower=Arrays.binarySearch(hai1,n,comp1);
			if(lower>=0) lower--;
			else lower=-2-lower;
			res+=lower-higher+1;
			
			x[n]=tx-d;
			y[n]=ty-d;
			higher =Arrays.binarySearch(hai2,n,comp2);
			if(higher<0) higher=-1-higher;
			
			x[n]=tx+d;
			lower=Arrays.binarySearch(hai2,n,comp2);
			if(lower<0) lower=-2-lower;
			res+=lower-higher+1;
			
			x[n]=tx-d;
			y[n]=ty+d;
			higher =Arrays.binarySearch(hai2,n,comp2);
			if(higher<0) higher=-1-higher;
			
			x[n]=tx+d;
			lower=Arrays.binarySearch(hai2,n,comp2);
			if(lower<0) lower=-2-lower;
			res+=lower-higher+1;
		}
		System.out.println(res/2);
	}
}