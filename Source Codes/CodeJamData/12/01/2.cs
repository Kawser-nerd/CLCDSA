using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<char, string> dict = new Dictionary<char, string>();
            dict['a']="y";
            dict['b']="h";
            dict['c']="e";
            dict['d']="s";
            dict['e']="o";
            dict['f']="c";
            dict['g']="v";
            dict['h']="x";
            dict['i']="d";
            dict['j']="u";
            dict['k']="i";
            dict['l']="g";
            dict['m']="l";
            dict['n']="b";
            dict['o']="k";
            dict['p']="r";
            dict['q']="z";
            dict['r']="t";
            dict['s']="n";
            dict['t']="w";
            dict['u']="j";
            dict['v']="p";
            dict['w']="f";
            dict['x']="m";
            dict['y']="a";
            dict['z']="q";
            dict[' ']=" ";
            

            string[] inLine = File.ReadAllLines(".in");
            int N = Convert.ToInt32(inLine[0]);
            string[] outLine = new String[N];
            for(int n = 0;n<N;n++){
                outLine[n] = "Case #" + (n +1).ToString() + ": ";
                for(int i = 0; i<inLine[n+1].Length;i++){
                    outLine[n] += dict[inLine[n+1][i]];
                }
            }

            File.WriteAllLines(".out", outLine);
              
        }
    }
}
