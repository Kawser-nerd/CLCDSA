import java.util.*;
class Main{
  public static void main(String[]args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int q=sc.nextInt();
    int[]nums=new int[n];
    int tmpL;
    int tmpR;
    int tmpT;
    for(int i=0;i<q;i++){
      tmpL=sc.nextInt();
      tmpR=sc.nextInt();
      tmpT=sc.nextInt();
      for(int j=tmpL-1;j<tmpR;j++){
        nums[j]=tmpT;
      }
    }
    for(int a:nums){
      System.out.println(a);
    }
  }

}