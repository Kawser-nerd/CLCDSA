using System;
using System.Collections;
using System.Linq;


public class ARC31
{	
	
    public static bool can = false;

    public static int[,] Map;
    public static int[,] MapClone;

	public static void Main()
	{
		int H = 10;
		int W = 10;
		
        Map = new int[H+2,W+2];
        MapClone = new int[H+2,W+2];
        for(int i = 1 ; i <= H ; i++ )
        {
            for( int j = 1 ; j <= W ; j++)
            {
                Map[i,j] = 0;
            }

        }
        char[] c;
		for(int i = 1 ; i <= H ; i++)
		{
            c = Console.ReadLine().ToCharArray();
			for(int j = 1 ; j <= W ; j++)
			{
                if(c[j-1]=='o')
                {
				    Map[i,j] = 1;
                    MapClone[i,j] = 1;
                }
            }
		}

        for(int i = 1 ; i <= H ; i++ )
        {
            for( int j = 1 ; j <= W ; j++)
            {
                if(!can)
                {
                Array.Copy(Map,MapClone,Map.Length);
                MapClone[i,j] = 1;
                DFS(i, j);
                Check();
                }
                    
             }
        }

        if(can) Console.WriteLine("YES");
        else Console.WriteLine("NO");
	}

	public static void DFS ( int h, int w)
	{
        MapClone[h,w] = -1;
		if(MapClone[h+1, w]==1) DFS(h+1,w);
        if(MapClone[h-1, w]==1) DFS(h-1,w);
        if(MapClone[h, w+1]==1) DFS(h,w+1);
        if(MapClone[h, w-1]==1) DFS(h,w-1);
	}

    public static void Check()
    {
        can = true;
        for(int i = 1 ; i <= 10 ; i++)
        {
            for(int j = 1 ; j <= 10 ; j++)
            {
                if(MapClone[i,j] == 1) can = false;
            }
        }
    }
}