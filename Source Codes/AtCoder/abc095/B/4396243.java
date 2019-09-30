import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();int m=sc.nextInt();
	int po[]=new int[n];
  for(int i=0;i<n;i++){
    po[i]=sc.nextInt();
    m-=po[i];
  }
  Arrays.sort(po);
  System.out.println(n+m/po[0]);
}}