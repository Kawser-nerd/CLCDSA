import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
    long N = scanner.nextLong();
    int depth = 0;
    long x = 1;
    for(long i = N; i > 0; i/=2){
      depth++;
    }
    char turn = 'T';
    if(depth%2==0){
      while(N >= x){
        if(turn == 'T'){
          x *= 2;
          turn = 'A';
        }else if(turn == 'A'){
          x = x * 2 + 1;
          turn = 'T';
        }
      }
    }else if(depth%2==1){
      while(N >= x){
        if(turn == 'T'){
          x = x * 2 + 1;
          turn = 'A';
        }else if(turn == 'A'){
          x *= 2;
          turn = 'T';
        }
      }
    }
    if(turn == 'T'){
      System.out.println("Takahashi");
    }else{
      System.out.println("Aoki");
    }
  }
}