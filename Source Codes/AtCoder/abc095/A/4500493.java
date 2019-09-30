import java.util.*;
public class Main {
	public static void main(String[] args){
      	//???????
		Scanner sc = new Scanner(System.in);
		int cnt = 700;
		String S = sc.next();
    
      	for(int i=0;i<3;i++){
        	if(S.charAt(i)=='o')cnt += 100;
        }
      	System.out.println(cnt);
      
      	
    }
}