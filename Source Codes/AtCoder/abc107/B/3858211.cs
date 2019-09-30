using System;
using System.Linq;
using System.Collections.Generic;

namespace _0030
{
    class Gyo
    {
        internal int dot;
        internal int sharp;

        public Gyo()
        {
            this.dot = 0;
            this.sharp = 0;
        }
    }

    class Program
    {

        
        static void Main(string[] args)
        {

            string[] str = Console.ReadLine().Split(' ');

            int n = int.Parse(str[0]);
            int m = int.Parse(str[1]);

            char[,] data = new char[n, m];

            var delete_i =new List<int>();  //?????
            var delete_j =new List<int>();  //?????
            var gyo_delete_j = new Gyo[m];  //??????????????

            //gyo_delete_j??????????
            for(int j = 0; j < m; j++)
            {
                gyo_delete_j[j] = new Gyo();
            }

            int count_dot = 0;
            
            string strer;

            //i?j?
            for(int i = 0; i < n; i++)
            {
                strer = Console.ReadLine();
                count_dot = 0;
                
                for(int j = 0; j < m; j++)
                {
                    data[i, j] = strer[j];

                    //?????????????
                    //?????????????1??????
                    if(strer[j] == '.')
                    {
                        count_dot++;
                        gyo_delete_j[j].dot = 1;
                    }
                    else
                    {                      
                        gyo_delete_j[j].sharp = 1;
                    }

                    //?????
                    //m???????????
                    if(count_dot == m)
                    {                      
                        delete_i.Add(i);
                    }
                    
                }        
            }

            //????????
            for(int j = 0; j < m; j++)
            {
                //????1?????????????????
                if(gyo_delete_j[j].dot == 1 && gyo_delete_j[j].sharp == 0)
                {
                    delete_j.Add(j);
                }
                
            }

            //Console.WriteLine();           

            //????????????
            for(int i = 0; i < n; i++)
            {
                if (delete_i.Contains(i))
                {
                    continue;
                }
                for(int j = 0; j < m; j++)
                {
                    if (delete_j.Contains(j))
                    {
                        continue;
                    }
                    Console.Write(data[i, j]);
                }
                Console.WriteLine();
            }

        }
    }
}