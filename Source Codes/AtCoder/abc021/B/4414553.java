import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int []po=new int[n+1];
  po[sc.nextInt()]++;po[sc.nextInt()]++;
  int m=sc.nextInt();
  for(int i=0;i<m;i++)po[sc.nextInt()]++;
  boolean b=true;
  for(int i=0;i<n+1;i++){
    if(po[i]>1){b=false;break;}
  }
  System.out.println(b?"YES":"NO");
}}