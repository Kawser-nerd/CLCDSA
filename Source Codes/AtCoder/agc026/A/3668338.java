import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] a=new int[n];
		for(int i=0;i<n;i++)a[i]=sc.nextInt();
		
		int res=0;
		for(int i=0;i<n;i++){
			int c=a[i];
			int j=i;
			while((j<n)&&(c==a[j]))j++;
			j--;
			res+=(j-i+1)/2;
			i=j;
		}
		pl(res);
	}
	static void pl(Object o){System.out.println(o);}
}