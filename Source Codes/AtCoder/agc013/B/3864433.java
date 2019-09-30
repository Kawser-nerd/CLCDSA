import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    static ArrayList<Integer>[] graph;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        graph = new ArrayList[n+1];
        for(int i=0;i<=n;i++) graph[i]=new ArrayList<>();
        for(int j=0;j<m;j++){
            int a=sc.nextInt(),b=sc.nextInt();
            graph[a].add(b);
            graph[b].add(a);
        }
        LinkedList<Integer> ans = helper(n);
        PrintWriter out = new PrintWriter(System.out);
        out.println(ans.size());
        while(ans.size()>0){
            out.print(ans.poll());
            out.print(" ");
        }
        out.flush();
    }
    static LinkedList<Integer> helper(int n){
        boolean[] vis = new boolean[n+1];
        LinkedList<Integer> ans = new LinkedList<>();
        ans.add(1);
        ans.add(graph[1].get(0));
        vis[1]=true;vis[ans.peekLast()]=true;
        boolean flag = true;
        while(flag){
            flag=false;
            for(int w:graph[ans.peek()]){
                if(!vis[w]){
                    ans.addFirst(w);
                    vis[w]=true;
                    flag = true;
                    break;
                }
            }
        }
        flag=true;
        while(flag){
            flag=false;
            for(int w:graph[ans.peekLast()]){
                if(!vis[w]){
                    ans.addLast(w);
                    vis[w]=true;
                    flag = true;
                    break;
                }
            }
        }
        return ans;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.