//Author: Fluorine
import java.math.*;
import java.util.*;

public class C{
	public static int[] a;
	
	public static int find(int k,int x){
		int low=1;
		int up=k;
		while (low<up){
			int mid=(low+up)/2;
			if (a[mid]<=x) low=mid+1;
			else up=mid;
		}
		return low;
	}
	
	public static void main(String args[]){
		a=new int[1000001];
		a[1]=2;
		a[2]=4;
		for (int i=3;i<=1000000;++i)
			a[i]=find(i-1,i)+i;
		Scanner scanner=new Scanner(System.in);
		int caseNumber=scanner.nextInt();
		for (int cases=0;cases<caseNumber;++cases){
			int a1=scanner.nextInt();
			int a2=scanner.nextInt();
			int b1=scanner.nextInt();
			int b2=scanner.nextInt();
			BigInteger ans=new BigInteger("0");
			for (int i=a1;i<=a2;++i){
				int up=b2;
				int low=a[i];
				if (b1>low) low=b1;
				if (low>up) continue;
				ans=ans.add(new BigInteger(Integer.toString(up-low+1)));
			}
			for (int i=b1;i<=b2;++i){
				int up=a2;
				int low=a[i];
				if (a1>low) low=a1;
				if (low>up) continue;
				ans=ans.add(new BigInteger(Integer.toString(up-low+1)));
			}
			System.out.println("Case #"+(cases+1)+": "+ans);
		}
	}
}