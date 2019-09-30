using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    public Solve(){}
    StringBuilder sb;
    Readlong re;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        re = new Readlong();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        long H = re.i();
        long W = re.i();
        int N = re.i();
        RedBlackTree Set1 = new RedBlackTree();
        RedBlackTree Set2 = new RedBlackTree();
        List<long> D = new List<long>();
        for(int l=0;l<N;l++){
            long h = re.i()-1;
            long w = re.i()-1;
            Set1.Insert(h*1000000000+w);
            for(long i=h-1;i<=h+1;i++){
                if(i >= 1 && i < H-1){
                    for(long j=w-1;j<=w+1;j++){
                        if(j >= 1 && j < W-1){
                            long d = i*1000000000+j;
                            if(!Set2.Exist(d)){
                                D.Add(d);
                                Set2.Insert(d);
                            }
                        }
                    }
                }
            }
        }
        long[] ans = new long[10];
        for(int l=0;l<D.Count;l++){
            long d = D[l];
            long h = d / 1000000000;
            long w = d % 1000000000;
            int c = 0;
            for(long i=h-1;i<=h+1;i++){
                if(i >= 0 && i < H){
                    for(long j=w-1;j<=w+1;j++){
                        if(j >= 0 && j < W){
                            long dij = i*1000000000+j;
                            if(Set1.Exist(dij)){
                                c++;
                            }
                        }
                    }
                }
            }
            ans[c]++;
        }
        ans[0] = (H-2)*(W-2);
        for(int i=1;i<=9;i++){
            ans[0] -= ans[i];
        }
        for(int i=0;i<=9;i++){
            sb.Append(ans[i]+"\n");
        }
    }
}
class Node{
    public bool Color;
    public bool LR;
    public long value;
    public Node Parent;
    public Node Left;
    public Node Right;
    public void Write(){
        Console.WriteLine(Color);
        Console.WriteLine(value);
        Console.WriteLine("Left: (");
        if(Left != null){
            Left.Write();
        }
        Console.WriteLine(")");
        Console.WriteLine("Right: (");
        if(Right != null){
            Right.Write();
        }
        Console.WriteLine(")");
    }
    public Node(bool C,long D,Node p){
        Color = C;
        value = D;
        Parent = p;
        Left = null;
        Right = null;
    }
    public Node(bool C,long D,Node p,bool lr){
        Color = C;
        value = D;
        Parent = p;
        Left = null;
        Right = null;
        LR = lr;
    }
    public void SetLeft(Node no){
        Left = no;
        if(no != null){
            no.Parent = this;
            no.LR = true;
        }
    }
    public void SetRight(Node no){
        Right = no;
        if(no != null){
            no.Parent = this;
            no.LR = false;
        }
    }
}
class RedBlackTree{///compare???
    Node Root;
    public RedBlackTree(){
        Root = null;
    }
    public void Write(){
        Root.Write();
    }
    //??????b-a
    public int Compare(long a,long b){
        return b > a ? 1 : (b == a ? 0 : -1);
    }
    public void Insert(long D){
        if(Root == null){
            Root = new Node(false,D,null);
            return;
        }
        Node no = Root;
        while(true){
            if(Compare(no.value,D) <= 0){
                if(no.Left == null){
                    break;
                }
                else{
                    no = no.Left;
                }
            }
            else{
                if(no.Right == null){
                    break;
                }
                else{
                    no = no.Right;
                }
            }
        }
        if(Compare(no.value,D) <= 0){
            no.Left = new Node(true,D,no,true);
        }
        else{
            no.Right = new Node(true,D,no,false);
        }
        while(no != null){
            if(no.LR && no.Color && no.Left != null && no.Left.Color){
                Node n1 = no.Left;
                Node n2 = no.Parent;
                Node n3 = no.Right;
                if(n2.Parent != null){
                    if(n2.LR){
                        n2.Parent.SetLeft(no);
                    }
                    else{
                        n2.Parent.SetRight(no);
                    }
                }
                else{
                    Root = no;
                    no.Color = false;
                    no.Parent = null;
                }
                no.SetRight(n2);
                n2.SetLeft(n3);
                n1.Color = false;
                no = no.Parent;
            }
            else if(no.LR && no.Color && no.Right != null && no.Right.Color){
                Node n1 = no.Right;
                Node n2 = no.Parent;
                Node n3 = n1.Right;
                Node n4 = n1.Left;
                if(n2.Parent != null){
                    if(n2.LR){
                        n2.Parent.SetLeft(n1);
                    }
                    else{
                        n2.Parent.SetRight(n1);
                    }
                }
                else{
                    Root = n1;
                    n1.Color = false;
                    n1.Parent = null;
                }
                n1.SetLeft(no);
                n1.SetRight(n2);
                no.SetRight(n4);
                n2.SetLeft(n3);
                no.Color = false;
                no = n1.Parent;
            }
            else if(!no.LR && no.Color && no.Left != null && no.Left.Color){
                Node n1 = no.Left;
                Node n2 = no.Parent;
                Node n3 = n1.Right;
                Node n4 = n1.Left;
                if(n2.Parent != null){
                    if(n2.LR){
                        n2.Parent.SetLeft(n1);
                    }
                    else{
                        n2.Parent.SetRight(n1);
                    }
                }
                else{
                    Root = n1;
                    n1.Color = false;
                    n1.Parent = null;
                }
                n1.SetLeft(n2);
                n1.SetRight(no);
                no.SetLeft(n3);
                n2.SetRight(n4);
                no.Color = false;
                no = n1.Parent;
            }
            else if(!no.LR && no.Color && no.Right != null && no.Right.Color){
                Node n1 = no.Right;
                Node n2 = no.Parent;
                Node n3 = no.Left;
                if(n2.Parent != null){
                    if(n2.LR){
                        n2.Parent.SetLeft(no);
                    }
                    else{
                        n2.Parent.SetRight(no);
                    }
                }
                else{
                    Root = no;
                    no.Color = false;
                    no.Parent = null;
                }
                no.SetLeft(n2);
                n2.SetRight(n3);
                n1.Color = false;
                no = no.Parent;
            }
            else{
                break;
            }
        }
    }
    public void Delete(long D){
        Node no = Root;
        while(no != null){
            if(Compare(no.value,D) > 0){
                no = no.Right;
            }
            else if(Compare(no.value,D) < 0){
                no = no.Left;
            }
            else{
                break;
            }
        }
        if(no == null){
            return;
        }
        bool Change;
        bool LRChange;
        if(no.Left == null){
            Change = !no.Color;
            LRChange = no.LR;
            if(no.Parent == null){
                Root = no.Right;
            }
            else{
                if(no.LR){
                    no.Parent.SetLeft(no.Right);
                }
                else{
                    no.Parent.SetRight(no.Right);
                }
            }
            no = no.Parent;
        }
        else{
            Node biggest = no.Left;
            while(biggest.Right != null){
                biggest = biggest.Right;
            }
            Change = !biggest.Color;
            LRChange = biggest.LR;
            no.value = biggest.value;
            no = biggest.Parent;
            if(LRChange){
                no.Left = null;
            }
            else{
                no.Right = null;
            }
        }
        while(Change && no != null){
            if(LRChange){
                if(no.Right.Color){
                    Node n1 = no.Right;
                    Node n2 = n1.Left;
                    if(no.Parent == null){
                        Root = n1;
                    }
                    else{
                        if(no.LR){
                            no.Parent.SetLeft(n1);
                        }
                        else{
                            no.Parent.SetRight(n1);
                        }
                    }
                    no.Color = true;
                    n1.Color = false;
                    no.SetRight(n2);
                    n1.SetLeft(no);
                }
                else if(no.Right.Left != null && no.Right.Left.Color){
                    Node n1 = no.Right;
                    Node n2 = n1.Left;
                    Node n3 = n2.Left;
                    Node n4 = n2.Right;
                    n2.Color = no.Color;
                    no.Color = false;
                    if(no.Parent == null){
                        Root = n2;
                        n2.Color = false;
                    }
                    else{
                        if(no.LR){
                            no.Parent.SetLeft(n2);
                        }
                        else{
                            no.Parent.SetRight(n2);
                        }
                    }
                    n2.SetLeft(no);
                    n2.SetRight(n1);
                    no.SetRight(n3);
                    n1.SetLeft(n4);
                    Change = false;
                }
                else if(no.Right.Right != null && no.Right.Right.Color){
                    Node n1 = no.Right;
                    Node n2 = n1.Right;
                    Node n3 = n1.Left;
                    n1.Color = no.Color;
                    no.Color = false;
                    n2.Color = false;
                    if(no.Parent == null){
                        Root = n1;
                        n1.Color = false;
                    }
                    else{
                        if(no.LR){
                            no.Parent.SetLeft(n1);
                        }
                        else{
                            no.Parent.SetRight(n1);
                        }
                    }
                    n1.SetLeft(no);
                    no.SetRight(n3);
                    Change = false;
                }
                else{
                    Change = !no.Color;
                    no.Right.Color = true;
                    no.Color = false;
                    LRChange = no.LR;
                    no = no.Parent;
                }
            }
            else{
                if(no.Left.Color){
                    Node n1 = no.Left;
                    Node n2 = n1.Right;
                    if(no.Parent == null){
                        Root = n1;
                    }
                    else{
                        if(no.LR){
                            no.Parent.SetLeft(n1);
                        }
                        else{
                            no.Parent.SetRight(n1);
                        }
                    }
                    no.Color = true;
                    n1.Color = false;
                    no.SetLeft(n2);
                    n1.SetRight(no);
                }
                else if(no.Left.Right != null && no.Left.Right.Color){
                    Node n1 = no.Left;
                    Node n2 = n1.Right;
                    Node n3 = n2.Right;
                    Node n4 = n2.Left;
                    n2.Color = no.Color;
                    no.Color = false;
                    if(no.Parent == null){
                        Root = n2;
                        n2.Color = false;
                    }
                    else{
                        if(no.LR){
                            no.Parent.SetLeft(n2);
                        }
                        else{
                            no.Parent.SetRight(n2);
                        }
                    }
                    n2.SetRight(no);
                    n2.SetLeft(n1);
                    no.SetLeft(n3);
                    n1.SetRight(n4);
                    Change = false;
                }
                else if(no.Left.Left != null && no.Left.Left.Color){
                    Node n1 = no.Left;
                    Node n2 = n1.Left;
                    Node n3 = n1.Right;
                    n1.Color = no.Color;
                    no.Color = false;
                    n2.Color = false;
                    if(no.Parent == null){
                        Root = n1;
                        n1.Color = false;
                    }
                    else{
                        if(no.LR){
                            no.Parent.SetLeft(n1);
                        }
                        else{
                            no.Parent.SetRight(n1);
                        }
                    }
                    n1.SetRight(no);
                    no.SetLeft(n3);
                    Change = false;
                }
                else{
                    Change = !no.Color;
                    no.Left.Color = true;
                    no.Color = false;
                    LRChange = no.LR;
                    no = no.Parent;
                }
            }
        }
    }
    public long FindBiggest(){
        Node n = Root;
        while(n.Right != null){
            n = n.Right;
        }
        return n.value;
    }
    public long FindSmallest(){
        Node n = Root;
        while(n.Left != null){
            n = n.Left;
        }
        return n.value;
    }
    public bool Exist(long D){
        Node no = Root;
        while(no != null){
            if(Compare(no.value,D) > 0){
                no = no.Right;
            }
            else if(Compare(no.value,D) < 0){
                no = no.Left;
            }
            else{
                return true;
            }
        }
        return false;
    }
}
class Readlong{
    string[] str;
    int counter;
    public Readlong(){
        counter = 0;
    }
    public string s(){
        if(counter == 0){
            str = Console.ReadLine().Split(' ');
            counter = str.Length;
        }
        counter--;
        return str[str.Length-counter-1];
    }
    public int i(){
        return int.Parse(s());
    }
    public long l(){
        return long.Parse(s());
    }
    public double d(){
        return double.Parse(s());
    }
    public int[] ia(int N){
        int[] ans = new int[N];
        for(int j=0;j<N;j++){
            ans[j] = i();
        }
        return ans;
    }
    public int[] ia(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        int[] ans = new int[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = int.Parse(str[j]);
        }
        return ans;
    }
    public long[] la(int N){
        long[] ans = new long[N];
        for(int j=0;j<N;j++){
            ans[j] = l();
        }
        return ans;
    }
    public long[] la(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        long[] ans = new long[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = long.Parse(str[j]);
        }
        return ans;
    }
    public double[] da(int N){
        double[] ans = new double[N];
        for(int j=0;j<N;j++){
            ans[j] = d();
        }
        return ans;
    }
    public double[] da(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        double[] ans = new double[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = double.Parse(str[j]);
        }
        return ans;
    }
    public List<int>[] g(int N,int[] f,int[] t){
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<f.Length;j++){
            ans[f[j]].Add(t[j]);
            ans[t[j]].Add(f[j]);
        }
        return ans;
    }
    public List<int>[] g(int N,int M){
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<M;j++){
            int f = i()-1;
            int t = i()-1;
            ans[f].Add(t);
            ans[t].Add(f);
        }
        return ans;
    }
    public List<int>[] g(){
        int N = i();
        int M = i();
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<M;j++){
            int f = i()-1;
            int t = i()-1;
            ans[f].Add(t);
            ans[t].Add(f);
        }
        return ans;
    }
}
public static class Define{
    public const long mod = 1000000007;
}
public static class Debug{
    public static void Print(double[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(double[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(double[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
    public static void Print(long[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(long[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(long[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
    public static void Print(int[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(int[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(int[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
}