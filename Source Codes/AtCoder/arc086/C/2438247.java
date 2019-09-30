import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;



class Main{

    static class Pair{
        long p1,p2;
        Pair(long p1,long p2){this.p1=p1;this.p2=p2;}
    }
    static class Edge{
        int to;
        Edge(int to){this.to=to;}
    }
    static List<Integer> edges[];
    static Edge edge[];
    static long base;
    static long invtwo;
    static int n;
    static long mod = (long)1e9+7;

    static ArrayDeque<Pair> dfs(int v){
        long p1 = base;
        long p2 = base;
        ArrayDeque<Pair> res;
        if(edges[v].size()==0){
            res = new ArrayDeque<>();
        }else{
            res = dfs(edges[v].get(0));
            List<Long> pp = new ArrayList<>();
            for(int i=1;i<edges[v].size();++i){
                ArrayDeque<Pair> que = dfs(edges[v].get(i));
                if(que.size()>res.size()){
                    ArrayDeque<Pair> tmp = res;
                    res =que;que=tmp;
                }
                Iterator itr = res.iterator();
                while(pp.size() < que.size())pp.add(0L);
                int index = 0;
                while(!que.isEmpty()){
                    Pair pj = que.pollFirst();
                    Pair pi = (Pair)itr.next();
                    long p = ((((pi.p1*pj.p2)%mod + (pi.p2*pj.p1)%mod)%mod) *invtwo)%mod;
                    pp.set(index, (pp.get(index) + (((pi.p2*pj.p2)%mod)*invtwo%mod)%mod)%mod );
                    ++index;
                    pi.p1 = ((pi.p1*pj.p1)%mod*invtwo)%mod;
                    pi.p2 = p;
                }
            }
            Iterator itr = res.iterator();
            for(Long p : pp){
                Pair pi = (Pair)itr.next();
                pi.p1 = (pi.p1 + p)%mod;
            }
        }
        res.addFirst(new Pair(p1,p2));
        return res;
    }

    static long inverse(long m, long mod){
        long res =1;
        for(int i=0;i<32;++i){
            if((((mod-2)>>i)&1)==1)res=(res*m)%mod;
            m=(m*m)%mod;
        }
        return res;
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        edges = new ArrayList[n+1];
        edge = new Edge[n+1];
        for(int i=0;i<n+1;++i)edges[i]=new ArrayList<>();
        for(int i=0;i<n;++i)edges[scan.nextInt()].add(i+1);
        long ans = 0;
        invtwo=1;
        for(int i=1;i<=n+1;++i)invtwo=(invtwo*2)%mod;
        invtwo=inverse(invtwo, mod);
        base = 1;
        for(int i=0;i<n;++i)base=(2*base)%mod;

        ArrayDeque<Pair> mp = dfs(0);
        Iterator itr = mp.iterator();
        while(itr.hasNext()){
            Pair p = (Pair)itr.next();
            ans = (ans + p.p2)%mod;
        }
        System.out.println(ans);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.