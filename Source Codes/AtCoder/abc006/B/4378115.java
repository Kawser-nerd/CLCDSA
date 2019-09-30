import java.util.*;
public class Main{
  public static void main(String[]args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int a[]=new int[n];
    if(n>=3){
    a[0]=0;a[1]=0;a[2]=1;}
    for(int i=3;i<n;i++){
    	a[i]=(a[i-1]+a[i-2]+a[i-3])%10007;
    }
    if(n==1||n==2){
    System.out.println(0);
    }
    else if(n==3)System.out.println(1);
      else System.out.println(a[n-1]);
  }
}