using System;
using System.Collections.Generic;
//using System.Linq;
class Program
{
	static void Main(string[] args)
	{
		// ??????
        //string[] input = Console.ReadLine().Split(' ');
				int N = int.Parse(Console.ReadLine());
				List<point> coordinate = new List<point>();
				for(int i=0; i<N; i++)
				{
					string[] input = Console.ReadLine().Split(' ');
					point p = new point();
					p.x = int.Parse(input[0]);
					p.y = int.Parse(input[1]);
					p.h = int.Parse(input[2]);
					coordinate.Add(p);
				}

				// ??1~100, 1~100?????????????????
				bool isCenter	= true;
				point center = new point();
				for(int i=0; i<=100; i++)
				{
					for(int j=0; j<=100; j++)
					{
						// ??(i, j)??????????
						//Console.Write(i + " " + j + " is Center? ");
						int H = 0;
						isCenter = true;
						for(int k = 0; k<N; k++)
						{
							point pyramid = coordinate[k];
							if(pyramid.h > 0)
							{
								H = pyramid.h + Math.Abs(i - pyramid.x) + Math.Abs(j - pyramid.y);
								break;
							}
						}
						foreach(var py in coordinate)
						{
							int hh = Math.Max(H - Math.Abs(i-py.x) - Math.Abs(j-py.y), 0);
							if(hh != py.h)
							{
								isCenter = false;
								break;
							}
						}

						if(isCenter)
						{
							center.x = i;
							center.y = j;
							center.h = H;
							break;
						}
					}
					if(isCenter) break;
				}
        Console.WriteLine(center.x + " " + center.y + " " + center.h);
    }

		class point
		{
			public int x{set; get;}
			public int y{set; get;}
			public int h{set; get;}
		}
}