import java.util.*;
import java.util.stream.Stream;

public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        
        long xMin = 1L<<30;
        long xMax = 0;
        long yMin = 1L<<30;
        long yMax = 0;
        
        long[][] bg = new long[n][2];
        
        for(int i=0; i<n; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            if(x>y){
                int tmp = x;
                x = y;
                y = tmp;
            }
            
            bg[i][0] = x;
            bg[i][1] = y;
            
            xMin = Math.min(xMin, x);
            xMax = Math.max(xMax, x);
            yMin = Math.min(yMin, y);
            yMax = Math.max(yMax, y);
        }
        
        long ans = (xMax - xMin)*(yMax - yMin);
        
        
        Arrays.sort(bg, new Comparator<long[]>() {
            public int compare(long[] p1, long[] p2) {
                if(p1[0] < p2[0]) return -1;
                if(p1[0] > p2[0]) return 1;
                return 0;
            }
        });
        
        long yUsedMax = 0;
        long yUsedMin = 1L<<30;
        for(int i=0; i<n-1; i++){
            yUsedMin = Math.min(yUsedMin, bg[i][1]);
            yUsedMax = Math.max(yUsedMax, bg[i][1]);
            //bMin? Math.min(??????y???, ?????????x)
            long bMin = Math.min(yUsedMin, bg[i+1][0]);
            //bMax? Math.max(??????y???, ??????????x)
            long bMax = Math.max(yUsedMax, bg[n-1][0]);
            
            ans = Math.min(ans, (yMax-xMin)*(bMax-bMin));
        }
        
        System.out.println(ans);
        
    }
}