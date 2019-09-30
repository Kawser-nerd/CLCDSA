import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        int num = 1 << n;
        HashMap hm = new HashMap<String, Integer>();
        for(int i=0; i<num; i++){
            String bin = String.format("%"+n+"s",Integer.toBinaryString(i)).replace(' ', '0');
            char[] left = new char[n];
            int lc = 0, rc = n-1;
            for(int j=0; j<n; j++){
                if(bin.charAt(j) == '0'){
                    left[lc] = s.charAt(j);
                    lc++;
                }else{
                    left[rc] = s.charAt(j);
                    rc--;
                }
            }
            String sleft = new String(left) + lc;
            if(hm.get(sleft) != null){
                hm.put(sleft, (int)hm.get(sleft) + 1);
            }else{
                hm.put(sleft, 1);
            }
        }

        long ans = 0;

        for(int i=0; i<num; i++){
            String bin = String.format("%"+n+"s",Integer.toBinaryString(i)).replace(' ', '0');
            char[] right = new char[n];
            int lc = 0, rc = n-1;
            for(int j=0; j<n; j++){
                if(bin.charAt(j) == '0'){
                    right[lc] = s.charAt(2*n-j-1);
                    lc++;
                }else{
                    right[rc] = s.charAt(2*n-j-1);
                    rc--;
                }
            }
            String sright = new String(right) + lc;
            if(hm.get(sright) != null){
                ans += (int)hm.get(sright);
            }
        }

        System.out.println(ans);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.