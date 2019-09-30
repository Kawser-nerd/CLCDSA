import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// ?????
		int codeNum = sc.nextInt();
		int featNum = sc.nextInt();
		int c = sc.nextInt();
        int[] b = new int[featNum];
        int num = 0;
        int num2 = 0;
        int sum = 0;
        int count = 0;
		for(int i=0; i<featNum; i++){
         	 b[i] = sc.nextInt();
        }
      	for(int i=0; i<codeNum; i++){
          for(int j=0; j<featNum; j++){
         	 num = sc.nextInt();
             num2 = b[j] * num;
             sum += num2;
          }
          if(sum + c > 0) count++;
          sum = 0;
        }
		System.out.println(count);
	}
}