//zeljkoni@gmail.com
//Zeljko Nikolicic
using System;
using System.Collections.Generic;
using System.Text;

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string line;
            string[] values;

            Int64 L = 0;
            Int64 D = 0;
            Int64 N = 0;
            
            Int64 R = 0;
           


          //read L D N
            values = Console.ReadLine().Split(' ');
            L = Int64.Parse(values[0]);
            D = Int64.Parse(values[1]);
            N = Int64.Parse(values[2]);
            
           //osnovne strukture
            byte[,] Dict;
            Dict = new byte[D,L];            
            Boolean[,,] Case = new Boolean[N,L,26];          
      
           //read Dict          
            for (int i = 0; i < D ; i++)
            {                        
                line = Console.ReadLine();
                for (int j = 0;j <L;j++)
                {                 
                    byte code =  (byte) ( (int)(line[j]) - (int)('a')) ;
                    Dict[i, j] = code;
                }                
            }

              
            
            //set default  cases to false  
            for (int i = 0; i < N; i++)
            {               
                for (int j = 0; j < L; j++)
                {
                    for (int k = 0; k < 26; k++)
                    {
                       Case[i,j,k] = false;
                    } 
                }
            }
            //read cases
            for (int i = 0; i < N; i++)
            {
                line = Console.ReadLine();
                int p = 0;
                bool zagradaON = false;
                for (int j = 0; j < line.Length; j++)
                {
                   if (line[j] == ')') {  p++; zagradaON = false;}
                    else if (line[j] == '(') { zagradaON = true;}
                     else {
                         byte code = (byte)((int)(line[j]) - (int)('a'));
                        Case[i,p,code] = true;
                        if (!(zagradaON)) {p++;}                       
                     }
                    
                }       
            } 
            
            //process cases
            for (int i = 0; i < N; i++)
            {   
                R = 0;
                for (int j = 0; j < D; j++)
                {
                   bool ok = true;                   
                   int k = 0;
                   while ((k<L) && (ok))
                   {
                       if (Case[i,k, Dict[j,k]]) k++;
                        else ok = false;
                   }
                   if (ok) R++;
                }
                int cc = i + 1;
                Console.WriteLine("Case #" + (cc) + ": " + R);
            } 
  
        }
    }
}
