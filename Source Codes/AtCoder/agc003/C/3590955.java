import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        int[] a = new int[n];
        int[] aeve = new int[(n+1)/2];
        
        for(int i=0; i<n; i++){
            a[i] = Integer.parseInt(sc.next());
            if(i%2==0){
                aeve[i/2] = a[i];
            }
        }
        
        Arrays.sort(a);
        
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<n; i++){
            map.put(a[i], i%2);
        }
        
        long cnt = 0L;
        for(int i=0; i<aeve.length; i++){
            cnt += map.get(aeve[i]);
        }
        
        System.out.println(cnt);
        
    }
}