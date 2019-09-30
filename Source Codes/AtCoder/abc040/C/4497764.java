import java.util.*;
public class Main{
  public static void main(String[]args){
  Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
    int a[]=new int[n];
    int b[]=new int[n];
    for(int i=0;i<n;i++)a[i]=sc.nextInt();
    b[0]=0;
    b[1]=Math.abs(a[0]-a[1]);
    for(int i=2;i<n;i++){
    	b[i]=Math.min(b[i-1]+Math.abs(a[i]-a[i-1]),b[i-2]+Math.abs(a[i]-a[i-2]));
    }
    System.out.println(b[n-1]);
  }
}