import java.util.*;
public class A{
    static HashMap<String,Integer> hm = new HashMap();
    static int X;
    static int id(String s){
        if(s.matches("[a-z]+"))return -1;
        if(hm.containsKey(s))
            return hm.get(s);
        else 
            hm.put(s,X);
        return X++;
    }
    static int[][] ls;
    static int go(int id){
        if(id == -1)return -1000000;
        int[] cnt = new int[ls[id].length];
        int mixes = 0;
        for(int i = 0; i<cnt.length; i++){
            if(ls[id][i]>=0)
                mixes++;
            cnt[i] = go(ls[id][i]);
        }
        Arrays.sort(cnt);
        int ret = 1;
        for(int i = 0; i<cnt.length; i++){
            ret = Math.max(ret,cnt[i]+cnt.length-i-1);
        }
        //System.out.println(id+" "+ret+" "+mixes+" "+ls[id].length);
        return Math.max(ret,mixes+1);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int C = sc.nextInt();
        String s;
        for(int i = 0; i<C; i++){
            hm = new HashMap();
            X = 0;
            int N = sc.nextInt();
            ls = new int[N][];
            for(int j = 0; j<N; j++){
                int id1 = id(sc.next());
                ls[id1] = new int[sc.nextInt()];
                for(int k = 0; k<ls[id1].length; k++){
                    ls[id1][k] = id(s = sc.next());
                }
                Arrays.sort(ls[id1]);
            }
            int req = go(0);
            //if(req == 0)req = 1;
            System.out.printf("Case #%d: %d\n",i+1,req);
        }
    }
}
