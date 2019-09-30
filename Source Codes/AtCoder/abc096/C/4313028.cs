using System;
using System.Linq;
using System.Collections.Generic;

namespace Hello_World
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int H = int.Parse(s[0]), W = int.Parse(s[1]);
            bool[,] state = new bool[H,W];
            for(int i=0; i<H; i++){
                string paint = Console.ReadLine();
                for(int j=0; j<W; j++){
                    if(paint.Substring(j,1) == "#"){
                        state[i,j] = true;
                    }
                }
            }
            bool can0 = true;
            for(int i=0; i<H; i++){
                for(int j=0; j<W; j++){
                    bool can = false;
                    if(state[i,j]){
                        if(j!=0)if(state[i,j-1] == true)can = true;
                        if(j!=W-1)if(state[i,j+1] == true)can = true;
                        if(i!=0)if(state[i-1,j] == true)can = true;
                        if(i!=H-1)if(state[i+1,j] == true)can = true;
                    }else can = true;
                    if(!can){
                    can0=false;
                    break;
                    }
                if(!can0) break;
                }
            }
            Console.WriteLine(can0?"Yes":"No");
        }
    }
}