using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        string s = Console.ReadLine();
        SuffixArray S = new SuffixArray(s);
        long count = 0;
        for(int i=s.Length/2;i<s.Length-2;i++){
            if(s[0] == s[i+1] && s[i] == s[s.Length-1]){
                int f = S.SameSize(0,i+1);
                f = f >= s.Length-1-i ? s.Length-2-i : f;
                int b = S.SameSizeRev(i,s.Length-1);
                b = b >= s.Length-1-i ? s.Length-2-i : b;
                count += f + b - s.Length + 2 + i > 0 ? f + b - s.Length + 2 + i : 0;
            }
        }
        sb.Append(count+"\n");
    }
}
public class SuffixArray{
    List<int[]> a;
    int size;
    public SuffixArray(string s){
        a = new List<int[]>();
        int[] b = new int[s.Length];
        {
            int[] c = new int[s.Length];
            for(int i=0;i<s.Length;i++){
                c[i] = i;
            }
            Array.Sort(c,(x,y) => s[x] > s[y] ? 1 : (s[x] == s[y] ? 0 : -1));
            int count = 0;
            b[c[0]] = 0;
            for(int i=1;i<s.Length;i++){
                if(s[c[i-1]] != s[c[i]]){
                    count++;
                }
                b[c[i]] = count;
            }
        }
        a.Add(b);
        int l;
        for(l=2;l<s.Length;l*=2){
            int[] c = new int[s.Length-l+1];
            for(int i=0;i<s.Length-l+1;i++){
                c[i] = i;
            }
            Array.Sort(c,(x,y) => b[x] > b[y] ? 1 : (b[x] == b[y] ? b[x+l/2] - b[y+l/2] : -1));
            int count = 0;
            int[] b0 = new int[s.Length-l+1];
            b0[c[0]] = 0;
            for(int i=1;i<s.Length-l+1;i++){
                if(b[c[i-1]] != b[c[i]] || b[c[i-1]+l/2] != b[c[i]+l/2]){
                    count++;
                }
                b0[c[i]] = count;
            }
            a.Add(b0);
            b = b0;
        }
        size = l/2;
    }
    public int SameSize(int x,int y){
        int x0 = x;
        int y0 = y;
        int count = 0;
        int p = a.Count-1;
        for(int l=size;l!=0;l/=2,p--){
            if(x0 < a[p].Length && y0 < a[p].Length && a[p][x0] == a[p][y0]){
                count += l;
                x0 += l;
                y0 += l;
            }
        }
        return count;
    }
    public int SameSizeRev(int x,int y){
        int x0 = x;
        int y0 = y;
        int count = 0;
        int p = a.Count-1;
        for(int l=size;l!=0;l/=2,p--){
            if(x0 >= l-1 && y0 >= l-1 && a[p][x0-l+1] == a[p][y0-l+1]){
                count += l;
                x0 -= l;
                y0 -= l;
            }
        }
        return count;
    }
}