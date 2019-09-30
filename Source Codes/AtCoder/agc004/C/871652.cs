using System;
using System.Collections.Generic;
class Solve{
    public int h;
    public int w;
    public bool[][] a;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();        
        for(int i = 0;i < h;i++){
            string s = "";
            for(int j = 0;j < w;j++){
                if(i == 0 || (j%2 == 0 && i != h-1) || a[i][j]){
                    s += "#";
                }
                else{
                    s += ".";
                }
                if(j == w-1){
                    Console.WriteLine(s);
                }
            }
        }
        Console.WriteLine("");
        for(int i = 0;i < h;i++){
            string s = "";
            for(int j = 0;j < w;j++){
                if(i == h-1 || (j%2 == 1 && i != 0) || a[i][j]){
                    s += "#";
                }
                else{
                    s += ".";
                }
                if(j == w-1){
                    Console.WriteLine(s);
                }
            }
        }
    }
    void getinput(){
        string[] str = Console.ReadLine().Split(' ');
        h = int.Parse(str[0]);
        w = int.Parse(str[1]);
        a = new bool[h][];
        for(int i = 0;i < h;i++){
            string s = Console.ReadLine();
            a[i] = new bool[w];
            for(int j = 0;j < w;j++){
                if(s[j] == '#'){
                    a[i][j] = true;
                }
                else{
                    a[i][j] = false;
                }
            }
        }
    }    
}