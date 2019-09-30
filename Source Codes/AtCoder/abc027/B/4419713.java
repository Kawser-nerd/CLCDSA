import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();int []po=new int[n];int sum=0;
  for(int i=0;i<n;i++){
    po[i]=sc.nextInt();
    sum+=po[i];
  }
  if(sum%n==0){
      int h=sum/n;
    sum=0;
    int count=0;
    int count2=0;
  	for(int i=0;i<n;i++){
    	sum+=po[i];
    	count2++;
      if(sum==h*count2){sum=0;
          count2=0;
          
      }
      else count++;
    }
    System.out.println(count);
  }
  else System.out.println(-1);
}
}