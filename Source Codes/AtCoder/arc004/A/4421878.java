import java.util.*;
 
public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.nextLine());
    String[][] s = new String[N][2];
    int[][] nums = new int[N][2];
    
    for(int i = 0; i < N; i++){
      s[i] = sc.nextLine().split(" ");
      nums[i][0] = Integer.parseInt(s[i][0]);
      nums[i][1] = Integer.parseInt(s[i][1]);
    }
    
    int max = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        int n = 0;
        int a1 = (nums[i][0] - nums[j][0]);
        int a2 = (nums[i][1] - nums[j][1]);
        if(i == j){
        }
        else{
          n = (a1 * a1) + (a2 * a2);
        }
        
        if(n > max){
          max = n;
        }
      }
    }
    
    System.out.println(Math.sqrt(max));
  }
}