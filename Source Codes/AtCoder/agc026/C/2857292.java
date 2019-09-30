import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        String s = sc.next();
        
        HashMap<String, Long> h = new HashMap<>();
        
        for(int i=0; i< 1<<n; i++){
            String red = "";
            String blue = "";
            for(int j=0; j<n; j++){
                if((i&(1<<j)) > 0){
                    red += s.charAt(j);
                }else{
                    blue += s.charAt(j);
                }
            }
            String key = red+":"+blue;
            long tmp = h.getOrDefault(key, 0L);
            h.put(key, tmp+1);
        }
        
        long ans = 0;
        for(int i=0; i< 1<<n; i++){
            String red = "";
            String blue = "";
            for(int j=0; j<n; j++){
                if((i&(1<<j)) > 0){
                    red += s.charAt(2*n-1-j);
                }else{
                    blue += s.charAt(2*n-1-j);
                }
            }
            String key = red+":"+blue;
            long tmp = h.getOrDefault(key, 0L);
            ans += tmp;
        }
        
        System.out.println(ans);
    }
}