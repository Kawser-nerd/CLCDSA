using System;
using System.Collections.Generic;
class Solve{
    public int n;
    public long k;
    public int[] a;
    Tree[] tree;
    int count;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    int dfs(Tree t,bool b){
        int max = 0;
        for(int i = 0;i < t.child.Count;i++){
            int m = dfs(t.child[i],true)+1;
            if(max < m){
                max = m;
            }
        }
        if(max == k-1 && b){
            count++;
            max = -1;
        }
        return max;
    }
    void Calc(){
        getinput();
        int rootnum = 0;
        int[] root = new int[n];
        tree = new Tree[n-1];
        for(int i = 0;i < n-1;i++){
            tree[i] = new Tree();
        }
        for(int i = 0;i < n-1;i++){
            if(a[i+1] == 1){
                root[rootnum] = i;
                rootnum++;
            }
            else{
                tree[a[i+1]-2].AddChild(tree[i]);
            }    
        }
        count = 0;
        for(int i = 0;i < rootnum;i++){
            dfs(tree[root[i]],false);
        }
        if(a[0] == 1){
            Console.WriteLine(count);
        }
        else{
            Console.WriteLine(count+1); 
        }
    }
    void getinput(){
        string[] str = Console.ReadLine().Split(' ');
        n = int.Parse(str[0]);
        k = int.Parse(str[1]);
        a = new int[n];
        str = Console.ReadLine().Split(' ');
        for(int i = 0;i < n;i++){
            a[i] = int.Parse(str[i]);
        }
    }    
}
class Tree{
    public List<Tree> child;
    public Tree(){
        child = new List<Tree>();
    }
    public void AddChild(Tree t){
        child.Add(t);
    }
}