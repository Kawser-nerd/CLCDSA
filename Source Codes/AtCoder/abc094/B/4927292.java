import java.util.Scanner;

public class Main {
	public static void main(String... args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
int f=-1;
long a[]=new long[m+1];
a[0]=-3;
for(int i=1;i<=m;i++){
	a[i]=sc.nextLong();
if(a[i-1]<x&&a[i]>x){
	f=i;
}
}

System.out.println(Math.min(f-1, m-f+1));

	}}