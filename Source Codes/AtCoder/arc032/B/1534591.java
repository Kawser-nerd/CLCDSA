import java.util.*;

public class Main{      
    
    public static class Node{
        ArrayList<Integer> to;
        boolean visit;
        Node(){
            to = new ArrayList<Integer>();   
            visit = false;
        }                
    }

    static Scanner sc = new Scanner(System.in);
    static int N = sc.nextInt();
    static int M = sc.nextInt();
    static Node[] node = new Node[100000];
    
    public static void main(String[] args){
        
        for(int i = 0;i < N;i++)
           node[i] = new Node();
        
        for(int i = 0;i < M;i++){
           int a = sc.nextInt();
           int b = sc.nextInt();
           node[a-1].to.add(b-1);
           node[b-1].to.add(a-1);                
        }
        
        int count = 0;
        
        for(int i = 0;i < N;i++){
           if(node[i].visit) continue; 
           node[i].visit = true;
           solve(node[i]);
           count++;
        }        
        
        System.out.println(count - 1);
                
    }
    
    public static void solve(Node n){
        for(int i = 0;i < n.to.size();i++){
            int next = n.to.get(i);
            if(node[next].visit) continue;
            node[next].visit = true;            
            solve(node[next]);
        }                            
    }
    
}