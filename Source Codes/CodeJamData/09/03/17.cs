//zeljkoni@gmail.com
//Zeljko Nikolicic
using System;
using System.Collections.Generic;
using System.Text;

namespace B
{
    class cord
    {
        public int x, y;
        public cord(int x0, int y0)
        {
            x = x0;
            y = y0;
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            string line;
            string[] values;

            Int64 N = 0;
            Int64 R = 0;
            
            int H;
            int W;

            string BigS;
            string SmallS ="welcome to code jam";
            
            H = SmallS.Length;
            
            int[,] M =  new int[H+1, 501];;
            
            //read N  
            N = Int64.Parse(Console.ReadLine());          
            
            for (int cc = 0; cc < N; cc++)
            {
                R = 0;
                
                //load BigS
                BigS = Console.ReadLine();
                
                W = BigS.Length;   
                            
                //init
                for (int i = 0; i <= H; i++)
                {
                    for (int j = 0; j <= W; j++)
                    {
                        M[i,j] = 0;
                    } 
                }
                
             
                for (int y = H-1; y >= 0; y--)
                {                    
                    
                    for (int x = ( W-1 - (H-y)+1); x >= 0; x--)
                    {
                        M[y, x] = M[y, x + 1];
                         
                         if (SmallS[y] == BigS[x])
                         {
                            if (y == H-1)
                            {
                                M[y,x]++;                     
                            }
                            else 
                            {
                                M[y,x] += M[y+1,x+1];
                            }
                         }                       
                         
                         M[y, x] %= 10000;
                    }
                }
                              
                
                
                R = M[0,0];
                Console.WriteLine("Case #" + (cc+1) + ": " + String.Format("{0:0000}", R)  );
            }            
        }
    }
}
