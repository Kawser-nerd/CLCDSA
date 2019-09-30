using System;
using System.Collections;
using System.Collections.Generic;
using System.Configuration;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading;
class Simple{
    private const int size = 8000 * 2;
    private const int offset = size / 2;
    void Solve(){
        var s = io.String;
        var x = io.Int;
        var y = io.Int;
        var f = s.Split('T').Select(str => str.Length).ToArray();
        var fx = f.Where((v, i) => (i & 1) == 0).ToArray();
        var fy = f.Where((v, i) => (i & 1) == 1).ToArray();
        var xdp = new bool[fx.Length, size];
        var ydp = new bool[fy.Length, size];       
        
        if(fy.Length == 0){
            Console.WriteLine((fx[0]==x)?"Yes":"No");
            return;            
        }         
        
        //about x
        xdp[0, 0 + fx[0] + offset] = true;
        for(int i = 1; i < fx.Length; ++i){
            for(int j = 0; j < size; ++j){
                if(0 <= j - fx[i] && j + fx[i] < size){
                    xdp[i, j] |= xdp[i - 1, j - fx[i]] || xdp[i - 1, j + fx[i]];                    
                }else if(0 <= j - fx[i]){
                    xdp[i, j] |= xdp[i - 1, j - fx[i]];                     
                }else if(j + fx[i] < size){
                    xdp[i, j] |= xdp[i - 1, j + fx[i]];
                }
            }
        }
        //about y
        ydp[0, 0 + fy[0] + offset] = true;
        ydp[0, 0 - fy[0] + offset] = true;
        for(int i = 1; i < fy.Length; ++i){
            for(int j = 0; j < size; ++j){
                if(0 <= j - fy[i] && j + fy[i] < size){
                    ydp[i, j] |= ydp[i - 1, j - fy[i]] || ydp[i - 1, j + fy[i]];                    
                }else if(0 <= j - fy[i]){
                    ydp[i, j] |= ydp[i - 1, j - fy[i]];                     
                }else if(j + fy[i] < size){
                    ydp[i, j] |= ydp[i - 1, j + fy[i]];
                }
            }
        }       
        Console.WriteLine((xdp[fx.Length - 1, x + offset] && ydp[fy.Length - 1, y + offset]) ? "Yes" : "No");        
    }
    SimpleIO io = new SimpleIO();
    public static void Main(string[] args) { new Simple().Stream(); }
    void Stream(){
        Solve();
        io.writeFlush();
    }
}
class SimpleIO{
    string[] nextBuffer;
    int BufferCnt;
    char[] cs = new char[]{' '};
    StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()){AutoFlush = false};
    public SimpleIO(){
        nextBuffer = new string[0];
        BufferCnt = 0;
        Console.SetOut(sw);
    }
    public string Next(){
        if(BufferCnt < nextBuffer.Length) return nextBuffer[BufferCnt++];
        string st = Console.ReadLine();
        while(st == "") st = Console.ReadLine();
        nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        BufferCnt = 0;
        return nextBuffer[BufferCnt++];
    }
    public string String => Next();
    public char Char => char.Parse(String);
    public int Int => int.Parse(String);
    public long Long => long.Parse(String);
    public double Double => double.Parse(String);
    public void writeFlush() { Console.Out.Flush(); }
}