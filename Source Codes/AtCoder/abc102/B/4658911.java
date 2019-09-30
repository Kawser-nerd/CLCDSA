import java.util.*;
 
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int []a = new int[N];
    for(int i=0;i<N;i++){
      a[i]=sc.nextInt();
    }
    int max=a[0];
    int min=a[0];
    for(int i=0;i<N;i++){
      if(max<a[i]){
        max=a[i];
      }
    }

    for(int i=0;i<N;i++){
      if(min>a[i]){
        min=a[i];
      }
    }
    System.out.println(max-min);
  } 
}