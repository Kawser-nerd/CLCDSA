/*
????????????????long???????
???split??contains??????"+"??????????????"\\+"???
 */
import sun.reflect.generics.tree.Tree;

import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        long[] ans = new long[n + 1];
        ArrayList<Integer>[] sub = new ArrayList[n + 1];
        int[] boss = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            sub[i] = new ArrayList<>();
        }
        for (int i = 2; i <= n; i++) {
            boss[i] = sc.nextInt();
            sub[boss[i]].add(i);
        }
        Queue<Integer> q=new ArrayDeque<>();
        TreeSet<Integer> ts=new TreeSet<>();
        q.add(1);
        while (!q.isEmpty()){
            int p=q.poll();
            for (Integer k:sub[p]){
                if(sub[k].size()==0){
                    ts.add(p);
                    ans[k]=1;
                }
                q.add(k);
            }
        }
        for (Integer k:ts){
            q.add(k);
        }
        while (!q.isEmpty()){
            int p=q.poll();
            long t=1,max=0,min=Long.MAX_VALUE;
            for (Integer k:sub[p]){
                t*=ans[k];
                max=max(max,ans[k]);
                min=min(min,ans[k]);
            }
            if(t!=0){
                ans[p]=max+min+1;
                if(p!=1)q.add(boss[p]);
            }
        }
        out.println(ans[1]);
    }
} ./Main.java:5: warning: Tree is internal proprietary API and may be removed in a future release
import sun.reflect.generics.tree.Tree;
                                ^
Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.
1 warning