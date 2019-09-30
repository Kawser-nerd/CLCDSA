import java.util.*;

public class Main {	       
    
    public static void main(String[] args){
        new Main().solve();        
    }                   
    
    void solve(){
         Scanner sc = new Scanner(System.in);                                                                                                              
         
         int n = sc.nextInt();
		int max = 0;
		int sum = 0;
		for(int i=0;i<n;i++){
			int dis = sc.nextInt();
			max = Math.max(max, dis);
			sum += dis;
		}
                
		System.out.println(sum);
		System.out.println(Math.max(0, 2 * max - sum));         
                                     
    }   
}