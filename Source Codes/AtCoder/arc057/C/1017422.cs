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
        int[] a = new int[s.Length];
        bool d = true;
        for(int i=0;i<s.Length;i++){
            a[i] = int.Parse(s[s.Length-1-i]+"");
            if(a[i] != 9){
                d = false;
            }
        }
        int[] b = new int[2*s.Length];
        {
            int c = 0;
            for(int i=0;i<b.Length;i++){
                int l = i+1 > s.Length ? s.Length : i+1;
                for(int j = i < s.Length ? 0 : i - s.Length + 1;j < l;j++){
                    c += a[j]*a[i-j];
                }
                b[2*s.Length - i - 1] = c % 10;
                c /= 10;
            }
        }
        if(d){
            if(s.Length == 1){
                sb.Append("81\n");
                return;
            }
            int i = 0;
            while(b[i] == 0){
                i++;
            }
            for(;i<b.Length;i++){
                if(b[i] == 9){
                    sb.Append("9");
                }
                else{
                    break;
                }
            }
            if(i%2 != 0){
                sb.Append(b[i]+1+"");
            }
            else{
                sb.Append(b[i] + (b[i+1] == 9 ? 1 : 0)+"");
                sb.Append((b[i+1] == 9 ? 0 : b[i+1] + 1) + "");
            }
        }
        else{
            int[] b1 = new int[2*s.Length];
            for(int i=0;i<a.Length;i++){
                if(a[i] == 9){
                    a[i] = 0;
                }
                else{
                    a[i]++;
                    break;
                }
            }
            int c = 0;
            for(int i=0;i<b1.Length;i++){
                int l = i+1 > s.Length ? s.Length : i+1;
                for(int j = i < s.Length ? 0 : i - s.Length + 1;j < l;j++){
                    c += a[j]*a[i-j];
                }
                b1[2*s.Length - i - 1] = c % 10;
                c /= 10;
            }
            int lastb = b.Length;
            int lastb1 = b1.Length;
            for(int i=b.Length-1;i>=0;i--){
                if(b[i] != 0){
                    lastb = i+1;
                    break;
                }
            }
            for(int i=b1.Length-1;i>=0;i--){
                if(b1[i] != 0){
                    lastb1 = i+1;
                    break;
                }
            }
            int k=0;
            while(b[k] == 0){
                k++;
            }
            while(b[k] == b1[k]){
                if(k == lastb-1){
                    break;
                }
                sb.Append(b[k]+"");
                k++;
            }
            if(k%2 != 0){
                if(k == lastb-1){
                    sb.Append(b[k]+"");
                }
                else{
                    if(b[k]+1 == b1[k] && k >= lastb1-1){
                        sb.Append(b[k]);
                        k++;
                        while(b[k] == 9){
                            sb.Append("9");
                            k++;
                        }
                        if(k != lastb - 2){
                            if(k%2 != 0){
                                sb.Append(b[k]+1);
                            }
                            else{
                                sb.Append(b[k]+(b[k+1] == 9 ? 1 : 0));
                                sb.Append(b[k+1] == 9 ? 0 : b[k+1]+1);
                            }
                        }
                        else{
                            if(k%2 != 0){
                                sb.Append(b[k]);
                            }
                            else{
                                sb.Append(b[k]);
                                sb.Append(b[k+1]);
                            }
                        }
                    }
                    else{
                        sb.Append(b[k]+1+"");
                    }
                }
            }
            else if(k == lastb-1 || k == lastb - 2){
                sb.Append(b[k]+"");
                sb.Append(b[k+1]+"");
            }
            else{
                if(b[k]+1 == b1[k] && k >= lastb1-1){
                    sb.Append(b[k]);
                    k++;
                    while(b[k] == 9){
                        sb.Append("9");
                        k++;
                    }
                    if(k%2 != 0){
                        sb.Append(b[k]+1);
                    }
                    else{
                        sb.Append(b[k]+(b[k+1] == 9 ? 1 : 0));
                        sb.Append(b[k+1] == 9 ? 0 : b[k+1]+1);
                    }
                }
                else{
                    sb.Append(b[k] + (b[k+1] == 9 ? 1 : 0)+"");
                    sb.Append((b[k+1] == 9 ? 0 : b[k+1] + 1) + "");
                }
            }
        }
        sb.Append("\n");
    }
}