import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        int[] wrc = new int[n+1];
        int[] wrn = new int[n+1];
        
        for(int i=0; i<m; i++){
            int s = sc.nextInt();
            int t = sc.nextInt();
            
            wrc[s-1] += 1;
            wrc[t] -= 1;
            
            wrn[s-1] += i;
            wrn[t] -= i;
        }
        
        boolean[] brni = new boolean[m];
        Arrays.fill(brni, true);
        int linecnt = 0;
        
        for(int i=0; i<n; i++){
            wrc[i+1] += wrc[i];
            wrn[i+1] += wrn[i];
        }
        
        for(int i=0; i<n; i++){
            if(wrc[i]==1 && brni[wrn[i]]){
               brni[wrn[i]] = false;
               linecnt++;
            }
        }
        
        System.out.println(m-linecnt);
        for(int i=0; i<m; i++){
            if(brni[i]){
                System.out.println(i+1);
            }
        }
    }
}