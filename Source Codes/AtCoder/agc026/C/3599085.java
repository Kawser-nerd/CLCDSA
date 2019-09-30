import java.util.*;

class Main{
    static int inf = Integer.MAX_VALUE;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String S = sc.next();
        StringBuilder sb = new StringBuilder(S);
        char[] backRev = sb.reverse().toString().substring(0,n).toCharArray();
        char[] front = S.substring(0,n).toCharArray();
        //HashMap<String,ArrayList<Integer>> backDic = new HashMap<>();
        HashMap<String,HashMap<String,Long>> backDic = new HashMap<>();
        for(int i=0;i<(1<<n);i++){
            String cur = getSub(backRev,i);
            String remain = getRemainRev(backRev,i);
            if(!backDic.containsKey(cur)) {
                HashMap<String,Long> toAdd = new HashMap<>();
                toAdd.put(remain,1L);
                backDic.put(cur,toAdd);
            }
            else{
                HashMap<String,Long> toModify = backDic.get(cur);
                long now = toModify.getOrDefault(remain,0L)+1;
                toModify.put(remain,now);
            }
        }
        long cnt = 0;
        for(int i=0;i<(1<<n);i++){
            String redFront = getSub(front,i);
            String blueEnd = getRemainRev(front,i);
            if(!backDic.containsKey(redFront)) continue;
            HashMap<String,Long> toCheck = backDic.get(redFront);
            cnt += toCheck.getOrDefault(blueEnd,0L);
        }
        System.out.println(cnt);
    }
    static String getSub(char[] s, int idx){
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<s.length;i++){
            if((idx&(1<<i))>0) sb.append(s[i]);
        }
        return sb.toString();
    }
    static String getRemainRev(char[] s, int idx){
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<s.length;i++){
            if((idx&(1<<i))==0) sb.append(s[i]);
        }
        sb.reverse();
        return sb.toString();
    }
}