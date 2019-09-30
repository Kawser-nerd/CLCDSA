import java.util.*;

class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int ng[] = new int[3];
    int[] DP = new int[301];
    int[] DP2 = new int[301];
    Arrays.fill(DP,0);
    Arrays.fill(DP2,999);
    
    for(int i = 0; i < 3; i++){
      ng[i] = sc.nextInt();
      DP[ng[i]] = -1;
    }
    DP[0] = 1;
    DP2[0] = 0;
    for(int i = 1; i < 4; i++){
      boolean flag = false;
      for(int j = 0; j < 3; j++){
        if(ng[j] == i)
          flag = true;
      }
      if(flag){
        DP[i] = -1;
      }else{
        DP[i] = 1;
        DP2[i] = 1;
      }
    }
    
    for(int i = 4; i <= n; i++){
      if(i != ng[0] && i != ng[1] && i != ng[2]){
        if(DP[i-3] == 1){
          DP[i] = 1;
          DP2[i] = DP2[i-3] + 1;
        }else if(DP[i-2] == 1){
          DP[i] = 1;
          DP2[i] = DP2[i-2] + 1;
        }else if(DP[i-1] == 1){
          DP[i] = 1;
          DP2[i] = DP2[i-1] + 1;
        }else{
          DP[i] = -1;
        }
      }else{
        DP[i] = -1;
      }
    }
    if(DP2[n] <= 100){
      System.out.print("YES");
    }else{
      System.out.print("NO");
    }
  }
}