import java.util.*;
import java.util.stream.Stream;

public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.nextLine());
        int[] a = Stream.of(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        
        boolean allneg = true;
        for(int i=0; i<n; i++){
            if(a[i]>=0) allneg = false;
        }
        
        ArrayList<Integer> ans = new ArrayList<>();
        long max = -10_000_000_000_000L;
        
        if(!allneg){
            boolean[][] mi = new boolean[2][n/2+1];
            long[] scr = new long[2];
            for(int i=0; i<2; i++){
                for(int j=i; j<n; j+=2){
                    if(a[j]<0){
                        mi[i][j/2] = true;
                    }else{
                        scr[i] += a[j];
                    }
                }
            }
            int idx = (scr[0] > scr[1])? 0:1;
            max = scr[idx];
            //
            int size = n;
            
            if(idx==1){
                ans.add(1);
                size -= 1;
            }
            
            if(size%2==0){
                ans.add(size);
                size -= 1;
            }
            
            for(int i=n/2; i>=0; i--){
                if(mi[idx][i]){
                    int t = i*2+1;
                    ans.add(t);
                    if(t == 1){
                        ans.add(t);
                    }else if(t == size){
                        ans.add(t-1);
                    }
                    size -= 2;
                }
            }
            
            while(size>1){
                ans.add(2);
                size -= 2;
            }
        }else{
            int idx = 0;
            for(int i=0; i<n; i++){
                if(a[i] > max){
                    max = a[i];
                    idx = i;
                }
            }
            for(int i=0; i<idx; i++){
                ans.add(1);
            }
            for(int i=n-idx; i>1; i--){
                ans.add(i);
            }
        }
        
        System.out.println(max);
        System.out.println(ans.size());
        for(int i=0; i<ans.size(); i++){
            System.out.println(ans.get(i));
        }
    }
}