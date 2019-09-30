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
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        long K = int.Parse(str[1]);
        string s = Console.ReadLine();
        if(N == 1){
            if(K % 2 == 0 ^ s[0] == 'A'){
                sb.Append("B\n");
            }
            else{
                sb.Append("A\n");
            }
        }
        else{
            bool f = false;
            bool c = false;
            int count = 0;
            for(int i=0;i<N;i++){
                if(!f){
                    if(s[i] == 'A' ^ c){
                        if(K == 1){
                            K--;
                            sb.Append("B");
                            count++;
                        }
                        else{
                            K -= 2;
                            c = !c;
                        }
                        if(K == 0){
                            f = true;
                        }
                    }
                    else{
                        K--;
                        c = !c;
                        if(K == 0){
                            f = true;
                        }
                    }
                }
                else{
                    if(s[i] == 'A' ^ c){
                        sb.Append("A");
                    }
                    else{
                        sb.Append("B");
                    }
                    count++;
                }
            }
            if(K != 0){
                if(N % 2 == 0){
                    c = false;
                    for(int i=0;i<N;i++){
                        if(c){
                            sb.Append("A");
                        }
                        else{
                            sb.Append("B");
                        }
                        c = !c;
                    }
                }
                else{
                    if(K % 2 == 0){
                        sb.Append("A");
                    }
                    else{
                        sb.Append("B");
                    }
                    c = false;
                    for(int i=0;i<N-1;i++){
                        if(c){
                            sb.Append("A");
                        }
                        else{
                            sb.Append("B");
                        }
                        c = !c;
                    }
                }
            } 
            else{
                for(int i=count;i<N;i++){
                    if(c){
                        sb.Append("A");
                    }
                    else{
                        sb.Append("B");
                    }
                    c = !c;
                }
            }
            sb.Append("\n");
        }
    }
}