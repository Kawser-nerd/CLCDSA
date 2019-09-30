import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    char[] nums = {'1','2','3','4','5','6'};
    char tem = '0';
    String[] s = new String[30];
    for(int i = 0; i < 30; i++){
      s[i] = new String(nums);
      int a = i % 5;
      tem = nums[a];
      nums[a] = nums[a+1];
      nums[a+1] = tem;
    }
    int b = N % 30;
    System.out.println(s[b]);
  }
}