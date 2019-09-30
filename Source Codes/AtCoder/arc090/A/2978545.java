import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int[] a1=new int[n];
		int[] a2=new int[n];
		int[] s1=new int[n];
		int[] s2=new int[n];
		
		for(int i=0;i<n;i++) a1[i]=sc.nextInt();
		for(int i=0;i<n;i++) a2[i]=sc.nextInt();
		
		s1[0]=a1[0]; s2[n-1]=a2[n-1];
		for(int i=1;i<n;i++) s1[i]=s1[i-1]+a1[i];
		for(int i=n-2;i>=0;i--) s2[i]=s2[i+1]+a2[i];
		
		int score=0;
		for(int i=0;i<n;i++) score=Math.max(score, s1[i]+s2[i]);
		
		System.out.println(score);
	}
}