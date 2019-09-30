import java.util.*;
public class Main{
  public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
    int n=sc.nextInt()-1;
    final int mod=10007;
    int[] a=new int[3];
    a[2]=1;
    for(int i=0;i<n/3;i++){
      a[0]=(a[0]+a[1]+a[2])%mod;
      a[1]=(a[0]+a[1]+a[2])%mod;
      a[2]=(a[0]+a[1]+a[2])%mod;
    }
    System.out.println(a[n%3]);

	}
}