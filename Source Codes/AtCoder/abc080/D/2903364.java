import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int C = sc.nextInt();
        final int nMax = 100000;
        LinkedList<int[]>[] dic = new LinkedList[C+1];
        for(int i=0;i<=C;i++) dic[i] = new LinkedList<>();
        for(int i=1;i<=N;i++){
            int s = sc.nextInt();
            int t = sc.nextInt();
            int c = sc.nextInt();
            dic[c].add(new int[]{s,t});
        }
        int[] res = new int[nMax+5];
        for(int i=1;i<=C;i++){
            if(dic[i].size()==0) continue;
            int[] cur = new int[nMax+5];
            while(dic[i].size()>0){
                int[] temp = dic[i].remove();
                cur[temp[0]]++;
                cur[temp[1]+1]--;
            }
            for(int j=1;j<nMax+5;j++) cur[j] = cur[j-1]+cur[j];
            for(int j=1;j<nMax+5;j++){
                if(cur[j]>0) res[j]++;
            }
        }
        int ans = 0;
        for(int j=1;j<nMax+5;j++) ans = Math.max(ans, res[j]);
        System.out.println(ans);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.