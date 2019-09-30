import java.util.*;

public class Main {                  
    
    public static void main(String[] args){           
        
        Scanner sc = new Scanner(System.in);
                                                
        int N = sc.nextInt();  
        int M = sc.nextInt();

        int[] s = new int[300002];        
        int[] t = new int[300002];
        int[] x = new int[300002];
	int[] b = new int[300002];

	for(int i = 0; i < M; ++i){
	    s[i] = sc.nextInt();
	    t[i] = sc.nextInt();
	    int l = s[i]-1; int r = t[i]-1;
	    b[l]++; b[r+1]--;
        }
                
	for(int i = 0; i < N+1; ++i){
		b[i+1] += b[i];
                if(b[i] == 1) x[i+1] = x[i] + 1;
                else x[i+1] = x[i] + 0;
        }
                
        ArrayList<Integer> ans = new ArrayList<Integer>();        
        
        for(int i = 0;i < M;i++){
            if(x[t[i]] - x[s[i] - 1] == 0){
                ans.add(i+1);   
            }            
        }        
        
        System.out.println(ans.size());
        for(int i = 0;i < ans.size();i++){
            System.out.println(ans.get(i));
        }        
        
    }    
}