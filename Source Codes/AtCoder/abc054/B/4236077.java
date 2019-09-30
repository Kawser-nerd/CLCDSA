import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    String[] str1 = new String[N];
    String[] str2 = new String[M];
    for(int i = 0; i < N; i++){
      str1[i] = sc.next();
    }
    for(int i = 0; i < M; i++){
      str2[i] = sc.next();
    }
    for(int i = 0; i <= N - M; i++){
      for(int j = 0; j <= N - M; j++){
        boolean flag = true;
        for(int k = 0; k < M; k++){
          if(!str2[k].equals(str1[k+j].substring(i, i+M))){
            flag = false;
            break;
          }
        }
        if(flag){
          System.out.println("Yes");
          System.exit(0);
        }
      }
    }
    System.out.println("No");
  }
}