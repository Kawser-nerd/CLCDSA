import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  String a=sc.next();
  int nums[]=new int[6];
  char[]s=a.toCharArray();
  for(int i=0;i<s.length;i++)nums[s[i]-65]++;
  System.out.println(nums[0]+" "+nums[1]+" "+nums[2]+" "+nums[3]+" "+nums[4]+" "+nums[5]);
  }}