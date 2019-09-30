import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int m=sc.nextInt();
  long ans=0;
  long po[]=new long[n+1];
  po[0]=0;
  for(int i=1;i<=n;i++)po[i]=po[i-1]+sc.nextInt();
  for(int i=m;i<=n;i++)
      ans+=(po[i]-po[i-m]);
System.out.println(ans);
}

}