//zeljkoni@gmail.com
//Zeljko Nikolicic
using System;
using System.Collections.Generic;
using System.Text;

namespace B
{
    class cord
    {
        public int x,y;
        public cord (int x0,int y0)
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

            Int64 T = 0;
            Int64 H = 0;
            Int64 W = 0;

           

            int[,] A = new int[100,100];
            byte[,] G = new byte[100,100];
            char[,] RM = new char[100,100];

            Queue<cord> BFS_Q = new Queue<cord>(10002);

            //Queue<cord> Sink_Q = new Queue<cord>(10002);
            
            

            //read T
            T = Int64.Parse(Console.ReadLine());
            
            for (int i = 0; i < T; i++)
            {
                                     
                    //read H, W
                    values = Console.ReadLine().Split(' ');                    
                    H = Int64.Parse(values[0]);
                    W = Int64.Parse(values[1]);

                    //Sink_Q.Clear();
                    BFS_Q.Clear();

                    //read A[,]  , null G[,] 
                    for (int k = 0; k < H; k++)
                    {                                
                        values = Console.ReadLine().Split(' ');
                        for (int j = 0; j < W; j++)
                        {
                            
                            A[k,j] = int.Parse(values[j]);
                            G[k,j] = 0;
                        }
                    }
                    
                    //init G, RM
                                       
                    for (int k = 0; k < H; k++)
                    {
                        for (int j = 0; j < W; j++)
                        {       
                            //um mark all 
                            RM[k,j] = '-';
                            
                            //up (-1,0) right (0,-1) left (0,+1) down (+1,0)  ...(k,j)
                            int min = +20000; //grather than 10000                            
                            int dk = 0;
                            int dj = 0;                            
                            int go_k = 0; 
                            int go_j = 0;
                            byte go_code;
                            byte go_code_out;
                            byte code;
                            byte code_out;
                            
                            go_code = 0;
                            go_code_out = 0;
                            
                            dk = k+1;
                            dj = j+0;
                            code = 8;
                            code_out = 1;
                            if ((dk < H) && (dk >= 0) && (dj < W) && (dj >= 0)) 
                              {
                                if ((A[k,j] > A[dk,dj]) && (A[dk,dj] <= min))  
                                {
                                    min = A[dk,dj];                                    
                                    go_k = dk;
                                    go_j = dj;
                                    go_code = code;
                                    go_code_out = code_out;                               
                                }                          
                              }

                              dk = k + 0;
                              dj = j + 1;
                              code = 4;
                              code_out = 2;
                              if ((dk < H) &&  (dk>=0) &&  (dj<W) &&  (dj>=0))
                              {
                                  if ((A[k, j] > A[dk, dj]) && (A[dk, dj] <= min))
                                  {
                                      min = A[dk, dj];
                                      go_k = dk;
                                      go_j = dj;
                                      go_code = code;
                                      go_code_out = code_out;
                                  }
                              }

                              dk = k + 0;
                              dj = j - 1;
                              code = 2;
                              code_out = 4;
                              if ((dk < H) && (dk >= 0) && (dj < W) && (dj >= 0))
                              {
                                  if ((A[k, j] > A[dk, dj]) && (A[dk, dj] <= min))
                                  {
                                      min = A[dk, dj];
                                      go_k = dk;
                                      go_j = dj;
                                      go_code = code;
                                      go_code_out = code_out;
                                  }
                              }

                              dk = k - 1;
                              dj = j + 0;
                              code = 1;
                              code_out = 8;
                              if ((dk < H) && (dk >= 0) && (dj < W) && (dj >= 0))
                              {
                                  if ((A[k, j] > A[dk, dj]) && (A[dk, dj] <= min))
                                  {
                                      min = A[dk, dj];
                                      go_k = dk;
                                      go_j = dj;
                                      go_code = code;
                                      go_code_out = code_out;
                                  }
                              }
                            
                            
                            if (go_code==0) //sink
                               {
                                 
                                   //Sink_Q.Enqueue( new cord(k , j));   
                               }
                               else 
                               {
                                   //put one directed edge in the coded  graph G 
                                    G[go_k,go_j] =  (byte)(G[go_k,go_j] | go_code);

                                    //put another one OUT  edge in the coded  graph G 
                                    G[k, j] = (byte)(G[k, j] |   go_code_out); 
                               }
                        }    
                    }
                   
                   //BFS for all 
                   int marked_no = 0;
                   int ik = 0;
                   int ij = 0;
                   
                   char char_mark  = 'a';
                   while (marked_no < H*W) //(Sink_Q.Count > 0)
                    {   
                        //find next not marked by  leksi north/west rule...
                        while (RM[ik,ij] != '-')
                        {
                            ij++;
                            if (ij == W)
                              {
                                 ij = 0;
                                 ik++;
                              }  
                        }
                        
                        cord c = new cord(ik,ij); //Sink_Q.Dequeue();                          
                                                
                        BFS_Q.Enqueue(c);                        
                        while (BFS_Q.Count>0) 
                        {
                            cord e  = BFS_Q.Dequeue(); 
                            RM[e.x, e.y] = char_mark;
                            marked_no++;
                            
                            if (((G[e.x, e.y] & 1 ) > 0)&&(RM[e.x+1,e.y]=='-')) BFS_Q.Enqueue(new cord(e.x+1,e.y));
                            if (((G[e.x, e.y] & 2 ) > 0)&&(RM[e.x,e.y+1]=='-')) BFS_Q.Enqueue(new cord(e.x , e.y + 1));
                            if (((G[e.x, e.y] & 4 ) > 0)&&(RM[e.x,e.y-1]=='-')) BFS_Q.Enqueue(new cord(e.x , e.y - 1));
                            if (((G[e.x, e.y] & 8) > 0) &&(RM[e.x - 1, e.y] == '-')) BFS_Q.Enqueue(new cord(e.x - 1, e.y));
                        } 
                         
                        //next char
                        char_mark++;
                    }
                    
                    

                    int cc = i + 1;
                    Console.WriteLine("Case #" + (cc) + ":");

                    for (int x = 0; x < H; x++)                    
                    {
                        for (int y = 0; y < W; y++)
                        {
                            Console.Write(RM[x,y]);
                            if (y<W-1) Console.Write(' ');
                        }
                        if ((x < H - 1) || (i<T-1)) Console.WriteLine();
                    }
                }
        }
    }
}
