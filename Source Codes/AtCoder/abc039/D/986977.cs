using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int H,W;
    bool[,] b;
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Read();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        bool[,] c = new bool[H,W];
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                bool d = true;
                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){
                        if(i+k >= 0 && i+k < H && j+l >= 0 && j+l < W && !b[i+k,j+l]){
                            d = false;
                        }
                    }
                }
                c[i,j] = d;
            }
        }
        bool ans = true;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(b[i,j]){
                    bool d = true;
                    for(int k=-1;k<=1;k++){
                        for(int l=-1;l<=1;l++){
                            if(i+k >= 0 && i+k < H && j+l >= 0 && j+l < W && c[i+k,j+l]){
                                d = false;
                            }
                        }
                    }
                    if(d){
                        ans = false;
                    }
                }
            }
        }
        if(ans){
            sb.Append("possible\n");
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    if(c[i,j]){
                        sb.Append('#');
                    }
                    else{
                        sb.Append('.');
                    }
                }
                sb.Append('\n');
            }
        }
        else{
            sb.Append("impossible\n");
        }
    }
    void Read(){
        string[] str = Console.ReadLine().Split(' ');
        H = int.Parse(str[0]);
        W = int.Parse(str[1]);
        b = new bool[H,W];
        for(int i=0;i<H;i++){
            string s = Console.ReadLine();
            for(int j=0;j<W;j++){
                b[i,j] = s[j] == '#';
            }
        }
    }    
}