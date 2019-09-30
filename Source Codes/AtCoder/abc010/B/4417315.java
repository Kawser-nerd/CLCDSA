import java.util.*;
public class Main{
public static void main(String[]args){
  Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int ans=0;
  for(int i=0;i<n;i++){
    int po=sc.nextInt();
  ans+=(po%6==0)?3:(po%6==5)?2:(po%6==4||po%6==2)?1:0;
  }
  System.out.println(ans);
}

}