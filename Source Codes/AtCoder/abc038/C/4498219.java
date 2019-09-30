import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int index=1;long ans=0;
  int p=sc.nextInt();
  for(int i=1;i<n;i++){
    int po=sc.nextInt();
  	if(po>p)
    	index++;
    else {
      ans+=(long)index*(index+1)/2;
      index=1;
    }
    p=po;
  }
  ans+=(long)index*(index+1)/2;
System.out.println(ans);
}

}