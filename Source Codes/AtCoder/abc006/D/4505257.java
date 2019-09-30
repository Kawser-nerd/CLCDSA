import java.util.*;
public class Main{
  public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int[] nums=new int[n];
    for(int i=0;i<n;i++){
      nums[i]=sc.nextInt();
    }
    int[] dp=new int[n+1];
    int maxlength=0;
    for(int i=1;i<n+1;i++){
      dp[i]=Integer.MAX_VALUE;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<maxlength+1;j++){
        if(dp[j]<nums[i]&&dp[j+1]>nums[i]){
          if(dp[j+1]==Integer.MAX_VALUE){
            maxlength++;
          }
          dp[j+1]=nums[i];
        }
      }
    }
    System.out.println(n-maxlength);
	}
}