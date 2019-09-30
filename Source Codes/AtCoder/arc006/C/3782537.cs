using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace Program
{
    public class Box
    {
        internal List<int> kasane;
        public Box()
        {
            kasane = new List<int>();
        }
    }
    
    public class Program
    {	
        public static void Main()
    	{
            int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int N = n[0];
            int cnt = 0;
            
            Box[] boxes = new Box[N];
            for(int i = 0 ; i < N ; i++) boxes[i] = new Box();
            
            int hako = int.Parse(Console.ReadLine());
            boxes[0].kasane.Add(hako);
            bool set = false;
            for(int i = 1 ; i < N ; i++)
            {
                hako = int.Parse(Console.ReadLine());
                set = false;
                
                for(int j = 0 ; j < N ; j++)
                {
                    if(set) continue;
                    if(boxes[j].kasane.Count > 0 && boxes[j].kasane[boxes[j].kasane.Count-1] >= hako)
                    {
                        boxes[j].kasane.Add(hako);
                        set = true;
                    }
                    else if(boxes[j].kasane.Count == 0)
                    {
                        boxes[j].kasane.Add(hako);
                        set = true;
                    }
                }
            }
            for(int i = 0 ; i < N ; i++)
            {
                /*
                for(int j = 0 ; j < boxes[i].kasane.Count ; j++)
                {
                    Console.Write(boxes[i].kasane[j] +" ");
                }
                Console.WriteLine();
                */
                if(boxes[i].kasane.Count > 0) cnt++;
            }
            Console.WriteLine(cnt);
    	}
    }
}