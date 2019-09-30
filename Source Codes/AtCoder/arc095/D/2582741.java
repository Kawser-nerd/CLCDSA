import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main{
    static List<Integer> edges[];
    static List<Integer> edge = new ArrayList<>();
    static boolean[] isLeaf;

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        // ???????
        int n = scan.nextInt();
        edges = new ArrayList[n];
        for(int i=0;i<n;++i)edges[i]=new ArrayList<>();
        for(int i=0;i<n-1;++i){
            int v = scan.nextInt()-1;
            int u = scan.nextInt()-1;
            edges[v].add(u);edges[u].add(v);
        }
        isLeaf = new boolean[n];
        for(int i=0;i<n;++i)if(edges[i].size()==1)isLeaf[i]=true;
        for(int i=0;i<n;++i){
            if(isLeaf[i])continue;
            int cnt = 0;
            for(int u : edges[i])if(!isLeaf[u])++cnt;
            if(cnt<=1)edge.add(i);
            if(cnt>2){
                System.out.println(-1);
                return;
            }
        }
        List<Integer> ans = new ArrayList<>();
        if(edge.size()==2){
            for(int v : edge){
                List<Integer> list = new ArrayList<>();
                list.add(0);
                int bef=-1;
                int u = v;
                boolean flag=true;
                while(flag){
                    list.add(edges[u].size()-2);
                    flag=false;
                    for(int w :edges[u])if(!isLeaf[w]&&w!=bef){
                        flag=true;bef=u;u=w;break;
                    }
                }
                list.add(0);
                if(ans.size()==0)ans=list;
                else{
                    for(int i=0;i<ans.size();++i){
                        if(ans.get(i)==list.get(i))continue;
                        else if(ans.get(i)> list.get(i))ans=list;
                        break;
                    }
                }
            }
        }else{
            ans = new ArrayList<>();
            ans.add(0);
            if(edge.size()>0)ans.add(edges[edge.get(0)].size()-2);
            ans.add(0);
        }



        List<Integer> res = new ArrayList<>();
        int num = 1;
        for(int k : ans){
            for(int i=0;i<k;++i)res.add(1+num++);
            res.add(num++ -k);
        }
        for(int k : res)System.out.print(k+" ");
        System.out.println();

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.