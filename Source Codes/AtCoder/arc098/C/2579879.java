import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        int k = Integer.parseInt(sc.next());
        int q = Integer.parseInt(sc.next());
        int[] a = new int[n];
        for(int i=0; i<n; i++){
            a[i] = Integer.parseInt(sc.next());
        }
        
        int ans = (int)1e9;
        for(int x : a){
            int cnt = 0;
            PriorityQueue<Integer> que = new PriorityQueue<>();
            PriorityQueue<Integer> ya = new PriorityQueue<>();
            for(int i=0; i<n; i++){
                que.add(a[i]);
                if(a[i] < x){
                    que.clear();
                }
                if(k <= que.size()){
                    cnt++;
                    ya.add(que.poll());
                }
            }
            
            if(q <= cnt){
                int y = 0;
                for(int i=0; i<q; i++){
                    y = ya.poll();
                }
                ans = Math.min(ans, y-x);
            }
        }
        
        System.out.println(ans);
    }
}