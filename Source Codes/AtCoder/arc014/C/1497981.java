import java.util.*;

public class Main{

    public static void main(String[] args){
           
      Scanner sc = new Scanner(System.in);
        
      int N = sc.nextInt();
      
      char s[] = sc.next().toCharArray();
      
      int[] num = new int[3];
      
      for (int i = 0; i < N; i++) {
			switch (s[i]) {
				case 'R':
					num[0]++;
					break;
				case 'G':
					num[1]++;
					break;
				case 'B':
					num[2]++;
					break;
			}
      }
      
      int ans = 0;
      
      for (int i = 0; i < 3; i++) {
	   ans += num[i] % 2;
      }

       System.out.println(ans);			     
                  
    }        
}