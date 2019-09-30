import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        HashMap<Integer,Integer> E=new HashMap<>();
        HashMap<Integer,Integer> L=new HashMap<>();
        for (int i = 0; i < 6; i++) {
            int k=sc.nextInt();
            E.put(k,E.getOrDefault(k,0)+1);
        }
        int B=sc.nextInt();
        for (int i = 0; i < 6; i++) {
            int k=sc.nextInt();
            L.put(k,L.getOrDefault(k,0)+1);
        }
        int c=0;
        for (Integer k:E.keySet()){
            if(L.get(k)!=null){
                if(E.get(k)==L.get(k)){
                    c+=E.get(k);
                    E.put(k,0);
                    L.put(k,0);
                }else if(E.get(k)>L.get(k)){
                    c+=L.get(k);
                    E.put(k,E.get(k)-L.get(k));
                    L.put(k,0);
                }else {
                    c+=E.get(k);
                    E.put(k,0);
                    L.put(k,L.get(k)-E.get(k));
                }
            }
        }
        int ans=0;
        if(c==6)ans=1;
        if(c==4)ans=4;
        if(c==3)ans=5;
        if(c==5){
            int f=0;
            for (Integer k:L.keySet()){
                if(L.get(k)>0&&k==B){
                    f++;
                }
            }
            if(f>0)ans=2;
            else ans=3;
        }
        out.println(ans);
    }
}