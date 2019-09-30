import java.util.*;

public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int m=sc.nextInt();
  int k=sc.nextInt();
  for(int i=0;i<k;i++){
  int a=sc.nextInt();
    System.out.println((a<n)?n-a:(a>m)?-1:0);
  }
}
}