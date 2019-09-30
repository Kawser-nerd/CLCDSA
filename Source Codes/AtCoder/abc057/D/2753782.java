import java.io.*;
import java.util.*;

class Main {
  public static void main (String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int a = sc.nextInt();
    int b = sc.nextInt();
    long[] nums = new long[n];
    for(int i = 0; i < n; i++) {
      nums[i] = sc.nextLong();
    }
    Arrays.sort(nums);
    double sum = 0;
    int[] occurs = new int[a];
    long count = 0;
    for(int i = n-1; i >= n-a; i--) {
      sum += nums[i];
    }
    sum /= a;
    boolean flag = true;
    int index = -1;
    if(nums[n-1] != nums[n-a]) {
      int counts = 0;
      for(int i = n-1; i >= 0; i--) {
        if(nums[i] == nums[n-a]) {
          if(flag) {
            index = i+1;
            flag = false;
          }
          counts++;
        }
      }
      count = combinations(counts, a-(n-index));
    } else {
      int l = 0;
      for(int i = n-1; i >= 0; i--) {
        if(nums[i] == nums[n-1]) {
          l++;
        }
      }
      for(int i = a; i <= b; i++) {
        if(nums[n-1] == nums[n-i]) {
          count += combinations(l, i);
        }
      }
    }
    System.out.println(sum);
    System.out.println(count);
  }
  
  private static long combinations(int n, int k) {
    long ans = 1;
    for(int i = 1; i <= k; i++) {
      ans *= n-k+i;
      ans /= i;
    }
    return ans;
  }
}