import java.util.*;
public class Main{
public static void main(String[]args){
  Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
    int m=sc.nextInt();
 String po=Integer.toBinaryString(m);
 while(po.length()<n)po="0"+po;
 String p[]=po.split("",0);
 int ans=0;
 for(int i=0;i<n;i++){
     int k=sc.nextInt();
     ans+=(p[n-1-i].equals("1"))?k:0;
 }
 System.out.println(ans);
}

}