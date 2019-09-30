using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static List<int> connectnumDelite(List<int> list)
        {
            int i = 0;
            while (i < list.Count()-1)
            {
                while (list[i] == list[i + 1])
                {
                    list.RemoveAt(i);
                    if (i >= list.Count-1)
                    {
                        break;
                    }
                }
                i++;
                if (i >= list.Count-1)
                {
                    break;
                }
            }

            return list;
        }


        static void Main()
        {
            IO io = new IO();

            //????
            int flowerNum = io.ReadLineToInt();
            List<int> height = new List<int>();
            height.Add(0);
            height.AddRange(io.ReadLineToIntList());
            height.Add(0);

            flowerNum = height.Count();
            
            int ans = 0;

            while (flowerNum != 1)
            {
                if (flowerNum == 2)
                {
                    ans += height.Max();
                    break;
                }
                height = connectnumDelite(height);
                flowerNum = height.Count();

                for(int i = 0; i < flowerNum - 2; i++)
                {
                    if (height[i] < height[i + 1] && height[i + 1] > height[i + 2])
                    {
                        int temp;
                        if (height[i] > height[i + 2])
                        {
                            temp = height[i];
                        }
                        else
                        {
                            temp = height[i + 2];
                        }
                        ans += height[i + 1] - temp;
                        height[i + 1] = temp;
                        height = connectnumDelite(height);
                        flowerNum = height.Count();
                    }

                }
            }

            //????
            Console.Write(ans);
            Console.ReadKey();
        }
    }

    //IO??????
    public class IO
    {
        //string???
        public string ReadLineToString()
        {
            return Console.ReadLine();
        }

        //int???
        public int ReadLineToInt()
        {
            return int.Parse(Console.ReadLine());
        }

        //????????????????string[]?????
        public string[] ReadLineToStringArray()
        {
            return Console.ReadLine().Split(' ').ToArray();
        }


        //???????????????int[]?????
        public int[] ReadLineToIntArray()
        {
            return Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        }

        //????????????????List<string>?????
        public List<string> ReadLineToStringList()
        {
            return Console.ReadLine().Split(' ').ToList();
        }

        //???????????????List<int>?????
        public List<int> ReadLineToIntList()
        {
            return Console.ReadLine().Split(' ').Select(int.Parse).ToList();
        }

    }

}