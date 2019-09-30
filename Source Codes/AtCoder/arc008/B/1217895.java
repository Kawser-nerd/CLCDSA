import java.util.*;

public class Main {
	public static void main(String[] args) {
                Scanner sc = new Scanner(System.in);
                
                int N = sc.nextInt();
                int M = sc.nextInt();
               
                String name = sc.next();
                String kit  = sc.next();
                
                int a[] = new int[200];
                int b[] = new int[200];
                
                for(char c :name.toCharArray()){
                    a[(int) c]++;
                }
                
                for(char c : kit.toCharArray()){
                    b[(int) c]++;
                }
                
                int ans = 1;
                
                for(int i = 0 ;i < 200;i++){                    
                    
                    if(a[i] == 0)
                        continue;

                    
                    if(b[i] == 0){
                        System.out.println(-1);
                        return;
                    }
                    
                    if(a[i] <=b[i])
                        continue;        
                    
                    int count = 0;
                    if(a[i]%b[i] == 0){
                       count = a[i]/b[i];
                    }else{
                       count = a[i]/b[i] + 1;
                    }
                                                                         
                    ans = Math.max(ans,count);
                }
                
                System.out.println(ans);                                                
		
	}
}