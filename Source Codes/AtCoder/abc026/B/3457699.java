import java.util.Scanner;
import java.util.Arrays;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int[] radius = new int[N];
    double pi = Math.PI;
    double area = 0;
    for(int i = 0; i < N; i++){
      radius[i] = scanner.nextInt();
    }
    Arrays.sort(radius);
    for(int i = N-1; i>=0; i--){
      if(N%2==0){
        if(i%2==0){
          area -= pi*radius[i]*radius[i];
        }else if(i%2==1){
          area += pi*radius[i]*radius[i];
        }
      }
      if(N%2==1){
        if(i%2==0){
          area += pi*radius[i]*radius[i];
        }else if(i%2==1){
          area -= pi*radius[i]*radius[i];
        }
      }
    }
    System.out.println(area);
  }
}