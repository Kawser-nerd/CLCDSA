import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int num[]=new int[n];
  for(int i=0;i<n;i++)num[i]=sc.nextInt();
  Arrays.sort(num);
  System.out.println(num[num.length-1]-num[0]);
}
}