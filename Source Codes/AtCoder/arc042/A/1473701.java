import java.util.*;

public class Main {                  
    
    public static void main(String[] args){           
        
        Scanner sc = new Scanner(System.in);
                                                
        int N = sc.nextInt();
        int M = sc.nextInt();
        
        ArrayDeque<Integer> deque = new ArrayDeque<>(M);                
        
        for(int i = 0;i < M;i++){
            deque.addFirst(sc.nextInt());
        }
        
        boolean f[] = new boolean[N+1];
        
        while(!deque.isEmpty()){            
            int p = deque.poll();
            if(!f[p]){
                f[p] = true;
                System.out.println(p);   
            }            
        }
        
        for(int i = 1;i <= N;i++){
            if(!f[i]){
                System.out.println(i);
            }
        }
        
    }    
}