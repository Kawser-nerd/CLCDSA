import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  long ans=0;
  long a[]=new long[100001];
  long k=Long.parseLong(sc.next());
  for(int i=0;i<n;i++){
  	int po=sc.nextInt();
  	a[po]+=sc.nextInt();
  }
  for(int i=0;i<100001;i++){
  	ans+=a[i];
    if(ans>=k){
    System.out.println(i);
      break;
    }
  }}
}