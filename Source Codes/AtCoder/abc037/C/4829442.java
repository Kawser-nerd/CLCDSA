import java.util.*;
class Main{
  public static void main(String[]args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int k=sc.nextInt();
    long[] nums=new long[n];
    long output=0;
    for(int i=0;i<n;i++){
      nums[i]=sc.nextInt();
    }
    for(int i=1;i<n;i++){
      nums[i]+=nums[i-1];
    }
    for(int i=0;i<n-k+1;i++){
      output+=nums[k+i-1]-(i==0?0:nums[i-1]);
    }
        System.out.println(output);
  }

}