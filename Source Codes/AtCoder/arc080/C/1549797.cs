using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

struct I
{
    public int Value,Index;
    public I(int v,int i)
    {
        Value=v;
        Index=i;
    }
}

struct S
{
    public int Left,Right;
    public I Min;
    public S(int left,int right,I min)
    {
        Left=left;
        Right=right;
        Min=min;
    }
}

class PQ
{
    public int Length=0;
    private const int MaxSize=1<<17;
    private S[]Tree=new S[MaxSize+1];
    
    public void  Push(S s)
    {
        if(s.Right-s.Left<2) return;
        Length++;
        Tree[Length]=s;
        int pos=Length;
        while(pos>1)
        {
            int u=pos/2;
            if(Tree[pos].Min.Value<Tree[u].Min.Value)
            {
                Swap(pos,u);
            }
            else
            {
                return;
            }
            pos=u;
        }
    }
    
    public S Pop()
    {
        S result=Tree[1];
        Length--;
        if(Length>0)
        {
            Tree[1]=Tree[Length+1];
            int pos=1;
            while(pos*2<=Length)
            {
                int left=pos*2;
                int right=pos*2+1;
                int min=Min(left,right);
                if(Tree[min].Min.Value<Tree[pos].Min.Value)
                {
                    Swap(min,pos);
                    pos=min;
                }
                else
                {
                    break;
                }
            }
        }
        
        return result;
    }
    
    private void Swap(int a,int b)
    {
        var t=Tree[a];
        Tree[a]=Tree[b];
        Tree[b]=t;
    }
    
    private int Min(int a,int b)
    {
        if(b>Length)
        {
            return a;
        }
        if(Tree[a].Min.Value<Tree[b].Min.Value)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
}

class SegTree
{
    private int N;
    private I[]Tree;
    public SegTree(I[]array)
    {
        N=1<<18;
        Tree=new I[N*2];
        for(int i=1;i<N*2;i++)
        {
            Tree[i]=new I(int.MaxValue,-1);
        }
        for(int i=0;i<array.Length;i++)
        {
            Tree[i+N]=array[i];
        }
        for(int i=N-1;i>=1;i--)
        {
            Tree[i]=Min(Tree[i*2],Tree[i*2+1]);
        }
    }
    public I Query(int a,int b,int k,int l,int r)
    {
        if(a<=l&&r<=b)return Tree[k];
        if(b<=l||r<=a)return new I(int.MaxValue,-1);
        I left=Query(a,b,k*2,l,(l+r)/2);
        I right=Query(a,b,k*2+1,(l+r)/2,r);
        return Min(left,right);
    }
    public I Q(int a,int b)
    {
        return Query(a,b,1,0,N);
    }
    private I Min(I a,I b)
    {
        if(a.Value<b.Value)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
}

class Magatro
{
    private int N;
    private SegTree G,K;
    private PQ Pq;
    private int[]Anser;
    private void Scan()
    {
        N=int.Parse(Console.ReadLine());
        var line=Console.ReadLine().Split(' ');
        Pq=new PQ();
        I[]kk=new I[N];
        I[]gg=new I[N];
        
        for(int i=0;i<N;i++)
        {
           int a=int.Parse(line[i]);
            if(i%2==1)
            {
                kk[i]=new I(a,i);
                gg[i]=new I(int.MaxValue,-1);
            }
            else
            {
                gg[i]=new I(a,i);
                kk[i]=new I(int.MaxValue,-1);
            }
        }
        G=new SegTree(gg);
        K=new SegTree(kk);
        Pq.Push(new S(0,N,G.Q(0,N)));
    }
    public void Solve()
    {    
        Scan();
        Anser=new int[N];
        int cnt=0;
        while(Pq.Length>0)
        {
            S top=Pq.Pop();
            int left=top.Left;
            int right=top.Right;
            I min = top.Min;
            I rightMin;
            if(left%2==0)
            {
                rightMin=K.Q(min.Index,right);
                S a=new S(left,min.Index,G.Q(left,min.Index));
                S b=new S(min.Index+1,rightMin.Index,K.Q((min.Index+1),rightMin.Index));
                S c=new S(rightMin.Index+1,right,G.Q((rightMin.Index+1),right));
                Pq.Push(a);
                Pq.Push(b);
                Pq.Push(c);
            }
            else
            {
                rightMin=G.Q(min.Index,right);
                S a=new S(left,min.Index,K.Q(left,min.Index));
                S b=new S(min.Index+1,rightMin.Index,G.Q((min.Index+1),rightMin.Index));
                S c=new S(rightMin.Index+1,right,K.Q((rightMin.Index+1),right));
                Pq.Push(a);
                Pq.Push(b);
                Pq.Push(c);
            }
            Anser[cnt]=min.Value;
            Anser[cnt+1]=rightMin.Value;
            cnt+=2;
        }
        Console.WriteLine(string.Join(" ",Anser));
    }
}