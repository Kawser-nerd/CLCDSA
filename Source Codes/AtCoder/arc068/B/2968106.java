import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a=new int[n];
		int[] b=new int[100005];
		for(int i=0;i<n;i++){
			a[i]=sc.nextInt();
			b[a[i]]++;
		}
		
		int pair=0;
		long sum=0;
		for(int i=0;i<b.length;i++){
			if(b[i]>=3) {
				b[i] = (b[i]%2==0)? 2:1; 
			}
			if(b[i]==1)sum++;
			if(b[i]==2){sum+=2;pair++;}
		}
		sum-= (pair%2==0)?pair:pair+1;
		
		System.out.println(sum);
	}
}