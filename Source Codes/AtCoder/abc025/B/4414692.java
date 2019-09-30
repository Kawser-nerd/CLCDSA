import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int a=sc.nextInt();
  int b=sc.nextInt();
  int ans=0;
  for(int i=0;i<n;i++){
    String po=sc.next();
    int c=sc.nextInt();
  ans+=(po.equals("East"))?(c<a)?a:(b<c)?b:c:(c<a)?-a:(b<c)?-b:-c;
  }
  System.out.println((ans==0)?0:(ans>0)?"East "+ans:"West "+(-ans));
}}