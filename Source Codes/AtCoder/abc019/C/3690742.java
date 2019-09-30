import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;


public class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int[] a = new int[N];
    for(int i = 0; i < N; i++){
      a[i] = scanner.nextInt();
    }
    Set<Integer> set = new HashSet<Integer>();
    for(int i = 0; i < N; i++){
      while(a[i]%2==0){
        a[i] /= 2;
      }
      set.add(a[i]);
    }
    System.out.println(set.size());
  }
}