import java.util.Scanner;
class Main
{
public static void main (String [] args)
{
Scanner sc=new Scanner(System.in);
int n=sc.nextInt();
int x=sc.nextInt();int y=sc.nextInt();
int []a=new int [n];
for(int i=0;i<n;i++)
a[i]=sc.nextInt();
int max=Math.abs(a[n-1]-y);
if(n!=1)
max=Math.max(max,Math.abs(a[n-1]-a[n-2]));
System.out.println(max);
}
}