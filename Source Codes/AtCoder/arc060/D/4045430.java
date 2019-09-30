import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String str=sc.next();
		int[] a=mp(str);
		int n=str.length();
		
		int shuki=n-a[n];
		if(shuki==1){
			System.out.println(n);
			System.out.println(1);
		}else if(n%shuki!=0 || shuki==n){
			System.out.println(1);
			System.out.println(1);
		}else{
			System.out.println(2);
			StringBuilder restr=new StringBuilder();
			for(int i=n-1;i>=0;i--) restr.append(str.charAt(i));
			int[] b=mp(restr.toString());
			int count=0;
			for(int i=0;i<n;i++){//0 to i , i+1 to n-1
				int shuki1=i+1-a[i+1];
				if(shuki1!=(i+1) && (i+1)%shuki1==0) continue;
				//0 to n-i-2
				int shuki2=n-i-1-b[n-i-1];
				if(shuki2!=(n-i-1) && (n-i-1)%shuki2==0) continue;
				count++;
			}
			System.out.println(count);
		}
	}
	static int[] mp(String str){
		int n=str.length();
		int[] a=new int[n+1];
		a[0]=-1;
		int j=-1;
		for(int i=0;i<n;i++){
			while(j>=0 && str.charAt(i)!=str.charAt(j)) j=a[j];
			j++;
			a[i+1]=j;
		}
		return a;
	}
}