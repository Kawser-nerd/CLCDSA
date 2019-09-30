import java.util.*;

public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        int[] x = new int[n];
        Queue<Integer> pq = new PriorityQueue<Integer>(k, Comparator.reverseOrder());
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        for(int i=0; i<n; i++){
            int tmp = sc.nextInt();
            map.put(tmp, i+1);
            x[i] = tmp;
            if(i<k){
                pq.add(tmp);
            }
        }
        
        System.out.println(map.get(pq.peek()));
        
        for(int i=k; i<n; i++){
            int t = x[i];
            if(pq.peek() > t){
                pq.add(t);
                pq.poll();
            }
            System.out.println(map.get(pq.peek()));
        }
    }
}