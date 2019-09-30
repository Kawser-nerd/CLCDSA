using System;
using System.IO;//StreamWriter??????
using System.Collections.Generic;//List?????????

namespace dotnetproj
{
    class Program
    {
        static void Main(string[] args)
        {
            int maxcount = 0;
            int N = int.Parse(Console.ReadLine());
            string[] input = Console.ReadLine().Split(' ');
            var strList = new List<int>();
            foreach(string str in input){
                strList.Add(int.Parse(str));
            }
            while(true){
                int devCount=0;
                foreach(int c in strList){//odd or even
                    if(c%2==0) {
                        devCount++;
                    }
                }
                if(devCount==N){
                    maxcount++;
                    //Console.WriteLine(strList[0]);
                    //Console.WriteLine(strList[1]);
                   for(int i=0;i<N;i++){
                       strList[i]=strList[i]/2;
                   } 
                }
                else
                {
                    Console.WriteLine(maxcount);
                    break;
                }
            }
        }
    }
}